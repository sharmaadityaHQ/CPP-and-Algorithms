// https://www.interviewbit.com/problems/merge-overlapping-intervals/

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
bool mycomp(Interval x, Interval y)  
{ 
    return (x.start < y.start); 
}  
  
vector<Interval> Solution::merge(vector<Interval> &A) {
    int n = A.size();
    sort(A.begin(), A.end() , mycomp);  
    int index = 0;
    for (int i=1; i<n; i++)  
    {  
        if (A[index].end >=  A[i].start)  
        {  
            A[index].end = max(A[index].end, A[i].end);  
            A[index].start = min(A[index].start, A[i].start);  
        }  
        else { 
            index++; 
            A[index] = A[i];  
        }     
    }
    vector<Interval> B;
    for(int i = 0; i<= index; i++){
        B.push_back(A[i]);
    }
  return B;
}
