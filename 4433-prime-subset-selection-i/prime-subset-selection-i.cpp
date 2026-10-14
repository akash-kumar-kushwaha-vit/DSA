class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;

        for (int i = 3; 1LL * i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    vector<int> maxPrimes(int n, int s) {
        
       vector<int>ans;
       priority_queue<int, vector<int>, greater<int>> pq;
       int sum=0;
        for(int i=2;i<=n;i++){
            if(isPrime(i)){
                if( sum+i<=s){
                   pq.push(i);
                    sum+=i;
                }
                if(sum>s){
                  while(sum>s && !pq.empty()){
                    sum-=pq.top();
                    pq.pop();
                  }
                }
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;

    }
};