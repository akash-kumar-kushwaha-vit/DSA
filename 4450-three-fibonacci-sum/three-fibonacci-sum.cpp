class Solution {
public:
    bool threeFibonacciSum(int n) {
        if(n==2)return true;
       long long a=0;
       long long b=1;
       for(int i=2;i<=n;i+=2){
        if(a!=0 && (a+a==n || b+b==n) )return true;
        if(a+a>n || b+b>n)return false;
        a=a+b;
        b=a+b;
       }
       return false;
    }
};