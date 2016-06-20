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
    vector<vector<int>> levelOrderBottom(TreeNode* r) {

        // Declare DS
        queue<TreeNode*> qu;
        vector<vector<int>> res;
        vector<int> lvltmp;

        // Immediate return status
        if(!r) return res;

        // Init
        qu.push(r);
        qu.push(NULL);
        // Process level
        while(!qu.empty()){
        	TreeNode* p = qu.top();
        	qu.pop();
        	lvltmp.push_back(p->val);

        	if(p->left) qu.push(p->left);
        	if(p->right) qu.push(p->right);
        	// level stoping condition
        	if(qu.top()==NULL){
        		qu.pop();
        		res.push_back(lvltmp);
        		lvltmp.clear();
        		if(!qu.empty()) qu.push(NULL);
        	}
        }
        reverse(res.begin(),res.end());
        return res;
    }
};