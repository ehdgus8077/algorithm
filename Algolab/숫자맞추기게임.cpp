#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class num4 {
private:
	vector <int> number;
public:
	num4() {
		for (int i = 0;i <= 9999;i++)
			number.push_back(i);
	}
	void explore(int num, int strike,  int ball) {

		for (int i = 0;i<number.size();i++) {
			if (check(number.at(i), num,strike,ball)) {
                number.erase(number.begin() + i);
				i--;
			}
		}
	}
	bool check( int num1, int num2,int strike, int ball) {
		int array1[4], array2[4];
		div(array1, num1);
		div(array2, num2);
		int count1=0,count2 = 0;
		for (int i = 0;i<4;i++) {
			if (array1[i] == array2[i])
				count1++;
		}
		for (int i = 0;i<4;i++) {
			for (int j = 0;j<4;j++) {
				if ((i == j))
					continue;
				if (array1[i] == array2[i] || array1[j] == array2[j])
					continue;
				if (array1[i] == array2[j]) {
					array1[i] = array2[j] = -1;
					count2++;
					break;
				}
			}
		}
		return (count1!=strike||count2!=ball);
	}

	void div(int * arr, int num) {
            arr[0]=num/1000;
            arr[1]=num%1000/100;
            arr[2]=num%100/10;
            arr[3]=num%10;
	}
	int result() {
		if (number.size() == 1)
			return number.front();
		else if (number.size() == 0)
			return -2;
		else
			return -1;
	}
};
int main() {

     ifstream inStream("input.txt");
     int testcase;
    inStream >> testcase ;
    for(int k=0;k<testcase;k++)
    {    int c;
         inStream >> c;
         num4 number;

        for (int j = 0;j<c;j++) {
			int num, st, bo;
			inStream >> num >> st >> bo;
           number.explore(num, st, bo);
		}
		cout << number.result() << endl;
    }


	return 0;
}
