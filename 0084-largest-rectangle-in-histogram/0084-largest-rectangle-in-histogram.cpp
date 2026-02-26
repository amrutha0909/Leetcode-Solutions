class Solution {
public:
    void PSE(vector<int>&heights, vector<int>&pse, int n){
        stack<int>s;
        pse[0]=-1;
        s.push(0);
        for(int i=1;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty())pse[i]=s.top();
            else pse[i]=-1;
            s.push(i);
        }
    }
    void NSE(vector<int>&heights,vector<int>&nse, int n){
        stack<int>s;
        nse[n-1]=n;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(!s.empty())nse[i]=s.top();
            else nse[i]=n;
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse(n);
        vector<int>nse(n);
        NSE(heights,nse,n);
        PSE(heights,pse,n);
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea, heights[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;
    }
};