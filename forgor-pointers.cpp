#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*int* ret(int* A)
{
    return A;
}*/

int main(int argc, char const *argv[])
{
    int* A[10],B[10];
    cout<<**A<<endl<<B<<endl;
    *A = B;
    cout<<A<<endl<<B<<endl;
    //*B = ret(A);
    return 0;
}

