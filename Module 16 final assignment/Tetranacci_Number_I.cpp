#include<bits/stdc++.h>
using namespace std;
vector<int> dp(35,-1);
int tetranacci(int n)
{
    if(n == 0 || n == 1)
        return n;
    if(n == 2 || n == 3)
        return n-1;
    if(dp[n] != -1)
        return dp[n];
    int op1 = tetranacci(n-1);
    int op2 = tetranacci(n-2);
    int op3 = tetranacci(n-3);
    int op4 = tetranacci(n-4);
    return dp[n] = op1+op2+op3+op4;
}

int main()
{
    int n; cin >> n;
    cout << tetranacci(n);
    return 0;
}