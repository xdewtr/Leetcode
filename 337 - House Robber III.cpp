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
        if(!r) return 0;
        pair<int,int> i = helper(r);
        return max(i.first,i.second);

    }
    pair<int,int> helper(TreeNode* p){
        if(!p) return make_pair(INT_MIN,0);
        if(!(p->left||p->right)) return make_pair(p->val,0); // so next level if we want to include we use the second
        int yes, no =0;
        pair<int,int> l = helper(p->left);
        pair<int,int> r = helper(p->right);
        yes = p->val + l.second + r.second;
        no = max(l.first,l.second) + max(r.first,r.second);
        // this doesn't work because we need to take empty node into consideration
        // it will screw up by having normal + INT_MIN like in simple 1,2,null case
        // at level 1 we have (2,0) yes = 1 no = 2+INT_MIN
        //no = l.first + r.first;
        return make_pair(yes,no);
    }

};