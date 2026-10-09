// With negative values, your current code can fail because in C++:
// -1 % 5
// gives:
// -1
// But mathematically, we usually want the remainder to be in:
// 0 ... k-1


long long divisibleSumPairs(vector<long long> arr, int n, int k)
{
    unordered_map<long long, long long> mp;

    mp[0] = 1;

    long long count = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        long long rem = ((sum % k) + k) % k;

        count += mp[rem];

        mp[rem]++;
    }

    return count;
}