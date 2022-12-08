#include <iostream>
#include <chrono>

using namespace std;

int main () {
    long sum = 0;
	long i = 0;
	
    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();
    
    long iterations = 75000000;
    for (i=0; i<iterations; i++) {
        sum = sum + i;
    }
    
    // End measuring time
    auto end = std::chrono::high_resolution_clock::now();
   
    cout << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microsecs" << endl;
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " millisecs" << endl;
    cout << "Elapsed time in seconds: "      << chrono::duration_cast<chrono::seconds>(end - start).count()      << " secs";
       
    return 0;
}