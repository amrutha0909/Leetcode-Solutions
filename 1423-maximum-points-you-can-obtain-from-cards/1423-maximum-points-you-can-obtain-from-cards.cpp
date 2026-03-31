class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        int n=cardPoints.size();
        for(int num:cardPoints){
            total+=num;
        }
        int win=n-k; //picking k cards from the ends means there are n-k cards left in the middle. To maximize the sum of the k picked cards, we have to minimize the sum of the n-k unpicked cards
        int left=0;
        int sum=0;
        int minSum=INT_MAX;
        if(n==k)return total;
        for(int right=0;right<n;right++){
            sum+=cardPoints[right];
            if(right-left+1>win){
                sum-=cardPoints[left];
                left++;
            }
            if(right-left+1==win)minSum=min(minSum,sum);
        }
        return total-minSum;
    }
};