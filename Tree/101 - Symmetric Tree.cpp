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
    bool isSymmetric(TreeNode* r) {
        if(!r) return 1;
        return helper(r->left,r->right);
    }
    bool helper(TreeNode* p, TreeNode* q){
    	if(p&&q) return p->val == q->val &&
    					helper(p->right,q->left) &&
    					helper(p->left,q->right);
    	else if(p||q) return 0;
    	else return 1;
    }
};