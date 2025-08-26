#include<bits/stdc++.h>
using namespace std;
int n, m;
char buil[1005][1005];
bool vis[1005][1005];
int room = 0;
vector<pair<int, int>> direct = { {0,-1},{0,1},{-1,0},{1,0} };

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj)
{

    vis[si][sj] = true;
    room++;
    for (int i = 0;i < 4;i++)
    {
        int ci = si + direct[i].first;
        int cj = sj + direct[i].second;
        if (isValid(ci, cj) && !vis[ci][cj] && buil[ci][cj] == '.') {
            dfs(ci, cj);
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
            cin >> buil[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    vector<int>rooms;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (!vis[i][j] && buil[i][j] == '.') {
                room = 0;
                dfs(i, j);
                rooms.push_back(room);
            }
        }
    }
    sort(rooms.begin(), rooms.end());

    if (rooms.empty()) {
        cout << 0 << " ";
    }
    else {
        for (int r : rooms) {
            cout << r << " ";
        }
    }



    return 0;
}