/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>

int main(int argc, char* argv[])
{
  Node* even = NULL;
  Node* odd = NULL;
  Node* inputHead = new Node(6, new Node(8, new Node(7, new Node(2, NULL))));
  
  

  split(inputHead, odd, even);


  while(odd != NULL){
    Node* temp = odd->next;

    delete odd;

    odd = temp;

  }

  while(even != NULL){
    Node* temp = even->next;

    delete even;

    even = temp;
    
  }

}
