class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int sum=0;
        int boats=0;
        int i=0;
        int j=people.length-1;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++;
                j--;
            }
            else{
                j--;
            }
            boats++;
        }
        return boats;
    }
}