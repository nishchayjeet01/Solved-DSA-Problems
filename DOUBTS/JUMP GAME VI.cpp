class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int score=nums[0];
        int len=nums.size();
        int i;
        int temp;
        while(i < len){
            for(int j=i+1;j<k;j++){
                temp=max(nums[j],nums[j+1]);
            }
            score+=temp;
            i=nums[temp];
        }
        return score;
    }
};