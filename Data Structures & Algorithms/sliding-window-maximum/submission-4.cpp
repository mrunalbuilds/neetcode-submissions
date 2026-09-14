class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //we store maximum with its index
        //we increment l and r for each window and check if 
        //the number of index is inside window
        //and while incrementing r and check max comparing with previous max

        //unordered_map<int,int> max_heap;
        int r = 0;
        vector<int> result;
        int max = INT_MIN;
        int index = 0;

        for (int l = 0; l + k <= nums.size(); l++) {

            // Previous maximum went out of the window
            if (index < l) {
                max = nums[l];
                index = l;

                //Recalculate max for the current window
                for (int i = l; i < r; i++) {
                    if (nums[i] > max) {
                        max = nums[i];
                        index = i;
                    }
                }
            }

            // Add new elements using r
            while (r < nums.size()) {

                if (nums[r] > max) {
                    max = nums[r];
                    index = r;
                }

                r++;

                // Current window has k elements
                if (r - l == k)
                    break;
            }

            result.push_back(max);
        }

        return result;
    }
};
