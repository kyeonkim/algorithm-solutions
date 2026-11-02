/*
투 포인터를 이용
반복문을 통해 left와 right 둘 다 vowel일 때까지 포인터를 이동
둘 다 vowel인데 left가 right보다 작으면 swap
left가 right보다 크거나 같아질때가지 반복
*/
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while(left < right && vowels.find(tolower(s[left])) == vowels.end()) left++;
            while(left < right && vowels.find(tolower(s[right])) == vowels.end()) right--;
            if (left < right) swap(s[left], s[right]);
            left++;
            right--;
        }

        return s;
    }
};