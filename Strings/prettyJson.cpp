// https://www.interviewbit.com/problems/pretty-json/

vector<string> Solution::prettyJSON(string A) {
    string s = A;
    vector<string> ans;
    string temp = "";
    int tabs = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            continue;
        }
        else if(s[i] == '{' || s[i] == '[') {
            if(temp != "") {
                ans.push_back(temp);
            }
            temp = "";
            for(int j=0; j < tabs; j++) {
                temp += "\t";
            }
            temp += s[i];
            ans.push_back(temp);
            temp = "";
            tabs++;
        }
        else if(s[i] == '}' || s[i] == ']') {
            if(temp != "") {
                ans.push_back(temp);
            }
            temp = "";
            for(int j=0; j < tabs - 1; j++) {
                temp += "\t";
            }
            temp += s[i];
            if(i < s.length() && s[i+1] == ',') {
                ++i;
                temp += s[i];
            }
            ans.push_back(temp);
            temp = "";
            tabs--;
        }
        else {
            if(temp == "") {
                for(int j=0; j < tabs; j++) {
                    temp += "\t";
                }
            }
            temp += s[i];
            if(s[i] == ',') {
                ans.push_back(temp);
                temp = "";
            }
        }
    }
    return ans;
}
