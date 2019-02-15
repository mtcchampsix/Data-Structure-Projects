#include "main.h"

int main(int argc, const char * argv[]) {
    ifstream inputFile;
    inputFile.open(argv[1]);
    
    BST Bst;
    AVLTree AVL;
    int value;
    
    if (!inputFile){
        cout << "Input file not valid. " << endl;
        return -1;
    }
    
    while (inputFile){
        inputFile >> value;
        Bst.insert(value);
        AVL.insert(value);
    }
    Bst.display();
    AVL.display();
    cin.clear();
    cin.ignore(1);
    
    while (inputFile){
        inputFile >> value;
        Bst.remove(value);
        Bst.display();
        AVL.remove(value);
        AVL.display();
    }
    
    cout << "Comparisons for BST Tree: " << Bst.BSTcomparisons() << endl;
    cout << "Comparisons for AVL Tree: " << AVL.AVLComparisons() << endl;
    if (Bst.BSTcomparisons() < AVL.AVLComparisons()){
        cout << "BST Tree is more efficient than AVL Tree." << endl;
    } else if (AVL.AVLComparisons() < Bst.BSTcomparisons()) {
        cout << "AVL Tree is more efficient than BST tree." << endl;
    }
    
    
    return 0;
}

