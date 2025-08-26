#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n;cin >> n;
        char s[n];
        char ss[n][n];
        for (int i = 0;i < n;i++)
        {
            cin >> s[i];
        }

        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                if (i == j) {
                    s[j] == '0' ? ss[i][j] = '1' : ss[i][j] = '0';
                }
                else ss[i][j] = s[j];
            }
        }
        int cnt = 0;
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                if (ss[i][j] == '1') {
                    cnt++;
                }
            }

        }
        cout << cnt << endl;
    }

    return 0;
}