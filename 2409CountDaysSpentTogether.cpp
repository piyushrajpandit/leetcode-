
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> month = {31, 28, 31, 30, 31, 30,
                             31, 31, 30, 31, 30, 31};

        int aA_m = 0, lA_m = 0, aB_m = 0, lB_m = 0;
        int aA_d = 0, lA_d = 0, aB_d = 0, lB_d = 0;

        for (int i = 0; i < 2; i++) {
            aA_m = aA_m * 10 + (arriveAlice[i] - '0');
            lA_m = lA_m * 10 + (leaveAlice[i] - '0');
            aB_m = aB_m * 10 + (arriveBob[i] - '0');
            lB_m = lB_m * 10 + (leaveBob[i] - '0');
        }

        for (int i = 3; i < 5; i++) {
            aA_d = aA_d * 10 + (arriveAlice[i] - '0');
            lA_d = lA_d * 10 + (leaveAlice[i] - '0');
            aB_d = aB_d * 10 + (arriveBob[i] - '0');
            lB_d = lB_d * 10 + (leaveBob[i] - '0');
        }

        auto toDays = [&](int m, int d) {
            for (int i = 0; i < m - 1; i++) {
                d += month[i];
            }
            return d;
        };

        int start = max(toDays(aA_m, aA_d),
                        toDays(aB_m, aB_d));

        int end = min(toDays(lA_m, lA_d),
                      toDays(lB_m, lB_d));

        return max(0, end - start + 1);
    }
};
