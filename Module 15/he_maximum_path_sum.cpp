#include<bits/stdc++.h>
using namespace std;
int n, m;
int mat[15][15];
int dp[15][15];

int knapsack(int i, int j)
{
    if (i > n || j > m) return INT_MIN;
    if (i == n && j == m) return mat[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    int down = knapsack(i + 1, j);
    int right = knapsack(i, j + 1);
    dp[i][j] = mat[i][j] + max(down, right);
    return dp[i][j];

}

int main()
{

    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            cin >> mat[i][j];
            dp[i][j] = -1;
        }
    }

    cout << knapsack(1, 1) << endl;
    return 0;
}