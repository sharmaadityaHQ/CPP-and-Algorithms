// https://www.interviewbit.com/problems/valid-ip-addresses/

bool isValid(string A) {
    if(A.size() > 1 && A[0] == '0') {
        return false;
    }
    else if(stoi(A) <= 255 && stoi(A) >= 0) {
        return true;
    }
    else {
        return false;
    }
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> sol;
    string result = "";
    if(A.size() > 12 || A.size() < 4) {
        return sol;
    }
    for(int i = 1; i < 4; i++) {
        string first = A.substr(0, i);
        if(!isValid(first)) {
            continue;
        }
        for(int j = 1; i + j < A.size() && j < 4; j++) {
            string second = A.substr(i, j);
            if(!isValid(second)) {
                continue;
            }
            for(int k = 1; i + j + k < A.size() && k < 4; k++) {
                string third = A.substr(i + j, k);
                string fourth = A.substr(i + j + k);
                if(isValid(third) && isValid(fourth)) {
                    result = first + "." + second + "." + third + "." + fourth;
                    sol.push_back(result);
                    result = "";
                }
            }
        }
    }
    return sol;
}
