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
    ListNode* headNode;

    Solution(ListNode* head) {
        headNode=head;
    }
    
    int getRandom() {
        ListNode* temp=headNode;
        int i=1;
        int result=0;
        while(temp){
            if(rand()%i==0){  // choose current with probability 1/i
                result=temp->val;
            }
            temp=temp->next;
            i++;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */