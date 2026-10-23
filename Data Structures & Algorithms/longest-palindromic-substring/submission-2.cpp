class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int anslen=1,index=0;
        vector<vector<int>>dp(n+1,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2|| dp[i+1][j-1])){
                    dp[i][j]=1;
                    if(anslen<(j-i+1)){
                        anslen=j-i+1;
                        index=i;
                    }
                }
            }
        }
        return s.substr(index,anslen);
    }
};
