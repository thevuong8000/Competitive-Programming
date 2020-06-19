/*input
3
1 3 5
*/

/**
 *  Rabin Karp Algorithm  
 *  Written by Katorin
 *  Last edited: 19 June, 2020
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef pair<int, int> ii;

const int mod = 1e9 + 7; /* mod is a prime */
const int N = 1e5 + 5;
const int base = 19; /* base is a prime */

int fact[N]; /* factorial */
int hsh[N]; /* hash from idx 0, i.e. hsh[i] is the hash for substring from index 0 to i */
string str; /* assume that str contains only lowercase characters */

void init(){
    /* factorial init */
    fact[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = (1ll * fact[i - 1] * base) % mod;

    /* hashing following rules:
        a -> 1
        b -> 2
        c -> 3
        ...
        z -> 26
    */
    hsh[0] = str[0] - 'a' + 1;
    for(int i = 1; i < str.length(); i++){
        hsh[i] = (1ll * hsh[i - 1] * base) % mod  +  (str[i] - 'a' + 1);
    }
}

int get_hash(int l, int r){ /* get hashing value of substring from index l to r */
    int res = hsh[r];
    if(l == 0) return res; /* return the value we've already initialized */

    /* Follow the formular:
        hash(l, r) = hash(0, r) - hash(0, l) * fact[r - l + 1] 
    */
    res = (res - 1ll * hsh[l - 1] * fact[r - l + 1] + 1ll * mod * mod) % mod;
    
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    str = "banana";
    init();
    bool checkTrue = get_hash(1, 3) == get_hash(3, 5); // both substring is "ana"
    cout << checkTrue << endl; // print true (or 1)

    bool checkFalse = get_hash(0, 2) == get_hash(2, 4); // compare "ban" and "ana"
    cout << checkFalse << endl; // print false (or 0)
    return 0;
}