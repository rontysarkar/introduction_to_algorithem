#include<bits/stdc++.h>
using namespace std;
int n, m;
char maze[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int, int> parant[1005][1005];

vector<pair<int, int>> d = { {0,1},{0,-1},{-1,0},{1,0} };

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int ri, int rj)
{
    queue<pair<int, int>> q;
    q.push({ ri,rj });
    vis[ri][rj] = true;
    level[ri][rj] = 0;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();

        for (int i = 0;i < 4;i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (isValid(ci, cj) && !vis[ci][cj] && (maze[ci][cj] == '.' || maze[ci][cj] == 'D'))
            {
                q.push({ ci,cj });
                vis[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1;
                parant[ci][cj] = par;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int di,dj,ri,rj;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'R')
            {
                ri = i;
                rj = j;
            }
            if (maze[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
            parant[i][j] = {-1,-1};
        }
    }
    memset(vis, false, sizeof(vis));
    parant[ri][rj] = {ri,rj};
    bfs(ri,rj);

    if (vis[di][dj])
    {
        pair<int, int> par = parant[di][dj];
        while (!(par.first == ri && par.second == rj))
        {
            if(parant[par.first][par.second].first == -1) break;
            maze[par.first][par.second] = 'X';
            par = parant[par.first][par.second];
        }
    }

    for (int i = 0;i < n; i++)
    {
        for (int j = 0;j < m;j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}
