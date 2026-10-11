class Solution {
public:
    int isvalid(string s, vector<int>&v,int len,int m){
        vector<int>curr(52);
        for(int i=0;i<len;i++){
            if(s[i]>='a' && s[i]<='z') curr[s[i]-'a']++;
            else curr[(s[i]-'A')+26]++;
        }
        bool flag1=true;
        for(int j=0;j<52;j++){
            if(curr[j]>=v[j]) continue;
            flag1=false;
        }
        if(flag1) return len-1;
        for(int i=len;i<m;i++){
            if(s[i]>='a' && s[i]<='z') curr[s[i]-'a']++;
            else curr[(s[i]-'A')+26]++;
            if(s[i-len]>='a' && s[i-len]<='z') curr[s[i-len]-'a']--;
            else curr[(s[i-len]-'A')+26]--;
            bool flag=true;
            for(int j=0;j<52;j++){
                if(curr[j]>=v[j]) continue;
                flag=false;
            }
            if(flag) return i;
        }
        return -1;
    }
    string minWindow(string s, string t) {
        int n=t.size();
        int m=s.size();
        vector<int>v(52);
        for(int i=0;i<n;i++){
            if(t[i]>='a' && t[i]<='z') v[t[i]-'a']++;
            else v[(t[i]-'A')+26]++;
        }
        int l=0,r=m,mid=0;
        int start=-1,end=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            int x=isvalid(s,v,mid,m);
            if(x!=-1){
                end=x;
                start=x-mid+1;
                r=mid-1;
            }
            else l=mid+1;
        }
        if(start==-1) return "";
        string ans;
        cout<<start<<" "<<end<<" ";
        for(int i=start;i<=end;i++) ans.push_back(s[i]);
        return ans;
    }
};
