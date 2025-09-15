#include<bits/stdc++.h>
using namespace std;  
int val[1005];
int weight[55];
int dp[25][105];

int knapsack(int i,int mx_w)
{
    if(i<0 || mx_w <= 0)
        return 0;
    if(dp[i][mx_w] != -1)
        return dp[i][mx_w];
        
    if(weight[i] <= mx_w)
    {
        int op1 = knapsack(i-1,mx_w-weight[i])+val[i];
        int op2 = knapsack(i-1,mx_w);
        dp[i][mx_w] = max(op1,op2);
        return dp[i][mx_w];
    }else{

        dp[i][mx_w] = knapsack(i-1,mx_w);
        return dp[i][mx_w];
    }
}

int main()
{
    int n,mx_weight;
    cin >> n >> mx_weight;
    for(int i =0;i<n;i++)
    {
        cin >> weight[i] >> val[i];
    }
    for(int i =0;i<= n;i++)
        for(int j =0;j<=mx_weight;j++)
            dp[i][j] = -1;
    cout << knapsack(n-1,mx_weight);
    return 0;
}