#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

vector<int> dfs(vector<vector<int>> A,int v0)
{
    stack<int> S;
    vector<int> trav;
    vector<bool> visited(A.size(), 0);
    cout<<A.size();
    visited[v0] = 1;
    S.push(v0);
    trav.push_back(v0);
    while(!S.empty())
    {
        int node = S.top();
        for (int i = 0; i < A[node].size(); i++)
        {
            if (!visited[A[node][i]])
            {
                S.push(A[node][i]);
                visited[A[node][i]] = 1;
                trav.push_back(A[node][i]);
            }
            
        }
        
        S.pop();
    }
    return trav;
    // {
    //    int node = S.top();
    //    S.pop();
    //    visited[node] = 1;
    //    for(int i = 0; i < A[node].size(); i++)
    //        if(!visited[A[node][i]])
    //        {
    //            S.push(A[node][i]);
    //            trav.push_back(A[node][i]);
    //        }
    // }
    // return trav;
}

int main()
{
    int v,e;
    int i,start,end;
    //cout<<"Enter number of vertices ";
    //cin>>v;
    v = 5; e = 7;
    vector<vector<int>> A(v);
    //cout<<"Enter number of edges ";
    //cin>>e;
    //for(i = 0; i < e; i++)
    //{
    //    cin>>start>>end;
    //    A[start-1].push_back(end-1);
    //    A[end-1].push_back(start-1);
    //}
    A[1-1].push_back(2-1);
    A[1-1].push_back(5-1);
    A[2-1].push_back(1-1);
    A[2-1].push_back(5-1);
    A[2-1].push_back(3-1);
    A[2-1].push_back(4-1);
    A[3-1].push_back(2-1);
    A[3-1].push_back(4-1);
    A[4-1].push_back(2-1);
    A[4-1].push_back(5-1);
    A[4-1].push_back(3-1);
    A[5-1].push_back(4-1);
    A[5-1].push_back(1-1);
    A[5-1].push_back(2-1);
    
    //for(int i = 0; i < A.size(); i++)
    //{
    //    cout<<i+1<<"->";
    //    for (int j = 0; j < A[i].size(); j++)
    //    {
    //        cout<<A[i][j]+1<<" ";
    //    }
    //    cout<<endl;
    //}
    vector<int> trav = dfs(A, 0);
    cout<<"back";
    //cout<<"Breadth First Traversal : ";
    for (int i = 0; i < trav.size(); i++)
    {
        cout<<trav[i]+1<<" ";
    }
    
    
    return 0;
}