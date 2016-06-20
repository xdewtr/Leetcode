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
    bool hasPathSum(TreeNode* r, int sum) {
        bool res=0;
        if(!r) return 0;
        dfs(r,sum,res);
        return res;
    }
    void dfs(TreeNode* p, int sum, bool &res){
    	if(res||sum<0) return;
    	if(!(p->left||p->right) && sum==p->val){
    		res= 1;
    		return;
    	}
    	if(p->left) dfs(p->left,sum-p->val,res);
    	if(p->right) dfs(p->right,sum-p->val,res);
    	return;
    }
};