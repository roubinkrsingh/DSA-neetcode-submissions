class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>p_product(n+1),s_product(n+1);
        p_product[0]=nums[0];
        s_product[n-1]=nums[n-1];
        for(int i=1;i<n;i++) p_product[i]=nums[i]*p_product[i-1];
        for(int i=n-2;i>=0;i--) s_product[i]=nums[i]*s_product[i+1];
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(i==0) ans[i]=s_product[i+1];
            else if(i==n-1){
                ans[i]=p_product[i-1];
            }
            else ans[i]=p_product[i-1]*s_product[i+1];
        }
        return ans;

    }
};
