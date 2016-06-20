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
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        if(r==NULL||r==q||r==p) return r;
        TreeNode* L = lowestCommonAncestor(r->left,p,q);
        TreeNode* R = lowestCommonAncestor(r->right,p,q);
        if(L&&R) return r;
        return L? L:R;
    }
};