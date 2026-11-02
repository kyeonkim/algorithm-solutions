/*
1. n에서 lost 사이즈를 뺀다 -> 확정적으로 체육 수업을 들을 수 있는 학생 수
2. lost 배열과 reserve 배열들의 값을 키로 가지고 false를 값으로 가지는 map을 각각 만든다
    2-1. lost map : 내가 체육복이 있는 상태인지 확인
    2-2. reserve map : 여분의 체육복을 빌려준 상태인지 확인
3. lost가 정렬되어 있다는 보장이 없으니 한번 정렬해준다
4. lost 배열을 순회하며 자기 자신이 여분의 체육복이 있다면 해당 번호의 값들을 true로 바꾸고 학생 수를 +1 한다
5. lost를 배열을 순회하며 생성한 reserve map에 다음과 같은 조건으로 검색한다
    5-1. -1, +1 번호가 있는 경우, 해당 번호의 값들을 true로 바꾸고 학생 수를 +1 한다
    5-2. 자기 번호와 앞뒤 번호가 없는 경우, 다음 학생으로 넘어간다.
---
1. 첫번째 시도 실패: lost가 정렬되어 있다는 보장이 없음 (TC: 5, [4, 2], [3, 5], 기대값: 5)
2. 두번째 시도 실패: 여분의 체육복이 있는데 자기 자신이 잃어버린 경우에는 다른 학생에게 빌려줄 수 없으므로 빌려주기 전에 검사해야함(TC: 5, [2, 3], [3, 4], 기대값 4)
3. 세번째 시도 실패: 자기 자신이 잃어버리고 여분의 체육복이 있는데 다른 학생한테 또 빌림...(TC: 2번과 동일)
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    unordered_map<int, bool> hasGymClothes, reserveStatus;
    
    for (int& lostNum : lost) hasGymClothes[lostNum] = false;
    for (int& reserveNum : reserve) reserveStatus[reserveNum] = false;
    sort(lost.begin(), lost.end());
    for (int& lostNum : lost) {
        if (reserveStatus.contains(lostNum) && reserveStatus[lostNum] == false && hasGymClothes[lostNum] == false) {
            hasGymClothes[lostNum] = true;
            reserveStatus[lostNum] = true;
            answer++;
        }
    }
    for (int& lostNum : lost) {
        if (reserveStatus.contains(lostNum - 1) && reserveStatus[lostNum - 1] == false && hasGymClothes[lostNum] == false) {
            hasGymClothes[lostNum] = true;
            reserveStatus[lostNum - 1] = true;
            answer++;
        }
        else if (reserveStatus.contains(lostNum + 1) && reserveStatus[lostNum + 1] == false && hasGymClothes[lostNum] == false) {
            hasGymClothes[lostNum] = true;
            reserveStatus[lostNum + 1] = true;
            answer++;
        }
    }
    
    return answer;
}