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
    int rob(TreeNode* r) {
        queue<TreeNode*> qu;
        int sumodd =0, sumeven =0, tmp=0;
        bool tick =1;
        if(!r) return 0;
        qu.push(r);
        qu.push(NULL);
        while(!qu.empty()){
        	TreeNode* p = qu.front();
        	qu.pop();
        	tmp+= p->val;
        	if(p->left) qu.push(p->left);
        	if(p->right) qu.push(p->right);
        	if(qu.front()==NULL){
        		qu.pop();
        		if(tick) sumodd+=tmp;
        		else sumeven+=tmp;
        		tmp=0;
        		tick=!tick;
        		if(!qu.empty())qu.push(NULL);
        	}

        }
        return sumeven>sumodd ? sumeven:sumodd;
    }
};