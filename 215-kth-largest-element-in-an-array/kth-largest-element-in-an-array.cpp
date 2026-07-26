class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> mx;
        for(int x:nums){
            mx.push(x);
        }
        for(int i=1;i<k;i++){
            mx.pop();
        }
        return mx.top();
    }
};