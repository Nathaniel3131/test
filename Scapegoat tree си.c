#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

 // Структура Node 
 
struct node {
    int key;
        struct node *right, *left, *parent;
};
  struct node* newNode(int item){
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = NULL;
	temp->right = NULL;
    temp->parent = NULL;
    return temp;
}
 
  int n, q;
  
  struct node *root;
  

 //Структура Scapegoattree
 
 struct node* Scapegoattree(){
            
			root = NULL;
            n = 0;
}
 
  bool add(int x)
        {
            // first do basic insertion keeping track of depth 
            struct node* u = (struct node*)malloc(x * sizeof(struct node));
            int d = addWithDepth(u);
            if (d > log32(q))
            {
                // depth exceeded, find scapegoat 
                  struct node* w = u->parent;
                while (3 * size(w) <= 2 * size(w->parent))
                    w = w->parent;
                rebuild(w->parent);
            }
            return d >= 0;
        }
        
       // Function to rebuild tree from node u 
        void rebuild(struct node *u)
        {
            int ns = size(u);
             struct node *p = u->parent;
             struct node **a = (struct node*)malloc(ns * sizeof(struct node));
            packIntoArray(u, a, 0);
            if (p == NULL)
            {
                root = buildBalanced(a, 0, ns);
                root->parent = NULL;
            }
            else if (p->right == u)
            {
                p->right = buildBalanced(a, 0, ns);
                p->right->parent = p;
            }
            else
            {
                p->left = buildBalanced(a, 0, ns);
                p->left->parent = p;
            }
        }
        
        // Function to check if tree is empty 
        bool isEmpty()
        {
            return root == NULL;
        }
 
        // Function to clear  tree 
        void makeEmpty()
        {
            root = NULL;
            n = 0;
        }
 
         // Function to count number of nodes recursively 
        int size(struct node *r){
            if (r == NULL)
                return 0;
            else{
                int l = 1;
                l += size(r->left);
                l += size(r->right);
                return l;
            }
        }
 
  // Functions to search for an element 
        bool search(int val)
        {
            return search(val);
        }
        
         // Function to search for an element recursively 
        bool search1(struct node* r, int val)
        {
            bool found = false;
            while ((r != NULL) && !found)
            {
                int rval = r->key;
                if (val < rval)
                    r = r->left;
                else if (val > rval)
                    r = r->right;
                else
                {
                    found = true;
                    break;
                }
                found = search1(r, val);
            }
            return found;
        }
        
        // Function for inorder traversal 
        void inorder()
        {
            inorder(root);
        }
        void inorder1(struct node* r)
        {
            if (r != NULL)
            {
                inorder(r->left);
                printf(r->key);
                inorder(r->right);
            }
            else
                return;
        }
        
         // Function for preorder traversal 
        void preorder()
        {
            preorder(root);
        }
        void preorder1(struct node* r)
        {
            if (r != NULL)
            {
                printf(r->key);
                preorder(r->left);
                preorder(r->right);
            }
            else
                return;
        }
        
        // Function for postorder traversal 
        void postorder()
        {
            postorder(root);
        }
        void postorder1(struct node* r)
        {
            if (r != NULL)
            {
                postorder(r->left);
                postorder(r->right);
                printf(r->key);
            }
            else
                return;
        }
 
        int log32(int q)
        {
            double log23 = 2.4663034623764317;
            return (int)ceil(log23 * log(q));
        }
        
        // Function to packIntoArray 
        int packIntoArray(struct node *u, struct node *a[], int i)
        {
            if (u == NULL)
            {
                return i;
            }
            i = packIntoArray(u->left, a, i);
            a[i++] = u;
            return packIntoArray(u->right, a, i);
        }
        
          // Function to build balanced nodes 
        int buildBalanced(struct node **a, int i, int ns)
        {
            if (ns == 0)
                return NULL;
            int m = ns / 2;
            a[i + m]->left = buildBalanced(a, i, m);
            if (a[i + m]->left != NULL)
                a[i + m]->left->parent = a[i + m];
            a[i + m]->right = buildBalanced(a, i + m + 1, ns - m - 1);\
            if (a[i + m]->right != NULL)
                a[i + m]->right->parent = a[i + m];
            return a[i + m];
        }
        
        // Function add with depth 
        int addWithDepth(struct node *u)
        {
            struct node *w = root;
            if (w == NULL)
            {
                root = u;
                n++;
                q++;
                return 0;
            }
            bool done = false;
            int d = 0;
            do
            {
                if (u->key < w->key)
                {
                    if (w->left == NULL)
                    {
                        w->left = u;
                        u->parent = w;
                        done = true;
                    }
                    else
                    {
                        w = w->left;
                    }
                }
                else if (u->key > w->key)
                {
                    if (w->right == NULL)
                    {
                        w->right = u;
                        u->parent = w;
                        done = true;
                    }
                    else
                    {
                        w = w->right;
                    }
                }
                else
                    return -1;
                d++;
            }
            while (!done);
            n++;
            q++;
            return d;
        }

 
int main(){
	printf("ScapeGoat Tree Test");
    char ch;
    int val;
    //  Операции с деревом
    do{
        printf("\nScapeGoat Tree Operations:\n");
        printf("1. Insert: ");
        printf("2. Count nodes: ");
        printf("3. Search");
        printf("4. Check empty");
        printf("5. Empty tree");
        int choice;
        printf(": ");
        scanf(choice);
        switch (choice)
        {
        case 1 :
            printf("Enter integer element to insert: ");
            scanf(val);
            add(val);
            break;
        case 2 :
            printf("Nodes = " , size);
            break;
        case 3 :
            printf("Enter integer element to search: ");
            scanf(val);
            if (search(val))
                printf("%d found in the tree");
            else
                printf("%d not found", val);
            break;
        case 4 :
            printf("Empty status = ");
            if (isEmpty())
                printf("Tree is empty");
            else
                printf("Tree is non - empty");
            break;
        case 5 :
            printf("\nTree cleared\n");
            makeEmpty();
            break;
        default :
            printf("Wrong Entry \n ");
            break;
        }
 
        //  Показать дерево
        printf("\nPost order : ");
        postorder();
        printf("\nPre order : ");
        preorder();
        printf("\nIn order : ");
        inorder();
        printf("\nDo you want to continue (Type y or n) \n");
        scanf(ch);
    }
    while (ch == 'Y'|| ch == 'y');
    return 0;
}
