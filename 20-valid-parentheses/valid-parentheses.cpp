class Solution {
public:
    bool f(char a,char b){
        if(a=='(' && b==')')return true;
        if(a=='[' && b==']')return true;
        if(a=='{' && b=='}')return true;
        return false;
    }
    bool isValid(string s) {
        stack<char>st;
        for(char ch:s){
            if(ch==')' || ch=='}' || ch==']'){
                 if (st.empty()) return false;
                if(!f(st.top(),ch))return false;
                st.pop();
            }else{
                st.push(ch);
            }
        }
        return st.empty()?true:false;
    }
};