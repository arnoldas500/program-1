//
//  insert.c
//  program 1
//
//  Created by arnoldas kurbanovas on 2/2/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "constants.h"


tree_node * insert(tree_node *node, char str[MAXLEN]){
    puts("running insert");
    if(node == NULL){
        node = (tree_node *)malloc(sizeof(tree_node));
        strncpy(node -> string, str, MAXLEN);
        node -> left = NULL;
        node -> right = NULL;
    //    printToFile( node->string );
        
    }
    // printToFile( node->string );
    
    else if(strcmp(node->string, str)>0){
        node -> right = insert(node->right, str);
        node->rightsubtree++;
    }
    else if(strcmp(node->string, str)<0){
        node -> left = insert(node->left, str);
        node->leftsubtree++;
    }
    
    return node;
}


/*
 tree_node * insert(tree_node *node, char str[MAXLEN]){
 puts("running insert");
 if(node == NULL){
 node = (tree_node *)malloc(sizeof(tree_node));
 strncpy(node -> string, str, MAXLEN);
 node -> left = NULL;
 node -> right = NULL;
 }
 
 else if(strcmp(node->string, str)>0){
 node -> right = insert(node->right, str);
 }
 else if(strcmp(node->string, str)<0){
 node -> left = insert(node->left, str);
 }
 else if(strcmp(node->string, str) == 0){
 node -> left = insert(node->left, str);
 }
 
 return node;
 
 }
 
 */