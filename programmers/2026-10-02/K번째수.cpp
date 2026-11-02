/*
0. command를 저장할 i, j, k 변수 생성
1. commands 배열을 순회하며 i, j, k 변수에 값을 넣는다
2. 원본 array 배열을 건드리지 않으며 i, j에 맞게 slice 해온다
3. slice한 배열을 오름차순으로 정렬한 뒤 k번째 값을 가져와 answer에 push한다
---
ref
1. sort(https://en.cppreference.com/cpp/algorithm/sort)
2. slice(https://agandi.tistory.com/22)
*/

#include <string>
#include <vector>
#include <algorithm>
// #include <iostream>

using namespace std;
vector<int> custom_slice(const vector<int>& array, int start, int end);

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> sliceArray;
    int i, j, k;
    
    for (vector<int>& command : commands) {
        i = command[0]; j = command[1]; k = command[2];
        sliceArray = custom_slice(array, i, j);
        sort(sliceArray.begin(), sliceArray.end());
        answer.push_back(sliceArray[k - 1]);
    }
    
    return answer;
}

vector<int> custom_slice(const vector<int>& array, int start, int end) {
    return vector<int>(array.begin() + start - 1, array.begin() + end);
}