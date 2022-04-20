
#include "Header.h"

BstNode::BstNode()
{
    BstNode(chara, strings);
}
BstNode::BstNode(char cha, char* str)
{
    strcpy(strings, str);
    chara = cha;
    pLeft = nullptr;
    pRight = nullptr;
}
BstNode::~BstNode()
{
    cout << " ";
}
void BstNode::chr(const char cha)
{
    chara = cha;
}
void BstNode::str(char* const str)
{
    strcpy(strings, str);
}
void BstNode::left(BstNode* const pleft)
{
    pLeft = pleft;
}
void BstNode::right(BstNode* const pright)
{
    pRight = pright;
}
char BstNode::chr() const
{
    return this->chara;
}
string BstNode::string() const
{
    return this->strings;
}
BstNode*& BstNode::left()
{
    return this->pLeft;
}
BstNode*& BstNode::right()
{
    return this->pRight;
}


Bst::Bst()
{
    char cha = '\0';
    char str[100] = " ";
    pHead = nullptr;
    MorseTable.open("MorseTable.txt");
    while (!MorseTable.eof()) {
        MorseTable >> cha;
        MorseTable.getline(str, 100);
        insert(cha, str);
    }
}
Bst::~Bst()
{
    if (MorseTable.is_open())
    {
        MorseTable.close();
    }
    
}
void Bst::sethead(BstNode* const newhead)
{
    pHead = newhead;
}
BstNode* Bst::gethead() const
{
    return pHead;
}
void Bst::insert(const char newcha, char* const newstr)
{
    insert(pHead, newcha, newstr);
}
string Bst::search(char cha)
{
    string Str;
    Str = search(pHead, cha);
    return Str;
}
void Bst::print() 
{
    cout << "This is a test of the cpts 122" << endl << "Morse code conversion tool" << endl;
}

BstNode* Bst::makeNode(const char newcha, char* const newstr)
{
    BstNode* node = new BstNode(newcha, newstr);
    return node;
}
void Bst::insert(BstNode*& newNode, const char cha, char* const str)
{
    if (newNode == nullptr) {
        BstNode* pMem = new BstNode(cha, str);
        newNode = pMem;
    }
    else {
        if ((cha < newNode->chr())) {
            insert((newNode)->left(), cha, str);
        }
        else if (cha > newNode->chr()) {
            insert((newNode)->right(), cha, str);
        }
    }
}
string Bst::search(BstNode* tree, char cha)
{
    string Str;
    if (tree != nullptr) {
        search(tree->left(), cha);
        search(tree->right(), cha);
        if (tree->chr() == cha) {
            Str = tree->string();
            cout << tree->string();
        }
    }
    return Str;
}