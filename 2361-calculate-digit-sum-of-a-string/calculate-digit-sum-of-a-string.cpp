class Solution {
public:
    string digitSum(string s, int k) {
        int len=s.length();
        while(len>k){
            string temp="";
            for(int i=0;i<len;i+=k){
                int sum=0;
               for(int j=i;j<i+k && j<len;j++){
                  sum+=(s[j]-'0');
               }
               temp+=to_string(sum);
            }
            len=temp.length();
            s=temp;  
        }
        return s;
    }
};