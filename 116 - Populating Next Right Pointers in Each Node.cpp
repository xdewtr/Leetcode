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
        TreeLinkNode *p = r, *leftmost = NULL;
        while(p->left){
        	leftmost = p->left;
        	while(p){
        		p->left->next = p->right;
        		p->right->next = p->next ? p->next->left:NULL;
        		p = p->next;
        	}
        	p = leftmost;
        }
    }
};