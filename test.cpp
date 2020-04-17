#include <bits/stdc++.h>
using namespace std;

/*
Find the critical vertices and bridges in a graph.
Time is the order visiting vertices in graph
Num[x] is the time visit the vertex x
Low[x] is the lowest time of the vertex that x could get back to, following dfs, without going back.
*/

const int N = 10000;
vector<int> edge[N + 5];
int Low[N + 5], Num[N + 5], Time = 0, CritEdge = 0;
bool CritVertex[N + 5];
 
void dfs(int root, int parent){
	Low[root] = Num[root] = ++Time;
	int branches = 0;
	for(int child : edge[root]){
		if(child == parent) continue;
		if(Num[child]){
			Low[root] = min(Low[root], Num[child]);
			continue;
		}
		branches++; // just to justify if the first node visit is critical 
		dfs(child, root);
		Low[root] = min(Low[root], Low[child]);

		if(Low[child] == Num[child]) CritEdge++;

		if(parent == 0){ // if current root is the first 
			if(branches >= 2) CritVertex[root] = true;
		}
		else{
			if(Low[child] >= Num[root]) CritVertex[root] = true;
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	while(m--){
		int x, y; cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		if(!Num[i]) dfs(i, 0);
	}
	int res = 0;
	for(int i = 1; i <= n; i++) if(CritVertex[i]) res++;
	cout << res << " " << CritEdge;
	return 0;
}