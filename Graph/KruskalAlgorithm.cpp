#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int u, v, wt;
    Node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};
// Defining our custom comparator
bool comp(Node a, Node b)
{
    return (a.wt < b.wt);
}

// Function for finding the parent (In C++ vectors are sent to function as pass by reference) 
int findParent(int u, vector<int> &parent)
{
    if(u == parent[u])
    {
        return u;
    }
    return parent[u] = findParent(parent[u], parent);
}

// Function for union of disjoint sets
void union_set(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u] < rank[v]) 
    {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) 
    {
    	parent[v] = u; 
    }
    else 
    {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int main()
{
    // Defining a vector to add the edges
    vector<Node> edges;

    // Adding the edges
    edges.push_back(Node(0, 1, 2));
    edges.push_back(Node(0, 3, 6));
    edges.push_back(Node(1, 3, 8));
    edges.push_back(Node(1, 4, 5));
    edges.push_back(Node(1, 2, 3));
    edges.push_back(Node(2, 4, 7));

    // Sorting the edges in non-decreasing order
    sort(edges.begin(), edges.end(), comp);

    // Defining a Parent array
    vector<int> parent(5);
    for(int i=0; i<5; i++)
    {
        parent[i] = i;
    }

    // Defining the Rank array
    vector<int> rank(6, 0);

    int cost = 0;
	vector<pair<int,int>> mst; 
	for(auto it : edges) 
    {
	    if(findParent(it.v, parent) != findParent(it.u, parent)) 
        {
	        cost += it.wt; 
	        mst.push_back({it.u, it.v}); 
	        union_set(it.u, it.v, parent, rank); 
	    }
	}
    cout << "The MST is :: " << endl;
    for(auto it: mst)
    {
        cout << it.first << "-" << it.second << endl;
    }
}