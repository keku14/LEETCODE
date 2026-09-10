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
    void fn(TreeNode* root,int& ans){
        if(root == NULL) return;

        fn(root->left,ans);

        int sum = 0;
        int cnt = 0;
        ind(root,sum,cnt);
        if(sum/cnt == root->val) ans++;

        fn(root->right,ans);
    }
    void ind(TreeNode* root,int& sum,int& cnt){
        if(root == NULL) return;

        ind(root->left,sum,cnt);

        sum+=root->val;
        cnt++;

        ind(root->right,sum,cnt);
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        fn(root,ans);
        return ans;
    }
};