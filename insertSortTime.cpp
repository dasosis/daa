#include <iostream>
#include <chrono>
#include<vector>
#include<valarray>
#include<time.h>
using namespace std;

void insertionSort(vector<int> &a)
{
    for(int j=2;j<a.size();j++)
    {
        int key = a[j],i=j-1;
        while(i>0 and a[i]>key)
        {
            a[i+1]=a[i];
            i-=1;
        }
        a[i+1]= key;
    }
}

int main () 
{
    vector<int> v;int n=1000;
    //cout<<"Input the number of elements to be filled into the vector : ";cin>>n;
    srand(time(0));
    for(int i=0;i<n;i++) v.push_back(rand()%10000+1);
    auto start = std::chrono::high_resolution_clock::now();
    
    insertionSort(v);
    
    // End measuring time
    auto end = std::chrono::high_resolution_clock::now();
    
    cout << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microsecs" << endl;
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecs" << endl;
    cout << "Elapsed time in seconds: "      << chrono::duration_cast<chrono::seconds>(end - start).count()      << " secs";
    return 0;

    
}