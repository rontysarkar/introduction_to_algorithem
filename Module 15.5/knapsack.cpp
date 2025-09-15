#include<bits/stdc++.h>
using namespace std;
int val[25];
int weight[25];
int dp[25][25];

int knapsack(int i,int w)
{
    if(i < 0 || w <= 0)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    if(weight[i] <= w)
    {
        int op1 = val[i] + knapsack(i-1,w-weight[i]);
        int op2 = knapsack(i-1,w);
        return dp[i][w] = max(op1,op2);
    }else{
        dp[i][w] = knapsack(i-1,w);
        return dp[i][w];
    }
}

int main()
{
    int n,w;
    cin >> n >> w;
    for(int i =0;i<n;i++)
    {
        cin >> weight[i] >> val[i];
    }
    for(int i =0;i<= n;i++)
        for(int j =0;j<=w;j++)
            dp[i][j] = -1;

    cout << knapsack(n-1,w);
    return 0;
}