class Solution {
public:
    int reverse(int x) {
        bool flag=false;
        if(x<0) flag=true;
        x=abs(x);
        int len=1,n=x;
        while(x>9){
            len*=10;
            x/=10;
        }
        int ans=0;
        while(n){
            int d=n%10;
            if(d>2 && len==1000000000) return 0;
            n/=10;
            if(flag){
                if((-1*ans)<INT_MIN+(d*len)) return 0;
                else ans+=(d*len);
            }
            else{
                if(ans>INT_MAX-(d*len)) return 0;
                else ans+=(d*len);
            }
            len/=10;
        }
        if(flag) return -1*ans; 
        return ans;
    }
};
