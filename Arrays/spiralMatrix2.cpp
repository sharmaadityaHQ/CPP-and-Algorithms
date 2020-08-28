// https://www.interviewbit.com/problems/spiral-order-matrix-ii/

// track top, bottom, left and right
vector<vector<int>> Solution::generateMatrix(int A) {
    int n = A;
    int t=0,l=0,r=n-1,b=n-1;
    int d=0,count=1;
    vector<vector<int>>a(n,vector<int>(n));
    while(t<=b && l<=r){
        if(d==0){
            for(int i=l;i<=r;i++){
                a[t][i]=count;
                count++;
            }
            d=1;
            t++;
        }
        else if(d==1){
            for(int i=t;i<=b;i++){
                a[i][r]=count;
                count++;
            }
            d=2;
            r--;
        }
        else if(d==2){
            for(int i=r;i>=l;i--){
                a[b][i]=count;
                count++;
            }
            d=3;
            b--;
        }
        else if(d==3){
            for(int i=b;i>=t;i--){
                a[i][l]=count;
                count++;
            }
            d=0;
            l++;
        }
    }
    return a;
}
