#include<iostream>
using namespace std;

int doS(int a){
    cout<<a<<endl;
    a+=5;
    cout<<a<<endl;
    a+=5;
    cout<<a<<endl;
}
int main()
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    doS(num);
    cout<<num<<endl;
    return 0;
}