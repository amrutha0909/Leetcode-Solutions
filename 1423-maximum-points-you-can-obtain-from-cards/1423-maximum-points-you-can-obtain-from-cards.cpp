class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        int win=n-k;
        int left=0;
        int minSum=INT_MAX;
        int total=0;
        for(int num:cardPoints){
            total+=num;
        }
        if(n==k)return total;
        for(int right=0;right<n;right++){
            sum+=cardPoints[right];
            while(right-left+1>win){
                sum-=cardPoints[left];
                left++;
            }
            if(right-left+1==win)minSum=min(minSum,sum);
        }
        return total-minSum;
    }
};