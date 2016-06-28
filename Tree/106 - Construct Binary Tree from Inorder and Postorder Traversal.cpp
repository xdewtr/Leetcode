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
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        return helper(po, po.size()-1, in, 0, in.size()-1);
    }
    TreeNode* helper(vector<int>& po, int pi, vector<int>& in,int s, int e){
    	if(pi>=po.size()||s>e) return NULL;
    	TreeNode* p = new TreeNode(po[pi]);
    	if(s==e) return p;
    	int idx = find(in,p->val,s,e);
    	int lo = idx-s;
    	int ro = e-idx;
    	pi--;
    	if(lo!=0)
    		p->left = helper(po, pi-ro, in ,s, idx-1);
    	if(ro!=0)
    		p->right = helper(po, pi, in, idx+1, e);
    	return p;
    }
    int find(vector<int>& v, int val,int s, int e){
    	int i =s;
    	for(;i<=e;++i){
    		if(v[i]==val) break;
    	}
    	return i;
    }
};