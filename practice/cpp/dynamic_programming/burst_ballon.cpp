// problem: https://leetcode.com/problems/burst-balloons/
int maxCoins(vector<int>& nums) {
    return maxCoinsR(nums, 0, nums.size()-1);
}
    
int maxCoinsR(vector<int> nums, int b, int e)
{
    if (b > e) return 0;
    if (b == e) return nums[b];
        
    int coin;
    int res = 0;
    for (int i = b; i <= e; i++) {
        int l = (i == b ? 1 : nums[i-1]);
        int r = (i == e ? 1 : nums[i+1]);
        coin = l * r * nums[i];
        res =  max(res, coin + maxCoinsR(nums, b, i-1) + maxCoinsR(nums, i+1, e));
    }
    return res;
}

int compareVersion(string version1, string version2) {
    int p1 = version1.find('.');
    string v1 = version1.substr(0, p1);
    while (v1.length() != 0 && v1[0] == '0')
    {
        v1.erase(0,1);
    }

    version1 = (p1 != string::npos ? version1.substr(p1+1) : "");

    int p2 = version2.find('.');
    string v2 = version2.substr(0, p1);
    while (v2.length() != 0 && v2[0] == '0')
    {
        v2.erase(0,1);
    }
    version2 = (p2 != string::npos ? version2.substr(p2+1) : "");

    @
        if (v1.length() == 0 && v2.length() == 0) {
            return version1.length() > version2.length();
        } else if (v1.length() != 0 && v2.length() == 0) {
            return 1;
        } else if (v1.length() == 0 && v2.length() != 0) {
            return -1;
        }

    // comparing
    for (int i = 0; i < min(v1.length(), v2.length()); i++) {
        if (v1[i] >  v2[i]) {
            return 1;
        } else if (v1[i] < v2[i]) {
            return -1;
        }
    }

    if (v1.length() > v2.length()) {
        return 1;
    } else if (v1.length() < v2.length()) {
        return -1;
    }

    if (version1.length() > version2.length()) {
        for (int i = 0; i < version1.length(); i++) {
            if (version1[i] != '0' && version1[i] != '.') {
                return 1;
            }
        }
    } else if (version1.length() < version2.length()) {
        for (int i = 0; i < version2.length(); i++) {
            if (version2[i] != '0' && version2[i] != '.') {
                return -1;
            }
        }          
    }
    return 0;
}
