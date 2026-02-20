class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int num:nums){
            pq.push(num);
        }
        int count=0;
        while(count<k-1){
            count++;
            pq.pop();
        }
        return pq.top();
    }
};