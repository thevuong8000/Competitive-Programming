#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    int n;
    vector<int> sum;
    vector<int> lazy;

    void init(int idx, int l, int r, vector<int>& a){
        if(l == r){
            sum[idx] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        init((idx << 1) + 1, l, mid, a); init((idx << 1) + 2, mid + 1, r, a);
        sum[idx] = sum[(idx << 1) + 1] + sum[(idx << 1) + 2];
    }

    void doLazy(int idx, int l, int r){
        if(!lazy[idx]) return;
        sum[idx] += lazy[idx] * (r - l + 1);
        if(l != r){
            lazy[(idx << 1) + 1] += lazy[idx];
            lazy[(idx << 1) + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    void update(int idx, int l, int r, int left, int right, int val){
        doLazy(idx, l, r);
        if(l > right || r < left) return;
        int mid = (l + r) >> 1;
        if(left <= l && r <= right){
            sum[idx] += (r - l + 1) * val;
            int leftIdx = (idx << 1) + 1, rightIdx = (idx << 1) + 2;
            if(leftIdx < lazy.size()) lazy[(idx << 1) + 1] += val;
            if(rightIdx < lazy.size()) lazy[(idx << 1) + 2] += val;
            return;
        }
        update((idx << 1) + 1, l, mid, left, right, val);
        update((idx << 1) + 2, mid + 1, r, left, right, val);
        sum[idx] = sum[(idx << 1) + 1] + sum[(idx << 1) + 2];
    }
    
    int getSum(int idx, int l, int r, int left, int right){
        doLazy(idx, l, r);
        if(r < left || l > right) return 0;
        if(left <= l && r <= right) return sum[idx];
        int mid = (l + r) >> 1;
        return getSum((idx << 1) + 1, l, mid, left, right) + getSum((idx << 1) + 2, mid + 1, r, left, right);
    }
public:
    FenwickTree(vector<int>& a){
        this->n = a.size();
        sum.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
        init(0, 0, n - 1, a);
    }
    
    void update(int index, int val){
        update(0, 0, n - 1, index, index, val);
    }

    void update(int left, int right, int val){
        update(0, 0, n - 1, left, right, val);
    }

    int getSum(int left, int right){
        return getSum(0, 0, n - 1, left, right);
    }
};

int main(){
    vector<int> a(1e5, 0);
    FenwickTree* tree = new FenwickTree(a);
    tree->update(0, 1);
    // tree->update(1, 5, 2);
    cout << tree->getSum(1, 4) << endl;
    return 0;
}