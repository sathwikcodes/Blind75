class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int available = 0;
        double total = 0;
        for(auto& customer : customers){
            int arrival = customer[0];
            int t = customer[1];
            available = max(available,arrival) + t;
            total += available - arrival;
        }
        return (double) total/ customers.size();

    }
};


/*  Example case [[1,2],[2,5],[4,3]]
    available = 0
    total = 0
    first iteration : 
    arrival = 1;
    t = 2;
    available = 1 + 2 = 3;
    total = 0 + 3 - 1 = 2

    SECOND ITERATION 
    arrival = 2;
    t = 5;
    available = 3 + 5 = 8
    total  = 2  + 8 - 2 = 8
*/