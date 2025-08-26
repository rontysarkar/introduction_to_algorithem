#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool vis[100];
int level[100];

void bfs(int src)
{
    queue<int > q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!vis[child]) {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
}

int main()
{
    int v, e; cin >> v >> e;

    while (e--)
    {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }



    int l; cin >> l;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(0);

    for(int i =100;i >= 0;i--)
    {
        if(level[i] == l)
        {
            cout << i << " ";
        }
    }


    return 0;
}