/*
가장 먼저 떠오른 방식은 문자열 배열을 만들어 문자열 s를 단어 단위로 끊어서 저장한 뒤 reverse 후에 다시 문자열을 만드는것
다만, 문제에서 요구한 것 중에 내가 푸는 언어에서 string 타입이 mutable 하다면 새로운 공간을 만들지말고 풀어보라고해서 다른 방법 고민

흠...ex3에서 a와 example을 바꾼다고 했을 때 good이 바꿀 자리에 존재함...이걸 어떻게 해결할까

(10분 고민...)

먼저 필요없는 space들(연속적인 space)을 삭제함. space는 단어 사이에 1개만 존재
문자열 s를 reverse 시킴
리버스된 문자열 s에서 단어마다 시작점과 끝점을 찾아 해당 인덱스를 기준으로 다시 리버스함
큰 리버스 1번 작은 리버스 여러번으로 리버스가 된 word 문자열을 얻을 수 있음
이건 맞을듯

먼저 공백을 지워야 함
처음엔 erase로 지우는 방식을 생각했지만 erase의 동작은 원소를 하나씩 왼쪽으로 당겨오는거임
즉, 원소를 하나 없애려고 할 때마다 O(n)의 시간복잡도를 가짐. 10^4 정도면 가능할 거 같긴한데 그 이상 늘어나면 time limit 뜰 거 같은 비효율적인 방법이라 기각.

(10분 고민...)

erase로 지우는 방식이 아니라 앞에서부터 덮어쓰면서 연속적인 space가 나오지 않도록 당겨옴
문자열을 당겨온 후에 resize로 뒷부분을 날려버리면 빠르면서 불필요한 space가 없는 문자열을 가질 수 있음
*/
class Solution {
public:
    string reverseWords(string s) {
        // 1. 공백 지우기
        int write = 0;

        for (int read = 0; read < s.size(); read++) {
            if (s[read] != ' ') {
                s[write] = s[read];
                write++;
            }
            else if (write > 0 && s[write - 1] != ' ') {
                s[write] = ' ';
                write++;
            }
        }
        if (write > 0 && s[write - 1] == ' ') write--;
        s.resize(write);
        // 2. 올바른 문자열을 얻음. 이제 큰 리버스 후 작은 리버스
        reverse(s.begin(), s.end());
        int len = s.size();
        int start = 0;

        while(start < len) {
            int end = start;
            while (end < len && s[end] != ' ') end++;
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }

        return s;
    }
};