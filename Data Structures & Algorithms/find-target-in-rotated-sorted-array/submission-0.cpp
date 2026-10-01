class Solution {
public:
    int binary(int l,int r,vector<int>&nums,int target){
        if(l<0||r<0) return -1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]) l=mid+1;
            else r=mid;
        }
        int x=binary(l,n-1,nums,target);
        int y=binary(0,l-1,nums,target);
        if(x!=-1) return x;
        if(y!=-1) return y;
        return -1;
        
    }
};
