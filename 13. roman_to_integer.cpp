class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> um;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        int i = 0;
        int ans = 0;
        while(i < s.size())
        {
            if(s[i] == 'I' && s[i+1] == 'V'){
                ans += 4;
                i = i+2;
            }
            else if(s[i] == 'I' && s[i+1] == 'X'){
                ans +=9;
                i = i+2;
            }
            else if(s[i] == 'X' && s[i+1] == 'L'){
                ans += 40;
                i = i+2;
            }
            else if(s[i] == 'X' && s[i+1] == 'C'){
                ans += 90;
                i = i+2;
            }
            else if(s[i] == 'C' && s[i+1] == 'D'){
                ans += 400;
                i = i+2;
            }
            else if(s[i] == 'C' && s[i+1] == 'M'){
                ans += 900;
                i = i+2;
            }
            else {
                ans += um[s[i++]];
            }
        }
        return ans;
    }
};