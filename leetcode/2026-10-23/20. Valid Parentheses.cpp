/*
예전에 프로그래머스에서 풀었던 문제와 비슷한 문제, 괄호가 많아졌으므로 해시맵과 스택을 활용할 예정
1. 해시맵을 활용해 올바른 괄호를 짝지어둠
2. 각 괄호의 여는 괄호가 나오면 스택에 추가함
3. 각 괄호의 닫히는 괄호가 나오면 맵을 통해 올바른 괄호값을 가져오고 스택 top이 해당 괄호인지 확인
4. 해당 괄호가 아니라면 false를 반환, 맞다면 스택 pop
5. 주어진 string을 끝까지 돌렸는데 스택이 비어있다면 true 반환
*/
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> vStack;

        for (char& ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') vStack.push(ch);
            else {
                if (vStack.empty()) return false;
                if (vStack.top() != brackets[ch]) return false;
                vStack.pop();
            }
        }

        return vStack.empty() ? true : false;
    }
};