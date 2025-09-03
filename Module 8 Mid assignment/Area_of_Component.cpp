#include<bits/stdc++.h>
using namespace std;
int n,m;
char mat[1005][1005];
bool vis[1005][1005];
int mn = INT_MAX;
int cnt;

vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}};

bool isValid(int i ,int j)
{
    return ( i>=0 && i<n && j>=0 && j<m);
}

void dfs(int si,int sj)
{
    vis[si][sj] = true;
    cnt++;

    for(int i =0;i<4;i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(isValid(ci,cj) && !vis[ci][cj] && mat[ci][cj] == '.')
        {
            dfs(ci,cj);
        }
    }

}

int main()
{
    cin >> n >> m;
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    
    for(int i=0;i<n;i++)
        for(int j =0;j<m;j++)
        {
            if(!vis[i][j] && mat[i][j] == '.')
            {
                cnt = 0;
                dfs(i,j);
                mn = min(mn,cnt);
            }
        }

    if(mn == INT_MAX) cout << -1;
    else cout << mn;
    
    return 0;
}