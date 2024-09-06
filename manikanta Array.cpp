#include <iostream>
#include <vector>

using namespace std;

// Define a class for the Sparse Matrix
class SparseMatrix {
    // Internal structure to store non-zero elements
    struct Element {
        int row, col, value;
    };
    
    // Vector to store the list of non-zero elements
    vector<Element> elements;
    
public:
    // Insert method to add a non-zero element into the sparse matrix
    void insert(int row, int col, int value) {
        if (value != 0) { // Only store non-zero elements
            elements.push_back({row, col, value});
        }
    }
    
    // Method to display the stored non-zero elements in row, column, value format
    void display() {
        cout << "\nSparse Matrix Representation (Row, Column, Value):" << endl;
        cout << "| Row | Column | Value |" << endl;
        cout << "|-----|--------|-------|" << endl;
        for (const auto& elem : elements) {
            cout << "|  " << elem.row << "   |   " << elem.col << "    |   " << elem.value << "   |" << endl;
        }
    }
    
    // Method to display the original matrix (for clarity)
    void displayOriginalMatrix(int totalRows, int totalCols) {
        cout << "\nOriginal Matrix:" << endl;
        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < totalCols; j++) {
                bool found = false;
                for (const auto& elem : elements) {
                    if (elem.row == i && elem.col == j) {
                        cout << elem.value << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int rows, cols;
    
    // Get the dimensions of the matrix from the user
    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    // Create an instance of SparseMatrix
    SparseMatrix sparseMatrix;
    
    // Manually enter the values into the matrix
    cout << "\nEnter the values of the matrix (row by row):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int value;
            cout << "Enter value for position (" << i << ", " << j << "): ";
            cin >> value;
            sparseMatrix.insert(i, j, value);  // Insert only non-zero elements
        }
    }

    // Display the sparse matrix representation
    sparseMatrix.display();
    
    // Display the original matrix for comparison
    sparseMatrix.displayOriginalMatrix(rows, cols);

    return 0;
}