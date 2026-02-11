class Solution {
public:
    void PSE(vector<int>&heights,vector<int>&pse){
        stack<int>stk;
        stk.push(0);
        pse[0]=-1;
        for(int i=1;i<heights.size();i++){
            while(!stk.empty()&&heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty())pse[i]=-1;
            else pse[i]=stk.top();
            stk.push(i);
        }
    }
    void NSE(vector<int>&heights,vector<int>&nse){
        stack<int>stk;
        int n=heights.size();
        stk.push(n-1);
        nse[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!stk.empty()&&heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty())nse[i]=n;
            else nse[i]=stk.top();
            stk.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse(n);
        vector<int>nse(n);
        PSE(heights,pse);
        NSE(heights,nse);
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;
    }
};