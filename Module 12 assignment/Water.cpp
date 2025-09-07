#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        for (int i = 0;i < n;i++)
        {
            cin >> arr[i];
            if (arr[i] > mx1)
            {
                mx2 = mx1;
                mx1 = arr[i];
            }
            else if (arr[i] > mx2 && arr[i] << mx1)
                mx2 = arr[i];
        }

        for (int i = 0;i < n;i++)
        {
            if (arr[i] == mx1 || arr[i] == mx2)
                cout << i << " ";
        }
        cout << endl;

    }
    return 0;
}