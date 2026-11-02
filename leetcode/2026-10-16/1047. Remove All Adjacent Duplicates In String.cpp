/*
이전값을 알아야하기에 스택으로 풀면되지만 스택을 바로 string으로 반환할 수 없기에 string을 스택처럼 활용
string에 맨 끝값이 들어오는 값과 같으면 pop_back()
*/
class Solution {
public:
    string removeDuplicates(string s) {
        string result;

        for (char ch : s) {
            if (result.empty()) result.push_back(ch);
            else if (result.back() == ch) result.pop_back();
            else result.push_back(ch);
        }

        return result;
    }
};