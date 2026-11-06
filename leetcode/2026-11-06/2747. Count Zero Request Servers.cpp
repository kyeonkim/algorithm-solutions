/*
처음엔 이중루프를 생각했는데 제약 조건을 보니 이중루프로 풀면 10^5 * 10^5 = 10^10임...너무 큼. 이 방법으로 풀지 말라고 말해주는 제약조건. 다른 방법 고민...

(20분 고민했으나 효율적인 방법이 떠오르지 않음, AI에게 힌트 받음)

[힌트]
- "받지 않은"을 "전체 − 받은"으로
- 구간이 단조롭게 움직인다는 걸 보고, logs와 queries를 정렬해 슬라이딩 윈도우로 바꾸기
- queries를 정렬하게되면 인덱스가 깨지니 인덱스는 미리 저장

queries를 먼저 (값, 인덱스)로 묶은 배열을 만듬
queries로 만든 배열을 오름차순으로 정렬, logs도 time을 오름차순으로 정렬
queries로 만든 배열을 순회하며 left와 right 포인터를 통해 요청을 받은 서버수를 카운트함
카운트한 서버수를 결과값에 n - 받은 서버수를 묶어둔 인덱스에 넣음
정렬되어있으므로 한 방향으로만 순회하면서 요청을 받는 서버를 확인할 수 있음
*/
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int, int>> p_queries;
        
        for (int i = 0; i < queries.size(); i++) p_queries.push_back({queries[i], i});
        sort(p_queries.begin(), p_queries.end());
        sort(logs.begin(), logs.end(), 
            [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1];});
        
        vector<int> result(queries.size());
        vector<int> count(n + 1);
        int left = 0, right = 0;
        int active_servers = 0;

        for (pair<int, int> p_query : p_queries) {
            int idx = p_query.second;
            int query = p_query.first;
            while (right < logs.size() && logs[right][1] <= query) {
                int server_id = logs[right][0];
                count[server_id]++;
                if (count[server_id] == 1) active_servers++;
                right++;
            }
            while (left < right && logs[left][1] < query - x) {
                int server_id = logs[left][0];
                count[server_id]--;
                if (count[server_id] == 0) active_servers--;
                left++;
            }
            result[idx] = n - active_servers;
        }

        return result;
    }
};