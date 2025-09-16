#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc; cin >> tc;
    while (tc--)
    {
        int n, m;
        string s;
        cin >> n >> m >> s;
        int fre[7] = { 0 };
        for (char c : s)
        {
            fre[c - 'A']++;
        }
        int prb = 0;
        for (int i = 0;i < 7;i++)
        {
            if (fre[i] < m) {
                prb += m - fre[i];
            }
        }
        cout << prb << endl;
    }
    return 0;
}