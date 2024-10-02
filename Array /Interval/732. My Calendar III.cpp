/*

tc: o(n) worst case 
sc: o(n)
*/

class MyCalendarThree {
    map<int, int> events;

public:
    MyCalendarThree() {
    }

    int book(int startTime, int endTime) {
        // Mark the start of the event
        events[startTime]++;
        // Mark the end of the event
        events[endTime]--;
        
        int ongoingEvents = 0;
        int maxOverlaps = 0;

        // Sweep over all the time points to find the maximum number of ongoing events
        for (auto& event : events) {
            ongoingEvents += event.second;
            maxOverlaps = max(maxOverlaps, ongoingEvents);
        }

        return maxOverlaps;
    }
};
