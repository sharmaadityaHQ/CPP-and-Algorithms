// All factors of a no in O(sqrt(n))

vector<int> Solution::allFactors(int A) {
    vector<int> ret;
    for(int i=1;i<sqrt(A);i++){
        if(A%i==0) 
        ret.push_back(i);
    }
    for(int i=sqrt(A);i>=1;i--){
        if(A%i==0) 
        ret.push_back(A/i);
    }
    return ret;
}
