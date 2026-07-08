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
// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {
//         ListNode* dummy = new ListNode(-1);
//         ListNode* temp = head;

//         int sum = 0;
//         while(temp){
//             if(temp->val != 0) sum += temp->val;

//             if(!dummy){
//                 dummy->val = sum;
//                 sum = 0;
//                 ListNode* x = dummy;
//             }else{
//                 ListNode* node = new ListNode(sum);
//                 x->next = node;
//                 x = x->next;
//                 sum = 0;
//             }

//             temp = temp->next;
//         }
//         return dummy;
//     }
// };
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newhead = NULL;
        ListNode* curr = NULL;
        ListNode* temp = head->next;
        int sum = 0;
        while(temp){
            if(temp->val == 0){
                if(!newhead){
                    ListNode* newn = new ListNode(sum);
                    newhead = newn;
                    curr = newhead;
                }else{
                    ListNode* newn = new ListNode(sum);
                    curr->next = newn;
                    curr = curr->next;
                }
                sum = 0;
            }
            else{
                sum += temp->val;
            }

            temp = temp->next;
        }
        return newhead;
    }
};