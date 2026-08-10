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
    int fn(TreeNode* root, map<TreeNode*,int> &dp){
        if(root->left == NULL && root->right==NULL){
            return root->val;
        }
        //memo
        if(dp.count(root)) return dp[root];
        //not pick
        int npick=0;
        if(root->left){
            npick+=fn(root->left,dp);
        }
        if(root->right){
            npick+=fn(root->right,dp);
        }

        //pick
        int pick=root->val;
        if(root && root->left && root->left->left){
            pick+=fn(root->left->left,dp);
        }
        if(root && root->left &&root->left->right){
            pick+=fn(root->left->right,dp);
        }
        if(root && root->right &&root->right->left){
            pick+=fn(root->right->left,dp);
        }
        if(root && root->right &&root->right->right){
            pick+=fn(root->right->right,dp);
        }

        dp[root]= max(pick,npick);
        return dp[root];
    }
public:
    int rob(TreeNode* root) {
        map<TreeNode*,int> dp;
        return fn(root,dp);
    }
};