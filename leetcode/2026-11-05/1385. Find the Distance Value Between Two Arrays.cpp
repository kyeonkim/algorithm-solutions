/*
이중 루프와 abs를 사용해서 풀면 될 듯
*/
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        bool isPass;

        for (int i = 0; i < arr1.size(); i++) {
            isPass = true;
            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1[i] - arr2[j]) <= d) isPass = false;
            }
            if (isPass) count++;
        }

        return count;
    }
};