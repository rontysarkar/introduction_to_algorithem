#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[n];
        for(int i =0;i<n;i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        
        int mn =a[0];
        int mx =a[n-1];
        if(mx%2 == mn%2) cout << 0 << endl;
        else{
            int i=0; int j =n-1; int cnt1 =0; int cnt2 = 0;
            while(a[i]%2 != mx%2)
            {
                i++;
                cnt1++;
            }
            while(a[j]%2 != mn%2)
            {   
                j--;
                cnt2++;
            }

            cout << min(cnt1,cnt2) << endl;
        }
        
    }
   
    return 0;
}