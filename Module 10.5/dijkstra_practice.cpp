#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[100];
int dis[100];
int parnt[100];

void dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    dis[src] = 0;

    while(!pq.empty())
    {
        auto par_n = pq.top().second;
        auto par_c = pq.top().first;
        pq.pop();

        for(auto child : adj_list[par_n])
        {
            int child_n = child.second;
            int child_c = child.first;
            if(par_c + child_c < dis[child_n])
            {
                dis[child_n] = par_c + child_c;
                pq.push({dis[child_n],child_n});
                parnt[child_n] = par_n;     
            }
        }
    }
    
}

int main()
{
    int n, e;
    cin >> n >> e;
    
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({ c,b });
        adj_list[b].push_back({ c,a });
    }

    for(int i =0;i<n;i++)
    {
        dis[i] = INT_MAX;
        parnt[i] = -1;
    }

    dijkstra(1);

    for(int i =1;i<=n;i++)
    {
        cout << i << " >" << parnt[i] << endl;
    }

    
    return 0;
}