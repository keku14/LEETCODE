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
    void fn(unordered_map<int, TreeNode*>& p_mpp,TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* x = q.front();
            q.pop();

            if(x->left){
                p_mpp[x->left->val] = x;
                q.push(x->left);
            }
            if(x->right){
                p_mpp[x->right->val] = x;
                q.push(x->right);
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};
        unordered_map<int, TreeNode*> p_mpp;
        fn(p_mpp,root);

        vector<int> ans;
        unordered_map<int,int> visi;
        visi[target->val] = 1;
        queue<TreeNode*> q;
        q.push(target);

        int curr = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 1;i<=size;i++){
                TreeNode* x = q.front();
                q.pop();

                if(x->left && !visi.count(x->left->val)){
                    visi[x->left->val] = 1;
                    q.push(x->left);
                }
                if(x->right && !visi.count(x->right->val)){
                    visi[x->right->val] = 1;
                    q.push(x->right);
                }
                if(p_mpp[x->val] && !visi.count(p_mpp[x->val]->val)){
                    visi[p_mpp[x->val]->val] = 1;
                    q.push(p_mpp[x->val]);
                }
            }
            curr++;
            if(curr == k){
                while(!q.empty()){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }
        } 
        return ans;
    }
};