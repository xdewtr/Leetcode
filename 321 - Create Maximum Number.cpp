#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:

    void genDP(const vector<int> &v, vector<int> &dp, int k){
        vector<int> localv = v;
        for(int i=0, start=0; localv.size()>0; start =i==0?0:i-1){
            if((int)(localv.size())<=k) dp[(int)(localv.size())] = vec2Num(localv);
            for(i=start; i+1 < (int)(localv.size()) && localv[i]> localv[i+1]; ++i){
                   
            };
            cout << "current i points to " << i << "  ";
            cout << "num to erase is " << *(localv.begin()+i) << endl;
            localv.erase(localv.begin()+i);
        }
    }
    vector<int> calcMax(vector<int> dp1, vector<int> dp2){
        return {};
    }

    // helper 
    int vec2Num(const vector<int> &v){
        int mult =1, sum=0;
    	for(int i=v.size()-1; i>=0;--i){
    		sum+= v[i]*mult;
    		mult*=10;
    	}
    	return sum;
    }
    vector<int> num2Vector(int n){
    	vector<int> res;
    	int divider = 10;
    	while(n!=0){
    		res.push_back(n%divider);
    		n/=divider;
    	}
        reverse(res.begin(),res.end());
    	return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> dp1(k+1,0), dp2(k+1,0);
        genDP(nums1,dp1,k);
        genDP(nums2,dp2,k);
    
        return calcMax(dp1,dp2);
    }
};

int main()
{   
	Solution *s = new Solution();
    // ========= testing helper functions begin
    /*
    vector<int> v{2,2,3,4,5};
    int num = s->vec2Num(v);
    cout<< "num is: " << num << endl;

    vector<int> v2;
    v2 = s->num2Vector(num);
    cout << "vec is: " << endl;
    for(int &i: v2){
        cout << i << ", ";
    }*/
    // ========= testing helper functions end


    // ========= testing genDP
    vector<int> v3{9,1,2,5,8,3};
    int k =3;
    vector<int> dp(k+1,0);
    s->genDP(v3,dp,k);
    cout << "dp is: " << endl;
    for(int i: dp){
        cout << i << ", ";
    }  

    // ========= testing genDP
    return 1;
}
