// https://www.hackerrank.com/challenges/sparse-arrays/problem

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<int> results;
    for(int i = 0; i < queries.size(); i++) {
        int count = 0;
        for(int j = 0; j < strings.size(); j++) {
            if(queries[i] == strings[j]) {
                count++;
            }
        }
        results.push_back(count);
    }
    return results;
}