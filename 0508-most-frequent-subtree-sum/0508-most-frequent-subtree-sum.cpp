/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, unordered_map<int, int>& mpp, int& sum) {
        if (!root) {
            sum = 0;
            return;
        }

        int left, right;
        dfs(root->left, mpp, left);
        dfs(root->right, mpp, right);

        sum = root->val + left + right;
        mpp[sum]++;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mpp;
        int sum=0;
        dfs(root, mpp, sum);

        vector<int> ans;
        int f=0;
        for(auto it: mpp){
            f=max(f,it.second);
        }
        for(auto it: mpp){
            if(it.second == f) ans.push_back(it.first);
        }
        return ans;
    }
};