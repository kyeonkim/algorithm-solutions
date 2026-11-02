/*
가장 먼저 떠오르는건 삼중 반복문. 하지만 문제에서 요구하는 시간 복잡도는 O(n) 이므로 기각

(20분 고민했지만 딱히 방법이 떠오르지 않음. AI에게 힌트 달라고 함)

nums를 순회하며 그때그때 i, j, k를 갱신해주면 됨
예를 들어, i는 첫번째 원소부터 시작하면서 자기보다 작은 값이 나오면 교체
j는 i보다 크면 교체 마지막으로 k가 j보다 크면 triplet이 존재함으로 true 반환

i, j, k로 쓰면 인덱스와 헷갈리니 first, second, x로 작성
즉, x 값이 second보다 크면 true 반환
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        
        for (int x : nums) {
            if (x <= first) first = x;
            else if (x <= second) second = x;
            else return true;
        }

        return false;
    }
};