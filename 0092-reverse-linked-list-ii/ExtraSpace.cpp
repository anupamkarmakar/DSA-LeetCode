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

        ListNode *temp=head,*curr=head;
        int node=1;
        stack<int>st;

        while(temp && node<=right){
            if(node<left){
                curr=curr->next;
            }
            if(node>=left && node<=right){
                st.push(temp->val);
            }
            temp=temp->next;
            node++;
        }

        while(curr!=temp && curr){
            curr->val=st.top();
            st.pop();
            curr=curr->next;
        }
        return head;
    }
};