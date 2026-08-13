class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        
        int i = 0;
        int j = n - 1;
        int count = 0;
        
        while (i <= j) {
            // If the lightest and heaviest can share, move the lightest pointer
            if (people[i] + people[j] <= limit) {
                i++;
            }
            
            // The heaviest person ALWAYS gets on a boat (either alone or shared)
            j--;
            
            // One boat was dispatched
            count++;
        }
        
        return count;
    }
};