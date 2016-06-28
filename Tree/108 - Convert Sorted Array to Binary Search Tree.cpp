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
    TreeNode* sortedArrayToBST(vector<int>& n) {
        if(n.size()==0) return NULL;
        TreeNode *r = dfs(n,0,n.size()-1);
        return r;
    }
    TreeNode* dfs(vector<int>& n,int s, int e){
    	if(s>e) return NULL;
    	int m = s+ (e-s)/2;
    	TreeNode* p = new TreeNode(n[m]);
    	p->left = dfs(n,s,m-1);
    	p->right = dfs(n, m+1,e);
    	return p;
    }
};