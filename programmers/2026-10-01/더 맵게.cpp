/*
1. 최소 힙을 이용하여 우선순위 큐(priority_queue)를 생성한다
2. scoville 배열을 순회하며 생성한 우선순위 큐에 삽입한다
3. 우선순위 큐의 top이 K보다 크거나 같은지 확인한다
    3-1. 크거나 같을 경우, answer를 리턴한다
    3-2. 작을 경우, answer를 1 증가시키고 pop을 2번하여 '특별한 방법(문제에서 제시한)'으로 계산하여 우선순위 큐에 다시 삽입한다
4. 우선순위 큐의 사이즈가 1일 때까지 반복한다
5. 우선순위 큐의 사이즈가 1인데 top이 K보다 작다면 -1을 반환하고 크다면 answer를 반환한다
---
ref: 우선순위 큐(https://learn.microsoft.com/ko-kr/cpp/standard-library/priority-queue-class?view=msvc-170)
*/
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int firstMinValue, secondMinValue;
    priority_queue <int, vector<int>, greater<int>> pq;
    
    for (int& score : scoville) {
        pq.push(score);
    }
    while (pq.size() != 1) {
        if (pq.top() >= K) {
            return answer;
        }
        answer++;
        firstMinValue = pq.top();
        pq.pop();
        secondMinValue = pq.top();
        pq.pop();
        pq.push(firstMinValue + secondMinValue * 2);
    }
    
    return pq.top() >= K ? answer : -1; // 실패한 코드: return -1;
}

priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());