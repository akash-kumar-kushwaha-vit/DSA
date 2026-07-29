class Solution {
public:
    bool f(vector<int>& nums,int i,int n,unordered_set<int>&s){
        if(i>=n-1)return true;
        if(s.count(i))return false;
        s.insert(i);
        for(int c=1;c<=nums[i];c++){
            if(f(nums,i+c,n,s))return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        unordered_set<int>s;
        return f(nums,0,nums.size(),s);
    }
};