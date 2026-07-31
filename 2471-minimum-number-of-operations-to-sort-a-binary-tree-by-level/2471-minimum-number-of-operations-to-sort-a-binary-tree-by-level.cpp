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
    int fn(vector<int>& arr){
        // vector<int> v = temp;
        // sort(v.begin(),v.end());
        // int x = 0;
        // for(int i = 0;i<temp.size();i++){
        //     if(v[i] != temp[i]) x++;
        // }

        // return (x%2 == 0) ? x/2 : x/2 + 1;
        int n = arr.size();

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({arr[i], i});

    sort(v.begin(), v.end());

    vector<bool> vis(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i] || v[i].second == i)
            continue;

        int cycle = 0;
        int j = i;

        while (!vis[j]) {
            vis[j] = true;
            j = v[j].second;
            cycle++;
        }

        swaps += cycle - 1;
    }

    return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);

        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i = 1;i<=size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                temp.push_back(node->val);
            }
            cnt += fn(temp);
            cout << cnt << endl;
        }
        return cnt;
    }
};