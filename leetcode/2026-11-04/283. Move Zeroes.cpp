/*
[기본]
가장 먼저 떠오르는 방식은 이중루프
i, j로 돌며 i가 0인 경우에 j가 0이 아닌 값과 스위치한다
10^4라 통과는 될 듯
우선 이걸로 해결해보기

[심화 - 더 최적화 시켜보기]
굳이 이중루프문을 사용하지 않아도 됨
0이 아닌걸 앞으로 옮기다보면 0은 자연스럽게 뒤로 감
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};