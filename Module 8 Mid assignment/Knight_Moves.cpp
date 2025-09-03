#include<bits/stdc++.h>
using namespace std;
int n, m;
int chess[105][105];
bool vis[105][105];
int level[105][105];

vector<pair<int, int>> d = { {-2,1},{-2,-1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2} };

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int ki, int kj)
{
    queue<pair<int, int>> q;
    q.push({ ki,kj });
    vis[ki][kj] = true;
    level[ki][kj] = 0;

    while (!q.empty())
    {
        auto par = q.front();
        q.pop();

        for (int i = 0;i < 8;i++)
        {
            int ci = par.first + d[i].first;
            int cj = par.second + d[i].second;
            if (isValid(ci, cj) && !vis[ci][cj])
            {
                q.push({ ci,cj });
                vis[ci][cj] = true;
                level[ci][cj] = level[par.first][par.second] + 1;
            }
        }

    }

}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int ki, kj, qi, qj;
        cin >> ki >> kj >> qi >> qj;
        memset(vis, false, sizeof(vis));
        memset(level, 0, sizeof(level));

        bfs(ki, kj);
        if (vis[qi][qj])
        {
            cout << level[qi][qj] << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}