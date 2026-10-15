class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int v[101]={0};
            int d=0;
            for(int j=i;j<nums.size();j++){
                if(v[nums[j]]==0){
                    d++;
                }
                v[nums[j]]++;
                sum+=(d*d);
            }
        }
        return sum;
    }
};