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
    bool isPalindrome(ListNode* head){
        // If one or no element
        if(head==nullptr || head->next==nullptr) return true;

        vector<int> vec;
        ListNode *p=head;

        // copy element from LL to vector
        while(p!=nullptr){
            vec.push_back(p->val);
            p=p->next;
        }

        // Reverse
        vector <int> copy = vec; 
        reverse(vec.begin(),vec.end());

        // Checking
        if(vec==copy) return true;
        else return false;
    }
};