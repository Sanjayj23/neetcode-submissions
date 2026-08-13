class Solution {
public:
    bool isAnagram(string s, string t) {
        int n= s.size();
        int m= t.size();
        if(m!=n) return false;
        vector<int> hash(26, 0);
        for(int i=0; i<n; i++){
            char ch1= s[i];
            char ch2= t[i];
            hash[ch1-'a']++;
            hash[ch2-'a']--;
        }
        for(int i=0; i<26; i++){
            if(hash[i]!=0) return false;
        }
        return true;
    }
};
