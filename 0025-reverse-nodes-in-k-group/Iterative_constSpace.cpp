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
    ListNode *getkthNode(ListNode *temp,int k){
        k=k-1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode *getReverse(ListNode* head){
        ListNode *p=head, *prev=NULL;
        while(p){
            ListNode *nextNode = p->next;
            p->next = prev;
            prev=p;
            p=nextNode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head, *kthNode=head, *nextNode=NULL, *prevNode=NULL;

        while(temp){
            kthNode = getkthNode(temp,k);
            if(kthNode==NULL){
                if(prevNode) prevNode->next=temp;
                break;
            }
            nextNode=kthNode->next;
            kthNode->next=NULL;
            getReverse(temp);

            if(temp==head) head=kthNode;
            else prevNode->next=kthNode;

            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};