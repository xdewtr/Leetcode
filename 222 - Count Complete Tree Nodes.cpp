/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, 
and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.

*/


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
    int countNodes(TreeNode* r) {
    	if(!r) return 0;
    	TreeNode* p = r; int lh=1, rh=1;
    	while(p->left){
    		p = p->left;
    		lh++;
    	}
    	p = r;
    	while(p->right){
    		p = p->right;
    		rh++;
    	}
    	if(lh==rh) return pow(2,lh)-1;
    	// process remaining by bottom dfs
    	int add =0; bool stop =0;
    	dfs(r,stop,lh,1,add);
    	return pow(2,lh-1)-1+add;
    }
    void dfs(TreeNode* p, bool &stop, const int &h, int curh, int &add){
    	if(stop) return;
    	if(!(p->left||p->right)){
    		if(curh!=h) stop =1;
    		else add++;
    		return;
    	}
    	if(p->left) dfs(p->left,stop,h,curh+1,add);
    	if(p->right) dfs(p->right,stop,h,curh+1,add);

    }
};