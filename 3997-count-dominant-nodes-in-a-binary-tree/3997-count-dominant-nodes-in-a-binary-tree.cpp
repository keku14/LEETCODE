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
private:
    void in(TreeNode*root, int&cnt){
        if(root==NULL) return;
        in(root->left, cnt);
        //main kaam
        int maxi=root->val;
        fn(root,maxi);
        if(maxi == root->val) cnt++;
        in(root->right, cnt);
    }
    void fn(TreeNode*root, int &maxi){
        //root wale tree se max value compare to root->val
        if(root==NULL) return;
        fn(root->left,maxi);
        maxi=max(maxi,root->val);
        fn(root->right,maxi);
    }
public:
    int countDominantNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int cnt=0;
        in(root, cnt);
        return cnt;
    }
};