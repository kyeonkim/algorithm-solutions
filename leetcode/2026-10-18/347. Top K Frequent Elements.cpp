/*
수를 세고 저장하기 좋은건 가장 먼저 맵이 떠오름
1. 맵을 하나 만들어 nums의 값을 키로 두고 나올 때마다 하나씩 센다
2. 값을 기준으로 내림차순 정렬을 한 뒤 상위 k개의 키를 배열로 만들어 반환한다
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> numCount;
        vector<pair<int, int>> sortValueNumCount;
        vector<int> result;

        for (int& num : nums) {
            numCount[num] += 1;
        }
        for (pair<int, int> num : numCount) {
            sortValueNumCount.push_back(num);
        }
        sort(sortValueNumCount.begin(), sortValueNumCount.end(), compare);
        for (int i = 0; i < sortValueNumCount.size() && i < k; i++) {
            result.push_back(sortValueNumCount[i].first);
        }

        return result;
    }

    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};