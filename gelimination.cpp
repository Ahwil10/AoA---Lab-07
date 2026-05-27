#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

// 1. The Forward Elimination Algorithm
void forwardElimination(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();

    // Iterate over each pivot row
    for (int k = 0; k < n - 1; ++k) {
        // Iterate over the rows below the pivot
        for (int i = k + 1; i < n; ++i) {
            if (A[k][k] == 0) {
                throw runtime_error("Zero pivot error");
            }

            double factor = A[i][k] / A[k][k];

            // Eliminate the variable from the current row
            for (int j = k; j < n; ++j) {
                A[i][j] -= factor * A[k][j];
            }
            // Apply the same operation to the constants vector
            b[i] -= factor * b[k];
        }
    }
}

// Helper function to print the augmented matrix [A | b]
void printSystem(const vector<vector<double>>& A, const vector<double>& b) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(8) << setprecision(3) << A[i][j] << " ";
        }
        cout << " | " << setw(8) << setprecision(3) << b[i] << "\n";
    }
    cout << "\n";
}

int main() {
    // Define the coefficient matrix A
    vector<vector<double>> A = {
        {2.0, -1.0,  1.0},
        {4.0,  1.0, -1.0},
        {2.0, -1.0,  3.0}
    };

    // Define the constants vector b
    vector<double> b = {8.0, 13.0, 16.0};

    cout << "Original System [A | b]:\n";
    printSystem(A, b);

    // Execute the algorithm
    try {
        forwardElimination(A, b);

        cout << "Upper Triangular Form:\n";
        printSystem(A, b);

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
