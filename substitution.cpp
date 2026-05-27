#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// The Backward Substitution Algorithm
vector<double> backwardSubstitution(const vector<vector<double>>& U, const vector<double>& y) {
    int n = U.size();
    vector<double> x(n, 0.0); // This will hold our final variables [x0, x1, x2]

    // Iterate backwards from the last row (n-1) up to the first row (0)
    for (int i = n - 1; i >= 0; --i) {
        double sum_ax = 0.0;

        // Calculate the dot product of the known variables to the right of the diagonal
        for (int j = i + 1; j < n; ++j) {
            sum_ax += U[i][j] * x[j];
        }

        // Solve for the current variable
        x[i] = (y[i] - sum_ax) / U[i][i];
    }

    return x;
}

int main() {
    // We use the Upper Triangular Matrix (U) resulting from Forward Elimination
    vector<vector<double>> U = {
        {2.0, -1.0,  1.0},
        {0.0,  3.0, -3.0},
        {0.0,  0.0,  2.0}
    };

    // We use the modified constants vector (y) resulting from Forward Elimination
    vector<double> y = {8.0, -3.0, 8.0};

    cout << "Solving the Upper Triangular System...\n\n";

    // Execute the algorithm
    vector<double> solution = backwardSubstitution(U, y);

    // Print the results
    cout << "Solution:\n";
    for (int i = 0; i < solution.size(); ++i) {
        // Typically, indices 0, 1, 2 correspond to x, y, z
        cout << "Variable x_" << i << " = " << solution[i] << "\n";
    }

    return 0;
}
