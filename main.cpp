
#include "Header.h"



int main(void) {
    Bst tree;
    char chars = '\0';
    fstream infile;
    infile.open("Convert.txt");
    tree.print();
    while (!infile.eof()) {
        infile >> chars;
        tree.search(chars);

    }
    cout << endl;
    if (infile.is_open()) {
        infile.close();
    }

    return 0;

}