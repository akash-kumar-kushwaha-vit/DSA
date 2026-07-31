class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>m;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            m[s[i]]=i;
        }
        int maxlen=INT_MIN;
        int j=0;
        for(int i=0;i<s.size();i++){
            maxlen=max(maxlen,m[s[i]]);
            if(i==maxlen){
               ans.push_back(i-j+1);
               j=i+1;
            }
        }
       
       return ans; 
    }
};