class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int maxcount = 0;
        for(int i=0;i<nums.size();i++){
                freq[nums[i]]++;
                maxcount = max(maxcount, freq[nums[i]]);
        }
        //sort on basis of frequency 

        vector<pair<int, int>> arr;

        for (auto &it : freq) {
            arr.push_back(it);   // {number, frequency}
        }
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.second > b.second;   // descending frequency
        });

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(arr[i].first);
        }

        return result;
    }
};
