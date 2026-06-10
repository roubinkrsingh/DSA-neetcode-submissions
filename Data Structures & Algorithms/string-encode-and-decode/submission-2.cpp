class Solution {
public:
    vector<string>ans;
    string encode(vector<string>& strs) {
        ans=strs;
        if(strs.size()==0) return "";
        string s="";
        for(int i=0;i<strs.size();i++){
            s+=strs[i];
            if(i!=strs.size()-1) s+="-";
        }
        return s;
    }
    vector<string> decode(string s) {
        if(ans.size()==0) return {};
        vector<string>ans;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-'){
                ans.push_back(s.substr(j,i-j));
                j=i+1;
            }
        }
        ans.push_back(s.substr(j));
        return ans;

    }
};
