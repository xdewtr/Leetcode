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
        //if(pre.size()!=in.size()) return NULL;
        return helper(pre,in,0,in.size()-1);

    }
    TreeNode* helper(vector<int>& pre, vector<int>& in, int start, int end){
    	if(start>end) return NULL; // since start can be eq to end if only one node exists
    	int val = in[start++];
    	TreeNode* p = new TreeNode(val);
    	int idx = find(pre,val);
    	p->left = helper(pre,in,start,idx);
    	p->right = helper(pre,in,idx+1,end);
    	return p;


    }
    int find(vector<int> &v, const int &val){
    	for(int i=0; i<v.size(); ++i){
    		if(v[i]==val) return i;
    	}
    	return -1;
    }
};