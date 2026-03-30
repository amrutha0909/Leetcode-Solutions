class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<points.size();i++){
            int a=points[i][0];
            int b=points[i][1];
            int dist=pow((a-0),2)+pow((b-0),2);
            pq.push({dist,{a,b}});
        }
        vector<vector<int>>ans;
        while(k--&&!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int x=it.second.first;
            int y=it.second.second;
            ans.push_back({x,y});
        }
        return ans;
    }
};