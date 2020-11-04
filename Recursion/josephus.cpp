// Josephus problem - https://www.youtube.com/watch?v=ULUNeD0N9yI&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=19

void solve(vector<int> v, int k, int index, int &ans) {
    if(v.size() == 1) {
        ans = v[0];
        return;
    }
    index = (index + k) % v.size();
    v.erase(v.begin() + index);
    solve(v, k, index, ans);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    k--;
    int index = 0;
    int ans = -1;
    solve(v, k, index, ans);
    return ans;
}

