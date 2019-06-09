// brackets, dp, intervals

#include<bits/stdc++.h>
using namespace std;

string s;
string dp[100][100];

string solve(int l, int r) {
    if (l > r) return "";
    if (dp[l][r] != "") return dp[l][r];
    int index = l;
    int ans = 2+solve(l+1, r).size();
    if (s[l]=='(' || s[l]=='[') {
        for (int i = l+1; i <= r; i++) {
            if ((s[l]=='(' && s[i]==')') || (s[l]=='[' && s[i]==']')) {
                int current = 2+solve(l+1,i-1).size()+solve(i+1,r).size();
                if (current < ans) {
                    ans = current;
                    index = i;
                }
            }
        }
    }
    string res;
    if (index == l) {
        if (s[l]==')') res = "()"+solve(l+1,r);
        else if (s[l]==']') res = "[]"+solve(l+1,r);
        else if (s[l]=='(') res = "("+solve(l+1,r)+")";
        else if (s[l]=='[') res = "["+solve(l+1,r)+"]";
    } else {
        res = s[l]+solve(l+1,index-1)+(s[l]=='('?')':']')+solve(index+1,r);
    }

    return dp[l][r]=res;
}

int main() {
    cin >> s;

    string ans = solve(0, s.size()-1);
    cout << ans << endl;

    return 0;
}
