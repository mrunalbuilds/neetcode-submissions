class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //sorting
        //have sorted string as key and group it

        // eg: tea, tan, eat, nat
        // aet - tea, eat
        // ant - tan

        unordered_map<string, vector<string>> res;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            res[s].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (auto& pair : res) {
            result.push_back(pair.second);
        }

        return result;
        
    }
};
