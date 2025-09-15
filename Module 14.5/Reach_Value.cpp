#include<bits/stdc++.h>
using namespace std;

bool rechValu(long long val, long long n)
{
    if (val == n) return true;
    if (val > n) return false;

    return rechValu(val * 10, n) || rechValu(val * 20, n);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        if (n != 1 && n % 2 != 0)
        {
            cout << "NO" << endl;
        }
        else {
            if (rechValu(1, n)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}