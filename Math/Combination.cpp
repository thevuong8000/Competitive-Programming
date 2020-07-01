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

void init(){
    /* factorial init */
    fact[0] = 1;
    for(int i = 1; i <= N; i++) fact[i] = (1ll * fact[i - 1] * i) % mod;
}

int getFactorial(int n){
	if(n < 0) return -1;
	if(n <= N) return fact[n];
	int res = fact[N];
	for(int i = N + 1; i <= n; i++) res = (1ll * res * i) % mod;
	return res;
}

int pw(int n, int k){ /* calculate n^k with n and k is integers */
	if(k < 0) return 0;
	if(k == 0) return 1;
	int res = pw(n, k >> 1);
	res = (1ll * res * res) % mod;
	if(k & 1) res = (1ll * res * n) % mod;
	return res;
}

int C(int n, int k){
	if(k > n || k < 0 || n < 0) return -1;
	int res = getFactorial(n);
	res = (1ll * res * pw(getFactorial(n - k), mod - 2)) % mod;
	res = (1ll * res * pw(getFactorial(k), mod - 2)) % mod;
	return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init();
    cout << C(31, 17) << endl; /* 31C17 = 265182525 */
    
    return 0;
}
