#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=5;
    for(int i=0;i<n;i++){
        cout<<"\n";
        for(char ch='A';ch<='A'+(n-i-1);ch++){
            cout<<ch;
        }
    }
    return 0;
}