#include<bits/stdc++.h>
using namespace std;
#define MAXLEN 100

int sumarr_div(int a[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return a[0];
    }

    int mid = n / 2;
    int rsize = n - mid;
    int lsum = sumarr_div(a, mid);
    int rsum = sumarr_div(a + mid, rsize);
    return lsum + rsum;
}

int main(){
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
    int sum = sumarr_div(A, n);
    cout<<"sum is "<<sum; 
    return 0;
}