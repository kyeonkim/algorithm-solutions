/*
고민하다가 topics까지 보고 품
백트래킹 문제인데 재귀로 모든 경우의 수에 접근
여는 괄호를 추가할 수 있는 조건: open < n 
닫는 괄호를 추가할 수 있는 조건: close < open
재귀가 끝나는 조건: open == n && close == n
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtracking("(", 1, 0, n, result);
        return result;
    }

    static void backtracking(string str, int open, int close, int n, vector<string>& result) {
        if (open == n && close == n) {
            result.push_back(str); 
            return;
        }
        if (open < n) {
            backtracking(str + "(", open + 1, close, n, result);
        }
        if (close < open) {
            backtracking(str + ")", open, close + 1, n, result);
        }
    }
};