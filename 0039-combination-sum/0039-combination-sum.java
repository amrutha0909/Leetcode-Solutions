class Solution {
    public List<List<Integer>>res=new ArrayList<>();
    public void backtrack(int start,int[]candidates,List<Integer>temp,List<List<Integer>>res,int target,int sum){
        if(sum==target){
            res.add(new ArrayList<>(temp));
            return;
        }
        if(start>=candidates.length||sum>target){
            return;
        }
        temp.add(candidates[start]);
        backtrack(start,candidates,temp,res,target,sum+candidates[start]);
        temp.remove(temp.size()-1);
        backtrack(start+1,candidates,temp,res,target,sum);

    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        
        List<Integer>temp=new ArrayList<>();
        backtrack(0,candidates,temp,res,target,0);
        return res;
    }
}