class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]>list=new ArrayList<>();
        for(int[]interval:intervals){
            list.add(interval);
        }
        int low=0;
        int high=intervals.length-1;
        int target=newInterval[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(intervals[mid][0]<=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        list.add(low,newInterval);
        List<int[]>ans=new ArrayList<>();
        ans.add(list.get(0));
        int prev=list.get(0)[1];
        for(int i=1;i<list.size();i++){
            if(list.get(i)[0]<=prev){
                prev=Math.max(prev,list.get(i)[1]);
                ans.get(ans.size()-1)[1]=prev;
            }
            else{
                ans.add(list.get(i));
                prev=list.get(i)[1];
            }
        }
        return ans.toArray(new int[ans.size()][]);

    }
}