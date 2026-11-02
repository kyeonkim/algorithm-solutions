/*
1. 새로운 해시맵을 생성하여 completion 배열의 값을 키로 두고 값은 이름을 세어 초기화한다
2. participant 배열을 루프하여 생성한 해시맵에 키로 존재하는지 확인한다
    2-1. 존재할 경우: 키의 값을 -1 한다
    2-2. 존재하지 않을 경우: 해당 값을 바로 return 한다
    2-3. 존재하나 값이 0인 경우: 해당 값을 바로 return 한다
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> completionMap;
    
    for (const string& name : completion) {
        completionMap[name]++;
    }
    for (const string& name : participant) {
        if(completionMap.contains(name) && completionMap[name] != 0) {
            completionMap[name]--;
        }
        else {
            return name;
        }
    }
    
    return "";
}