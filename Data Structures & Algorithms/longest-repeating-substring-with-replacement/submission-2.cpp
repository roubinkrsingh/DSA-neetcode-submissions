class Solution {
public:
    bool isvalid(string s,int k,int mid){
        unordered_map<char,int>ump;
        for(int i=0;i<mid;i++) ump[s[i]]++;
        for(auto it:ump){
            if(it.second>=(mid-k)) return true;
        }
        for(int i=mid;i<s.size();i++){
            ump[s[i-mid]]--;
            if(!ump.count(s[i-mid])) ump.erase(s[i-mid]);
            ump[s[i]]++;
            for(auto it:ump){
                if(it.second>=(mid-k)) return true;
            }
        }
        return false;
    }
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=1,r=n,mid=0,ans=1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(isvalid(s,k,mid)){
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
