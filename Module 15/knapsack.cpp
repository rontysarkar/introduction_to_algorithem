#include<bits/stdc++.h>
using namespace std;
int val[100];
int weight[100];
int dp[100][100];


int knapsack(int i, int mx_w)
{
    if(i<0 || mx_w == 0)
        return 0;
    if(dp[i][mx_w] != -1)
        return dp[i][mx_w];
    if (weight[i] <= mx_w) {
        int nibo = knapsack(i - 1, mx_w - weight[i]) + val[i];
        int nibona = knapsack(i - 1, mx_w);
        dp[i][mx_w] = max(nibo,nibona);
        return dp[i][mx_w];
    }
    else {

        dp[i][mx_w] = knapsack(i - 1, mx_w);
        return dp[i][mx_w];
    }
}

int main()
{
    int n;
    int max_weight;
    cin >> n;
    for (int i = 0;i < n;i++)
        cin >> val[i];
    for (int i = 0;i < n;i++)
        cin >> weight[i];
    cin >> max_weight;
    for(int i =0;i<=n;i++)
        for(int j =0;j<=max_weight;j++)
            dp[i][j] = -1;
    cout << knapsack(n-1,max_weight);
    return 0;
}