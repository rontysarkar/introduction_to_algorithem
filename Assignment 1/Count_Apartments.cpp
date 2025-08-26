#include<bits/stdc++.h>
using namespace std;
int n,m;
char buil[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> direct = {{0,-1},{0,1},{-1,0},{1,0}};

bool isValid(int i ,int j)
{
    return (i >= 0 && i<n && j>= 0 && j<m);
}

void dfs(int si,int sj)
{

    vis[si][sj] = true;

    for(int i =0;i<4;i++)
    {
        int ci = si + direct[i].first;
        int cj = sj + direct[i].second;
        if(isValid(ci,sj) && !vis[ci][cj] && buil[ci][cj] == '.'){
            dfs(ci,cj);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin >> buil[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int cnt = 0;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            if( !vis[i][j] && buil[i][j] == '.'){
                dfs(i,j);
                cnt++;
            }
        }
    }

    cout << cnt <<endl;
    return 0;
}