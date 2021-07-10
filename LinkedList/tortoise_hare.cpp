#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

/**
 * return NULL if lst is NULL or there is no circle
 */
ListNode* getCircleStartPoint(ListNode* lst){
    if(!lst) return NULL;

    ListNode* tortoise = lst;
    ListNode* hare = lst;

    while(true){
        if(!hare->next) return NULL;
        tortoise = tortoise->next;
        hare = hare->next->next;

        if(tortoise == hare) break;
    }
    
    tortoise = lst;
    while(tortoise != hare){
        tortoise = tortoise->next;
        hare = hare->next;
    }

    return tortoise;
}

int main(){
    /*
     *             4 -> 5 
     *            /      \
     * 1 -> 2 -> 3        6
     *            \       /
     *             8 <-- 7
     */
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
    ListNode* node8 = new ListNode(8);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node3;

    cout << getCircleStartPoint(node1)->val << endl;
    return 0;
}
