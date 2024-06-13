class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ///xor of array
        ///leftmost 1st set bit
        ///1<<index (bit masking)
        ///loop array , xor1=0; xor2=0
        ///xor1-> set bit ; xor2-> unset bit

        ///step1: xor the whole array
        int ans1=0;
        for(int i=0;i<nums.size();i++){
            ans1=ans1^nums[i];
        }

        ///step2: finding the first set bit index
        int index;
        for(int i=0;i<32;i++){
            int mask=1<<i;
            if((ans1 & mask)!=0){
                index=i;   ///set index
                break;
            }
        }


        ///step3: putting set and unset in diff place and xor them
        int xor1=0,xor2=0;
        int mask=1<<index;   ///putting 1 to that indedx using masking
        for(int i=0;i<nums.size();i++){

            if((nums[i] & mask)!=0){
                xor1=xor1^nums[i];  ///set bits
            }else{
                xor2=xor2^nums[i];  ///unset bits
            }
        }

        vector<int> ans={xor1,xor2};
        return ans;
    }



};
