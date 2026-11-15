/*
스택으로 풀면될 듯
결과값이 string으로 나가야하니 string을 스택처럼 활용
(왜 미디움이지?)
*/
class Solution {
public:
    string removeStars(string s) {
        string result = "";

        for (char ch : s) {
            if (ch == '*' && result != "") result.pop_back();
            else if (ch != '*') result.push_back(ch);
        }

        return result;
    }
};