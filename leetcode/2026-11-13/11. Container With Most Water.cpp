/*
[첫번째 시도 실패: 번갈아가며 계산하면 안됨. maxArea가 끝 2개의 포인터로 존재할 수 있음]
왼쪽, 오른쪽 포인터 2개를 두고 왼쪽 오른쪽 번갈아 좁혀가며 넓이를 계산
맥스값을 두고 현재 계산한 값이 맥스값보다 크면 교체 
높이가 다르다면 작은 높이 * (오른쪽 거리 - 왼쪽 거리)
왼쪽 포인터가 오른쪽 포인터보다 작을 때만 반복

[두번째 시도: 제공되는 힌트 사용]
2개의 포인터를 처음, 끝 높이에서 시작해서 더 낮은 높이 포인터를 이동시킴
낮은 높이 포인터를 이동시키는 이유는 결국 높이를 결정하는건 낮은 높이인데
높은 높이을 움직이면 폭은 줄어드는데 높이는 그대로(낮은 높이를 따라가니까)이므로 무조건 손해를 봄
따라서, 낮은 벽을 이동시켜 높이를 바꿔보며 최적의 컨테이너를 찾아본다
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            int minHeight = min(height[left], height[right]);
            int currentArea = minHeight * (right - left);
            if (maxArea < currentArea) maxArea = currentArea;
            if (height[left] < height[right]) left++;
            else right--;
        }

        return maxArea;
    }
};