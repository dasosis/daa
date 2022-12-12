#include<bits/stdc++.h>
#include<vector>
using namespace std;
int partition(vector<int> &V, int start, int end)
{
    int pivot = V[end]; // pivot
    int i=(start-1);
    for (int j = start; j <= end - 1; j++) 
    {
        if (V[j] < pivot) {
            i++;
            swap(V[i], V[j]);
        }
    }
    swap(V[i + 1], V[end]);
    return (i + 1);
}
void quicksort(vector<int> &V, int start, int end)
{
    if (start < end) {
        int mid = partition(V, start, end);
        quicksort(V, start, mid - 1);
        quicksort(V, mid + 1, end);
    }
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
    quicksort(V,0,n-1);    
    auto end = std::chrono::high_resolution_clock::now();
    cout << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microsecs" << endl;
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecs" << endl;
    cout << "Elapsed time in seconds: "      << chrono::duration_cast<chrono::seconds>(end - start).count()      << " secs";
    return 0;
}
