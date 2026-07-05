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
    int ans = 0;
    void traversal(TreeNode* root,int mini,int maxi){
        if(!root) return;

        mini = min(mini,root->val);
        maxi = max(maxi,root->val);
        ans = max(ans,maxi-mini);

        traversal(root->left,mini,maxi);
        traversal(root->right,mini,maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxi = INT_MIN , mini = INT_MAX;
        traversal(root,mini,maxi);
        return ans;
    }
};