#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool vis[100];
int parant[100];
bool cycle;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout << par << endl;
        for (int child : adj_list[par])
        {
            if(vis[child] && parant[par] != child)
                cycle = true;
            if (!vis[child]) {
                q.push(child);
                vis[child] = true;
                parant[child] = par; 
            }
        }

    }

}

int main()
{
    int n, e; cin >> n >> e;
    while (e--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parant, -1, sizeof(parant));
    cycle = false;
    for (int i = 0;i < n;i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }
    if(cycle)
        cout << "detacted cycle" << endl;
    else 
        cout << " No cycle" << endl;
    return 0;
}