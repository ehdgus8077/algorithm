#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
class myMatrix
{
public:
	// friend 함수
	// Constructor (생성자)
	myMatrix(int nRows = 1, int nCols = 1);
	myMatrix(int nRows, int nCols, int initValue);
	myMatrix(int nRows, int nCols, int *data);
	myMatrix(int nRows, int nCols, int **data);
	// Copy constructor (복사 생성자)
	myMatrix(const myMatrix& mat);
	// Destructor (소멸자)
	~myMatrix();
	// Accessor functions (접근자)
	int getRows() const;
	int getCols() const;
	int* operator [](int i) const;
	int& operator ()(int i, int j) const;
	// Overloaded binary operators
	myMatrix operator +(const myMatrix& mat) const;
	myMatrix operator -(const myMatrix& mat) const;
	myMatrix operator *(const myMatrix& mat) const;
	myMatrix operator *(int value) const;
	// Overloaded assignment operators
	myMatrix& operator =(const myMatrix& mat);
	myMatrix& operator +=(const myMatrix& mat);
	myMatrix& operator -=(const myMatrix& mat);
	myMatrix& operator *=(const myMatrix& mat);
	myMatrix& operator *=(int value);
	// Overloading relational operators
	bool operator ==(const myMatrix& mat) const;
	bool operator !=(const myMatrix& mat) const;
	// Overloaded unary operators
	myMatrix operator -() const; // unary minus
								 // transpose the matrix
	myMatrix& transpose();
	friend ostream &operator <<(ostream &outStream, const myMatrix& mat);
	friend istream &operator >>(istream &inStream, myMatrix& mat);
	friend myMatrix operator *(int value, const myMatrix& mat);
private:
	int rows; // number of rows
	int cols; // number of columns
	int **pData; // pointer to actual data
	void allocateMemory(); // allocate memory for pDdata
	void deleteMemory(); // delete memory for pData
	void errorMessage(string msg) const; // print error message and exit
};
myMatrix::myMatrix(int nRows, int nCols) : rows(nRows), cols(nCols), pData(NULL)
{
	allocateMemory();
}
// Constructor
myMatrix::myMatrix(int nRows, int nCols, int initValue) : rows(nRows), cols(nCols),
pData(NULL)
{
	allocateMemory();
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			pData[i][j] = initValue;
}
myMatrix::myMatrix(int nRows, int nCols, int *data) : rows(nRows), cols(nCols),
pData(NULL)
{
	allocateMemory();
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			pData[i][j] = data[i*cols + j];
}
myMatrix::myMatrix(int nRows, int nCols, int **data) : rows(nRows), cols(nCols),
pData(NULL)
{
	allocateMemory();
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			pData[i][j] = data[i][j];
}
myMatrix::~myMatrix()
{
	if (pData != NULL)
		deleteMemory();
}
// Copy constructor
myMatrix::myMatrix(const myMatrix& mat) :
	rows(mat.rows), cols(mat.cols), pData(NULL)
{
	allocateMemory();
	for (int i = 0; i<rows; i++)
		for (int j = 0; j<cols; j++)
			pData[i][j] = mat.pData[i][j];
}
// Accessor functions
int myMatrix::getRows() const
{
	return rows;
}
int myMatrix::getCols() const
{
	return cols;
}
int* myMatrix::operator [](int i) const
{
	if ((i < 0) || (i >= rows))
		errorMessage("Accessing out-of-bound value of a matrix");
	return pData[i];
}
int& myMatrix::operator ()(int i, int j) const
{
	if ((i < 0) || (i >= rows) || (j < 0) || (j >= cols))
		errorMessage("Accessing out-of-bound value of a matrix");
	return pData[i][j];
}
// Overloaded binary operators
myMatrix myMatrix::operator +(const myMatrix& mat) const
{
    myMatrix newObj = myMatrix(rows, cols);
	if ((rows != mat.rows) || (cols != mat.cols))
		errorMessage("cannot add two matrices of different size");
    else{

        for (int i = 0;i < rows;i++) {
            for (int j = 0;j < cols;j++)
                newObj.pData[i][j] = pData[i][j] + mat.pData[i][j];
        }
    }
	return newObj;
}
myMatrix myMatrix::operator -(const myMatrix& mat) const
{
    myMatrix newObj = myMatrix(rows, cols);
	if ((rows != mat.rows) || (cols != mat.cols))
		errorMessage("cannot do subtraction between two matrices of different size");
	else{

        for (int i = 0;i < rows;i++) {
            for (int j = 0;j < cols;j++)
                newObj.pData[i][j] = pData[i][j] - mat.pData[i][j];
        }
	}
	return newObj;
}
myMatrix myMatrix::operator *(const myMatrix& mat) const
{    myMatrix newObj = myMatrix(rows, mat.cols);
    if (cols != mat.rows)
        errorMessage("cannot do multiplication between the given");
    else{

        for (int i = 0;i < rows;i++) {
            for (int j = 0;j < mat.cols;j++) {
                newObj.pData[i][j] = 0;
                for (int k = 0;k < cols;k++)
                    newObj.pData[i][j] += pData[i][k] * mat.pData[k][j];
            }
        }
	}
	return newObj;
}
myMatrix myMatrix::operator *(int value) const
{
	return value * (*this);
}
// Assignment operators
myMatrix& myMatrix::operator =(const myMatrix& mat)
{
	if (&mat == this)
		return *this;
	if (pData != 0) {
		delete[] pData[0];
		delete[] pData;
		pData = 0;
	}
	rows = mat.rows;
	cols = mat.cols;
	allocateMemory();
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			pData[i][j] = mat.pData[i][j];
		}
	}
	return *this;
}
myMatrix& myMatrix::operator +=(const myMatrix& mat)
{
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++)
			pData[i][j] += mat.pData[i][j];
	}
	return *this;
}
myMatrix& myMatrix::operator -=(const myMatrix& mat)
{
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++)
			pData[i][j] -= mat.pData[i][j];
	}
	return *this;
}
myMatrix& myMatrix::operator *=(const myMatrix& mat)
{
	int newmat[rows][mat.cols];
	for (int i = 0;i < rows;i++) {
            for (int j = 0;j < mat.cols;j++) {
                newmat[i][j] = 0;
                for (int k = 0;k < cols;k++)
                   newmat[i][j] += pData[i][k] * mat.pData[k][j];
            }
        }
	rows = rows;
	cols = mat.cols;
	allocateMemory();
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			pData[i][j]=newmat[i][j];
		}
	}
	return *this;
}
myMatrix& myMatrix::operator *=(int value)
{
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++)
			pData[i][j] *= value;
	}
	return *this;
}
// Overloading relational operators
bool myMatrix::operator ==(const myMatrix& mat) const
{
	if ((rows != mat.rows) || (cols != mat.cols))
		return false;
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++)
			if (pData[i][j] != mat.pData[i][j])
				return false;
	}
	return true;
}
bool myMatrix::operator !=(const myMatrix& mat) const
{
	return !((*this) == mat);
}
// Overloaded unary operators
myMatrix myMatrix::operator -() const // unary minus
{

	myMatrix newObj = myMatrix(rows,cols);
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++){
			newObj.pData[i][j] = -1*pData[i][j];
		}
	}
	return newObj;
}
// transpose the matrix
myMatrix& myMatrix::transpose()
{

    int newmat[cols][rows];
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++)
			newmat[j][i] = pData[i][j];
	}
	int t = rows;

	rows = cols;
	cols = t;
	allocateMemory();

	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++)
			pData[i][j] =  newmat[i][j];
	}
	return *this;
}
// private functions
void myMatrix::allocateMemory()
{
	if (pData != NULL)
		deleteMemory();
	pData = new int *[rows];
	if (pData == NULL)
		errorMessage("Memory allocation error");
	pData[0] = new int[rows*cols];
	if (pData[0] == NULL)
	{
		delete[] pData;
		errorMessage("Memory allocation error");
	}
	for (int i = 1; i<rows; i++)
		pData[i] = pData[0] + i * cols;
}
void myMatrix::deleteMemory()
{
	delete[] pData[0];
	delete[] pData;
	pData = NULL;
}
void myMatrix::errorMessage(string str) const
{
	cout << "Error: " << str << endl;
	exit(1);
}
// friend functions
myMatrix operator *(int value, const myMatrix& mat)
{
	myMatrix retObj = mat;
	retObj *= value;
	return retObj;
}
ostream &operator <<(ostream &outStream, const myMatrix& mat)
{
	outStream << mat.rows << "*" << mat.cols << endl;
	for (int i = 0; i<mat.rows; i++)
	{
		for (int j = 0; j<mat.cols; j++)
			outStream << mat[i][j] << " ";
		outStream << endl;
	}
	return outStream;
}
istream &operator >>(istream &inStream, myMatrix& mat)
{
	mat.deleteMemory();
	inStream >> mat.rows >> mat.cols;
	mat.allocateMemory();
	for (int i = 0; i<mat.rows; i++)
	{
		for (int j = 0; j<mat.cols; j++)
			inStream >> mat[i][j];
	}
	return inStream;
}
void testSimpleCase();
void testDataFromFile();
myMatrix readMatrix(ifstream& inStream);
int main(void)
{
	testSimpleCase();
	testDataFromFile();
	return 0;
}
void testSimpleCase()
{
	int testData1[6] = { 1, 2, 3, 4, 5, 6 };
	int testData2[6] = { 6, 5, 4, 3, 2, 1 };
	myMatrix m1(2, 2, 1);
	myMatrix m2(2, 3, testData1);
	myMatrix m3(3, 2, testData2);
	myMatrix m4(m3);
	myMatrix m5, m6(2, 3, 1), m7(3, 4, 1), m8(4, 2, 1), m9;
	cout << m1.getRows() << " " << m1.getCols() << endl;
	m4(0, 0) = 1;
	m4(0, 1) = 2;
	cout << m4[0][0] << " " << m4[0][1] << endl;
	cout << m4(1, 0) << " " << m4(1, 1) << endl;
	cout << m4[2][0] << " " << m4(2, 1) << endl;
	m3 = m3;
	cout << m3;
	m5 = m3 + m4;
	cout << m5;
	cout << (m4 == m3) << " " << (m4 != m3) << endl;
	m4 = m5 - m4;
	cout << (m4 == m3) << " " << (m4 != m3) << endl;
	m9 = m6 * m7 * m8 + m1;
	cout << m9;
	m8 = m7 = m6 = m5;
	cout << m8;
	m4 = m4 * 2;
	cout << m4;
	m4 = 2 * m4;
	cout << m4;
	m5 = m2 * m3;
	cout << m5;
	m2 *= m3;
	cout << m2;
	m2 += m1;
	cout << m2;
	m2 -= m1;
	cout << m2;
	m2 = -m1 + 2 * m2;
	cout << m2;
	m7 = m4;
	m8 = m7 * m4.transpose();
	cout << m8;
}
void testDataFromFile()
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
	for (int i = 0; i<numTestCases; i++)
	{
		myMatrix m0, m[4];
		for (int j = 0; j<4; j++)
			m[j] = readMatrix(inStream);
		m0 = m[0] * m[1] * m[2] + m[3];
		cout << m0;
		cout << m0[0][0] << " " << m0[m0.getRows() - 1][m0.getCols() - 1] << endl;
	}
	inStream.close();
}

#define MAX_SIZE 10000 // 100 * 100
myMatrix readMatrix(ifstream& inStream)
{
	int data[MAX_SIZE];
	int row, col;
	inStream >> row >> col;
	for (int i = 0; i<row*col; i++)
		inStream >> data[i];
	return myMatrix(row, col, data);
}
