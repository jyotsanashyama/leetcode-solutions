class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int value=nums[0];
        int count=0, index=0;

        for(int i=0;i<nums.size();i++){
            if(value==nums[i]) count++;
            else{
                count=1;
                value=nums[i];
            }
            if(count<=2) nums[index++]=nums[i];
        }

        return index;
    }
};
