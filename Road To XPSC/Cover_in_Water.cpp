#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc; cin >> tc;
    while (tc--)
    {
        int n;
        string s;
        cin >> n >> s;
        int consecutive = 0;
        int empty = 0;
        for(char c :s)
        {
            if(c == '.')
            {
                empty++;
                consecutive++;
                if(consecutive == 3) break;
            }else
                consecutive = 0;
        }
        if(consecutive == 3)
            cout << 2 << endl;
        else
            cout << empty << endl;
    }
    return 0;
}