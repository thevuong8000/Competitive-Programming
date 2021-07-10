#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& arr){
    int maxlen = 0;
    int n = arr.size();
    vector<int> last(n, -1);
    for(int i = 0; i < n; i++){
        int idx = lower_bound(last.begin(), last.begin() + maxlen, arr[i]) - last.begin();
        if(idx == maxlen){
            last[maxlen++] = arr[i];
            continue;
        }
        last[idx] = arr[i];
    }
    return maxlen;
}

int main(){
    int a[] = {1, 5, 2, 3, 6, 5, 4, 3, 2, 1};
    vector<int> arr(a, a + 10);
    cout << LIS(arr) << endl;
    return 0;
}
