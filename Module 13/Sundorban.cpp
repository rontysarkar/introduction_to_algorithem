#include<bits/stdc++.h>
using namespace std;
char mat[35][35];
bool vis[35][35];
int level[35][35];
int n;

vector<pair<int, int>> d = { {1,0},{-1,0},{0,1},{0,-1} };

bool isValid(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n)
        return true;
    else
        return false;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({ si,sj });
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        int par_i = q.front().first;
        int par_j = q.front().second;
        q.pop();

        for (int i = 0;i < 4;i++)
        {
            int ch_i = par_i + d[i].first;
            int ch_j = par_j + d[i].second;
            if (isValid(ch_i, ch_j) && !vis[ch_i][ch_j] && mat[ch_i][ch_j] != 'T')
            {
                q.push({ ch_i,ch_j });
                vis[ch_i][ch_j] = true;
                level[ch_i][ch_j] = level[par_i][par_j] + 1;
            }
        }
    }

}

int main()
{

    cin >> n;
    int si, sj, ei, ej;

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            if (mat[i][j] == 'E')
            {
                ei = i;
                ej = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(si, sj);
    cout << level[ei][ej];
    return 0;
}