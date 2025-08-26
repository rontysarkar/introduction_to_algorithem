#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[100];
bool vis[100];

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        // cout << f << " ";

        for (int child : adj_list[f])
        {
            if (!vis[child]) {
                q.push(child);
                vis[child] = true;
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

    memset(vis,false,sizeof(vis));
    int x,y;cin >> x >> y;
    bfs(x);
    if(vis[y])
        cout << "yes";
    else cout << "NO";


    return 0;
}