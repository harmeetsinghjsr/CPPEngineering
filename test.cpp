#include<bits/stdc++.h>
using namespace std;

int main()
{
    float arr[] = {28,
24,
23,
24,
22,
25,

24,
23,
24,
23,
26,
0,
26,
25,
28,
26,
23,
24,
24,
17,
24,
21,
25,
21,
26,
21,
24,
25,
25,
25,
24,
23,
24,
25,
27,
22,
22,
20,
22,
24,
26,
25,
22,
25,
23,
24,
23,
0,
23,
26,
28,
24,
14,
23,
26,
21,
25,
22,
25,
0,
25,
25,
20,
24,
19,
25,
27,
23,
20
};
    int n=sizeof(arr)/sizeof(arr[0]);
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 24) {
            counter1++;
        } else if (arr[i] >= 18 && arr[i] <= 23.97) {
            counter2++;
        } else if (arr[i] >= 12 && arr[i] <= 17.97) {
            counter3++;
        }
        else if(arr[i]<12 && arr[i]!=0){
            counter4++;
        }
        else if(arr[i]==0){
            counter5++;
        }
    }

    cout << "Number of students with marks greater than or equal to 24 (80%) : " << counter1 << endl;
    cout << "Number of students with marks between 18 and 23 (60-79.9%) : " << counter2 << endl;
    cout << "Number of students with marks between 12 and 17 (40-59.9%) : " << counter3 << endl;
    cout << "Number of students with marks less than 12 (less than 40%) : " << counter4<< endl;
    cout<<"Total number of student in this group :"<<n<<endl;
    cout<<"The number of absent students are :"<<counter5<<endl;
    cout<<"The number of present students are :"<<n-counter5<<endl;
    return 0;
}
