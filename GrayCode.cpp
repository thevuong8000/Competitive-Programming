/**
 *  Gray Code
 *  Gray Code is an array whose adjacent elements differ in only 1 bit
 *  For example: arr = [0, 1, 3, 2] is Gray Code
 *      which is transfer to binary is [00, 01, 11, 10]
 *  Reference: https://en.wikipedia.org/wiki/Gray_code
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/* generating gray array with n-bit elements */
vector<int> grayCode(int n){
    vector<int> res;
    for(int i = 0; i < (1 << n); i++)
        res.push_back(i ^ (i >> 1));
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    /* test with 3 bit */
    const int nElem = 3;
    vector<int> grayArr = grayCode(nElem);
    for(int elem : grayArr){
        cout << elem << " in binary: " << bitset<nElem>(elem).to_string() << endl;
    }
    return 0;
}
