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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left==right) return head;

        ListNode *dummy=new ListNode(0,head);
        ListNode *start=head,*end=head,*prev=dummy;
        int node=1;

        while(end && node<right){
            if(node<left){
                prev=start;
                start=start->next;
            }
            
            end=end->next;
            node++;
        }
        ListNode *nextend=end->next, *revfirst=start;

        prev->next=nullptr;
        end->next=nullptr;

        ListNode *revprev=nullptr;
        while(revprev!=end){
            ListNode *next=start->next;
            start->next=revprev;
            revprev=start;
            start=next;
        }

        prev->next=revprev;
        revfirst->next=nextend;
        
        return dummy->next;
    }
};