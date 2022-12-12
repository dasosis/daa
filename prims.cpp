#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int Prims_Algorithm(vector<vector<int>> adjacency_matrix,vector<pair<int,int>> &edges,int number_of_vertices,int starting_node)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;//wt,{node,parent}
    int mst_weight = 0;int node,weight;
    vector<int> visited(number_of_vertices+1,0);
    pq.push({0,{starting_node,-1}});
    while(!pq.empty())
    {
        pair<int,pair<int,int>> it = pq.top();
        pq.pop();
        node = it.second.first;
        if(visited[node]) continue; 
        visited[node]=1;       
        if(it.second.second!=-1)
        {
            mst_weight+=it.first;
            edges.push_back(it.second);
        }
        for(int i=1;i<=number_of_vertices;i++)
            if(adjacency_matrix[node][i])
                if(!visited[i])
                    pq.push({adjacency_matrix[node][i],{i,node}});
    }
    return mst_weight;
}

int main()
{
    int number_of_vertices;
	int v1,v2,w;
	int starting_node;
    cout<<"Input the number of vertices : ";
	cin>>number_of_vertices;
    vector<vector<int>> adjacency_matrix(number_of_vertices+1,vector<int>(number_of_vertices+1));    
    cout<<"Input the Adjacency Matrix of the graph : "<<endl;
    for(int row=1;row<=number_of_vertices;row++)
        for(int col=1;col<=number_of_vertices;col++)
            cin>>adjacency_matrix[row][col];
    cout<<"Edges of the graph are : "<<endl;
    for(int row=1;row<=number_of_vertices;row++)
        for(int col=row;col<=number_of_vertices;col++)
            if(adjacency_matrix[row][col])
                cout<<"( "<<row<<" , "<<col<<" ) : "<<adjacency_matrix[row][col]<<endl;
    cout<<"Input the starting node : ";cin>>starting_node;
    vector<pair<int,int>> edges;
    int mst_weight = Prims_Algorithm(adjacency_matrix,edges,number_of_vertices,starting_node);
    cout<<"The edges involved in Minimal Spanning Tree are : "<<endl;
    for(int i=0;i<edges.size();i++)
        cout<<"( "<<edges[i].second<<" , "<<edges[i].first<<" ) : "<<adjacency_matrix[edges[i].second][edges[i].first]<<endl;
    cout<<"Weight of the Minimal Spanning Tree is : "<<mst_weight<<endl;
    return 0;
}

/*
0 2 0 1 4 0
2 0 3 6 0 7
0 3 0 5 0 8
1 6 5 0 9 0
4 0 0 9 0 0
0 7 8 0 0 0
*/

/*
Prims_Algorithm(adj[][],edges,n,starting_node)
1. create min_heap to store the tuple {wt,node,parent}
2. create visited[n] // initialize to 0
3. mst_weight=0
4. push staring_node to min_heap
5. while(min_heap is not empty)
6.      pop and store topmost element from min_heap in it
7.      if node has been visited move to next iteration
8.      visited[node]=1
9.      if node is not the starting node
10.         add edge to edges // edges stores the edges in the mst
11.         mst_weight += weight(node)
12.         for u adj[node]
13.             if u has not been visited push to min_heap
14. return mst_weight
*/