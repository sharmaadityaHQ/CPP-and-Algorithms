// Solve Tower of Hanoi problem using recursion

// Print the moves to move all the plates from source to destination pole using helper pole

// For n disks, 2^(n - 1) moves are required

// Design the function - solve() moves the plates from source to destination, 1 at a time
// First move n - 1 plates from source to helper pole
// Then move nth plate from source to destination
// Then move n - 1 plates from helper pole to destination pole

void solve(int source, int destination, int helper, int n) {
    if(n == 1) {
        cout<<"Move plate 1 from "<<source<<" to "<<destination;
        return;
    }
    solve(source, helper, destination, n - 1);
    cout<<"Move plate "<<n<<" from "<<source<<" to "<<destination;
    solve(helper, destination, source, n - 1);
}