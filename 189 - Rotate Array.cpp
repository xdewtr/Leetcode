/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3,
 the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, 
there are at least 3 different ways to solve this problem.

*/

class Solution {
public:
    void rotate(vector<int>& n, int k) {
        if(n.size()==0||n.size()==1) return;
        k%=n.size();
        if(k==0) return;
        rev(0,n.size()-1,n);
        rev(0,k-1,n);
        rev(k,n.size()-1,n);

    }
    void rev(int s, int e, vector<int> &v){
    	if(s==e) return;
    	int m = s+(e-s+1)/2;
    	for(int i=0;i<m;++i)
    		swap(v[s+i],v[e-i]);
    }
    void swap(int &a, int &b){
    	int t = b;
    	b=a;
    	a=t;
    }
};