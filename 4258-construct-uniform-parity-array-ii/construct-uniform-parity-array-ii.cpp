class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        priority_queue<int, vector<int>, greater<int>>meven;
        priority_queue<int, vector<int>, greater<int>>modd;
        for(int x:nums1){
            if(x%2==0){
                meven.push(x);
            }else{
                modd.push(x);
            }
        }
        if(meven.size()==modd.size()){
            if(meven.empty() || modd.empty())return true;
            else if(modd.top()>meven.top())return false;
            else return true;
        }
        else{
            if(meven.empty() || modd.empty())return true;
            else if(modd.top()>meven.top())return false;
            else return true;
        }


    }
};