#include <iostream>
#include <fstream>
using namespace std;



int main(){
    ifstream inStream("input.txt");
    int testcase,count,idx,num_count,result_key,result;
    string str;
    double arr[]={8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074};
    double sum, min_sum;
    inStream >> testcase ;
    while(testcase--){
       inStream >> str;
       double alpha[26]={0,};
       count=str.size();
       num_count=0;
       for(int i=0;i<count;i++){            // 알파벳 빈도수 세서 넣기
            if((int)str[i]>=65&&(int)str[i]<=90){   // 대문자 경우
                    idx=(int)str[i]-65;
                    alpha[idx]++;
                    num_count++;
            }
             else if((int)str[i]>=97&&(int)str[i]<=122){  //소문자 경우
                 idx=(int)str[i]-97;
                 alpha[idx]++;
                 num_count++;
            }
       }

        for(int i=0;i<26;i++){      // 빈도수 나누기 총 빈도수 한 후 제곱
            if(alpha[i]!=0){
                alpha[i]/=num_count;

                alpha[i]*=alpha[i];
                }

        }

        for(int key=0;key<=25;key++){           // key값 찾기
                sum=0;

            for(int i=0;i<26;i++){
                if(alpha[i]!=0){
                        if(i<key){
                            sum+=alpha[i]/arr[i+26-key];


                        }
                        else{
                            sum+=alpha[i]/arr[i-key];
                         ;
                        }

                    }
            }
            if(key==0){min_sum=sum;
               result_key = 0; }
            if(sum-min_sum < 1e-7*-1){

               min_sum=sum;
                result_key=key;
            }
        }
       for(int i=0;i<str.size();i++){        // 출력
        if((int)str[i]>=65&&(int)str[i]<=90){
            result=str[i]-result_key;

          if(result<65){result+=26;}   //change
          cout<<(char)result;
        }
        else if((int)str[i]>=97&&(int)str[i]<=122){
            result=str[i]-result_key;

          if(result<97){result+=26;}
          cout<<(char)result;

        }
        else {cout<<str[i];

        }
       }
       cout<<endl;
        }

    return 0;
}
