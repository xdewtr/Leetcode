class Solution {
public:
    void genDP(vector<int> n, vector<vector<int>> &dp, int k){
        int i=0; // starting point
        int cursor =0; // cursor
        while(i>=0 && i<n.size()){
             
            if(n.size()<=k) dp[n.size()]= n;
            for(cursor=i; cursor+1 <n.size() &&n[cursor]>n[cursor+1]; ++cursor){}
            n.erase(n.begin()+cursor);
            i=cursor==0?0:cursor-1;
        }
    }
    vector<int> findMaxPair(vector<vector<int>> &dp1, vector<vector<int>> &dp2, int k){
        int i=0;
        int j=0;
        vector<int> maxres(k,0);
        for(i=0, j=k; i<dp1.size(); ++i,--j){
            vector<int> tmpres;
            int ii=0, jj=0;
            while(ii!=dp1[i].size() && jj!=dp2[j].size()&&tmpres.size()<k){
                int iii=ii,jjj=jj;
                for( ;dp1[i][iii]==dp2[j][jjj]; iii++,jjj++){    
                }
                if(dp1[i][iii]>dp2[j][jjj]){
                    tmpres.push_back(dp1[i][ii++]);
                }
                else if(dp1[i][iii]<dp2[j][jjj]){
                    tmpres.push_back(dp2[j][jj++]);
                }
                else{
                    

                }
            }
            if(ii!=dp1[i].size()){
                for(int i2= ii;i2<dp1[i].size()&&tmpres.size()<k; ++i2){
                    tmpres.push_back(dp1[i][i2]);
                }
            }
            else if(jj!=dp2[j].size()){
                for(int j2= jj;j2<dp2[j].size()&&tmpres.size()<k; ++j2){
                    tmpres.push_back(dp2[j][j2]);
                }
            }
            // comparison
            maxres = bigger(maxres,tmpres)? maxres: tmpres;
        }
        return maxres;
    }
    bool bigger(const vector<int> &lhs, const vector<int> &rhs){
        int i = 0, j=0;
        if(lhs.size()!=rhs.size()) return true;
        while(i!=lhs.size()&& j!=rhs.size()){
            if(lhs[i]>rhs[j]) return true;
            else if (lhs[i]<rhs[j]) return false;
            else{i++;j++;} 
        }
        return true;
    }
    
    vector<int> maxNumber(vector<int>& n1, vector<int>& n2, int k) {
        vector<vector<int>> dp1(k+1,vector<int>(0,0));
        vector<vector<int>> dp2(k+1,vector<int>(0,0));
        
        genDP(n1,dp1,k); genDP(n2,dp2,k);
        return findMaxPair(dp1,dp2,k);
    }
};