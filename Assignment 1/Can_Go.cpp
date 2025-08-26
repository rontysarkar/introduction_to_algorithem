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
void bfs(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    while(!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int ci = par.first + direct[i].first;
            int cj = par.second + direct[i].second;
            if(isValid(ci,cj) && !vis[ci][cj] && buil[ci][cj] != '#')
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
            }
        }
    }

}

int main()
{
    cin >> n >> m;
    int ai,aj,bi,bj;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<m;j++)
        {
            cin >> buil[i][j];
            if(buil[i][j] == 'A'){
                ai = i;
                aj = j;
            }else if(buil[i][j] == 'B'){
                bi = i;
                bj = j;
            }
        }
    }
    memset(vis,false,sizeof(vis));
    bfs(ai,aj);
    if(vis[bi][bj] == true)
        cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}