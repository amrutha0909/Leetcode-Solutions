class Solution {
public:
    int lowerBound(vector<vector<int>>& intervals, vector<int>& newInterval){
        int target=newInterval[0];
        int low=0;
        int high=intervals.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(intervals[mid][0]>=target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()){
            return {newInterval};
        }
        int lb=lowerBound(intervals,newInterval);
        intervals.insert(intervals.begin()+lb,newInterval);
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]<intervals[i][0])ans.push_back(intervals[i]);
            else ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
        return ans;
    }
};