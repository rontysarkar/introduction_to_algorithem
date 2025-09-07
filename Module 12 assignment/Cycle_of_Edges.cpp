#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis[100005];
int parant[100005];
int cycleCnt = 0;

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
            if(vis[child] && parant[par] != child)
            {
                cycleCnt++;
            }
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parant[child] = par;
            }
        }
    }
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    memset(parant,-1,sizeof(parant));

    bfs(1);
    cout << cycleCnt/2 << endl;
    return 0;
}