class Solution {
    public int helper(int i,int j,int[][]dp,List<List<Integer>> triangle){
        int n=triangle.size();
        if(i==n-1)return triangle.get(i).get(j);
        if(dp[i][j]!=Integer.MAX_VALUE)return dp[i][j];
        int way1=triangle.get(i).get(j)+helper(i+1,j,dp,triangle);
        int way2=triangle.get(i).get(j)+helper(i+1,j+1,dp,triangle);
        return dp[i][j]=Math.min(way1,way2);
    }
    public int minimumTotal(List<List<Integer>> triangle) {
        int n=triangle.size();
        int[][]dp=new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=Integer.MAX_VALUE;
            }
        }
        return helper(0,0,dp,triangle);
    }
}