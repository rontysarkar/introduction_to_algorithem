#include<bits/stdc++.h>
using namespace std;
int par[100005];
int dsu_size[100005];
int mx,cnt;

int find(int node)
{
    if(par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1,int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(leader1 == leader2)
        return;
    if(dsu_size[leader1] >= dsu_size[leader2])
    {
        par[leader2] = leader1;
        dsu_size[leader1] += dsu_size[leader2];
        mx = max(dsu_size[leader1],mx);
    }else{
        par[leader1] = leader2;
        dsu_size[leader2] += dsu_size[leader1];
        mx = max(dsu_size[leader2],mx);
    }
    cnt--;
} 




int main()
{
    int n,e;
    cin >> n >> e;
    mx = 1;
    cnt = n;
    for(int i =1;i<=n;i++)
    {
        par[i] = -1;
        dsu_size[i] = 1;
    }

    while(e--)
    {
        int a,b;
        cin >> a >> b;
        dsu_union(a,b);
        cout << cnt << " " << mx<< endl;
    }
    return 0;
}