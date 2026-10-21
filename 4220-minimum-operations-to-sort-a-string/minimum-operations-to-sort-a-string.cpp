class Solution {
public:
    int minOperations(string s) {
       
        int n=s.length();
        string t=s;
        sort(t.begin(),t.end());
        if(s==t)return 0;
        if(n<=2)return -1;
        int mia = INT_MAX;
        int mxa = INT_MIN;
        for (char ch : s) {
            mia = min(mia, ch - 'a');
            mxa = max(mxa, ch - 'a');
        }

         if((s[0]-'a')==mia || (s[n-1]-'a')==mxa)return 1;
         for(int i=1;i<n-1;i++){
            if(s[i]-'a'==mia || s[i]-'a'==mxa)return 2;
         }
        
         return 3;
     
    
    }
};