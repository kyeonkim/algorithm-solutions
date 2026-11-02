/*
1. 더 긴 문자열을 찾는다
2. 번갈아가며 결과에 한 문자씩 추가한다
3. 문자열 끝에 도달하면 추가하지 않는다
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int logestLength = max(word1.size(), word2.size());
        string result;

        for (int i = 0; i < logestLength; i++) {
            if (i < word1.size()) result += word1[i];
            if (i < word2.size()) result += word2[i];
        }

        return result;
    }
};