class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mpp;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num:arr)pq.push(num);
        int i=1;
        while(!pq.empty()){
            int num=pq.top();
            pq.pop();
            if(mpp.find(num)==mpp.end()){
                mpp[num]=i;
                i++;
            }
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mpp[arr[i]];
        }
        return arr;
    }
};