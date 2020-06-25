/**
 *  Kosaraju's Algorithm - Strongly Connected Components 
 *  @author Katorin
 *  Last editted: 25 June, 2020
 *
 *	Time complexity: O(E + V)
 * 	Space complexity: O(E + V)
 *
 *	Reference: https://www.geeksforgeeks.org/strongly-connected-components/
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5 + 5;

vector<vector<int>> edge;
vector<vector<int>> revEdge; // reversed graph
stack<int> finishDFS;
int nVertex; // number of vertices
bool visited[N];

void init(int n){
	edge.assign(n + 1, vector<int>());
	revEdge.assign(n + 1, vector<int>());
}

void addEdge(vector<vector<int>>& edge, int x, int y){ /* direction: x -> y */
	edge[x].push_back(y);
}

void buildReversedGraph(){
	for(int i = 1; i <= nVertex; i++){
		for(int child : edge[i]){
			addEdge(revEdge, child, i);
		}
	}
}

void dfs(int root){ /* dfs in the original graph */
	visited[root] = true;
	for(int child : edge[root]){
		if(visited[child]) continue;
		dfs(child);
	}
	finishDFS.push(root);
}

void dfsRev(int root, vector<int>& component){ /* dfs in the reversed graph */
	visited[root] = true;
	component.push_back(root);
	for(int child : revEdge[root]){
		if(visited[child]) continue;
		dfsRev(child, component);
	}
}

vector<vector<int>> getSCC(){
	for(int i = 1; i <= nVertex; i++){
    	if(!visited[i]) dfs(i);
    }

    buildReversedGraph();
    memset(visited, false, sizeof(visited));

    vector<vector<int>> res;

    while(!finishDFS.empty()){
    	res.push_back(vector<int>());
    	dfsRev(finishDFS.top(), res[res.size() - 1]);
    	while(!finishDFS.empty() && visited[finishDFS.top()]) finishDFS.pop();
    }

    return res;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    nVertex = 11;
    init(11);

    /*	Creating a graph:
		123 ---> 4567 <--- 89(10) ---> 11
    */
    addEdge(edge, 1, 2); addEdge(edge, 2, 3); addEdge(edge, 3, 1);
    addEdge(edge, 1, 4);
    addEdge(edge, 4, 5); addEdge(edge, 5, 6); addEdge(edge, 6, 7); addEdge(edge, 7, 4);
    addEdge(edge, 8, 5);
    addEdge(edge, 8, 9); addEdge(edge, 9, 10); addEdge(edge, 10, 8);
    addEdge(edge, 8, 11);

    vector<vector<int>> components = getSCC();

    for(int i = 0; i < components.size(); i++){
    	cout << "Strongly Connected Component " << i + 1 << ": ";
    	for(int elem : components[i]){
    		cout << elem << " ";
    	}
    	cout << endl;
    }
    return 0;
}
