class Solution {
public:
    int maxDepth(string s) {
        int mxd=0;
        int c=0;
        for(char ch:s){
            if(ch=='('){
                c++;
                mxd=max(mxd,c);
            }else if(ch==')')c--;
        }
        return mxd;
    }
};