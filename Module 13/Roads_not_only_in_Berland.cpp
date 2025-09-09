#include<bits/stdc++.h>
using namespace std;
int par[1005];
int dsu_size[1005];

int dsu_find(int node)
{
    if(par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1,int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if(dsu_size[leader1] >= dsu_size[leader2])
    {
        par[leader2] = leader1;
        dsu_size[leader1] += dsu_size[leader2];
    }else{
        par[leader1] = leader2;
        dsu_size[leader2] += dsu_size[leader1]; 
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        par[i] = -1;
        dsu_size[i] = 1;
    }

    vector<pair<int,int>> rmv;
    vector<pair<int,int>> create;
    for(int i =0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        int leader1 = dsu_find(a);
        int leader2 = dsu_find(b);
        if(leader1 == leader2)
        {
            rmv.push_back({a,b});
        }else{
            dsu_union(a,b);
        }
    }

    for(int i =2;i<=n;i++)
    {
        int leader1 = dsu_find(1);
        int leader2 = dsu_find(i);
        if(leader1 != leader2)
        {
            create.push_back({1,i});
            dsu_union(1,i);
        }
    }

    cout << rmv.size() << endl;
    for(int i =0;i<rmv.size();i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << create[i].first << " " << create[i].second << endl;
    }
    return 0;
}