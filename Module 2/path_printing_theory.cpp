#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool vis[100];
int level[100];
int parant[100];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout << par << " ";

        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parant[child] = par;
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

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parant, -1, sizeof(parant));


    int src, dest; cin >> src >> dest;
    bfs(src);

    // for(int i =0;i<7 ; i++)
    // {
    //     cout << i << " > " << parant[i] << endl;
    // }

    vector<int> path;
    int node = dest;
    while(node != -1)
    {
        path.push_back(node);
        node = parant[node];
    }

    reverse(path.begin(),path.end());
    for(int x : path)
    {
        cout << x << " ";
    }




    return 0;
}