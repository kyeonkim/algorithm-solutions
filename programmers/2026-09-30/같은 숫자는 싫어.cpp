/*
0. 이전값을 저장할 변수 준비
1. 배열에 있는 값을 순회하며 다음과 같은 조건으로 answer 배열에 추가한다
    1-1. 이전값과 같을 경우, 다음값으로 넘어간다
    1-2. 이전값과 다를 경우, answer 배열에 추가 후 이전값을 교체한다
*/

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int preferValue = -1;

    for (int& value : arr) {
        if (value != preferValue) {
            answer.push_back(value);
            preferValue = value;
        }
    }

    return answer;
}