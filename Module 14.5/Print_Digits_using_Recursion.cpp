#include<bits/stdc++.h>
using namespace std;

void print_digit(int num)
{
    int a = num / 10;
    int b = num % 10;
    if(a != 0)
        print_digit(a);
    cout << b << " ";
}

int main()
{
    int t;
    cin >> t;
    while(t--) 
    {
        int num;
        cin >> num;
        print_digit(num);
        cout << endl;
    }
    return 0;
}