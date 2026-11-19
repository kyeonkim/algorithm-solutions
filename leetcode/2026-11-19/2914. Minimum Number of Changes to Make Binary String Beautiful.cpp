/*
아름다운 문자열이란 결국 00 또는 11을 이어붙인 문자열임
0000이나 111111도 분해해보면 00 + 00, 11 + 11 + 11로 분해가 가능
문자열 s는 무조건 짝수의 문자열이므로 앞에서부터 2칸씩 10이나 01인 경우를 세면됨
*/
class Solution {
public:
    int minChanges(string s) {
        int change = 0;

        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] != s[i+1]) change++;
        }

        return change;
    }
};