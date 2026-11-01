/*
1. 0을 제외하고 전체곱을 구한다. 0은 따로 카운트한다
2. 0이 2개 이상이라면 모든 값이 0이 되고 0이 1개라면 0일때만 sum 값을 넣는다
3. 나머지는 sum / num으로 계산한다
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1;
        int zeroCount = 0;
        vector<int> result;

        for (int& num : nums) {
            if (num != 0) sum *= num;
            else zeroCount++;
        }
        for (int& num : nums) {
            if (num == 0 && zeroCount == 1) result.push_back(sum);
            else if (zeroCount > 0) result.push_back(0);
            else result.push_back(sum / num);
        }

        return result;
    }
};