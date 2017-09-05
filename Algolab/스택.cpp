#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stack>
using namespace std;

template <class T> class MyStack
{
public:

    MyStack();
    MyStack(long value);
    ~MyStack();

    bool push(const T pushValue);
    bool pop(T& popValue);
    bool peek(T& peekValue) const;

    bool isEmpty() const;   // test
    bool isFull() const;
    long Size();
    long top;
private:
    T *elements;
    long size;
    void setSize(long);
    void allocateMemory();
    const static long default_stack_size = 256;
};



template <class T>
MyStack<T>::MyStack()
{
    size = default_stack_size;
    allocateMemory();
    top = -1;
}

template <class T> MyStack<T>::MyStack(long val)
{
    if ( val < 0 )         val *= -1;
    else if ( val == 0 )         val = default_stack_size;

    size = val;
    allocateMemory();
    top = -1;
}

template <class T> MyStack<T>::~MyStack()
{
    //delete array dynamically allocated
    delete[] elements;
}

template <class T>
bool MyStack<T>::push(const T pushValue)
{
    if (!isFull())
    {
        elements[++top] = pushValue;
        return true;
    }
    else
        return false;
}

template <class T>
bool MyStack<T>::pop(T& popValue)
{
    if (!isEmpty())
    {
        popValue = elements[top--];
        return true;
    }
    else
        return false;
}
template <class T>
bool MyStack<T>::peek(T& peekValue) const
{
    if (!isEmpty())
    {
        peekValue = elements[top];
        return true;
    }
    else
        return false;
}
template <class T> bool MyStack<T>::isFull() const
{
    return top + 1 >= size;
}

template <class T> bool MyStack<T>::isEmpty() const
{
    return top==-1;
}


template <class T> void MyStack<T>::setSize(long val)
{
    size = val;
}

template <class T>
void MyStack<T>::allocateMemory()
{
    elements = new T [size];

    if (elements == NULL)
    {
        cout << "stack memory allocation error" << endl;

    }
}

template <class T> ostream& operator<< (ostream& os, const MyStack<T> &s)
{
    cout << "Contents of Stack:";

    int t = s.top;
    while (t > -1)         cout << s.elements[t--] << " ";
    cout << endl;

    return os;
}
const int MAX_SIZE = 9;

class Position
{
public:
    Position(int x=0, int y=0,int z=0)
    {
        row = x;
        col = y;
        dir= z ;
    }     int getRow() const
    {
        return row;
    }     int getCol() const
    {
        return col;
    }     int getDir() const
    {
        return dir;
    }     void setPos(int r, int c)
    {
        row = r;
        col = c;
    }     void setPos(Position &p)
    {
        row = p.row;
        col = p.col;
    }     void setDir(int d)
    {
        dir = d;
    }    private:
    int row;
    int col;
    int dir;
};
static int direction[8][2] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
class KnightTour
{
public:
    KnightTour();
    KnightTour(int sizeRow, int sizeCol);

    bool buildKnightTour(int startRow, int startCol);
    void printBoard();

private:
    typedef int boardType[MAX_SIZE][MAX_SIZE];
    bool nonrecurKnightTour(int startRow, int startCol,int move);
    bool isValidMove (int row, int col);

    int sizeRow, sizeCol;
    boardType board;
};

KnightTour::KnightTour()
{
    sizeRow = sizeCol = 8;  // default size of Chessboard
}

KnightTour::KnightTour(int sRow, int sCol)
{
    if (sRow>=2 && sRow<=MAX_SIZE)         sizeRow = sRow;
    else         sizeRow = 8;    // set to default size
    if (sCol>=2 && sCol<=MAX_SIZE)        sizeCol = sCol;
    else         sizeCol = 8;    // set to default size
}

void KnightTour::printBoard()
{
    for (int r = 0; r < sizeRow; r++)
    {
        for (int c = 0; c < sizeCol; c++)
            cout << board[r][c] << " ";

        cout <<endl;
    } // for r
}


bool KnightTour::buildKnightTour(int startRow, int startCol)
{
    for (int r=0; r<sizeRow; r++)
        for (int c=0; c<sizeCol; c++)
            board[r][c]= 0;

    if (startRow <= 0 || startRow > sizeRow)
        startRow = 0;
    if (startCol <= 0 || startCol > sizeCol)
        startCol = 0;

    board[startRow-1][startCol-1] = 1;

    return nonrecurKnightTour(startRow-1, startCol-1, 1);
}

bool KnightTour::nonrecurKnightTour(int row, int col, int move)
{
    int size = sizeRow*sizeCol;
	MyStack<Position>s = MyStack<Position>(size);
    Position temp;
	int dir = 0;
	s.push(Position(row, col, 0));
	while(!s.isFull()){
	    s.peek(temp);
		row = temp.getRow();
		col = temp.getCol();
		dir =temp.getDir();

		if(isValidMove(row+direction[dir][0], col+direction[dir][1])) {
			row += direction[dir][0];
			col += direction[dir][1];

			s.push(Position(row, col, 0));
			board[row][col] = ++move;

		}
		else {
			while(true) {
                s.peek(temp);
				if(temp.getDir() == 7) {
					board[temp.getRow()][temp.getCol()] = 0;
					--move;
					s.pop(temp);
					if(s.isEmpty())
						return false;
				}
				else{
                    s.peek(temp);
                    row = temp.getRow();
                    col = temp.getCol();
                    dir = temp.getDir() + 1;
                    s.pop(temp);
                    s.push(Position(row, col, dir));
					break;
				}
			}

		}
	}
	return true;
}

bool KnightTour::isValidMove(int row, int col)
{
    if(row>=sizeRow || row<0)         return false;
    if(col>=sizeCol || col<0)         return false;
    if(board[row][col] != 0)         return false;
    else         return true;
}
int main()
{
    ifstream inStream;
    int numTestCases;

    inStream.open("input.txt");
    if (inStream.fail())
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }

    inStream >> numTestCases;

    for(int i=0; i<numTestCases; i++)
    {
        int sizeRow, sizeCol;
        int startRow, startCol;

        inStream >> sizeRow >> sizeCol;
        inStream >> startRow >> startCol;

        KnightTour kTour(sizeRow, sizeCol);

        if (kTour.buildKnightTour(startRow, startCol))
        {
            cout << 1 << endl;
            kTour.printBoard();
        }
        else             cout << 0 << endl;
    }
    inStream.close();
    return 0;
}
