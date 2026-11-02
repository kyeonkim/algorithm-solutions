/*
1. 현재 시각까지 요청된 작업들을 우선순위 큐에 추가한다.
2. 우선순위 큐에서 소요 시간이 가장 짧은 작업을 꺼낸다.
3. 해당 작업을 완료하고 현재 시각과 반환 시간의 합계를 갱신한다.
4. 모든 작업이 완료될 때까지 반복한다.
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int currentTime = 0;
    int idx = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int s, l;
    
    sort(jobs.begin(), jobs.end());
    // AI에게 도움 받은 부분
    while (idx < jobs.size() || !pq.empty()) {
        while (idx < jobs.size() && jobs[idx][0] <= currentTime) {
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
        }
    // --------------------
        if (!pq.empty()) {
            l = pq.top().first;
            s = pq.top().second;
            pq.pop();
            answer += currentTime + l - s;
            currentTime += l;
        } else {
            currentTime++;
        }
    }
    
    return answer / jobs.size();
}