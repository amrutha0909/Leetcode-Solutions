class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer>res=new ArrayList<>();
        int count1=0;
        int count2=0;
        int candidate1=0;
        int candidate2=0;
        for(int num:nums){
            if(count1==0 && num!=candidate2){
                count1=1;
                candidate1=num;
            }
            else if(count2==0 && num!=candidate1){
                count2=1;
                candidate2=num;
            }
            else if(num==candidate1){
                count1++;
            }
            else if(num==candidate2){
                count2++;
            }
            else{
                count2--;
                count1--;
            }
        }
        count1=0;
        count2=0;
        int threshold=nums.length/3;
        for(int num:nums){
            if(num==candidate1)count1++;
            else if(num==candidate2)count2++;
        }
        if(count1>threshold)res.add(candidate1);
        if(count2>threshold)res.add(candidate2);
        return res;
    }
}