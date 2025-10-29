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

        ListNode *curr=head, *tail=nullptr;
        int length=0;

        while(curr){
            length++;
            tail=curr;
            curr=curr->next;
        }
        
        curr=head;
        k=k%length;
        int idx=length-k-1; 
        while(idx){
            curr=curr->next;
            idx--;
        }

        tail->next=head;
        head=curr->next;
        curr->next=nullptr;

        return head;
    }
};