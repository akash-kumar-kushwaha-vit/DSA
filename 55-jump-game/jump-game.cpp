class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int prev = 0;
        
        for(int i = 0; i < nums.size() - 1; i++)
        {
            int current = max(nums[i], prev - 1);
            
            if(current == 0)
                return false;
            
            prev = current;
        }
        
        return true;
    }
};