/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isleaf(TreeNode* root){
        return (root->left == NULL && root->right == NULL);
    }
    void fn(TreeNode* root,int& ans,int curr){
        if(isleaf(root)){
            ans += curr;
            return;
        }

        if(root->left) fn(root->left,ans,curr*10 + root->left->val);
        if(root->right) fn(root->right,ans,curr*10+ root->right->val);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        fn(root,ans,root->val);
        return ans;
    }
};