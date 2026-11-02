/*
1. 오름차순으로 정렬
2. 앞에서부터 순회하며 target과 일치하면 i값을 넣는다
3. result 배열을 만들어서 추가할건데 result 배열이 empty가 아닌데 값이 target과 다를 경우 순회를 종료한다(이미 정렬을 했기에 뒤는 더 볼 필요가 없음)
*/
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (!result.empty() && nums[i] != target) break;
            if (nums[i] == target) result.push_back(i);
        }

        return result;
    }
};