#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[100];
int dis[100];
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,src });
    dis[src] = 0;

    while (!pq.empty())
    {
        int par_dis = pq.top().first;
        int par_node = pq.top().second;
        pq.pop();
        
        for (auto child : adj_list[par_node])
        {
            int ch_node = child.first;
            int ch_dis = child.second;
            
            if (par_dis + ch_dis < dis[ch_node])
            {
                
                dis[ch_node] = par_dis + ch_dis;
                pq.push({ dis[ch_node],ch_node });
            }
        }
    }
}


int main()
{
    int n, e; cin >> n >> e;

    while (e--)
    {
        int a, b, c; cin >> a >> b >> c;
        adj_list[a].push_back({ b,c });
        adj_list[b].push_back({ a,c });
    }
    for (int i = 0;i < n;i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for(int i =0;i<n;i++)
    {
        cout << i << " > " << dis[i] << endl;
    }

    return 0;
}