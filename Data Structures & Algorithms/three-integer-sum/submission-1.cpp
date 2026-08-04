class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                if((nums[j]+nums[k])==-1*nums[i]){
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if((nums[j]+nums[k])>-1*nums[i]){
                    k--;
                }
                else j++;
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};
