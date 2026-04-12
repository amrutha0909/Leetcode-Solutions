class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mpp;
        int total=0;
        for(int i=0;i<time.size();i++){
            int rem=time[i]%60;
            if(mpp.find((60-rem)%60)!=mpp.end()){
                total+=mpp[(60-rem)%60];
            }
            mpp[time[i]%60]++;
        }
        return total;
    }
};