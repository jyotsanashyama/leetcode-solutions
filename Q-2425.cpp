class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;

    ///any time element appears even times, it got cancel out

    ///step1: xor all elememt of nums1 and nums2 separately
    int xor1=0, xor2=0;

    for(int i=0;i<nums1.size();i++){
        xor1^=nums1[i];
    }
    for(int i=0;i<nums2.size();i++){
        xor2^=nums2[i];
    }

    ///step2: if number size is even it automatically gets cancel out, so chooseing odd length
    int result=0;
    if(nums2.size()%2!=0){
        result^=xor1;
    }
    if(nums1.size()%2!=0){
        result^=xor2;
    }

    return result;
    }

/*
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                nums3.push_back(nums1[i]^nums2[j]);
            }
        }

        long long int ans=nums3[0]^nums3[1];
        for(int i=2;i<nums3.size();i++){
            ans^=nums3[i];
        }

        return ans;
    }

    */
};