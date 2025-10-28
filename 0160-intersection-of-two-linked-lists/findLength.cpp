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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0,n2=0;
        ListNode *ptr1=headA;
        ListNode *ptr2=headB;

        // Count Node in List A
        while(ptr1){
            n1++;
            ptr1=ptr1->next;
        }
        // Count Node in List B
        while(ptr2){
            n2++;
            ptr2=ptr2->next;
        }

        int diff=abs(n1-n2);

        // Adjust heads same distance from intersect
        if(n1>n2){
            while(diff){
                headA=headA->next;
                diff--;
            }
        }
        else{
            while(diff){
                headB=headB->next;
                diff--;
            }
        }

        // Where two ptr meet, this is intersect
        ptr1=headA,ptr2=headB;
        while(ptr1!=ptr2){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr1;
    }
};