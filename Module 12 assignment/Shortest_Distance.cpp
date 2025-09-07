#include<bits/stdc++.h>
using namespace std;
int n, e;
long long int mat[105][105];

void floyd_warshall()
{
    for (int k = 1;k <= n;k++)
    {
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                if (mat[i][k] != LLONG_MAX && mat[k][j] != LLONG_MAX && mat[i][k] + mat[k][j] < mat[i][j])
                {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            if (i == j)
                mat[i][j] = 0;
            else
            {
                mat[i][j] = LLONG_MAX;
            }
        }
    }

    while (e--)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        mat[a][b] = min(mat[a][b], w);
    }
    floyd_warshall();
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (mat[x][y] != LLONG_MAX)
            cout << mat[x][y] << endl;
        else
            cout << -1 << endl;
    }


    return 0;
}