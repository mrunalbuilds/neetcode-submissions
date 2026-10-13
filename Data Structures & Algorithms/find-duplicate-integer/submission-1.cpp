class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //have 2 pointers
        //one will be slow pointer and other will be fast

        //first we will find the starting point of cycle
        //for that we will iterate using value of arrays taking them as indices
        //if keep looping both the pointers will meet at one point since duplicates
        //will point to same number eventually
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Find the intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find the duplicate
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
