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
    vector<int> preorderTraversal(TreeNode* r) {
        vector<int> res;
        if(!r) return res;
        stack<TreeNode*> st;
        while(r){
        	res.push_back(r->val);
        	st.push(r);
        	r= r->left;
        	
        }
        while(!st.empty()){
        	TreeNode* p = st.top();
        	st.pop();
        	if(p->right){
        		p=p->right;
        		while(p){
        			res.push_back(p->val);
        			st.push(p);
        			p=p->left;
        			
        		}
        	}
        }
        return res;
    }
};