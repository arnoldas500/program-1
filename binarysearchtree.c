//
//  binarysearchtree.c
//  program 1
//
//  Created by arnoldas kurbanovas on 2/2/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "constants.h"
void treeprint( tree_node *node , FILE *OUTPUT_FILE){
    if ( node != NULL)
    {
        treeprint(node->left, OUTPUT_FILE);
        fprintf(OUTPUT_FILE , "%s\n" , node->string);
        treeprint(node->right , OUTPUT_FILE);
    }
}



/*
FILE *output_File;
void openWritableFile()
{
    output_File = fopen("output.txt", "w+");
}
void printToFile( char* data )
{
    fprintf(output_File, "%s\n", data );
}

*/