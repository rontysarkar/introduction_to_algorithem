#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        string s1, s2;
        vector<int> arr(26, 0);
        cin >> s1 >> s2;
        for (char c : s1)
        {
            arr[c - 'a']++;
        }
        for (char c : s2)
        {
            arr[c - 'a']--;
        }
        bool ispile = true;
        for (int i = 0;i < 26;i++)
        {
            if (arr[i] != 0)
            {
                ispile = false;
            }
        }
        if (ispile)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }


    return 0;
}