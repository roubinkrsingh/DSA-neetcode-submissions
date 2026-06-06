class Solution {
public:
    int getSum(int a, int b) {
        int ans =a^b;
        int carry=(a&b)<<1;
        while(carry){
            int x=ans;
            ans=(ans^carry);
            carry= (x& carry)<<1;
        }
        return ans;
    }
};
