/*
1. 중복없이 빠르게 찾기위해 unordered_set을 생성해서 원소들을 옮겨담는다
2. 배열의 시작점인 num - 1이 존재하지 않는 원소를 찾는다
3. 찾으면 num + 1을 하며 다음 원소들이 존재하는지 찾는다
4. 있다면 현재 길이를 증가시킨다
5. 현재 길이가 이전 길이 결과값보다 길다면 결과값을 바꾼다
6. 시작점이 여러개 존재할 수 있으므로 반복한다
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet;
        int longestLength = 0;
        int currentLength;

        for (int& num : nums) numsSet.insert(num);
        for (const int& num : numsSet) {
            if (numsSet.find(num - 1) == numsSet.end()) {
                currentLength = 1;
                for (int i = 1; numsSet.find(num + i) != numsSet.end(); i++) {
                    currentLength++;
                }
                if (longestLength < currentLength) {
                    longestLength = currentLength;
                }
            }
        }

        return longestLength;
    }
};