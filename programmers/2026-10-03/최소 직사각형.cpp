/*
1. sizes 배열을 순회하며 가로, 세로 길이를 비교하여 큰 값을 가로, 작은 값을 세로에 둔다
2. 가로 중 가장 큰 값과 세로 중 가장 큰 값을 찾은 뒤 명함 지갑을 만든다
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxHorizontal = 0;
    int maxVertical = 0;
    int horizontal, vertical;
    
    for (vector<int>& size : sizes) {
        if (size[0] < size[1]) {
            swap(size[0], size[1]);
        }
    }
    for (vector<int>& size : sizes) {
        horizontal = size[0]; vertical = size[1];
        if (horizontal > maxHorizontal) maxHorizontal = horizontal;
        if (vertical > maxVertical) maxVertical = vertical;
    }
    
    return maxHorizontal * maxVertical;
}