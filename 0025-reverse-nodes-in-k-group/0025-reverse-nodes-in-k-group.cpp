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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *left=head,*right=head;
        vector<int> vec;

        while(right){
            int ct=k;
            while(ct && right){
                vec.push_back(right->val);
                right=right->next;
                ct--;
            }
            if(ct) break;
            ct=k;
            while(ct){
                left->val=vec.back();
                vec.pop_back();
                left=left->next;
                ct--;
            }
        }
        return head;
    }
};