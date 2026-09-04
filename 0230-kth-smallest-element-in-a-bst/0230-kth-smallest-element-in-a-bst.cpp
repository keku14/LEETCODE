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
    int cnt = 0;
    int res = -1;
    void fn(TreeNode* root,int k){
        if(!root || cnt >= k) return;

        fn(root->left,k);
        cnt++;
        if(cnt == k){
            res = root->val;
            return;
        }
        fn(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        fn(root,k);
        return res;
    }
};