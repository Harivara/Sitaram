bool subarraySum(vector<long long>& arr, long long k)
{
    unordered_set<long long> st;

    st.insert(0);

    long long sum = 0;

    for (int i = 0; i < arr.size(); i++) {

        sum += arr[i];

        // We need an earlier prefix sum = sum - k
        if (st.count(sum - k)) {
            return true;
        }

        st.insert(sum);
    }

    return false;
}



int maxLength(vector<long long>& arr, long long k)
{
    unordered_map<long long, int> mp;

    mp[0] = -1;

    long long sum = 0;
    int maxi = 0;

    for (int i = 0; i < arr.size(); i++) {

        sum += arr[i];

        // Need previous prefix sum = sum - k
        if (mp.find(sum - k) != mp.end()) {
            maxi = max(maxi, i - mp[sum - k]);
        }

        // Store only the FIRST occurrence
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return maxi;
}