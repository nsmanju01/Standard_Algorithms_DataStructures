class Solution {
public:
    // the following code checks for the word which can translated to the existing word in the dictionary.
    bool check(string s,string temp)
    {
        int i;
        int j=0;
        for(int i=0 ; i <s.size();)
        {
            while(s[i] == temp[j] && i < s.size() && j < temp.size())
            {
                i++;
                j++;
            }
            if (j == temp.size())
                return true;
            i++;
        }
        return false;
    }
    string findLongestWord(string s, vector<string>& d) {
        vector<pair<string,int>>map;
        // sort the the input dictionary to obtain the output in lexicographical order.
        sort(d.begin(),d.end());
        int max_val = INT_MIN;
        // iterate over all the items in the dictionary to identify the possible words and store their lengths along with the word itself.
        // also make a note the maximum value to avoid the run time.
        for(auto e:d)
        {
            if (check(s,e))
            {
                map.push_back(make_pair(e,e.size()));
                max_val = max(max_val,int(e.size()));
            }
        }
        if (max_val == INT_MIN )
            return "";
        // return the first string with the max_Val to obtain the output in the lexicographical order
        for(auto e:map)
        {
            if (e.second == max_val)
                return e.first;
        }
        
    }
};