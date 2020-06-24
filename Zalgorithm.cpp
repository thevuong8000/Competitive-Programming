/**
 *  Z algorithm - string pattern seaching algorithm
 *  @author Katorin
 *  Last editted: 24 June, 2020
 *
 *	Time complexity: O(n + m)
 * 	Space complexity: O(n + m)
 *
 *	Reference: https://vnoi.info/wiki/translate/codeforces/z-algo
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5 + 5;

/* Z[i] is the length of substring start from index i that's also a prefix */

vector<int> getZ(string input){

    /* a a b a x a a b a c 
	   |_____|   |_____|
	   0 1 0 1 . 4 1 0 1 .
		 -----     -----
		 same pattern
	   We don't have to "re-compare" those same patterns
    */
	int L = 0, R = 0;
	vector<int> Z;
    Z.push_back(input.length()); /* Z[0] = Z.length() */

    for(int i = 1; i < input.length(); i++){
    	if(i > R){ // make a compare
    		L = R = i;
    		while(R < input.length() && input[R] == input[R - L]) R++;
    		Z.push_back(R - L);
    		R--;
    	} else{ // try to avoiding recompare
    		int k = i - L;
    		if(i + Z[k] - 1 < R){ // pattern has already been calculated
    			Z.push_back(Z[k]);
    		} else{
    			L = i;
    			while(R < input.length() && input[R] == input[R - L]) R++;
    			Z.push_back(R - L);
    			R--;
    		}
    	}	
    }
    return Z;
}

vector<int> listIndexOf(string str, string pattern){
	/* Application of Z-algorithm: find every indexes of {pattern} in {str}
		Concatenate 2 pattern with the $ character to distinguish 2 strings
		Find the Z array of the concatenated string to navigate the targeted indexes
	 */
	string s = pattern + "$" + str;
	vector<int> Z = getZ(s);
	vector<int> res;
	for(int i = pattern.length() + 1; i < Z.size(); i++){
		if(Z[i] == pattern.length()){
			res.push_back(i - pattern.length() - 1);
		}
	}
	return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str = "aabaaabbaab";
    string pattern = "aab";

    vector<int> idx = listIndexOf(str, pattern);

    cout << "Indexes of pattern: ";
    for(int i = 0; i < idx.size(); i++) cout << idx[i] << " ";
    return 0;
}
