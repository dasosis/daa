#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int node,edge,v1,v2;
    cout<<"Enter the number of nodes ";
    cin>>node;
    cout<<"Enter the number of edges ";
    cin>>edge;
    vector<vector<int>> adj_list(node);
    for (int i = 0; i < edge; i++)
    {
        cin>>v1>>v2;
        adj_list[v1-1].push_back(v2-1);
        adj_list[v2-1].push_back(v1-1);
    }
    for (int i = 0; i < node; i++)
    {
        cout<<i+1<<"->";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout<<adj_list[i][j]+1<<" ";
        }
        cout<<endl;        
    }     
}