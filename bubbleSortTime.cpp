#include <iostream>
#include <chrono>
#include<vector>
#include<valarray>
#include<time.h>
using namespace std;

void bubbleSort(vector<long> &a)
{
    for(int i=0;i<a.size();i++)
        for(int j=0;j<a.size()-1-i;j++) 
            if(a[j+1]<a[j]) swap(a[j+1],a[j]);
}

int main () 
{
    vector<long> v;long n=100000;
    //cout<<"Input the number of elements to be filled into the vector : ";cin>>n;
    srand(time(0));
    for(long i=0;i<n;i++) v.push_back(rand()%10000+1);
    
    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();
    
    bubbleSort(v);
    
    // End measuring time
    auto end = std::chrono::high_resolution_clock::now();
    
    cout << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microsecs" << endl;
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecs" << endl;
    cout << "Elapsed time in seconds: "      << chrono::duration_cast<chrono::seconds>(end - start).count()      << " secs";
    
    //system("insertSortTime.exe");
    return 0;
}