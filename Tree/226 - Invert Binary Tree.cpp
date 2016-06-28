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
    TreeNode* invertTree(TreeNode* r) {
        helper(r);
        return r;
    }
    void helper(TreeNode* r){
        if(!r) return;
        if(!(r->left) && !(r->right)) return;
        TreeNode* tmp = r->left;
        r->left = r->right;
        r->right = tmp;
        invertTree(r->left);
        invertTree(r->right);
    }
};