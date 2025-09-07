#include<bits/stdc++.h>
using namespace std;
int par[105];
int dsu_size[105];

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if (dsu_size[leader1] < dsu_size[leader2])
    {
        par[leader1] = leader2;
        dsu_size[leader2] += dsu_size[leader1];
    }
    else {
        par[leader2] = leader1;
        dsu_size[leader1] += dsu_size[leader2];
    }

}

int main()
{

    memset(par, -1, sizeof(par));
    memset(dsu_size, 1, sizeof(dsu_size));

    int n,e; cin >> n >> e;
    bool cycle = false;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        int leader1 = dsu_find(a);
        int leader2 = dsu_find(b);
        if(leader1 == leader2)
        {
            cycle = true;
        }else{
            dsu_union(a,b);
        }
    }
    
    if(cycle)
    {
        cout << "cycle detect";
    }else {
        cout << "no cycle";
    }
    return 0;
}