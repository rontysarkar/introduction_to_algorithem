#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n; 
    cin >> n;
    long long int res[n];
    res[0] = 0;
    res[1] = 1;
    res[2] = 1;
    res[3] = 2;
    for(int i=4;i<=n;i++)
    {
        res[i] = res[i-1]+res[i-2]+res[i-3]+res[i-4];
        
    }
    cout << res[n];

    return 0;
}