class Solution {
public:
    int removeElement(vector<int>& n, int val) {
    	if(n.size()==0) return 0;
        int res = n.size();
        int i =0, j=n.size()-1;
        while(i<n.size() && i<j){
        	if(n[i]==val){
        		res--;
        		while(n[j]==val) j--;
        		swap(n[i],n[j]);
        	}
        	i++;
        }
        if(res == 0) n.clear();
        else{
        	int len = n.size()-res;
        	for(i=0;i<len;++i){
        		n.pop_back();
        	}
        }
        return res;
    }
};