#include<bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if(n == 1)
        return n;
    return sum(n-1)+n;
}

int main()
{
    cout << sum(0) << endl;
    return 0;
}