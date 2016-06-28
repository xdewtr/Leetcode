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
    int sumNumbers(TreeNode* r) {
        int sum =0;
        dfs(r,sum,0);
        return sum;
    }
    void dfs(TreeNode* p, int &sum, int cs){
    	if(!(p->left||p->right)){
    		sum+= cs*10+p->val;
    		return;
    	}
    	if(p->left) dfs(p->left,sum,cs*10+p->val);
    	if(p->right) dfs(p->right,sum,cs*10+p->val);
    }
};