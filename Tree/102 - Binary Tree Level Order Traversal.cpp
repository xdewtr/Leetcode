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
    vector<vector<int>> levelOrder(TreeNode* r) {
        vector<vector<int>> res;
        vector<int> tmp;
        queue<TreeNode*> qu;
        if(!r) return res;
        qu.push(r);
        qu.push(NULL);
        while(!qu.empty()){
        	TreeNode* p = qu.front();
        	qu.pop();
        	tmp.push_back(p->val);
        	if(p->left) qu.push(p->left);
        	if(p->right) qu.push(p->right);
        	if(qu.front()==NULL){
        		qu.pop();
        		res.push_back(tmp);
        		tmp.clear();
        		if(!qu.empty()) qu.push(NULL);
        	}

        }
        return res;
    }
};