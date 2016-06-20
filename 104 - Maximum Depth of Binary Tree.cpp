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
    int maxDepth(TreeNode* r) {
        if(!r) return 0;
        int md = INT_MIN;
        dfs(md,1,r);
        return md;
    }
    void dfs(int &md, int cd, TreeNode* p){
    	if(!(p->left||p->right)){
    		md = max(md,cd);
    		return;

    	}
    	if(p->left) dfs(md,cd+1,p->left);
    	if(p->right) dfs(md,cd+1,p->right);
    	return;
    }
};