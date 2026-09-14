class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums[0];
        for(int i=1; i<nums.size();i++){
            if(nums[i] != n)
                n = nums[i];
            else
                return true;
        }

        return false;
    }
};