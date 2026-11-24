/*
조건값이 작으니 이중반복문으로 돌리고
prod, gcd, lcm 전부 누적값을 이용해서 길이를 구하면 될듯
*/
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxLength = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            unsigned long p = 1;
            int g = 0;
            int l = 1;
            for (int j = i; j < nums.size(); j++) {
                p *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                if (p == g * l) maxLength = max(maxLength, j - i + 1);
            }
        }

        return maxLength;
    }
};