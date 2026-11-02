/*
가장 먼저 떠오르는 방법으로 풀어보자

1. 각 수포자 배열을 만든다
2. answers를 기준으로 순회하며 채점한다
3. 각 수포자 배열의 사이즈에 도달할 경우, 0부터 다시 비교할 수 있도록 처리한다
4. 가장 높은 점수를 구한 뒤, 각 점수와 비교하면서 추가한다
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int supoja_counter(vector<int>& answers, vector<int>& supojaAnswer);

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> s1 = {1, 2, 3, 4, 5};
    vector<int> s2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> s3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int count1, count2, count3, maxCount;
    
    count1 = supoja_counter(answers, s1);
    count2 = supoja_counter(answers, s2);
    count3 = supoja_counter(answers, s3);
    maxCount = max({count1, count2, count3});
    if (count1 == maxCount) answer.push_back(1);
    if (count2 == maxCount) answer.push_back(2);
    if (count3 == maxCount) answer.push_back(3);
    
    return answer;
}

int supoja_counter(vector<int>& answers, vector<int>& supojaAnswer) {
    int answerCount = 0;
    
    for (int i=0; i < answers.size(); i++) {
        if (answers[i] == supojaAnswer[i % supojaAnswer.size()]) answerCount++;
    }
    
    return answerCount;
}