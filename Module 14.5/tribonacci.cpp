#include<bits/stdc++.h>
using namespace std;
int dp[40];
int tribo(int n)
{
    if(dp[n] != -1)
        return dp[n];
    dp[n] = tribo(n - 1) + tribo(n - 2) + tribo(n - 3);
    return dp[n];
}

int main()
{
    int n; cin >> n;

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    cout << tribo(n);
    return 0;
}