class Solution {
public:
    void PSE(vector<int>&pse,vector<int>&heights){
        pse[0]=-1;
        stack<int>stk;
        stk.push(0);
        for(int i=1;i<heights.size();i++){
            while(!stk.empty()&&heights[stk.top()]>=heights[i])stk.pop();
            if(stk.empty())pse[i]=-1;
            else pse[i]=stk.top();
            stk.push(i);
        }
    }
    void NSE(vector<int>&nse,vector<int>&heights){
        int n=heights.size();
        nse[n-1]=n;
        stack<int>stk;
        stk.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!stk.empty()&&heights[stk.top()]>=heights[i])stk.pop();
            if(stk.empty())nse[i]=n;
            else nse[i]=stk.top();
            stk.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=INT_MIN;
        int n=heights.size();
        vector<int>pse(n);
        vector<int>nse(n);
        PSE(pse,heights);
        NSE(nse,heights);
        for(int i=0;i<heights.size();i++){
            maxArea=max(maxArea,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;
    }
};