// tree.cpp
#include "../inc/word_tree.h"
#include <cstring>
#include <cstdio>

void iniWordlist(Node **wurzel) {
  *wurzel = nullptr;
}

bool insertNewNode(Node       **wurzel,
                   char        *data,
                   unsigned int puffer_size,
                   unsigned int wpos) {
  bool flag =  false;

  if (*wurzel != nullptr) {
    int cmp = strncmp((*wurzel)->data.name, data, puffer_size + 1);

    if (cmp > 0) flag = insertNewNode(&(*wurzel)->left, data, puffer_size, wpos);
    else if (cmp < 0) flag = insertNewNode(&(*wurzel)->right, data, puffer_size,
                                           wpos);
    else {
      (*wurzel)->data.anzahl++;
      delete[] data;
      flag = true;
    }
  }

  else { // Wort ist noch nicht vorgekommen, Speicherplatz muss neu dafür
         // reserviert werden.
    Node *knoten = new Node;

    if (knoten != nullptr) {
      *wurzel                      = knoten;
      knoten->left                 = nullptr;
      knoten->right                = nullptr;
      knoten->data.name            = data;
      knoten->data.anzahl          = 1;
      knoten->data.erstesVorkommen = wpos;
      flag                         = true;
    }
  }


  return flag;
}

static void outputTree(Node **wurzel) {
  if (*wurzel != nullptr) {
    outputTree(&(*wurzel)->left);
    printf("%-20s%10d%10d\n",
           (*wurzel)->data.name,
           (*wurzel)->data.erstesVorkommen,
           (*wurzel)->data.anzahl);
    outputTree(&(*wurzel)->right);
  }
}

// Wrapper
void outputWordlist(Node **wurzel) {
  printf("\nAusgabe der Wortliste: \n\n");
  printf("%-20s%10s%10s\n", "Name", "First", "Anzahl");
  outputTree(wurzel);
}

void deleteWordlist(Node **wurzel) {
  if (*wurzel != nullptr) {
    deleteWordlist(&(*wurzel)->left);
    deleteWordlist(&(*wurzel)->right);
    delete *wurzel;
  }
}
