/**
 *  Combination nCk calculation 
 *  @author Katorin
 *  Last editted: 1 July, 2020
 *
 *	Time complexity: O(N + log(n))
 * 	Space complexity: O(N)
 *
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5;
const int mod = 1e9 + 7; /* mod must be prime */

int fact[N + 5]; /* factorial */

class Calculator{
private:
    // best support for calculate with number less than N
    int N = 0;
    int mod = 1e9 + 7;
    vector<int> fact;

public:
    Calculator(){
        fact.push_back(1);
    }

    Calculator(int mod): Calculator(){
        //Calculator();
        this->mod = mod;
    }

    int getFactorial(int n){
    	if(n < 0) return -1;
	    if(n <= N) return fact[n];
    	int res = fact[N];
    	for(int i = N + 1; i <= n; i++){
            fact.push_back((1ll * i * fact.back()) % mod);
        }
        this->N = n;
    	return fact[n];
    }
    
    // get power n^exp
    int pw(int n, int exp){
        /* not support decimal or negative {exp} */
        if(exp < 0) return -1;
        if(exp == 0) return 1;
        int res = pw(n, exp >> 1);
        res = (1ll * res * res) % mod;
        if(exp & 1) res = (1ll * res * n) % mod;
        return res;
    }
    
    // get combination nCk
    int C(int n, int k){
        if(k > n || k < 0 || n < 0) return -1;
    	int res = getFactorial(n);
    	res = (1ll * res * pw(getFactorial(n - k), mod - 2)) % mod;
    	res = (1ll * res * pw(getFactorial(k), mod - 2)) % mod;
    	return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    //Calculator cal;
    Calculator cal(1e9 + 9);
    cout << cal.getFactorial(5) << endl;
    cout << cal.C(31, 17) << endl; /* 31C17 = 265182525 */
    
    return 0;
}
