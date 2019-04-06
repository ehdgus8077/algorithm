#include<vector>
#include<iostream>
using namespace std;

vector<int> bestSet(int no,int sum)
{
    vector<int> answer(1);
	if(sum<no){
        ;
        answer[0] = -1;

	}
	else{
        answer.resize(no);
        int value = sum/no;
        int Remainder = sum%no;
        for (int i = 0 ; i <no ;i++ ){
            answer[i] = value;
        }
        while(Remainder--){
            answer[no-1] +=1;
            no--;
        }
	}
	return answer;
}
int main()
{
	int n=3, s=13;
	vector<int> test= bestSet(n,s);

// 아래는 테스트로 출력해 보기 위한 코드입니다.
	for(int i=0; i<test.size(); i++)
		cout << test[i] << " ";
}
