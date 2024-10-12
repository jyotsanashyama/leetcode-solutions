class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1); ///create vector and initialize with -1
        return minJump(nums,0,dp);
    }

    int minJump(vector<int>& nums, int pos, vector<int> &dp){
        int n=nums.size();
        ///base case
        if(pos==n-1){
            return 0;
        }

        ///if dp value id not -1,mens we have already updated it, so check that
        if(dp[pos]!=-1){
            return dp[pos];
        }

        ///calculate jump from curr pos
        int jump=INT_MAX;
        int maxJump=min(pos+nums[pos], n-1);

        for(int i=pos+1;i<=maxJump;i++){
            int res=minJump(nums,i,dp);
            if(res!=INT_MAX){
                jump=min(jump,res+1);
            }
        }

        if(jump==INT_MAX){
            dp[pos]=INT_MAX;
        }else{
            dp[pos]=jump;
        }

        return dp[pos];

    }
};
