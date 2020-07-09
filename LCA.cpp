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
 *  LCA - Lowest Common Ancestor
 *  @author Katorin
 *  Last editted: 9 July, 2020
 *
 *	Time complexity: O(N * log(N) + query * log(n))
 * 	Space complexity: O(N * log(N))
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5;
const int mod = 1e9 + 7; /* mod must be prime */

int n; /* number of vertices */
vector<int> edge[N]; /* graph */

/* 	pa[i][j] is the 2^j ancestor of node i 
	pa[i][0] is the direct ancestor of node i 
	if pa[i][j] does not exist, it will be equal to 0(or -1 in some cases) */
int pa[N][18]; 
int level[N];

void dfs(int root, int parent){
	for(int nextVertex : edge[root]){
		if(nextVertex == parent) continue; /* avoiding going back in dfs */
		level[nextVertex] = level[root] + 1;
		pa[nextVertex][0] = root;
		dfs(nextVertex, root);
	}
}

void init(){ /* assume that all pa[i][0] have been already available */
	/* considering 1 is the tree root */
	pa[1][0] = 0;
	level[1] = 0;
	dfs(1, 0);

	for(int j = 1; j < 18; j++){
		for(int i = 1; i <= n; i++){
			pa[i][j] = pa[pa[i][j - 1]][j - 1];
		}
	}
}

int move(int x, int targetLevel){
	int dist = level[x] - targetLevel;
	for(int bit = 17; bit >= 0; bit--){
		if(dist & (1 << bit)) x = pa[x][bit];
	}
	return x;
}

int findLCA(int x, int y){
	if(level[x] < level[y]) swap(x, y); /* x is always lower than y */
	x = move(x, level[y]); /* x move to the node with the same level with y */
	if(x == y) return x;
	for(int i = 17; i >= 0; i--){
		if(pa[x][i] != pa[y][i]){
			x = pa[x][i];
			y = pa[y][i];
		}
	}
	return pa[x][0];
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y; cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	init();
	cout << findLCA(6, 8);
    return 0; 
}
