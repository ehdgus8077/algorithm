#include<iostream>
#include<vector>
using namespace std;

string change124(int no)
{	int temp = 0;
  vector<char> temp_str;
    string answer = "";
  while(no){
    temp = no%3;
    switch(temp){
      case 1:
        temp_str.push_back('1');
        break;
      case 2:
        temp_str.push_back('2');
        break;
      case 3:
        temp_str.push_back('4');
        break;
        no/=3;
    }
  }
    int k = 0 ;
  for ( int i = temp_str.size()-1 ; i>=0 ; i--){
    answer[k++] = temp_str[i];
  }


	return answer;
}
int main()
{
	int testNo = 10;
	string testAnswer = change124(testNo);

	cout<<testAnswer;
}
