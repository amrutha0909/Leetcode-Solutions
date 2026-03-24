class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub; // stores the "smallest tail" of increasing subsequences

        for (int num : nums) {
            int i = 0, j = sub.size() - 1;
            int pos = sub.size(); // default: append to sub if num is bigger than all

            // Simple binary search to find first element >= num
            while (i <= j) {
                int mid = (i + j) / 2;
                if (sub[mid] >= num) {
                    pos = mid;   // found a candidate to replace
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            }

            if (pos == sub.size()) {
                // num is bigger than all → append
                sub.push_back(num);
            } else {
                // replace to keep subsequence "tail" small
                sub[pos] = num;
            }
        }

        return sub.size(); // length of LIS
    }
};