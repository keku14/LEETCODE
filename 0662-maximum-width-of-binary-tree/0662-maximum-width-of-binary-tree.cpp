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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        if(root) q.push({root,0});
        long long ans = 0;

        while(!q.empty()){
            int size = q.size();
            int left = 0;
            int right = 0;
            int mini = q.front().second;
            for(int i = 0;i<size;i++){
                TreeNode* x = q.front().first;
                int idx = q.front().second - mini;
                q.pop();

                if(i == 0) left = idx;
                if(i == size-1) right = idx;

                if(x->left) q.push({x->left,1LL*2*idx+1});
                if(x->right) q.push({x->right,1LL*2*idx+2});
            }
            ans = max(ans,(long long)right-left+1);
        }
        return (int)ans;
    }
};