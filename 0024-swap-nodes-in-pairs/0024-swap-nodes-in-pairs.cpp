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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        ListNode* prev = head;
        ListNode* temp = head->next;

        while (prev && temp) {
            int a = prev->val;
            int b = temp->val;

            temp->val = a;
            prev->val = b;

            if(prev->next != NULL) prev = prev->next->next;
            if(temp->next != NULL) temp = temp->next->next;
        }
        return head;
    }
};