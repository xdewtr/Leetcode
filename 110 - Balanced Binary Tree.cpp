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
    bool isBalanced(TreeNode* r) {
        if(!r) return 1;
        return helper(r) == -1? 0:1;
    }
    int helper(TreeNode* p){
    	if(!r) return 0;
    	int L=0, R=0;
    	L = helper(p->left);
    	R = helper(p->right);
    	if(L==-1||R==-1) return -1;
    	if(abs(L-R)>1) return -1;
    	return max(L,R)+1;
    }
};