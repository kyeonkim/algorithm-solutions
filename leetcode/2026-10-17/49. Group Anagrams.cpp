/*
1. 맵을 하나 만들어서 각 문자열의 정렬된 문자열을 키로 두고 비교한 뒤 같으면 값에 추가한다
2. 추가한 맵을 하나로 만들어서 반환한다
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups;
        string word;

        for (string str : strs) {
            word = str;
            sort(word.begin(), word.end());
            groups[word].push_back(str);
        }
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }

        return result;
    }

};