// Complete the reverseArray function below.

vector<int> reverseArray(vector<int> a) {
    for(int i = 0, j = a.size() - 1; i <= j ; i++, j--) {
        swap(a[i], a[j]);
    }
    return a;
}