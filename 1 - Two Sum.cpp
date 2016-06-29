class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        vector<int> res;
        unordered_map<int,int> umap;
        for(int i=0; i<n.size();++i){
        	if(umap.find(n[i])==umap.end())
        		umap[n[i]]=i;
        	if(umap.find(t-n[i])!=umap.end()&&umap[t-n[i]]!=i){
        		res.push_back(umap[t-n[i]]);
        		res.push_back(i);
        		return res;
        	}

        }
        return res;
    }
};