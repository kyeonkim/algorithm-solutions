/*
문자열 s의 길이가 k보다 작거나 같을 때까지 반복
먼저 문자열 s를 복사, 문자열 s는 빈값으로 초기화
복사한 문자열을 순회하며 index를 k로 나누었을때 나머지가 0이 되는 순간 문자열 s에 추가를 반복
*/
class Solution {
public:
    string digitSum(string s, int k) {
        string s_copy;

        while (s.size() > k) {
            s_copy = s;
            s = "";
            for (int i = 0, sum = 0; i < s_copy.size(); i++) {
                sum += s_copy[i] - '0';
                if ((i + 1) % k == 0 || (i + 1) == s_copy.size()) {
                    s += to_string(sum);
                    sum = 0;
                }
            }
        }

        return s;
    }
};