/*
1. phone_book을 정렬한다
2. 첫번째 인덱스의 값이 두번째 인덱스에 접두어인 경우가 있는지 확인한다
3. 있으면 false를 반환하고 끝까지 없으면 true를 반환한다
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i + 1].find(phone_book[i]) == 0) return false;
    }
    
    return true;
}