/*
(데일리 문제가 슬라이딩 윈도우 문제였는데 연습을 위해 해당 유형의 쉬운 문제를 힌트 없이 하나 더 풀어봄)

left, right 2개의 포인터를 이용해서 k만큼 계산해 max 값으로 지정함
2개의 포인터를 동시에 한 방향으로 움직이며 left만큼 빼고 right만큼 더해서 다시 계산함
계산한 값이 현재 max값보다 크면 max값을 교체
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0);
        double max = sum / k;
        int left = 0, right = k;

        while (right < nums.size()) {
            sum -= nums[left];
            sum += nums[right];
            if (sum / k > max) max = sum / k;
            left++;
            right++;
        }

        return max;

    }
};