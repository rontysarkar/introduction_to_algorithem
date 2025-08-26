#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,e; cin >> v >> e;
    vector<int> adj_list[v];
    while(e--)
    {
        int a,b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int n; cin >> n;
    int num = adj_list[n].size();
    cout << num ;
    return 0;
}