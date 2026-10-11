class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int x:gifts){
            pq.push(x);
        }
        for(int i=0;i<k;i++){
            int x=pq.top();
            pq.pop();
            x= sqrt(x);
            pq.push(x);
        }
        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};