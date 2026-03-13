class Solution {
public:
    bool isPossible(int h, vector<int>& workerTimes, long long mid){
        long long removed = 0;

        for(int t : workerTimes){
            long long val = (2LL * mid) / t;

            long long k = (sqrt(1 + 4*val) - 1) / 2;

            removed += k;

            if(removed >= h) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
        long long high = 1e18;
        long long ans = 0;

        while(low <= high){
            long long mid = low + (high - low) / 2;

            if(isPossible(mountainHeight, workerTimes, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};