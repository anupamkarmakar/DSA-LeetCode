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
    ListNode* reverseList(ListNode* head) {
        vector<int> vec;
        ListNode *p=head;

        while(p!=nullptr){
            vec.push_back(p->val);
            p=p->next;
        }
        p=head;
        while(p!=nullptr){
            p->val= vec.back();
            vec.pop_back();
            p=p->next;
        }
        return head;
    }
};