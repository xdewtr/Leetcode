/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *r) {
        if(!r) return;
        dfs(r);
    }
    void dfs(TreeLinkNode* p ){
    	if(!p) return;
    	if(p->left) p->left->next = p->right;
    	dfs(p->left);
    	dfs(p->right);
    }
};