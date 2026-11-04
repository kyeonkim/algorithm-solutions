/*
[기본]
가장 먼저 떠오르는 방식은 이중루프
i, j로 돌며 i가 0인 경우에 j가 0이 아닌 값과 스위치한다
10^4라 통과는 될 듯
우선 이걸로 해결해보기

[심화]
더 최적화 시켜보기
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == 0 && nums[j] != 0) swap(nums[i], nums[j]);
            }
        }
    }
};