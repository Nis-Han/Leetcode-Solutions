class Solution {
public:
    vector<int> findErrorNums(vector<int>& a) {
        int n = a.size();

        vector<int> cnt(n+1, 0);

        vector<int> v(2);
        for(auto i : a){
            cnt[i]++;
            if(cnt[i] == 2){
                v[0] = i;
                v[1] = 0;
            }
        }
        v[1] = min_element(cnt.begin()+1, cnt.end()) - cnt.begin();
        return v;
    }
};