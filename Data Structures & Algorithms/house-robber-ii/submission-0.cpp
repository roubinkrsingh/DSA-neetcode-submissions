class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>firstdp(n,0);
        vector<int>seconddp(n,0);
        firstdp[0]=nums[0];
        for(int i=1;i<n;i++){
            if(i==1){
                firstdp[i]=max(firstdp[i-1],nums[i]);
                seconddp[i]=nums[i];
            }
            else if(i==2){
                firstdp[i]=max(firstdp[i-1],nums[i]+firstdp[i-2]);
                seconddp[i]=max(seconddp[i-1],nums[i]);
            }
            else if(i==n-1){
                seconddp[i]=max(seconddp[i-1],nums[i]+seconddp[i-2]);
            }
            else{
                firstdp[i]=max(firstdp[i-1],nums[i]+firstdp[i-2]);
                seconddp[i]=max(seconddp[i-1],nums[i]+seconddp[i-2]);
            }
        }
        if(n==1) return nums[0];
        return max(firstdp[n-2],seconddp[n-1]);
    }
};
