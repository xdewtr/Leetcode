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
    int minDepth(TreeNode* r) {
        int minh = INT_MAX;
        if(!r) return 0;
        dfs(minh,1,r);
        return minh;
    }
    void dfs(int &minh, int curh, TreeNode* p){
    	if(curh > minh) return;
    	if(!(p->left||p->right)){
    		minh = min(minh,curh);
    		return;
    	}
    	if(p->left) dfs(minh, curh+1, p->left);
    	if(p->right) dfs(minh, curh+1, p->right);
    }
};