class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hs1(26, 0);
        vector<int> hs2(26, 0);
        int n1= s1.size();
        int n2= s2.size();
        if(n1>n2) return false;
        for(int i=0; i<s1.size(); i++){
            hs1[s1[i]-'a']++;
        }
        for(int i=0; i<s1.size(); i++){
            hs2[s2[i]-'a']++;
        }
        if(hs1==hs2) return true;
        
        for(int right= n1; right<n2; right++){
                hs2[s2[right-n1]-'a']--;
            hs2[s2[right]-'a']++;
            if(hs1==hs2) return true;
        }
        return false;

    }
};
