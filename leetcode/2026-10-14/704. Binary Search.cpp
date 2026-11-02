/*
1. 문제명에도 나와있듯이 이분탐색 문제
2. 배열의 왼쪽이나 오른쪽을 줄여가며 해당 배열의 중앙값이 target인지 비교한다
3. 왼쪽과 오른쪽이 같은 인덱스를 바라보는데도 target이 없다면 -1을 반환한다
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};