/*
모든 경로를 #으로 초기화 한 후에 가장 간단하게 이동할 수 있는 계단식(오른쪽 -> 아래쪽) 경로를 만든다
마지막 열까지 도달하면 아래쪽으로 쭉 이동한다
*/
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        int i = 0;
        int j = 0;
        grid[i][j] = '.';

        while (i < m - 1 || j < n - 1) {
            if (i < m - 1) {
                i++;
                grid[i][j] = '.';
            }
            if (j < n - 1) {
                j++;
                grid[i][j] = '.';
            }
        }

        return grid;
    }
};

.  .  . 
#  #  .
#  #  .
#  #  .
#  #  .

.  .  # 
#  .  .
#  #  .
#  #  .
#  #  .