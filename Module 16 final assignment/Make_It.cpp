#include<bits/stdc++.h>
using namespace std;
vector<int> dp(100005, -1);

bool reach(long long int val, long long int n)
{
    if (val == n)
        return true;
    if (val > n)
        return false;
    if (dp[val] != -1)
        return dp[val];
        
    bool ans = reach(val + 3, n) || reach(val * 2, n);
    dp[val] = ans;
    return  ans;

}

int main()
{
    int tc; cin >> tc;
    while (tc--)
    {
        long long int n;
        cin >> n;
        fill(dp.begin(), dp.begin() + n + 1, -1);
        if (reach(1, n))
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}