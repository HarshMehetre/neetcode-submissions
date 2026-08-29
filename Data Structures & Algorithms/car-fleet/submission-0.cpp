class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n==0) return 0;
        
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        int fleetCount = 0;
        double maxTime = 0.0;

        for (int i = 0; i < n; i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;

            if (time > maxTime) {
                fleetCount++;
                maxTime = time;
            }
        }
        return fleetCount;
    }
};
