// https://www.hackerrank.com/challenges/dynamic-array/problem

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> seq(n);
    int lastAnswer = 0;
    vector<int> sol;
    for(int i = 0; i < queries.size(); i++) {
        if(queries[i][0] == 1) {
            seq[(queries[i][1] ^ lastAnswer) % n].push_back(queries[i][2]);
        }
        else {
            lastAnswer = seq[(queries[i][1] ^ lastAnswer) % n]
                            [queries[i][2] % seq[(queries[i][1] ^ lastAnswer) % n].size()];
            sol.push_back(lastAnswer);
        }
    }
    return sol;
}