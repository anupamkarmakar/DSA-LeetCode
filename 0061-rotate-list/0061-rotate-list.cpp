/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;

        ListNode *p=head, *q=nullptr;
        int nodeCount=0;
        while(p){
            nodeCount++;
            p=p->next;
        }
        k=k%nodeCount;

        p=head;
        while(k){
            while(p->next){
                q=p;
                p=p->next;
            }
            q->next=nullptr;
            p->next=head;
            head=p;
            k--;
        }
        return head;
    }
};