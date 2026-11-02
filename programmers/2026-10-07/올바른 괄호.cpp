/*
1. 스택 하나 생성
2. s를 순회하며 '(' 문자를 만나면 스택에 넣고 ')' 문자를 만나면 스택이 비어있는지 비어있지 않다면 top이 '('인지 확인
3. '(' 문자라면 스택에서 pop 진행, 아니라면 push 진행
4. 스택 사이즈가 empty가 아니라면 false 나머지는 true
*/
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack <char>  bracketStack;

    for (char ch : s) {
        if (ch == '(') bracketStack.push(ch);
        if (ch == ')') {
            if (bracketStack.empty()) bracketStack.push(ch);
            else if (bracketStack.top() == '(') bracketStack.pop();
            else bracketStack.push(ch);
        }
    }
    
    return bracketStack.empty() ? true : false;
}