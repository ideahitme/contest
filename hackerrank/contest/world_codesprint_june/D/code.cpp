// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};
 
// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
 
// The main function to construct MST using Kruskal's algorithm
vector<vector<pii>> KruskalMST(struct Graph* graph, int total_size, vector<Edge> &edges)
{
    int V = graph->V;
    struct Edge result[V];  // Tnis will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges
 
    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    // Allocate memory for creating V ssubsets
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );
 
    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        struct Edge next_edge = graph->edge[i++];
 
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
 
        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
 	vector<vector<pii>> res(total_size);
    // print the contents of result[] to display the built MST
    for (i = 0; i < e; ++i){
    	edges.push_back(result[i]);
    	res[result[i].src].push_back({result[i].dest, result[i].weight});
    	res[result[i].dest].push_back({result[i].src, result[i].weight});
    }
    return res;
}
 
typedef long long ll;

int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; // If len1 >= len2
}
 
// The main function that adds two bit sequences and returns the addition
string addBitStrings( string first, string second )
{
    string result;  // To store the sum bits
 
    // make the lengths same before adding
    int length = makeEqualLength(first, second);
 
    int carry = 0;  // Initialize carry
 
    // Add all bits one by one
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';
 
        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';
 
        result = (char)sum + result;
 
        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }
 
    // if overflow, then add a leading 1
    if (carry)
        result = '1' + result;
 
    return result;
}

typedef pair<int, string> pis;

string bfs(int start, vector<vector<pii>> &edges, int str_len){
    vector<int> visited(edges.size(), 0);
    string def(str_len, '0');
    string res = "";
    queue<pis> to_visit;
    to_visit.push({start, def});
    while(!to_visit.empty()){
        int cur = to_visit.front().first;
        string cur_dist = to_visit.front().second;
        res = addBitStrings(res, cur_dist);
        to_visit.pop();
        visited[cur] = 1;
        for(auto it = edges[cur].begin(); it != edges[cur].end(); it++){
            int ver = it->first;
            int weight = it->second;
            if (visited[ver] == 0){
                string new_dist = cur_dist;
                new_dist[str_len-weight-1] = '1';
                to_visit.push({ver, new_dist});
            }
        }
    }
    return res;
}

void dfs(const vector<vector<pii>> &graph, vector<int> &visited, int &result, int start, int weight, int &total){
    visited[start] = 1;
    for(auto it = graph[start].begin(); it != graph[start].end(); it++){
        int neigh = it->first;
        int sub_weight = it->second;
        if (visited[neigh] == 0){
            dfs(graph, visited, result, neigh, sub_weight, total);
            cout << "from " << start << " to " << neigh << endl;
            cout << "sub_total " << total << " weight: " << pow(2, sub_weight) << endl;
        }
    }
    total += graph[start].size();
    result += total * pow(2, weight);
}

// Driver program to test above functions
int main()
{
 	ios::sync_with_stdio(false);
	int V, E;
	cin >> V >> E;
    struct Graph* graph = createGraph(V, E);

	for(int j = 0; j < E; j++){
		int x,y,r;
		cin >> x >> y >> r;
		graph->edge[j].src = x-1;
		graph->edge[j].dest = y-1;
		graph->edge[j].weight = r;
	}
 
    vector<Edge> edges;
    vector<vector<pii>> res = KruskalMST(graph, V, edges);
    vector<int> visited(res.size(), 0);
    int result = 0;
    int total = 0;
    dfs(res, visited, result, 0, 0, total);
    // string result = "";
    // for(int i = 0; i < V; i++){
    // 	result = addBitStrings(result, bfs(i, res, E));
    // }
    cout << result << endl;
    return 0;
}
