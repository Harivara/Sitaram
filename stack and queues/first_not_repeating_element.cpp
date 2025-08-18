// string Solution::solve(string A) {
//     unordered_map<char, int> mp;
//     queue<char> qe;
//     string B = "";

//     for (char ch : A) {
//         mp[ch]++;
//         if (mp[ch] == 1) {
//             qe.push(ch);
//         }

//         while (!qe.empty() && mp[qe.front()] > 1) {
//             qe.pop();
//         }

//         B += qe.empty() ? '#' : qe.front();
//     }

//     return B;
// }