class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        int firstCritical = -1, lastCritical = -1, prevCritical = -1;
        int mini = INT_MAX;

        while (curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    mini = min(mini, index - prevCritical);
                }

                prevCritical = index;
                lastCritical = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (firstCritical == lastCritical)
            return {-1, -1};

        return {mini, lastCritical - firstCritical};
    }
};
