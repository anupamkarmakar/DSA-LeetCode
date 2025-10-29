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