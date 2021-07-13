#include<bits/stdc++.h>
using namespace std;

class BIT {
private:
    vector<int> bit;
    int maxValue;

public:
    BIT(int maxValue){
        this->maxValue = maxValue;
        bit.assign(maxValue + 1, 0);
    }

    void update(int idx, int val){
        if(idx == 0) return;
        while(idx <= maxValue){
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int get(int val){
        int res = 0;
        while(val){
            res += bit[val];
            val -= val & (-val);
        }
    }
};

int main(){
    
    return 0;
}