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
    void flatten(TreeNode* r) {
        if(!r) return;
        TreeNode* p =helper(r);
    }
    TreeNode* helper(TreeNode* p){
    	TreeNode*pre =p, *l=p->left, *r=p->right;
    	p->left = NULL; p->right =NULL;
    	if(l){
    		pre = helper(l);
    		p->right = l;
    	}
    	if(r){
    		pre->right = r;
    		pre = helper(r);
    	}
    	return pre;
    }
};