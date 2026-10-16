class Solution {
public:
    static bool comp(Interval& a, Interval& b) {
        return a.start < b.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();

        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), comp);

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto it : intervals) {
            if (!pq.empty() && pq.top() <= it.start) {
                pq.pop();
            }

            pq.push(it.end);
        }

        return pq.size();
    }
};