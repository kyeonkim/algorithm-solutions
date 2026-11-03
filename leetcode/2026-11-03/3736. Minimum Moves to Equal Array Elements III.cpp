/*
어제 풀었던 문제의 쉬운버전. 왜 3인데 1보다 쉬운걸까..? 이걸 1로 만들었으면 더 좋았을텐데
최대값을 찾고 최대값 - 현재값의 sum을 반환하면 될 듯
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int sum = 0;

        for (int num : nums) {
            sum += max - num;
        }

        return sum;
    }
};