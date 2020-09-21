// https://www.hackerrank.com/challenges/array-left-rotation/problem

vector<int> rotateLeft(int d, vector<int> arr) {
    int n = arr.size();
    // d = d % n;
    for(int i = 0; i < d; i++) {
        int temp = arr[0], j; 
        for (j = 0; j < n - 1; j++) 
            arr[j] = arr[j + 1]; 
  
        arr[j] = temp; 
    }
    return arr;
}