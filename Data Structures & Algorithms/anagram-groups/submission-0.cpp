// Use std::array so the map can compare and store the keys
typedef array<int, 26> Alphabet; 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<Alphabet, vector<string>> anagramMap;
        vector<vector<string>> result;

        for (const string &str : strs) {
            Alphabet bitmap = {0};
            for (char c : str) {
                bitmap[c - 'a']++;
            }

            anagramMap[bitmap].push_back(str);
        }

        for (auto const& [key, group] : anagramMap) {
            result.push_back(group);
        }

        return result;
    }
};
