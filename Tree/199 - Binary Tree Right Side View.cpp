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
    vector<int> rightSideView(TreeNode* r) {
        vector<int> res;
        if(!r) return res;
        queue<TreeNode*> qu;
        qu.push(r);
        qu.push(NULL);
        while(!qu.empty()){
        	TreeNode* p = qu.front();
        	qu.pop();
        	if(p->left) qu.push(p->left);
        	if(p->right) qu.push(p->right);
        	if(qu.front()==NULL){
        		res.push_back(p->val);
        		qu.pop();
        		if(!qu.empty()) qu.push(NULL);
        	}
        }
        return res;
    }
};