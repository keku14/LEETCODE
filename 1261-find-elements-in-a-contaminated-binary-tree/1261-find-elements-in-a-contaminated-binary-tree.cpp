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
class FindElements {
private:
    void bfs(TreeNode* &root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=1; i<=size; i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left){
                    node->left->val=node->val*2+1;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val=node->val*2+2;
                    q.push(node->right);
                }
            }
        }
    }
    bool in(TreeNode* root, int target){
        //base case
        if(root==NULL) return false;

        bool l=in(root->left,target);
        //main kaam
        if(root->val==target){
            return true;
        }
        bool r=in(root->right,target);
        return l||r;
    }
public:
    TreeNode* temp=NULL;
    FindElements(TreeNode* root) {
        root->val=0;
        bfs(root);
        temp=root;
    }
    
    bool find(int target) {
        return in(temp,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */