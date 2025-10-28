class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) 
            return head;

        // Step 1: Count nodes
        int n = 0;
        ListNode* p = head;
        while (p != nullptr) {
            n++;
            p = p->next;
        }

        // Step 2: Create raw array of size n
        int* arr = new int[n];

        // Step 3: Copy values into array
        p = head;
        for (int i = 0; i < n; i++) {
            arr[i] = p->val;
            p = p->next;
        }

        // Step 4: Sort raw array
        sort(arr, arr + n);

        // Step 5: Copy values back into list
        p = head;
        for (int i = 0; i < n; i++) {
            p->val = arr[i];
            p = p->next;
        }

        // Step 6: Free the allocated memory
        delete[] arr;

        return head;
    }
};
