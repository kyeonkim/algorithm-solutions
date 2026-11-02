/*
Alice와 Bob의 날짜를 365일로 바꿔서 포함된 날짜만 계산해서 반환
바꿀 때 각 월에 day도 미리 더해두면 좋을듯
*/
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startAlice = convertDateToDay(arriveAlice);
        int endAlice = convertDateToDay(leaveAlice);
        int startBob = convertDateToDay(arriveBob);
        int endBob = convertDateToDay(leaveBob);
        int count = 0;

        for (int day = 1; day <= 365; day++) {
            if (day >= startAlice && day <= endAlice && 
                day >= startBob && day <= endBob) {
                count++;
            }
        }

        return count;
    }

    static int convertDateToDay(string date) {
        vector<int> accDays = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        return accDays[month - 1] + day;
    }
};