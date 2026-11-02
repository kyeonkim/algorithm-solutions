/*
1. 문자열 왼쪽과 오른쪽을 가리키는 2개의 포인터를 만든다
2. 왼쪽 오른쪽 값을 확인하며 영문자, 숫자가 아니라면 포인터를 이동한다
3. 소문자를 기준으로 비교하여 같지 않다면 false를 반환하고 같다면 true를 반환한다
4. 왼쪽 포인터 사이즈가 오른쪽 포인터 사이즈를 넘길 때까지 반복한다
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            while (left < s.size() && !isalnum(s[left])) left++;
            while (right > -1 && !isalnum(s[right])) right--;
            if (left < right && tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }

        return true;
    }
};