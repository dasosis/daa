#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

stack<int> S;

void toposort(vector<vector<int>> A, vector<bool> &V, int node)
{
	V[node] = 1;
	for (auto it: A[node])
	{
		if (!V[it])
		{
			toposort(A,V,it);
		}
	}
	S.push(node);
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
    }
	
    vector<bool> visited(n_vert,0);
	for (int i = 0; i < n_vert; i++)
	{
		if(!visited[i])
			toposort(adj_list,visited,i);
	}
    cout<<"topologically sorted order : ";
    for (int i = 0; !S.empty(); i++)
	{
		cout<<S.top()+1<<" ";
		S.pop();
	}
	
    return 0;
}
