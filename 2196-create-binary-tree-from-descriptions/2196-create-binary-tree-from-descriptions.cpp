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


// mp-> 85 82
//            74     
//         85    39     
//       82     13    70
//     38 
//  root-> 85 74
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        set<int> s;
        for(auto it: descriptions){
            int parent=it[0];
            int child=it[1];
            bool left=it[2];

            if(!mp.count(parent)){
                TreeNode* p=new TreeNode(parent);
                s.insert(parent);
                mp[parent]=p;
                if(!mp.count(child)){
                    TreeNode* c=new TreeNode(child);
                    mp[child]=c;
                    if(left==1){
                        p->left=c;
                    }else{
                        p->right=c;
                    }
                }else{
                    if(left==1){
                        p->left=mp[child];
                    }else{
                        p->right=mp[child];
                    }
                }
            }else{
                TreeNode* p=mp[parent];
                if(!mp.count(child)){
                    TreeNode* c=new TreeNode(child);
                    mp[child]=c;
                    if(left==1){
                        p->left=c;
                    }else{
                        p->right=c;
                    }
                }else{
                    if(left==1){
                        p->left=mp[child];
                    }else{
                        p->right=mp[child];
                    }
                }
            }
        }
        TreeNode* root=NULL;
        for(auto it: descriptions){
            if(s.count(it[1])) s.erase(it[1]);
        }
        for(auto it: s){
            root=mp[it];
        }
        return root;
    }
};