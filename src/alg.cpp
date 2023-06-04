// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

bool isLetter(char ch) {
    return ch >= 'a' && ch <= 'z';
}

BST<std::string> makeTree(const char* filename) {
  BST <std::string> tree;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return tree;
  } else {
     while (!file.eof()) {
     std::string temp = "";
     while (true) {
       char c;
       c = file.get();
       if (isLetter(c)) {
         temp += c;
       } else if (c >= 'A' && c <= 'Z') {
           c = tolower(c);
           temp += c;
           } else {
                break;
            }
     }
       tree.add(temp);
       temp.clear();
    }
        file.close();
        return tree;
    }
}
