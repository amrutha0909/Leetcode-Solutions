class Solution {
public:
    int reverseI(int num){
        int rev = 0;
        while(num > 0){
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            int rev = reverseI(nums[i]);

            // check BEFORE inserting
            if(mpp.find(nums[i]) != mpp.end()){
                ans = min(ans, i - mpp[nums[i]]);
            }

            // store latest index
            mpp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};