class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //we can also use stack
        //we will add the time in stack and if time lesser that mean its it forms a fleet
        //we pop that, eventually the size of stakc in number of fleet

        //we will sort the array in descending order or position
        //because 

        vector<pair<int, int>> cars;
        for(int i=0;i<position.size();i++){
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.rbegin(), cars.rend());
        stack<double> st;

        for (auto car : cars) {
            int pos = car.first;
            int spd = car.second;

            double time = (double)(target - pos) / spd;

            if(st.empty() || time > st.top()){
                st.push(time);
            }
        }

        return st.size();
    }
};
