class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans;
        int N=1<<n;
        for(int i=0;i<N;i++){
            ans.push_back(i^(i>>1));
        }
        return ans;
    }
};