class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;
        int ans=0;
        vector<int>start_index;
        for(int i=0;i<n;i++){
            if(mp.count(nums[i]-1)) continue;
            start_index.push_back(nums[i]);
        }
        for(int i=0;i<start_index.size();i++){
            int x=start_index[i];
            int curr_ans=0;
            while(mp.count(x)){
                curr_ans++;
                x++;
            }
            ans=max(ans,curr_ans);
        }
        return ans;
    }
};
