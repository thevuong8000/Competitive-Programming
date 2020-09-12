/*input
5 4
1 2
5 2
2 5
4 5
*/

/**
 *  Topological Sort
 *  @author Katorin
 *  Last editted: 12 September, 2020
 *
 *  Time complexity: O(N)
 *  Space complexity: O(N)
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5;
const int mod = 1e9 + 7; /* mod must be prime */

int n, m; /* number of vertices */

bool dfs(int root, vector<int>& visited, vector<vector<int>>& edge, vector<int>& res){
    visited[root] = 1;
    for(int child : edge[root]){
        if(visited[child]){
            if(visited[child] == 1) return false; // revisit on track
            continue;
        }
        if(!dfs(child, visited, edge, res)) return false;
    }
    visited[root] = 2;
    res.push_back(root);
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> edge(n + 1, vector<int>()); /* graph */
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        edge[x].push_back(y);
    }
    vector<int> visited(n + 1, 0);
    vector<int> res; // visiting sequence
    bool possible = true;
    for(int i = 1; i <= n; i++){
        if(visited[i]) continue;
        if(!dfs(i, visited, edge, res)){
            possible = false;
            break;
        }
    }
    if(possible){
        reverse(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++) cout << res[i] << " "; 
    } 
    else cout << "Can not schedule!";
    return 0; 
}