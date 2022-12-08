#include<bits/stdc++.h>
using namespace std;
#define MAXLEN 100

void minmax_div(int a[], int s, int e, int *min, int *max)
{
    if(s == e)
    {
        *max = a[s];
        *min = a[s];
    }
   
   else if(s == e-1)
   {    
        if(a[s] < a[e])
        {
            *max = a[e];
            *min = a[s];
        }
       else
       {
            *max = a[s];
            *min = a[e];
       }
   }
   else
   {
       int mid, max1, min1;
       max1 = INT_MIN;
       min1 = INT_MAX;
       mid = (s + e)/2;
       minmax_div(a, s, mid, min, max);
       minmax_div(a, mid+1, e, &min1, &max1);
       if(max1 > *max)
            *max = max1;
       if(min1 < *min)
            *min = min1;
   }
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
    int max, min;
    max = min = A[0];
    minmax_div(A, 0, n-1, &min, &max);
    cout<<"Maximum element in the array is "<<max<<endl;  
    cout<<"Minimum element in the array is "<<min; 
    return 0;
}