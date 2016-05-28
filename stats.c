//
//  stats.c
//  program 1
//
//  Created by arnoldas kurbanovas on 2/2/16.
//  Copyright © 2016 arnoldas kurbanovas. All rights reserved.
//

#include "constants.h"

// to find number of nodes along the longest path from the root node
// down to the farthest leaf node.
int treeHeight(struct tree_node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = treeHeight(node->left);
        int rDepth = treeHeight(node->right);
        
        /* use the larger one */
        if (lDepth > rDepth){
            lDepth++;
            return lDepth;
        }
        else{
            rDepth++;
            return rDepth;
        }
    }
}


//used to get the height of the tree and then called on the left and right root
//nodes to get the heigh of left and right subtrees when needed
int maxHeight(struct tree_node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree in maxDepth function */
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        
        /* use the larger one and dont add the first instance of a node */
        if (leftDepth > rightDepth){
            return leftDepth;
        }
        else{
            return rightDepth;
        }
    }
}






//function to count the left and right leafs of the tree(leafs are the end nodes)
int leafcount(struct tree_node* leaf){
    if (leaf==NULL)
        return 0;
    else if((leaf->left ==NULL) && (leaf->right==NULL)){
        return 1;
    }else{
        int lDepth = leafcount(leaf->left);
        int rDepth = leafcount(leaf->right);
        return lDepth + rDepth;
    }
}

