class Solution {
public:
    string frequencySort(string s) {
        vector<int> count(256);
        for(auto a:s)
            count[a]++;
        vector<pair<int,char>> arr;
        for(int i=0;i<256;i++)
        {
            if(count[i])
                arr.push_back({count[i],i});
        }
        sort(arr.begin(), arr.end());
        s="";
        for(int i=arr.size()-1;i>=0;--i)
        {
            string temp(arr[i].first,arr[i].second);
            s+=temp;
        }
        return s;
    }
    
};