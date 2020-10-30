// Print all subsets or subsequence or powersets of a string

// Eg. Input - "ab" Output - "", "a", "b", "ab"

void solve(string ip, string op) {
    if(ip.length() == 0) {
        cout<<op<<" ";
        return;
    }
    string op1, op2;
    op1 = op;
    op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
}

int main() {
    string ip;
    cin >> ip;
    string op = "";
    solve(ip, op);
}