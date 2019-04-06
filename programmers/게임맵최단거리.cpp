#include<vector>
#include<queue>
#include<utility>
#include<iostream>
using namespace std;

int solution(vector<vector<int> > maps)
{
	int answer = 0;
    queue<pair<int,int>> q;
    int x[4] = {0, 0, -1, 1};
    int y[4] = {1, -1, 0, 0};
    bool check[100][100];
    int n = maps.size();
    int m = maps[0].size();
    for (int i = 0; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            check[i][j] = 0;
        }
    }
    
    q.push(make_pair(0, 0));
    check[0][0] = 1;
    
    while(!q.empty()) {
        answer += 1;
        int s = q.size();
        for (int i = 0 ; i < s ; i++) {
            auto cur = q.front();
            q.pop();
            if (cur.first == n-1 && cur.second == m-1) return answer;
            for (int j = 0 ; j < 4 ; j++) {
                if (cur.first + x[j] < 0 || cur.second + y[j] < 0 ||
                    cur.first + x[j] >= n || cur.second + y[j] >= m ||
                    maps[cur.first + x[j]][cur.second + y[j]] == 0 || check[cur.first + x[j]][cur.second + y[j]]) continue;
                q.push(make_pair(cur.first + x[j], cur.second + y[j]));
                check[cur.first + x[j]][cur.second + y[j]] = true;
            }
            
        }
    }
    
	return -1;
}
