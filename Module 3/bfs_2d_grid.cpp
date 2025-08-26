#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
int n, m;
bool vis[105][105];
int level[105][105];
vector<pair<int, int>> d = { {-1,0},{1,0},{0,-1},{0,1} };

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    else return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({ si,sj });
    vis[si][sj] = true;
    level[si][sj] = 0;


    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        // cout << par.first << " " << par.second << endl;

        for (int i = 0; i < 4;i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
                q.push({ ci,cj });
                vis[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1;
            }
        }



    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            cin >> grid[i][j];
        }
    }
    int si,sj,di,dj; cin>> si >> sj >> di >> dj;
    memset(vis, false, sizeof(vis));
    memset(level,-1,sizeof(level));
    bfs(si,sj);
    cout << level[di][dj] << endl;

    return 0;
}