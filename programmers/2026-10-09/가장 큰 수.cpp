/*
1. 정수 배열을 문자열 배열로 만든다
2. 문자열 비교 함수를 새로 만든다
3. 정렬 시 문자열 새로 만든 비교 함수를 통해 비교해 정렬한다
4. 앞에 0이 오는 경우를 처리한다
5. 결과를 반환한다
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(string& num1, string& num2);

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNumbers;
    
    for (int& number : numbers) {
        strNumbers.push_back(to_string(number));
    }
    sort(strNumbers.begin(), strNumbers.end(), compare);
    if (strNumbers[0] == "0") return "0";
    for (string& strNumber : strNumbers) {
        answer += strNumber;
    }
    
    return answer;
}

bool compare(string& num1, string& num2) {
    return num1 + num2 > num2 + num1;
}