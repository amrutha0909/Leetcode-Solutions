class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>>mpp=new HashMap<>();
        for(String str:strs){
            char[]arr=str.toCharArray();
            Arrays.sort(arr);
            String sorted=new String(arr);
            mpp.putIfAbsent(sorted,new ArrayList<>());
            mpp.get(sorted).add(str);
        }
        List<List<String>>ans=new ArrayList<>();
        for(List<String>list:mpp.values()){
            ans.add(list);
        }
        return ans;
    }
}