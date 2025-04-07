#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <cctype>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int len = 2 * n;
    vector<int> result(n);
    vector<int> match(len, -1);
    stack<int> st;

    for (int i = 0; i < len; ++i) {
        if (st.empty()) {
            st.push(i);
        }
        else {
            int j = st.top();
            char a = s[i], b = s[j];
            if (toupper(a) == toupper(b) && isupper(a) != isupper(b)) {
                match[i] = j;
                match[j] = i;
                st.pop();
            }
            else {
                st.push(i);
            }
        }
    }

    if (!st.empty()) {
        cout << "Impossible\n";
        return 0;
    }

    int hunter_id = 0, ghost_id = 0;
    vector<int> hunter_num(len), ghost_num(len);

    for (int i = 0; i < len; ++i) {
        if (isupper(s[i])) hunter_num[i] = hunter_id++;
        else ghost_num[i] = ghost_id++;
    }

    for (int i = 0; i < len; ++i) {
        if (isupper(s[i])) {
            int j = match[i];
            result[hunter_num[i]] = ghost_num[j] + 1;
        }
    }

    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
