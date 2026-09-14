class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //sort the time we calculate 
        //iterate from back and compare [i] > lastTime then fleet++
        vector<pair<int, double>> cars;

        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.rbegin(), cars.rend());

        int fleet = 0;
        double lastTime = 0;

        for (auto& car : cars){
            if(car.second > lastTime){
                fleet++;
                lastTime = car.second;
            }
        }

        return fleet;
    }
};
