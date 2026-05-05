class Solution {
    public double power(double x, long n){
        if(n==0)return 1;
        if(n%2==0)return power(x*x,n/2);
        else return x*power(x,n-1);
    } 
    public double myPow(double x, int n) {
        long N=n;
        if(n<0){
            x=1/x;
            N=N*(-1);
        }
        return power(x,N);
    }
}