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
        int count=0;
        ListNode *p=head;
        while(p){
            count++;
            p=p->next;
        }

        int tar=count-n+1;
        
        ListNode *q=nullptr;
        p=head;
        if(tar==1){
            head=head->next;
            delete p;
        }
        else{
            for(int i=1;i<tar;i++){
                q=p;
                p=p->next;
            }    
            q->next=p->next;
            delete p;
        }

        return head;
    }
};