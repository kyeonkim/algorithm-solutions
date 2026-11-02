/*
처음과 끝에서만 한쪽 방향만 검사 후 심음
중간은 양 옆 검사 후 심음
주어진 배열의 수를 바꿔가며 검사해도 괜찮을 듯
flowerbed의 사이즈가 1인 경우가 애매함 따로 처리하자
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0 && n > 0) n--;
            return n == 0 ? true : false;
        }
        for (int i = 0; i < flowerbed.size() && n != 0; i++) {
            if (flowerbed[i] == 1) continue;
            if (i == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
            if (i == flowerbed.size() - 1 && flowerbed[i - 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
            if (i > 0 && i < flowerbed.size() - 1 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0 ? true : false;
    }
};

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;

        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {

                flowerbed[i] = 1;
                n--;
            }

            if (n == 0) return true;
        }

        return false;
    }
};