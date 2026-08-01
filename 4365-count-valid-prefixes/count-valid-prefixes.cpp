class Solution {
public:
    int countValidPrefixes(string s) {
        int count=0;
        int one=0;
        int zero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')one++;
            else zero++;
            if(one-1==zero || zero-1==one || one==zero)count++;
        }
        return count;
    }
};