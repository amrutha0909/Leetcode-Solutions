class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<points.size();i++){
            int a=points[i][0];
            int b=points[i][1];
            int dist=a*a+b*b;
            pq.push({dist,{a,b}});
            while(pq.size()>k)pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int x=it.second.first;
            int y=it.second.second;
            ans.push_back({x,y});
        }
        return ans;
    }
};