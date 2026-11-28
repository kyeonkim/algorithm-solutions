/*
먼저 다 더해서 rightSum 이라는 변수에 저장해둠
leftSum은 0부터 시작
인덱스 0부터 시작하는데 leftSum은 비교 후 누적하고 rightSum은 먼저 차감해서 비교
같다면 해당 인덱스 반환
같지 않다면 반복 진행
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = 0;

        for (int num : nums) rightSum += num;

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        
        return -1;
    }
};