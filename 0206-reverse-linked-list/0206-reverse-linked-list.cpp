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
        // Base Case
        if(head==NULL || head->next==NULL) return head;

        // Recursive function go till null and store last node as a 'newHead'
        ListNode* newNode = reverseList(head->next);

        // Create 'front' before 'head' node, then reverse links
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        
        // it step by step return newNode, after all the returing calls are happened,it return answer
        return newNode;
    }
};