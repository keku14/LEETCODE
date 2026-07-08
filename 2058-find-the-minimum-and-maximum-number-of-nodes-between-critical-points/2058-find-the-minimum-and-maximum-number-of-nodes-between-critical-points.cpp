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
        int a = -1;
        int b = -1;
        int mini = INT_MAX;

        ListNode* temp = head->next;
        ListNode* prev = head;

        int s = 1;

        while (temp->next) {
            int i = prev->val;
            int j = temp->val;
            int k = temp->next->val;

            if ((i < j && k < j) || (i > j && k > j)) {

                if (a == -1) {
                    a = s;
                } else {
                    mini = min(mini, s - b);
                }

                b = s;
            }

            s++;
            prev = temp;
            temp = temp->next;
        }

        if (a == -1 || a == b)
            return {-1, -1};

        return {mini, b - a};
    }
};