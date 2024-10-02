/*
using vector

tc: o(n)
sc: o(n)
*/

class MyCalendarTwo {
private:
    vector<pair<int,int>> doubleBookings;
    vector<pair<int,int>> totalBookings;

    bool checkRegion(int a1, int b1, int a2, int b2){
        return max(a1, a2) < min(b1, b2);
    }

    pair<int,int> doubleBookingRegion(int a1, int b1, int a2, int b2){
        return {max(a1, a2), min(b1, b2)};
    }
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(pair<int,int> booking: doubleBookings){
            if(checkRegion(booking.first, booking.second, start, end)){
                return false;
            }
        }

        for(pair<int,int> booking: totalBookings){
            if(checkRegion(booking.first, booking.second, start, end)){
                doubleBookings.push_back(doubleBookingRegion(booking.first, booking.second, start, end));
            }
        }
        totalBookings.push_back({start, end});
        return true;

    }
};