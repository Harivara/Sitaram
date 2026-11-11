// #include <bits/stdc++.h>
// using namespace std;

// void permutationPrint(string ques) {
//     sort(ques.begin(), ques.end());

//     do {
//         cout << ques << " ";
//     } while (next_permutation(ques.begin(), ques.end()));
// }



#include <bits/stdc++.h>
using namespace std;

void fun(int start, string ques) {
    if (start == ques.length()) {
        cout << ques << " ";
        return;
    }

    unordered_set<char> ss;

    for (int i = start; i < ques.length(); i++) {
        if (ss.find(ques[i]) != ss.end()) {
            continue;
        }

        ss.insert(ques[i]);

        swap(ques[i], ques[start]);

        fun(start + 1, ques);

        swap(ques[i], ques[start]);
    }
}

void permutationPrint(string ques) {
    fun(0, ques);
}

int main() {
    string str;
    cin >> str;
    permutationPrint(str);
}