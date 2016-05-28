
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 15

typedef struct tree_node{
    char string[MAXLEN+1];
    
    //int data;
    // char * key;
    
    struct tree_node *left;
    struct tree_node *right;
}tree_node;

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
void treeprint( tree_node *node , FILE *OUTPUT_FILE)
{
    if ( node != NULL)
    {
        treeprint(node->left, OUTPUT_FILE);
        fprintf(OUTPUT_FILE , "%s\n" , node->string);
        treeprint(node->right , OUTPUT_FILE);
    }
}

int main(int argc, char *argv[]){
    
    tree_node *root = NULL;
    
    FILE *ifp;
    FILE *ofp;
    char str[MAXLEN+1];
    
    if(argc != 2){
        printf("failed       1     ");
        fprintf(stderr, "Usage: %s file\n", argv[0]); exit(1);
    }
    
    if((ifp = fopen(argv[1], "r")) == NULL){
        printf("failed        2    ");
        fprintf(stderr, "Could not open file: %s\n", argv[1]); exit(1);
    }
    
    ofp = fopen("output.txt", "w+");
    
    while(fscanf(ifp, "%s", &str) != EOF){
        root = insert(root, str);
    }
    treeprint(root, ofp);
    
    return 0;
}


/*
struct Map
{
        typedef struct tree_node{
            struct tree_node *left;
            struct tree_node *right:
            char string[MAXLEN+1];
            
        //int data;
       // char * key;
            
        };tree_node;
    
    //tree_node* root;
    
    Map(){
        root = NULL;
    }
    
    bool isEmpty() const {return root==NULL;}
    void print_inorder();
    void inorder(tree_node*);
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

void Map::print_inorder(){
    inorder(root);
}

void Map::inorder(tree_node* p){
    if(p != NULL){
        if(p->left) inorder(p->left);
        cout <<" Salary[\""<<p->key <<"\"]="; cout <<p->data<<endl;
        if(p->right) inorder(p->right);
    }
    else return;
}
 */


