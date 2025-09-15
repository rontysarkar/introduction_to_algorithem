#include<bits/stdc++.h>
using namespace std;

long long int fac(long long int n)
{
    if(n == 1)
        return 1;
    long long int f = fac(n-1);
    return n*f;
}

int main()
{
    long long int n;
    cin >> n;
    cout << fac(n);
    return 0;
}