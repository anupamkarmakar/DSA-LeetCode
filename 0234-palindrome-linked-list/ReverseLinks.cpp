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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        // Find the mid of the LL
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        // Set 3 ptr for reversing the links rest of the half
        ListNode *prev=slow;
        ListNode *temp;
        slow = slow->next;
        prev->next=nullptr;

        // reverse the links
        while(slow){
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }

        // comparing values
        fast=head, slow=prev;
        while(slow){
            if(fast->val!=slow->val) return false; 
            else fast=fast->next, slow=slow->next;
        }
        return true;
    }
};