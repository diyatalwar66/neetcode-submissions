/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.empty()) return true;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int prevEnd;

        for(const auto& i : intervals){
            pq.push({i.start, i.end});
        }

        if(!pq.empty()) prevEnd = pq.top().second; pq.pop();

        while(!pq.empty()){
            if(prevEnd > pq.top().first) return false;
            prevEnd = max(prevEnd, pq.top().second);
            pq.pop();
        }

        return true;
    }
};
