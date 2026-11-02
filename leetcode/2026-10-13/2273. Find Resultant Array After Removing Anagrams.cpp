/*
(gpt가 추천해준 문제인데 투포인터로 예상하고 진행)
1. 인접한 단어를 비교할 두 개의 포인터를 만든다
2. words[i]와 words[j]가 다를 경우, j에 있던 값을 결과값에 추가하고 j 값을 i로 바꾼다
3. i와 j가 Anagram인 경우, 삭제되었다고 보고 i만 증가시킨다
4. words 배열 끝까지 반복한다

Anagram은 어떻게 판별하지?
1. 비교할 2개의 word를 복사 후 정렬 진행
2. 서로 같은지 비교
*/
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;

        result.push_back(words[0]);
        for (int i=1, j=0; i < words.size(); i++) {
            if (!isAnagram(words[j], words[i])) {
                result.push_back(words[i]);
                j = i;
            }
        }

        return result;
    }

    bool isAnagram(string str1, string str2) {
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        return str1 == str2;
    }
};