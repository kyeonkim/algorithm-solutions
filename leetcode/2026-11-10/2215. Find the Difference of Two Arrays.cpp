/*
배열은 find가 O(n)이라 배열끼리 비교하게되면 너무 오래걸림
각 배열을 map으로 만들어서 비교
c++에서는 unordered_set이라는 키만 가지는 자료구조가 존재(중복은 상관없으므로 해당 자료구조 사용)
*/
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s_nums1(nums1.begin(), nums1.end());
        unordered_set<int> s_nums2(nums2.begin(), nums2.end());
        vector<vector<int>> answer(2);

        for (int num : s_nums1) {
            if (!s_nums2.contains(num)) answer[0].push_back(num);
        }
        for (int num : s_nums2) {
            if (!s_nums1.contains(num)) answer[1].push_back(num);
        }

        return answer;
    }
};