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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow=head, *fast=head;

        // This ensures slow is exactly n nodes behind fast
        for(int i=0;i<n;i++){
            fast=fast->next;
        }

        // Edge case: If fast is nullptr after moving n steps → we need to remove head
        if(!fast){
            return head->next;
        }

        while(fast->next){
            fast=fast->next; //starting from nth (from starting)
            slow=slow->next; //starting from head (stop in before nth node from end)
        }

        // delete the link
        slow->next=slow->next->next;
        return head;
    }
};