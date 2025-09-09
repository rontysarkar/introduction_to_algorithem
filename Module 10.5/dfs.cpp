#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
bool vis[100];

void dfs(int src)
{
    vis[src] = true;
    cout << src << endl;

    for(auto it : adj_list[src])
    {
        if(!vis[it])
        {
            dfs(it);
        }
    }
}

int main()
{
    int n,e;
    cin >> n >>e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    dfs(1);

    // for(int i =0;i<n;i++)
    // {
    //     for(auto it : adj_list[i])
    //     {
    //         cout << it << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}