class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
                ans++;
            }
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                ans++;
                r++;
                l--;
            }
        }
        return ans;
        
    }
};
