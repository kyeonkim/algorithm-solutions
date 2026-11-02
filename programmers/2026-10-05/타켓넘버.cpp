/*
순서대로 깊게 파고 들어가기에 깊이 우선 탐색(DFS)을 이용
재귀 함수를 이용하여 각 자리마다 더하거나 빼면서 모든 숫자를 다 사용한 값이 target과 일치하는지 비교한다 
> 모든 숫자를 사용한 값이 target과 일치하면 count 증가
> depth가 numbers size와 동일하면 재귀를 종료
*/
#include <string>
#include <vector>

using namespace std;
void dfs(int depth, int cur, int& count, vector<int>& numbers, int& target);

int solution(vector<int> numbers, int target) {
    int count = 0;
    dfs(0, 0, count, numbers, target);
    return count;
}

void dfs(int depth, int cur, int& count, vector<int>& numbers, int& target) {
    if (depth == numbers.size()) {
        if (cur == target) count++;
        return;
    }
    dfs(depth + 1, cur + numbers[depth], count, numbers, target);
    dfs(depth + 1, cur - numbers[depth], count, numbers, target);
}