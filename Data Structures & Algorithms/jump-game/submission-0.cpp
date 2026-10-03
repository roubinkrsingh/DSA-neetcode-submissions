class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int prev=n-1;
        for(int i=n-2;i>=0;i--){
            int idx=prev-i;
            if(nums[i]>=idx){
                prev=i;
            }
        }
        if(prev==0) return true;
        return false;
    }
};
