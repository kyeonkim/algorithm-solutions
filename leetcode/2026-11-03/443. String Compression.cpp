/*
문자열을 하나 만든다
start와 end 포인터를 만든다
chars 문자열을 순회하며 start에 해당하는 문자를 먼저 생성한 문자열에 추가한다
end 포인터를 통해 start 문자와 같지 않는 문자나 배열에 끝에 도달할 때까지 인덱스를 증가시킨다
end - start 값이 1보다 크다면 문자열 뒤에 end - start 값을 추가한다
이렇게 얻은 문자열 길이만큼 순회하며 chars 배열에 각 인덱스의 값을 바꾸고 얻은 문자열 길이를 반환한다
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        string str = "";
        int start = 0, end = 0;

        while(start < chars.size()) {
            str += chars[start];
            while (end < chars.size() && chars[start] == chars[end]) end++;
            if (end - start > 1) str += to_string(end - start);
            start = end;
        }
        for (int i = 0; i < str.size(); i++) {
            chars[i] = str[i];
        }

        return str.size();
    }
};