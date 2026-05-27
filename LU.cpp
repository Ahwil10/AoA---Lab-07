#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

// The LU Decomposition Algorithm
void luDecomposition(const vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {
    int n = A.size();

    // Initialize L with 0s and U as a copy of A
    L.assign(n, vector<double>(n, 0.0));
    U = A;

    // Set the main diagonal of L to 1.0
    for (int i = 0; i < n; ++i) {
        L[i][i] = 1.0;
    }

    // Perform Gaussian elimination to build L and U
    for (int k = 0; k < n - 1; ++k) {
        for (int i = k + 1; i < n; ++i) {
            if (U[k][k] == 0) {
                throw runtime_error("Zero pivot encountered.");
            }

            // Calculate the multiplier factor
            double factor = U[i][k] / U[k][k];

            // Store the multiplier in the corresponding position in L
            L[i][k] = factor;

            // Perform row operation on U (Forward Elimination)
            for (int j = k; j < n; ++j) {
                U[i][j] -= factor * U[k][j];
            }
        }
    }
}

// Helper function to print a matrix nicely
void printMatrix(const vector<vector<double>>& mat) {
    for (const auto& row : mat) {
        for (double val : row) {
            cout << setw(8) << setprecision(3) << val << " ";
        }
        cout << "\n";
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

    // Matrices to hold our results
    vector<vector<double>> L, U;

    cout << "Original Matrix A:\n";
    printMatrix(A);

    try {
        // Execute the algorithm
        luDecomposition(A, L, U);

        cout << "Lower Triangular Matrix L:\n";
        printMatrix(L);

        cout << "Upper Triangular Matrix U:\n";
        printMatrix(U);

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
