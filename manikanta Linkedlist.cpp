#include <iostream>
using namespace std;

// Node class representing each element in the sparse matrix
class Node {
public:
    int row, col, value;
    Node* next; // Address of the next node

    Node(int r, int c, int val) {
        row = r;
        col = c;
        value = val;
        next = nullptr; // Initially, no next node
    }
};

// SparseMatrix class to manage the linked list of the sparse matrix
class SparseMatrix {
private:
    Node* head; // Head of the linked list

public:
    SparseMatrix() {
        head = nullptr; // Initially, the list is empty
    }

    // Method to insert a new element into the sparse matrix
    void insert(int row, int col, int value) {
        if (value == 0) return; // Only non-zero values are stored

        Node* newNode = new Node(row, col, value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next; // Traverse to the end of the list
            }
            temp->next = newNode; // Insert the new node at the end
        }

        // Display the details of the node just inserted
        cout << "Inserted node at (Row: " << row << ", Column: " << col << ") with Value: " << value << "\n";
        cout << "Current Node Address: " << newNode << ", Next Node Address: " << newNode->next << "\n";
    }

    // Method to display the sparse matrix as a linked list
    void display() {
        if (head == nullptr) {
            cout << "The sparse matrix is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "\nSparse Matrix Linked List Representation:\n";
        while (temp != nullptr) {
            cout << "Row: " << temp->row << ", Column: " << temp->col << ", Value: " << temp->value
                 << ", Current Node Address: " << temp << ", Next Node Address: " << temp->next << endl;
            temp = temp->next; // Move to the next node
        }
    }
};

// Main function to interact with the user
int main() {
    SparseMatrix sparseMatrix;
    int rows, cols, value;

    cout << "Sparse Matrix Linked List Implementation\n";
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Allow the user to input matrix values
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter value for element at (" << i << "," << j << "): ";
            cin >> value;
            sparseMatrix.insert(i, j, value); // Insert the element if non-zero
        }
    }

    // Display the sparse matrix linked list representation
    sparseMatrix.display();

    return 0;
}




