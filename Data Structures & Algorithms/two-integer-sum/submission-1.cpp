class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];
            //check if diff is there in mp
            if(mp.find(diff) != mp.end() && mp[diff] != i){
                return {mp[diff], i};
            }
            mp.insert({nums[i],i});
        }
        return {};
    }
};
