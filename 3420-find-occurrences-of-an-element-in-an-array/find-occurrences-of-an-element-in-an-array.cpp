class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x)temp.push_back(i);
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i]>temp.size()){
              queries[i]=-1;
            }else{
                queries[i]=temp[queries[i]-1];
            }
        }
        return queries;
    }
};