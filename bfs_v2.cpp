#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> bfs(vector<vector<int>> A, int v0)
{
    vector<int> trav;
    queue<int> Q;
    vector<bool> visited(A.size(),0);
    visited[v0] = 1;
    Q.push(v0);
    trav.push_back(v0);
    while (!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        for (int i = 0; i < A[node].size(); i++)
        {
            if (!visited[A[node][i]])
            {
                visited[A[node][i]] = 1;
                Q.push(A[node][i]);
                trav.push_back(A[node][i]);
            }
        }
    }
    return trav;    
}
int main(int argc, char const *argv[])
{
    int n_vert,n_edge,start,end;
    vector<int> trav_order;
    cout<<"enter number of vertices ";
    cin>>n_vert;
    vector<vector<int>> adj_list(n_vert);
    cout<<"enter number of edges ";
    cin>>n_edge;
    cout<<"enter start and end vertices of the edges"<<endl;
    for (int i = 0; i < n_edge; i++)
    {
        cin>>start>>end;
        adj_list[start-1].push_back(end-1);
        adj_list[end-1].push_back(start-1);
    }
    int starting_vert = 0;
    trav_order = bfs(adj_list,starting_vert);
    cout<<"bfs traversal order : ";
    for(int i = 0; i < trav_order.size(); i++)
    {
        cout<<trav_order[i]+1;
        if(i < trav_order.size()-1) 
        cout<<"->";
    }
    return 0;
}
