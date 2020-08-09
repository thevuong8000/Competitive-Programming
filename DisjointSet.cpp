/**
 *  DSU - Disjoint Sets Union
 *  Written by Katorin
 *  Last editted: 23 June, 2020
 *  Reference: https://en.wikipedia.org/wiki/Disjoint-set_data_structure
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5 + 5;
int pa[N]; /* pa[i] = x if x and i are in the same union
            or if pa[i] < 0 then group containing i has -pa[i] members (or elements) 
            i.e. int this case, we might consider i as a root of a group */
int nElem; // number of elements

void init(){
    /* At the beginning, there're nElem groups and each group has only 1 elements */
    memset(pa, -1, sizeof(pa));
}

int findPa(int elem){ /* find the root of group containing elem */
    if(pa[elem] < 0) return elem;
    else return pa[elem] = findPa(pa[elem]);
}

int findNumElem(int elem){
    return -pa[findPa(elem)];
}

bool isSameUnion(int x, int y){
    return findPa(x) == findPa(y);
}

void unionMerge(int x, int y){ /* merge 2 group */
    if(isSameUnion(x, y)) return; 

    int rootX = findPa(x);
    int rootY = findPa(y);

    /* This step will reduce the complexity to O(log(N)). This's called Union-by-rank. */
    if(pa[rootX] > pa[rootY]) swap(rootX, rootY);

    pa[rootX] += pa[rootY]; 
    pa[rootY] = rootX;
}
int numGroup(int n){
    int num_group = 0;
    for(int i = 0; i < n; i++){
    	if(pa[i] < 0) num_group++;
    }
    return num_group;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // test
    nElem = 10;
    init();

    /* group 1 */
    unionMerge(1, 4); unionMerge(1, 6); unionMerge(4, 8); unionMerge(6, 7);

    /* group 2 */
    unionMerge(2, 9); unionMerge(3, 9);

    /* group 3: only 5 left */
    
    // There're 3 groups:
    // 1) [1, 4, 6, 7, 8]
    // 2) [2, 3, 9]
    // 3) [5]

    cout << isSameUnion(4, 7) << endl; // print 1
    cout << isSameUnion(1, 2) << endl; // print 0
    cout << findNumElem(6) << endl; // print 5
    return 0;
}
