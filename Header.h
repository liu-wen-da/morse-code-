
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstring>
using namespace std;

class BstNode {
public:
    BstNode();
    ~BstNode();
    BstNode(char cha, char* str);
    void chr(const char cha);
    void str(char* const str);
    void left(BstNode* const pleft);
    void right(BstNode* const pright);
    char chr() const;
    string string() const;
    BstNode*& left();
    BstNode*& right();

private:
    char chara;
    char strings[100];
    BstNode* pLeft;
    BstNode* pRight;
};


class Bst {
public:
    Bst();
    ~Bst();
    void sethead(BstNode* const newhead);
    BstNode* gethead() const;
    void insert(const char newc, char* const newstr);
    string search(char cha);
    void print();

private:
    BstNode* makeNode(const char newc, char* const newstr);
    void insert(BstNode*& newNode, const char cha, char* const str);
    string search(BstNode* tree, char cha);
    BstNode* pHead;
    fstream MorseTable;
};