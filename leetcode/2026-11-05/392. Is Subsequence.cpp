/*
left와 right 2개의 포인터를 생성
left는 t에서 동일한 문자가 나올때만 증가
right를 t 길이만큼 순회하거나 left가 s길이보다 작을 때까지만 반복
left와 s가 같으면 true
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left = 0;

        for (int right = 0; left < s.size() && right < t.size(); right++) {
            if (s[left] == t[right]) left++;
        }

        return left == s.size() ? true : false;
    }
};