#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
#include<fstream>
#define N 1001
using namespace std;
int n, m;
bool visit[N];
vector < pair <int, int> > adj[N];
int main()
{

   ifstream inStream;
   inStream.open("input.txt");

   inStream >>n>>m;
    for(int i=0;i<m;i++){
        int a, b, c;
        inStream >> a>> b >>c;

        adj[a].push_back(make_pair(b, c));

    }

    visit[1] = true;

    priority_queue < pair < int, pair < int, int > > > pq;


     for(int i=0;i<adj[0].size();i++)
        pq.push(make_pair(-adj[0][i].second, make_pair(1, adj[0][i].first)));

    int ans = 0;

    while (!pq.empty())
    {

        int cost = -pq.top().first;

        int v1 = pq.top().second.first, v2 = pq.top().second.second;

        pq.pop();

        if (visit[v1] && visit[v2])

            continue;

        ans += cost;

        if (visit[v1])
        {

            visit[v2] = true;
             for(int i=0;i<adj[v2].size();i++)
                pq.push(make_pair(-adj[v2][i].second, make_pair(v2,adj[v2][i].first)));
        }

        else
        {

            visit[v1] = true;
            for(int i=0;i<adj[v1].size();i++)
                pq.push(make_pair(-adj[v1][i].second, make_pair(v2,adj[v1][i].first)));

        }

    }

    printf("%d", ans);

}
