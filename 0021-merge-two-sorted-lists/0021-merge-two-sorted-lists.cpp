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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        else if(!list1) return list2;
        else if(!list2) return list1;

        ListNode *mainList,*last;

        if(list1->val < list2->val){
            mainList=list1;
            last=list1;

            list1=list1->next;
            last->next=nullptr;
        }
        else{
            mainList=list2;
            last=list2;

            list2=list2->next;
            last->next=nullptr;
        }

        while(list1 && list2){
            if(list1->val < list2->val){
                last->next=list1;
                last=list1;
                list1=list1->next;
                last->next=nullptr;
            }
            else{
                last->next=list2;
                last=list2;
                list2=list2->next;
                last->next=nullptr;
            }
        }

        if(list1!=nullptr) last->next=list1;
        else last->next=list2;

        return mainList;
    }
};