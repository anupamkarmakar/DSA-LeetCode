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
    ListNode* sortList(ListNode* head) {
        deque<int> deq;
        ListNode *p=head;

        while(p!=nullptr){
            deq.push_back(p->val);
            p=p->next;
        }

        sort(deq.begin(),deq.end());

        p=head;
        while(p!=nullptr){
            p->val= deq.front();
            deq.pop_front();
            p=p->next;
        }
        return head;
    }
};