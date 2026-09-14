class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //store array in hashst
        //iterrate through array again and see if num-1 is present
        //if yes then break, otherwise continue

        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }

        int longest = 0;
        for (int num: nums){
            if (st.find(num - 1) == st.end()){
                int count = 1;
                int curr = num;

                while(st.find(curr + 1) != st.end() ){
                    count++;
                    curr++;
                }
                longest = max(count,longest);
            }
            
        }

        return longest;

    }
};
