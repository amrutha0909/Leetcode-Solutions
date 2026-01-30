class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int left=0;
        int right=0;
        vector<int>nums3;
        while(left<nums1.size() && right<nums2.size()){            
            if(nums1[left]<=nums2[right]){
                nums3.push_back(nums1[left]);
                left++;
            }
            else{
                nums3.push_back(nums2[right]);
                right++;
            }
        }
        while(left<nums1.size()){
            nums3.push_back(nums1[left]);
            left++;
        }
        while(right<nums2.size()){
            nums3.push_back(nums2[right]);
            right++;
        }
        int n=nums3.size();
        double median;
        if(n%2==0){
            median=(nums3[(n-1)/2]+nums3[n/2])/2.0;
        }
        else{
            median=nums3[n/2];
        }
        return median;
    }
};