/**
 *  Knuth – Morris – Pratt algorithm - string pattern seaching algorithm
 *  Written by Katorin
 *  Last editted: 23 June, 2020
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e5 + 5;

vector<int> getPrefix(string needle){

    /* pref[i] = x (x != i) when x is the maximum value 
        that substring from index i - x + 1 to i is a prefix of the needle */
    vector<int> pref(needle.length());
    int idx = 0;
    pref[0] = 0;
    for(int i = 1; i < needle.length(); i++){
        while(idx > 0 && needle[idx] != needle[i]) idx = pref[idx - 1];
        if(needle[idx] == needle[i]) pref[i] = ++idx;
        else pref[i] = 0;
    }
    return pref;
}

int strStr(string haystack, string needle) {
    if(needle == "") return 0;
    vector<int> pref = getPrefix(needle);
    int idx = 0;
    for(int i = 0; i < haystack.length(); i++){
        while(idx > 0 && 
              needle[idx] != haystack[i]) idx = pref[idx - 1];
        if(haystack[i] == needle[idx]){
            idx++;
            if(idx == needle.length()) return i - idx + 1;
        }
    }
    return -1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string str1 = "agadfadskatorinsadgdsaf";
    string str2 = "d";
    cout << strStr(str1, str2) << endl; // print 8
    return 0;
}
