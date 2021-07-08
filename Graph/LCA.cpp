/*input
11
1 2
1 3
2 4
2 5
5 6
5 7
7 8
7 9
3 10
10 11
*/

/**
 *  LCA - Lowest Common Ancestor using Sparse Table
 *  @author Katorin 
 *
 *	Time complexity: O(N * log(N) + query * log(n))
 * 	Space complexity: O(N * log(N))
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5;
const int mod = 1e9 + 7; /* mod must be prime */

class LCA {
private:
    // Sparse Table represents parents
    // pa[node][k]: parent 2^k of node
    vector<vector<int>> pa;

    // level or depth
    vector<int> level;

    // log_size, for sparse table purpose
    int log_size, maxElem;

    void dfs(int root, int parent, vector<vector<int>>& edges){
	    for(int nextVertex : edges[root]){
	    	if(nextVertex == parent) continue;
	    	level[nextVertex] = level[root] + 1;
    		pa[nextVertex][0] = root;
    		dfs(nextVertex, root, edges);
    	}
    }

    int move(int node, int targetLevel){
        int targetNode = node;
        int dist = level[node] - targetLevel;
	    for(int bit = 17; bit >= 0; bit--){
	    	if(dist & (1 << bit)) targetNode = pa[targetNode][bit];
    	}
    	return targetNode;
    }

public:
    LCA(vector<vector<int>>& edges, int root = 1, int startFrom = 1){
        this->maxElem = edges.size() - 1;
        this->log_size = (int)log2(edges.size()) + 1;
        pa.assign(this->maxElem + 2, vector<int>(this->log_size, root));
        level.assign(this->maxElem + 2, 0);

        dfs(root, -1, edges);

        
        for(int j = 1; j < this->log_size; j++){
		    for(int i = startFrom; i <= this->maxElem; i++){
		    	pa[i][j] = pa[pa[i][j - 1]][j - 1];
		    }
    	}
    }

    int get(int x, int y){
        // always level[x] >= level[y]
        if(level[x] < level[y]) swap(x, y);
        x = move(x, level[y]);

        // case y is ancestor of x
        if(x == y) return x;

	    for(int i = log_size - 1; i >= 0; i--){
	    	if(pa[x][i] != pa[y][i]){
	    		x = pa[x][i];
	    		y = pa[y][i];
	    	}
	    }
	    return pa[x][0];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n; cin >> n;
    vector<vector<int>> edges(n + 1, vector<int>());
	for(int i = 1; i < n; i++){
		int x, y; cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
    LCA lca(edges);
    cout << lca.get(2, 5);
    return 0; 
}
