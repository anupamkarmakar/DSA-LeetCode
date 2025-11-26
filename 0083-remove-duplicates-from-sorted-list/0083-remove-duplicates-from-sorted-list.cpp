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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy=new ListNode(0,head);
        ListNode *curr=head;
        ListNode *prev=dummy;

        while(curr){
            while(curr->next && curr->val==curr->next->val){
                curr=curr->next;
            }
            if(prev->next!=curr){
                prev->next=curr;
            }
            prev=curr;
            curr=curr->next;
        }
        return dummy->next;
    }
};