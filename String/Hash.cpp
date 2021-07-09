/**
 *  Rabin Karp Algorithm  
 *  Written by Katorin
 *  Last edited: 9th July, 2021 
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef pair<int, int> ii;

class StringHash {
private:
    int N = 1e5;
    int mod = 1e9 + 7;
    int base = 31;
    vector<int> fact;
    vector<int> hsh;
    string str;

    void init(){
        fact.push_back(1);
        for(int i = 1; i <= N; i++) fact.push_back((1ll * fact.back() * base) % mod);
    
        hsh.push_back(str[0] - 'a' + 1);
        for(int i = 1; i < N; i++){
            int value = (1ll * hsh[i - 1] * base) % mod  +  (str[i] - 'a' + 1);
            value %= mod;
            hsh.push_back(value);
        }
    }

public:
    StringHash(string& str, int base = 31, int mod = 1e9 + 7){
        this->str = str;
        this->base = base;
        this->mod = mod;
        this->N = str.length();

        init();
    }

    /**
     * get hashing value of substring from index l to r 
     */
    int get(int l, int r){
        int res = hsh[r];

        /* return the value we've already initialized */
        if(l == 0) return res;

        /* Follow the formular:
            hash(l, r) = hash(0, r) - hash(0, l) * fact[r - l + 1] 
        */
        res = (1ll * res - 1ll * hsh[l - 1] * fact[r - l + 1] + 1ll * mod * mod) % mod;
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str = "banana";
    StringHash hasher(str);
    bool checkTrue = hasher.get(1, 3) == hasher.get(3, 5); // both substring is "ana"
    cout << checkTrue << endl; // print true (or 1)

    bool checkFalse = hasher.get(0, 2) == hasher.get(2, 4); // compare "ban" and "ana"
    cout << checkFalse << endl; // print false (or 0)
    return 0;
}
