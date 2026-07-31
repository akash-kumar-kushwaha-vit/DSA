class Solution {
public:
    int minimumPushes(string word) {
       unordered_map<char,int>m;
       for(char x:word)m[x]++;
       priority_queue<int>q;
       for(auto x:m){
        q.push(x.second);
       }
      int ans=0;
      int i=1;
      int x=1;
       while(!q.empty()){
          ans+=(q.top()*x);
          q.pop();
          if(i%8==0)x++;
          i++;
       }
       return ans;
    }
};