class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0,x=31;
        for(int i=0;i<32;i++){
            if(n &(1ll<<i)){
                ans|=(1ll<<(x-i));
            }
        }
        return ans;
    }
};
