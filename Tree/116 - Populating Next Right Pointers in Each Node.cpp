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
        link(r->left,r->right);
    }
    void link(TreeLinkNode *l, TreeLinkNode *r){
    	if(!(l||r)) return;
    	l->next = r;
    	link(l->left,l->right);
    	link(l->right,r->left);
    	link(r->left,r->right);
    }

};