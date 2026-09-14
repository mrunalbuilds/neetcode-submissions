class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //store each word with its length in hashmap
        //if the length is same then check if it anagram 
        //otherwise proceed
        unordered_map<string,int> length;
        vector<vector<string>> ans;
        for( int i=0;i<strs.size();i++){
            length[strs[i]] = strs[i].size();
        }

        //iterate throught each string in array and if it present in hashmap 
        //check if it is anagram and add in  vector
        vector<bool> visited(strs.size(), false);

        for (int i = 0; i < strs.size(); i++) {
            if (visited[i]) continue;

            vector<string> group;
            group.push_back(strs[i]);
            visited[i] = true;

            for (int j = i + 1; j < strs.size(); j++) {
                if (!visited[j] &&
                    length[strs[i]] == length[strs[j]] &&
                    isAnagram(strs[i], strs[j])) {

                    group.push_back(strs[j]);
                    visited[j] = true;
                }
            }

            ans.push_back(group);
        }

        return ans;

    }

    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;

        for (char c : s) {
            count[c]++;
        }
        for (char c : t) {
            if (count[c] == 0) {
                return false;
            }
            count[c]--;
        }

        return true;
    }
};
