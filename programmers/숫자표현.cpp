#include<iostream>
using namespace std;
int expressions(int testCase)
{
	int answer = 0;
	int count = testCase/2;
    for ( int i = 1 ; i<=count+1 ; i ++ ){

        if(i%2 == 1 ){
            if(testCase%i == 0 && testCase/i - i/2 >0){
                answer++;

            }

        }
        else{
            if(testCase%i != 0&&testCase/i-(i/2-1)>0 &&testCase%i == i/2){
                answer++;
            }
        }
    }

	return answer;
}

int main()
{
	int testNo = 10;
	int testAnswer = expressions(testNo);
// 아래는 테스트로 출력해 보기 위한 코드입니다.
	cout<<testAnswer;
}
