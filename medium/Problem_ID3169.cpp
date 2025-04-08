class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(),meetings.end());
            vector<vector<int>>merged;
            merged.push_back(meetings[0]);
            for (int i = 1; i < meetings.size(); i++) {
                vector<int>&last=merged.back();
                if(last[1]>=meetings[i][0]){
                    last[1]=max(last[1],meetings[i][1]);
                }
                else{
                    merged.push_back(meetings[i]);
                }
            }
            int count=0;
            for(int i=0;i<merged.size()-1;i++){
                if((merged[i+1][0]-merged[i][1])>1){
                    count=count+(merged[i+1][0]-merged[i][1])-1;
                }
            }
            if(merged[merged.size()-1][1]<days){
                count=count+(days-merged[merged.size()-1][1]);
            }
            if(merged[0][0]>1){
                count=count+(merged[0][0]-1);
            }
            return count;
        }
    };