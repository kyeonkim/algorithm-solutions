/*
처음 max 값을 0으로 두고 값을 더해가며 max보다 큰 값이 나오면 교체한다
*/
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max = 0;
        int sum = 0;

        for (int num : gain) {
            sum += num;
            if (sum > max) max = sum;
        }

        return max;
    }
};