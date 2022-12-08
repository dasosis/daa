#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAXLEN 100

void sumarr(int*,int);
int main(int argc, char const *argv[])
{
    int A[MAXLEN], n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        A[i] = rand()%100;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    sumarr(A,n);    
    return 0;
}

void sumarr(int* A, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + A[i];
    }
    cout<<"sum is : "<<sum;    
}
