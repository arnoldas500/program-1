

//
//  main.c
//  program 1
//
//  Created by arnoldas kurbanovas on 2/1/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "constants.h"
#include "insert.c"
#include "stats.c"
#include "binarysearchtree.c"
#include "struct_def.h"


int main(int argc, char *argv[]){
    
    tree_node *root = NULL;
    
    //   FILE *output_File;
    FILE *input_File;
    FILE *output_File;
    char str[MAXLEN+1];
    int num_str = 0;
    
    if(argc != 3){
        printf(" not enough god dam files ");
        fprintf(stderr, "Usage: %s file\n", argv[0]); exit(1);
    }
    
    if((input_File = fopen(argv[1], "r")) == NULL){
        printf("failed to open input file");
        fprintf(stderr, "Could not open file: %s\n", argv[1]); exit(1);
    }
    
    if((output_File = fopen(argv[2], "w")) == NULL){
        printf("failed to open output file");
        fprintf(stderr, "Could not open file: %s\n", argv[2]); exit(1);
    }
    
   // output_File = fopen("output.txt", "w+");
    output_File = fopen(argv[2], "w");
    
    while(fscanf(input_File, "%s", str) != EOF){
       // fscanf(input_File, "%s", &str);
        root = insert(root, str);
        num_str++;
        
    }
    treeprint(root, output_File);
    fprintf(output_File, "No. of strings in the input file      =  %d \n", num_str);
    
    //should show the height
    fprintf(output_File, "Height of the search tree            =  %d \n", (maxHeight(root)));
   
    fprintf(output_File, "Number of leaves in the tree         =  %d \n", leafcount(root));

    fprintf(output_File, "Height of the left subtree of root   =  %d \n", (maxHeight(root->left)));

    fprintf(output_File, "No. of strings in the left subtree   =  %d \n", root->leftsubtree);

    fprintf(output_File, "Height of the right subtree of root  =  %d \n", (maxHeight(root->right)));

    fprintf(output_File, "No. of strings in the right subtree  =  %d \n", root->rightsubtree);
    
    
    // openWritableFile();
    //printToFile( node->str );
    
    return 0;
}




/*
  //int data;
 // char * key;
 
 };tree_node;
 
 //tree_node* root;
 
 bool isEmpty() const {return root==NULL;}
 void find(char * ch);
 void insert(char * ch, double d);
 
 };
 
 //Smaller elements go left
 //larger elements go right
 void find(char * ch)
 {
 bool isfind = false;
 struct tree_node* current;
 current = root;
 while(current){
 if(strcmp(ch, current->key)==0){
 cout << "found\n";
 isfind = true;
 break;
 
 }
 else if(strcmp(ch, current->key)>0)
 current = current->right;
 else if(strcmp(ch, current->key)<0)
 current = current->left;
 
 }
 if(!isfind)
 cout << "data not found\n";
 }
 
 void Map::insert(char * ch, double d){
 tree_node* t = new tree_node;
 tree_node* parent;
 t->key = ch;
 t->data = d;
 t->left = NULL;
 t->right = NULL;
 parent = NULL;
 
 //is this an empty tree?
 if(isEmpty())
 root = t;
 else{
 //insert as leafs
 tree_node* current;
 current = root;
 //find parent
 while(current){
 parent = current;
 if(strcmp(t->key, current->key))
 current = current->right;
 else
 current = current->left;
 }
 if(strcmp(t->key, parent->key))
 parent->right = t;
 else
 parent->left = t;
 }
 }
  */
