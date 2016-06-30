/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j 
in the array such that nums[i] = nums[j] and the difference 
between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& n, int k) {
        
        if(n.size()==0) return 0;
        unordered_map<int,int> umap;
        for(int i=0; i<n.size();++i){
        	if(umap.find(n[i])==umap.end())
        		umap[n[i]] = i;
        	else{
        		if(i-umap[n[i]]<=k) return 1;
        		umap[n[i]] = i;
        	}

        }
        return 0;
    }
};