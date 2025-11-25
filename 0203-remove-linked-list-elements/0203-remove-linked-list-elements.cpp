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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0,head);
        ListNode *curr = head;
        ListNode *prev = dummy;

        while(curr){
            while(curr && curr->val==val){
                curr=curr->next;
            }

            if(prev->next!=curr){
                prev->next=curr;
            }
            
            prev=curr;
            if(curr) curr=curr->next;
        }
        return dummy->next;
    }
};