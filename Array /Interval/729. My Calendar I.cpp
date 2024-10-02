/*
using vector

tc: o(n)
sc: o(n)
*/
class MyCalendar {
public:
    vector<pair<int,int>> booking;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(int i=0; i<booking.size(); i++){
            if(!(booking[i].first >= end || start >= booking[i].second)){
                return false;
            }
        }
        booking.push_back({start, end});
        return true;
    }
};

/*
using unordered_map

*/
class MyCalendar {
unordered_map<int, int>bookings;

public:
    MyCalendar() {
        
    }
    
    bool book(int s1, int e1) {
        for(auto& [s2, e2] : bookings) 
            if( !(s1 >= e2 || s2 >= e1) )   // if neither of above condition is satisfied, there exists an intersection
			    return false; 
        bookings[s1] = e1;                 // no intersection found, so insert the new slot and return true
        return true;
    }
};

/*
using set and upper_bound

tc: o(logn)
sc: o(n)

*/
class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // find the first event that start after or st the same time of {start, end}
        auto it = st.lower_bound({start, end});

        // check if the current event overlaps with the next event 
        if(it != st.end() && it->first < end){
            return false;
        }

        // check if the current overlaps with the previous event 
        if(it != st.begin()){
            auto prevIt = prev(it);
            if(start < prevIt->second){
                return false;
            }
        }
        st.insert({start, end});
        return true;
    }
};
