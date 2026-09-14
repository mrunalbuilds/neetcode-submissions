class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int l=0;
        sort(nums.begin(), nums.end());
        for (int i=0; i< nums.size()-2; i++){

            if (i>0 && nums[i] == nums[i-1]) // if we have duplicate next to each other we can skip that
                continue;

            int j = i+1, k = nums.size()-1;
            int target = -nums[i];
            while(j<k){
                int sum = nums[j] + nums[k];
                if (sum == target){
                    result.push_back({nums[i], nums[j], nums[k]});

                    while( j<k && nums[j] == nums[j+1])
                        j++;
                    while( j<k && nums[k]== nums[k-1])
                        k--;
                    j++;
                    k--;
                }

                else if(sum < target){
                    j++;
                }else {
                    k--;
                }
            }
        }

        return result;
    }
};
