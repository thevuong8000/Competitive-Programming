/**
 *  DSU - Disjoint Sets Union
 *  Written by Katorin
 *  Last editted: 23 June, 2020
 *  Reference: https://en.wikipedia.org/wiki/Disjoint-set_data_structure
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class DSU{
  private:
    // the number of distinct sets
    int numSets = 0;
  public:
    // The number of elements
    int nElems;

    /* pa[i] = x if x and i are in the same union
      or if pa[i] < 0 then group containing i has -pa[i] elements. */
    vector<int> pa;
    
    DSU(int nElems){
      this->nElems = nElems;
      this->numSets = nElems;

      // Initially, each element is a distince set
      pa.assign(nElems + 1, -1);
    }

    /* find the root of the set containing {elem} */
    int findPa(int elem){
      return pa[elem] < 0 ? elem : (pa[elem] = findPa(pa[elem]));
    }

    /* get size of the set containing {elem} */
    int getSize(int elem){
      return -pa[findPa(elem)];
    }

    /* check if 2 elements in the same union-set */
    bool isSameUnion(int x, int y){
      return findPa(x) == findPa(y);
    }

    /* merge 2 union-set */
    void merge(int x, int y){ 
      if(isSameUnion(x, y)) return; 

      int rootX = findPa(x);
      int rootY = findPa(y);
      
      this->numSets -= 1;

      /* This step will reduce the complexity to O(log(N)). This's called Union-by-rank. */
      if(getSize(rootX) < getSize(rootY)) swap(rootX, rootY);

      pa[rootX] += pa[rootY]; 
      pa[rootY] = rootX;
    }

    /* get the number of sets */
    int getNumSets(){
      return this->numSets; 
    }

    /* DEBUG only */
    void printSets(){
      vector<vector<int>> sets;
      map<int, int> rootToIndex;
      for(int i = 1; i <= this->nElems; i++){
        int parent = findPa(i);
        if(!rootToIndex.count(parent)){
          rootToIndex[parent] = rootToIndex.size();
          sets.push_back(vector<int>());
        }
        int index = rootToIndex[parent];
        sets[index].push_back(i);
      }
      for(int i = 0; i < sets.size(); i++){
        cout << "Union-Set " << i + 1 << ":";
        for(int j : sets[i]) cout << " " << j;
        cout << endl;
      }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nElems = 10;
    DSU dsu(nElems);

    /* group 1: {1, 4, 6, 7, 8} */
    dsu.merge(1, 4);
    dsu.merge(1, 6);
    dsu.merge(4, 8);
    dsu.merge(6, 7);

    /* group 2: {2, 3, 9} */
    dsu.merge(2, 9);
    dsu.merge(3, 9);

    /* group 3: {5, 10} */ 

    cout << dsu.isSameUnion(4, 7) << endl; // print 1
    cout << dsu.isSameUnion(1, 2) << endl; // print 0
    cout << dsu.getSize(6) << endl; // print 5
    cout << dsu.getNumSets() << endl; // print 3

    dsu.printSets();
    return 0;
}
