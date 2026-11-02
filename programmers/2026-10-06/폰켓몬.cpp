/*
1. nums의 사이즈/2를 폰켓몬을 최대로 가질 수 있는 값으로 둔다
2. set으로 중복을 제거한다
3. 중복을 제거한 배열의 사이즈가 최대값보다 작으면 해당 사이즈를 반환, 크면 최대값을 반환한다
*/
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = nums.size()/2;
    set <int> setNums(nums.begin(), nums.end());
    return setNums.size() < answer ? setNums.size() : answer;
}