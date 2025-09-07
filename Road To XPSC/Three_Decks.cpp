#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int d = (c - (b - a)) - b;
        if (d < 0)
            cout << "NO" << endl;
        else if (d == 0)
            cout << "YES" << endl;
        else {
            if (d % 3 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

    }

    return 0;
}