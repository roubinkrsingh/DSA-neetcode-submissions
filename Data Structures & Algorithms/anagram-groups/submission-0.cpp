class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>v=strs;
        for(int i=0;i<v.size();i++){
            string a=v[i];
            sort(a.begin(),a.end());
            v[i]=a;
        }

        vector<vector<string>>ans;
        vector<int>visit(v.size(),0);

        for(int i=0;i<v.size();i++){
            if(visit[i]) continue;
            visit[i]=true;
            vector<string>curr_ans;
            curr_ans.push_back(strs[i]);
            for(int j=i+1;j<v.size();j++){
                if(visit[j]==0 && v[i]==v[j]){
                    visit[j]=1;
                    curr_ans.push_back(strs[j]);
                }
            }
            ans.push_back(curr_ans);
        }
        return ans;
    }
};
