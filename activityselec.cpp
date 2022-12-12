#include<iostream>
#include<vector>
using namespace std;

int activity_selector(vector<int> start, vector<int> end)
{
    int free = end[0];
    int count = 1;
    for(int i = 1;i<start.size();i++)
    {
        if(start[i]>=free)
        {
            count+= 1;
            free = end[i];
        }
    }
    return count;
}

int main()
{
    int n;
    cout<<"Input the number of activities : ";cin>>n;
    vector<int> start(n),end(n);
    cout<<"Input the starting and ending times of each activity (sorted according to their ending times)"<<endl;
    for(int i=0;i<n;i++)
        cin>>start[i]>>end[i];
    cout<<"Maximum number of activities is : " <<activity_selector(start,end)<<endl;
    return 0;
}