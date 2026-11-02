/*
1. 두 문자열의 길이를 구한다
2. 짧은 쪽 길이에서 시작해 1까지 거꾸로 내려간다
3. 길이가 두 문자열 길이를 모두 나누는지 본다 아니면 다음 길이로 넘어간다
4. 첫 번째 문자열 앞에서 그 길이만큼 잘라 기준 문자열로 삼는다
5. 두 문자열이 각각 그 기준 문자열의 반복인지 본다
6. 둘 다 맞으면 기준 문자열을 답으로 돌려준다
7. 끝까지 찾지 못하면 빈 문자열을 돌려준다

AI 도움 받음(문제 유형): 
- 이름에 나와있는대로 gcd 문제인데 구현 방법이 20분동안 떠오르지 않음
- gcd와 같이 수학적인 방법을 이용하는 문제가 아직 익숙하지 않음
*/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        for (int len = min(n, m); len >= 1; len--) {
            if (n % len != 0 || m % len != 0) continue;
            string gcdStr = str1.substr(0, len);
            bool isOk = true;
            for (int i = 0; i < n; i += len) {
                if (str1.substr(i, len) != gcdStr) isOk = false;
            }
            for (int i = 0; i < m; i += len) {
                if (str2.substr(i, len) != gcdStr) isOk = false;
            }
            if (isOk) return gcdStr;
        }

        return "";      
    }
};