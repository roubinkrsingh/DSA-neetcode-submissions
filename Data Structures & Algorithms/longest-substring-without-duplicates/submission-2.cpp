class Solution {
public:
    bool isValid(string &s, int x,int n){
        bool ans=true;
        unordered_map<char,int>mp;
        for(int i=0;i<x;i++) mp[s[i]]++;
        for(auto it:mp){
            if(it.second>=2){
               ans=false;
               break;
            }
        }
        if(ans) return ans;

        for(int i=x;i<n;i++){
            mp[s[i-x]]--;
            mp[s[i]]++;
            bool ans1=true;
            for(auto it:mp){
                if(it.second>=2){
                    ans1 =false;
                    break;
                }
            }
            if(ans1) return ans1;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        int l=1,r=n,ans=1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(s,mid,n)){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
