// implement merge sort

/*
void Merge(int a[],int p , int q, int r)
{
    int n1=q-p+1,n2=r-q,i,j,k=p;
    int b[n1],c[n2];
    for(i=0;i<n1;i++)
        b[i]=a[k++];
    for(j=0;j<n2;j++)
        c[j]=a[k++];
    k=p;i=0;j=0;
    while(i<n1 && j<n2)
    {
        if(b[i]<c[j]) a[k++]=b[i++];
        else if(b[i]>c[j]) a[k++]=c[j++];
        else 
        {
            a[k++]=b[i++];j++;
        }
    }
    while(i<n1) a[k++]=b[i++];
    while(j<n2) a[k++]=c[j++];
}

void MergeSort(int a[],int start , int end)
{
    if(start < end)
    {
        int mid = start + (end - start)*0.5;
        MergeSort(a,start,mid);
        MergeSort(a,mid+1,end);
        Merge(a,start,mid,end);
    }
}


*/


#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;

void Merge(int a[],int p , int q, int r)
{
    int n1=q-p+1,n2=r-q,i,j,k=p;
    int b[n1],c[n2];
    for(i=0;i<n1;i++)
        b[i]=a[k++];
    for(j=0;j<n2;j++)
        c[j]=a[k++];
    k=p;i=0;j=0;
    while(i<n1 && j<n2)
    {
        if(b[i]<c[j]) a[k++]=b[i++];
        else if(b[i]>c[j]) a[k++]=c[j++];
        else 
        {
            a[k++]=b[i++];j++;
        }
    }
    while(i<n1) a[k++]=b[i++];
    while(j<n2) a[k++]=c[j++];
}

void MergeSort(int a[],int start , int end)
{
    if(start < end)
    {
        int mid = start + (end - start)*0.5;
        MergeSort(a,start,mid);
        MergeSort(a,mid+1,end);
        Merge(a,start,mid,end);
    }
}

int main () 
{
    int n;
    cout<<"Input the number of elements to be filled into the vector : ";cin>>n;
    int v[n];
    srand(time(0));
    for(int i=0;i<n;i++) v[i]=(rand()%10000+1);

    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();
    
    MergeSort(v,0,n);
    
    // End measuring time
    auto end = std::chrono::high_resolution_clock::now();
    
    cout << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microsecs" << endl;
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecs" << endl;
    cout << "Elapsed time in seconds: "      << chrono::duration_cast<chrono::seconds>(end - start).count()      << " secs";
       
    return 0;
}