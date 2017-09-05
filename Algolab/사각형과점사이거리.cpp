#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
   ifstream inStream;
   int numTestCases;

   inStream.open("input.txt");   //open input file
   if (inStream.fail())
   {
      cerr << "Input file opening failed.\n";
      exit(1);
   }

   inStream >> numTestCases;   //read the number of test cases.

   for (int i = 0; i < numTestCases; i++)
   {
      int numIntegers, value;
      int result = 1;

      inStream >> numIntegers;

      for (int j = 0; j < numIntegers; j++)
      {
         inStream >> value;
         result *= value%10;
         result %= 10;                  //���÷� �����ֱ�
      }
      cout << result << endl;            //���������� 21�� �ڸ� �����
   }
   inStream.close();         //close input file
}
