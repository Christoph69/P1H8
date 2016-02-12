// tree.cpp
#include "../inc/tree.h"
#include <cstring>
#include <cstdio>

void iniTree(Node *wurzel) {
  wurzel = nullptr;
}

bool insertNewNode(Node *wurzel, char *data, unsigned int puffer_size) {
  bool flag =  false;

  if (wurzel != nullptr) {
    int cmp = strncmp(wurzel->data->name, data, puffer_size);

    if (cmp < 0) flag = insertNewNode(wurzel->left, data, puffer_size);
    else if (cmp > 0) flag = insertNewNode(wurzel->right, data, puffer_size);
    else {
      wurzel->data->anzahl++;
      flag = true;
    }
  }

  else {
    Node *knoten = new Node;

    if (knoten != nullptr) {
      printf("1:");
      wurzel = knoten;
      printf("2:");
      knoten->left = nullptr;
      printf("3:");
      knoten->right = nullptr;
      printf("4:");
      knoten->data->name = data;
      printf("5:");
      knoten->data->anzahl = 1;
      printf("6:");
      flag = true;
    }
  }


  return flag;
}

// void outputTree(Node **wurzel) {
//   if (wurzel != nullptr) {
//     outputTree(wurzel->left);
//     printf("%s\n", wurzel->data->name);
//     outputTree(wurzel->right);
//   }
// }
