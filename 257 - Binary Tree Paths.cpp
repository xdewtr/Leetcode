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
    vector<string> binaryTreePaths(TreeNode* r) {
        //Declare DS
        vector<string> res;
        string tmp;
        if(!r) return res;
        dfs(tmp,res,r);
        return res;
    }

    void dfs(string tmp, vector<string> &res, TreeNode* p){
        if(!p->left&&!p->right){
            res.push_back(tmp+to_string(p->val));
            return;
        }
        if(p->left) dfs(tmp+to_string(p->val)+"->",res,p->left);
        if(p->right) dfs(tmp+to_string(p->val)+"->",res,p->right);
    }
};