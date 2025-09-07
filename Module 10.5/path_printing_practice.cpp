#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool vis[100];
int parnt[100];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child : adj_list[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parnt[child] = par;
            }
        }
    }
}

int main()
{
    int n,e; cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parnt,-1,sizeof(parnt));

    bfs(0);
    int nd = 6;

    
    while(nd != -1)
    {
        cout << nd << " ";
        nd = parnt[nd];
    }


    return 0;
}