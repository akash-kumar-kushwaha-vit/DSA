class Solution {
public:
    void f(vector<string>&ans,int op,int cl,int n,string str){
        if(cl==n){
            ans.push_back(str);
            return;
        }
        if(op<n)f(ans,op+1,cl,n,str+'(');
        if(cl<op)f(ans,op,cl+1,n,str+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
         f(ans,0,0,n,"");
         return ans;
    }
};