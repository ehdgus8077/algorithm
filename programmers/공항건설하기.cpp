#include<iostream>
#include<vector>
#include<utility>
#include <algorithm>
using namespace std;

long long chooseCity(int n, vector< pair<int,int> > city)
{
    sort(city.begin(),city.end());
  long long sum=0,answer=city[0].first,Size,temp,temp_sum;
  Size = city.size();
  long long s[Size+1];
  s[0] = city[0].second;
  for (int i = 1 ; i < Size ; i++){
    temp = (city[0].first-city[i].first);
    temp = (temp>0?temp:temp*-1);
    sum += (temp)*city[i].second;
    s[i] = s[i-1] + city[i].second;
  }
  temp = (city[0].first-city[1].first);
  temp = (temp>0?temp:temp*-1);
  temp_sum = sum + temp*(city[0].second - city[1].second-s[Size-1]+s[1]);
  for ( int i = 2 ; i < Size ; i++ ){
    temp = (city[i-1].first-city[i].first);
    temp = (temp>0?temp:temp*-1);
     temp_sum = sum + temp*(city[i-1].second - city[i].second + s[i-2] +s[i]-s[Size-1]);
    if( temp_sum < sum ){
      	sum = temp_sum;
      	answer = i;

      }
  }

	return answer;
}
int main()
{

	int tn = 3;
	pair<int,int> a,b,c;
	a.first = 1, a.second = 5;
	b.first = 2, b.second = 2;
	c.first = 3, c.second = 3;
	vector< pair<int,int> > tcity{a,b,c};

	//아래는 테스트 출력을 위한 코드입니다.
	cout<<chooseCity(tn,tcity);
}
