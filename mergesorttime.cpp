#include<bits/stdc++.h>
#include<vector>
using namespace std;
void mergeutil(vector<int> &V,int start,int mid,int end)
{    
    int n1 = mid - start + 1;    
    int n2 = end - mid;      
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)    
    L[i] = V[start + i];    
    for (int j = 0; j < n2; j++)    
    R[j] = V[mid + 1 + j];    
      
    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2)    
    {    
        if(L[i] <= R[j])    
        {    
            V[k] = L[i];    
            i++;    
        }    
        else    
        {    
            V[k] = R[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        V[k] = L[i];    
        i++;    
        k++;    
    }    
    while (j<n2)    
    {    
        V[k] = R[j];    
        j++;    
        k++;    
    }    
}    
void mergesort(vector<int> &V,int start,int end)
{
    if (start>=end)
    {
        return;
    }
    int mid = start + (end - start)/2;
    mergesort(V,start,mid);
    mergesort(V,mid+1,end);
    mergeutil(V,start,mid,end);
}
int main(int argc, char const *argv[])
{
    int n = 1000000;
    vector<int> V;
    for (int i = 0; i < n; i++)
    {
        V.push_back(rand()%10000);
    }
    auto start = std::chrono::high_resolution_clock::now();
    mergesort(V,0,n-1);    
    auto end = std::chrono::high_resolution_clock::now();
    cout << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microsecs" << endl;
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecs" << endl;
    cout << "Elapsed time in seconds: "      << chrono::duration_cast<chrono::seconds>(end - start).count()      << " secs";
    return 0;
}
