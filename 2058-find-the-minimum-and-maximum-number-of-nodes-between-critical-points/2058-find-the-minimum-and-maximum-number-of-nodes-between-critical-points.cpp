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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Need at least 3 nodes to have any critical point
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        
        vector<int> pos;      // positions of critical points
        int idx = 1;          // index of curr (0-based for head, 1 for second node)

        // Traverse while curr has a next node
        while (curr->next != nullptr) {
            int a = prev->val;
            int b = curr->val;
            int c = curr->next->val;

            // Check for local max or local min
            if ((b > a && b > c) || (b < a && b < c)) {
                pos.push_back(idx);
            }

            prev = curr;
            curr = curr->next;
            idx++;
        }

        // Need at least two critical points
        if (pos.size() < 2) {
            return {-1, -1};
        }

        // Max distance: between first and last critical points
        int maxi = pos.back() - pos.front();

        // Min distance: minimum of differences of consecutive critical points
        int mini = INT_MAX;
        for (int i = 1; i < (int)pos.size(); i++) {
            mini = min(mini, pos[i] - pos[i - 1]);
        }

        return {mini, maxi};
    }
};
