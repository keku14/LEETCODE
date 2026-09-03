/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        while(temp!=NULL){
            int val = temp->val;
            if(val < p->val && val < q->val){
                temp = temp->right;
            }
            else if(val > p->val && val > q->val){
                temp = temp->left;
            }
            else{
                return temp;
            }
        }
        return NULL;
    }
};