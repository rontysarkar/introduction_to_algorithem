#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100];
int prnt[100];
bool vis[100];
bool cycle;

void dfs(int src)
{
    // cout << src << endl;
    vis[src] = true;
    for(int child : adj_list[src]){
        if(vis[child] && prnt[src] != child)
            cycle = true;
        if(!vis[child])
        {
            prnt[child] = src;
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

    memset(vis,false,sizeof(vis));
    memset(prnt,-1,sizeof(prnt));
    cycle = false;
    for(int i =0;i<n;i++)
    {
        if(!vis[i]){
            dfs(i);
        }
    }

    if(cycle)
        cout << "cycle detected";
    else 
        cout << " No cycle";
    return 0;
}