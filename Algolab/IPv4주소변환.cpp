#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
   ifstream inStream;
   int numTestCases,temp;
   inStream.open("input.txt");
   inStream >> numTestCases;
   for (int i = 0; i < numTestCases; i++)
   {
        int check;
		inStream >> check;
		if (check == 1) {
			string str;
			inStream >>  str;
			unsigned int num=0;
			temp=1;
			int arr[4] = {0}, count = 0;
			for (int j = 0;j<str.size();j++) {

				if (str[j] == '.'){
                    num+=temp*arr[count];
                    num*=256;
					count++;}
				else {
					arr[count] *= 10;
					arr[count] += str[j] - '0';
				}
			}

			cout << num+arr[count] << endl;
		}
		else {
			unsigned int num;
			int arr[4];
			inStream >> num;
            arr[0]=num%256;
            num/=256;
            arr[1]=num%256;
            num/=256;
            arr[2]=num%256;
            num/=256;
            arr[3]=num;
			cout << arr[3] << "." << arr[2] << "." << arr[1] << "." << arr[0] << endl;
		}
   }
   inStream.close();
   return 0;
}
