#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
bool vis[100005];

void dfs(int src)
{
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e; cin >> n >> e;
    while (e--)
    {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    int k = 0;
    vector<pair<int, int>> v;
    for (int i = 1;i <= n;i++)
    {
        if (!vis[i]) {
            if (i != 1)
            {
                v.push_back({ i - 1,i });
                k++;
            }
            dfs(i);
        }
    }
    cout << k << endl;
    for (auto par : v)
    {
        cout << par.first << " " << par.second << endl;
    }
    return 0;
}