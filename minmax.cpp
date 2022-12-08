#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAXLEN 100

void minmax(int*,int);
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

    minmax(A,n);    
    return 0;
}

void minmax(int* A, int n)
{
    int min=A[0], max=A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i]<=min)
        {
            min = A[i];
        }
        if (A[i]>=max)
        {
            max = A[i];
        }
    }
    cout<<"min is : "<<min<<endl;
    cout<<"max is : "<<max;    
}
