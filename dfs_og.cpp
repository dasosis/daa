#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> dfs(vector<vector<int>> adj_list,int v1)
{
    stack<int> S;
    vector<int> B;
    vector<bool> V(adj_list.size()+1, 0);
    V[v1]=1;
    S.push(v1);
    B.push_back(v1);
    while(!S.empty())
    {
        int node = S.top();
        S.pop();
        for(int i = 0; i < adj_list[node].size(); i++)
            if(!V[adj_list[node][i]])
            {
                V[adj_list[node][i]]=1;
                S.push(adj_list[node][i]);
                B.push_back(adj_list[node][i]);
            }
    }
    return B;
}

int main()
{
    int v,e;
    int i,start,end;
    cout<<"Enter number of vertices ";
    cin>>v;
    
    vector<vector<int>> adj_list(v+1);
    
    cout<<"Enter number of edges ";
    cin>>e;
    cout<<"enter start and end vertices of the edges"<<endl;
    for(i = 0; i < e; i++)
    {
        cin>>start>>end;
        adj_list[start].push_back(end);
        adj_list[end].push_back(start);
    }
    
    vector<int> B = dfs(adj_list, 1);

    cout<<"Depth First Traversal : ";
    for(int i = 0; i < B.size(); i++)
    {
        cout<<B[i];
        if(i < B.size()-1) 
        cout<<"->";
    }
    return 0;
}