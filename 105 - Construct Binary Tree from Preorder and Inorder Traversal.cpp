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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        return helper(pre,0,in,0,in.size()-1);
    }
    TreeNode* helper(vector<int>& pre, int pi, vector<int>& in, int start, int end){
    	if(pi>=pre.size()||start>end) return NULL;
    	TreeNode*p = new TreeNode(pre[pi]);
    	if(start==end) return p;
    	// find it in in
    	int idx = find(in,p->val,start,end);
    	// leftoffset,rightoffset
    	int lo= idx-start;
    	int ro = end-idx;
    	pi++;
    	if(lo!=0) 
    		p->left = helper(pre,pi,in,start,idx-1);
    	if(ro!=0)
    		p->right = helper(pre,pi+lo,in,idx+1,end);
    	return p;
    }
    int find(vector<int> &v, int val, int s, int e){
    	int i =s;
    	for(;i<=e;++i){
    		if(v[i]==val) break;
    	}
    	return i;

    }
};