class Solution {
public:
    vector<int> hashh;
    int strHash(string s){
        hashh.clear();
        hashh.resize(26, 0);
        for(auto i :s){
            if(hashh[i-'a'])return 0;
            hashh[i-'a']++;
        }
        int res = 0;
        int mul = 1;
        for(auto i : hashh){
            if(i)res += mul;
            mul*=2;
        }
        return res;
    }

    int joinHash(int a, int b){
        if(a&b)return 0;
        return (a | b);
    }

    int SZ(int a){
        return __builtin_popcount(a);
    }

    int maxLength(vector<string>& a) {
        unordered_map<int, int> mp;
        int ans = 0;

        for(auto i : a){
            auto hashh = strHash(i);
            if(!hashh)continue;

            mp[hashh] = 1;
            int sz = SZ(hashh);

            vector<int> hashCache;
            for(auto j : mp){
                int joinedHash = joinHash(hashh, j.first);
                int joinedSZ = SZ(joinedHash);
                if(joinedSZ){
                    sz = max(sz, joinedSZ);
                    hashCache.push_back(joinedHash);
                }
            }
            for(auto j : hashCache)mp[j] = 1;
            ans = max(ans, sz);
        }
        return ans;
    }
};