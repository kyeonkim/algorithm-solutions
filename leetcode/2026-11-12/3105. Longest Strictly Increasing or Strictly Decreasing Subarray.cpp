/*
먼저 증가하는거 하나만 고려
이전 값보다 크면 현재 서브 배열 길이를 증가, 현재 서브 길이가 가장 긴 서브배열보다 길면 교체
이전 값보다 작으면 현재 서브 배열 길이를 초기화
배열 끝까지 반복
감소하는 것도 동일하게 반복
*/
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longestArrLen = 1;
        int currentLen = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) currentLen++;
            else currentLen = 1;
            if (currentLen > longestArrLen) longestArrLen = currentLen;
        }
        currentLen = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] < nums[i]) currentLen++;
            else currentLen = 1;
            if (currentLen > longestArrLen) longestArrLen = currentLen;
        }

        return longestArrLen;
    }
};