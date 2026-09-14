class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //instead of sorting and adding that as key
        //use array of 26 characters to count the frequent and add it as key
        //can be only used if all lower case
        //eg: (1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0) → [tan]

        // we can also have frequency hashmap instead of 26 char array

        vector<unordered_map<char, int>> arr;
        vector<vector<string>> result;

        // iterate through strs, check arr vector if satisfies hashmap, if it doesn't add it in vector and if it does 
        // add it in result
        for(auto &s: strs){
            unordered_map<char, int> mp;
            for(char c: s)
                mp[c]++;
            bool found = false;
            for(int i=0;i<arr.size();i++){
                if(arr[i] == mp){
                    result[i].push_back(s);
                    found = true;
                    break;
                }
            }

            if(found == false){
                arr.push_back(mp);
                result.push_back({s});
            }
        }

        return result;
    }
};
