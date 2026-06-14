class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int left=0,right=n-1;
        while(left<right){
            if(s[left]>='A' && s[left]<='Z') s[left]+=32;
            if(s[right]>='A' && s[right]<='Z') s[right]+=32;
            if((s[left]>='a' && s[left]<='z')||(s[left]>='0'&&s[left]<='9')){
                if((s[right]>='a' && s[right]<='z')||(s[right]>='0'&&s[right]<='9')){
                    if(s[left]!=s[right]) return false;
                    else left++,right--;
                }
                else right--;
            }
            else left++;
        }
        return true;
    }
};
