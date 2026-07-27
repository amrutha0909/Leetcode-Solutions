class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        int firstMax=INT_MIN;
        int secondMax=INT_MIN;
        int thirdMax=INT_MIN;
        int firstMin=INT_MAX;
        int secondMin=INT_MAX;
        for(int num:nums){
            if(num>=firstMax){
                thirdMax=secondMax;
                secondMax=firstMax;
                firstMax=num;
            }
            else if(num>=secondMax){
                thirdMax=secondMax;
                secondMax=num;
            }
            else if(num>thirdMax){
                thirdMax=num;
            }
            if(num<=firstMin){
                secondMin=firstMin;
                firstMin=num;
            }
            else if(num<secondMin){
                secondMin=num;
            }
        }
        return max(firstMax*secondMax*thirdMax,firstMin*secondMin*firstMax);
    }
};