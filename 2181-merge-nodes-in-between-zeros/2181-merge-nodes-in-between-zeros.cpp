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
    ListNode* mergeNodes(ListNode* head) {
        if(!head || !head->next) return nullptr;
        ListNode *p=head->next;
        ListNode *q=head;

        while(p){
            int sum=0;
            while(p && p->val!=0){
                sum+=p->val;
                p=p->next;
            }

            if(p->val==0){
                p->val=sum; //upadte value of ) node
                q->next=p; //Linking

                q=p; // ready for future linking
                p=p->next;
            }
            
        }
        return head->next;
    }
};