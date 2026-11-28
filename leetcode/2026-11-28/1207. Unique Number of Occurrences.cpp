/*
우선 해시맵을 이용해서 값을 카운트함
카운트한 해시맵을 순회하며 값만 해시셋에 추가
추가 시 중복된 값이 있다면 false를 반환
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> num_counts;
        unordered_set<int> unique_count;

        for (int num : arr) num_counts[num]++;
        for (pair<int, int> num_count : num_counts) {
            if (unique_count.contains(num_count.second)) return false;
            unique_count.insert(num_count.second);
        }

        return true;
    }
};