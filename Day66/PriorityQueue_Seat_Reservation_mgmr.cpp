class SeatManager {
public:

    //setting up minimum priority queue
    priority_queue<int, vector<int>, greater<int>> seats;

    SeatManager(int n) {

        //adding seat number into priority queue
        for(int i=1;i<=n;i++)
        {
            seats.push(i);
        }
    }
    
    int reserve() {
        //get minimum element from priority queue
        int minSeatNumber = seats.top();
        seats.pop();
        return minSeatNumber;
    }
    
    void unreserve(int seatNumber) {
        //unreverse the given Seatnumber and push it into Priority Queue
        seats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
