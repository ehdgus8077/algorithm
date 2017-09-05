#include <iostream>
#include <fstream>
using namespace std;
void num_one(string& result,int num){
    switch(num){
    case 1:
        result.append("One_");
        break;
    case 2:
        result.append("Two_");
        break;
    case 3:
        result.append("Three_");
        break;
    case 4:
        result.append("Four_");
        break;
    case 5:
        result.append("Five_");
        break;
    case 6:
        result.append("Six_");
        break;
    case 7:
        result.append("Seven_");
        break;
    case 8:
        result.append("Eight_");
        break;
    case 9:
        result.append("Nine_");
        break;


    }

}
void num_to_string(string& result,int num){
    if(num/100){
        num_one(result,num/100);
        result.append("Hundred_");
        num%=100;
    }
    if(num/10==1){
        switch(num){
    case 10:
        result.append("Ten_");
        break;
    case 11:
        result.append("Eleven_");
        break;
    case 12:
        result.append("Twelve_");
        break;
    case 13:
        result.append("Thirteen_");
        break;
    case 14:
        result.append("Fourteen_");
        break;
    case 15:
        result.append("Fifteen_");
        break;
    case 16:
        result.append("Sixteen_");
        break;
    case 17:
        result.append("Seventeen_");
        break;
    case 18:
         result.append("Eighteen_");
         break;
    case 19:
        result.append("Nineteen_");
         break;


        }
    }
    else if(num/10>1){
         switch(num/10){
    case 2:
        result.append("Twenty_");
        break;
    case 3:
        result.append("Thirty_");
         break;
    case 4:
        result.append("Forty_");
         break;
    case 5:
        result.append("Fifty_");
         break;
    case 6:
        result.append("Sixty_");
          break;
    case 7:
        result.append("Seventy_");
         break;
    case 8:
        result.append("Eighty_");
        break;
    case 9:
        result.append("Ninety_");
         break;

    }
     num_one(result,num%10);
    }
    else
       num_one(result,num);

}

int main()
{
   ifstream inStream;
   int numTestCases,num;
   inStream.open("input.txt");
   inStream >> numTestCases;
   for (int i = 0; i < numTestCases; i++)
   {    string result;
       inStream >> num;
       if(num/1000000000){
            num_to_string(result,num/1000000000);
            num%=1000000000;
            result.append("Billion_");
       }
       if(num/1000000){
            num_to_string(result,num/1000000);
            num%=1000000;
            result.append("Million_");
       }
       if(num/1000){
            num_to_string(result,num/1000);
            num%=1000;
            result.append("Thousand_");
       }
       num_to_string(result,num);
       result.erase(result.size()-1,1);
       cout<<result<<endl;

   }
   inStream.close();
   return 0;
}
