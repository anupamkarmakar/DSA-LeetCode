/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head==nullptr) return nullptr;

        ListNode *start = head;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }

        if(fast==nullptr || fast->next==nullptr) return nullptr;

        while(start!=slow){
            start = start->next;
            slow = slow->next;
        }
        return start;
    }
};