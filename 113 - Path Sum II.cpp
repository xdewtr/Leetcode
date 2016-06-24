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
    vector<vector<int>> pathSum(TreeNode* r, int sum) {
    	vector<vector<int>> res;
    	if(!r) return res;
    	vector<int> tmp;
    	dfs(res,tmp,sum,r);
    	return res;
    }
    void dfs(vector<vector<int>> &res, vector<int> tmp, int sum, TreeNode* p){
    	
    	if(!(p->left||p->right)&&sum==p->val){
    		tmp.push_back(p->val);
    		res.push_back(tmp);
    		return;
    	}
    	tmp.push_back(p->val);
    	if(p->left)
    		dfs(res,tmp,sum-p->val,p->left);
    	if(p->right)
    		dfs(res,tmp,sum-p->val,p->right);
    	tmp.pop_back();
    }
};