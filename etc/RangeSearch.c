#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORD_MAX 1000
#define MAX 10
#define MULTI 1
void insert_search(int count);
int extractString(char s[100]);

char s[50];
char *sArr[RECORD_MAX][3];
FILE *fp;

typedef struct node
{
    int from_data;
    int to_data;
    char* content_data;
    struct node* left;
    struct node* right;
} node;


typedef void (*callback)(node*);

int compare(int left,int right)
{
    if(left > right)
        return 1;
    if(left < right)
        return -1;
    return 0;
}

node* create_node(int from_data, int to_data, char* content_data)
{
    node *new_node = (node*)malloc(sizeof(node));
    if(new_node == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    new_node->from_data = from_data;
    new_node->to_data = to_data;
    content_data[sizeof(content_data)-1] = 0;
    new_node->content_data = content_data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

typedef int (*comparer)(int, int);

node* insert_node(node *root, comparer compare, int from_data, int to_data, char* content_data)
{
    if(root == NULL)
    {
        root = create_node(from_data,to_data,content_data);
    }
    else
    {
        int is_left = 0;
        int r = 0;
        node* cursor = root;
        node* prev = NULL;

        while(cursor != NULL)
        {
            r = compare(from_data, cursor->from_data);
            prev = cursor; 
            if(r < 0)
            {
                is_left = 1;
                cursor = cursor->left;
            }
            else if(r > 0)
            {
                is_left = 0;
                cursor = cursor->right;
            }
        }
        if(is_left)
            prev->left = create_node(from_data, to_data, content_data);
        else
            prev->right = create_node(from_data, to_data, content_data);

    }
    return root;
}

void dispose(node* root)
{
    if(root != NULL)
    {
        dispose(root->left);
        dispose(root->right);
        free(root);
    }
}

node* search(node *root,const int data, comparer compare)
{
    if(root == NULL)
        return NULL;

    int r1, r2;
    node* cursor = root;
    while(cursor != NULL)
    {
        r1 = compare(data,cursor->from_data);
        r2 = compare(data,cursor->to_data);
        printf("from_data :%d  to_data : %d  r1 : %d  r2 : %d \n", cursor->from_data, cursor->to_data, r1, r2);
        if(r1 >= 0 && r2 <= 0)
        {
            return cursor;
        } 
        else if(r1 <= 0)
        {
            cursor = cursor->left;
        } 
        else if(r2 >= 0)
        {
            cursor = cursor->right;
        }
    }
    return cursor;
}

//typedef node (*Temp)[];
node ** searchMulti(node *root,const int data, comparer compare)
{
    if(root == NULL)
        return NULL;

    int r1 = 0, r2 = 0, c = 0;
    node * cursor = root;
    node ** cursors = malloc(sizeof(root)*MAX); //MAX is maximum of found record data
    while(cursor != NULL)
    {
        r1 = compare(data,cursor->from_data);
        r2 = compare(data,cursor->to_data);
        printf(">> from_data :%d  to_data : %d  r1 : %d  r2 : %d \n", cursor->from_data, cursor->to_data, r1, r2);
        if(r1 >= 0 && r2 <= 0)
        {
            cursors[c] = cursor;
            c++;
            if(c >= MAX)
                break;
            cursor = cursor->right;
        } 
        else if(r1 <= 0)
        {
            cursor = cursor->left;
        } 
        else if(r2 >= 0)
        {
            cursor = cursor->right;
        }
        else
        {
            printf("r1 is %d and r2 is %d \n", r1, r2);
        }
    }
    printf("FOUND : %d\n", c);
    return cursors;
}

void display(node* nd)
{
    if(nd != NULL)
        printf("[%d ~ %d] : %s ",nd->from_data, nd->to_data, nd->content_data);
}

void display_tree(node* nd)
{
    if(nd == NULL)
        return;
    printf("%s", nd->content_data);
    if(nd->left != NULL)
        printf("(L:%s)", nd->left->content_data);
    if(nd->right != NULL)
        printf("(R:%s)", nd->right->content_data);
    printf("\n");

    display_tree(nd->left);
    display_tree(nd->right);
}

int main(int argc, char* argv[])
{
   fp = fopen("range.txt", "r"); 
   if(fp == NULL) {
       fprintf(stderr,"can't open file\n");
       exit(1);
   }
   //count = atoi(argv[1]);
   printf("argc :  %d  argv : %s \n", argc, *argv);
   
   /*
   while(!feof(fp))
   {
      fgets(s, 50, fp);
      printf("%s ", s);
   }
   */
  
   
   insert_search(extractString(s));

   fclose(fp);
   return 0;
}

void insert_search(int count)
{
    int i = 0;
    node* root = NULL;
    comparer int_comp = compare;

    for(i=0; i<count; i++)
    {
        root = insert_node(root, int_comp, atoi(sArr[i][0]), atoi(sArr[i][1]), sArr[i][2]);
    }

    display_tree(root);

    /* search for a node */
    int key = 0;
    node *snode;
    node **snodes;
    while(key != -1)
    {
        printf("Enter data to search (-1 to exit):");
        scanf("%d",&key);

#if MULTI
        snodes = searchMulti(root, key, int_comp);

        if(snodes != NULL)
        {
            for(i=0; i<sizeof(snodes); i++) 
            {
                if(snodes[i] != NULL)
                    printf("<< Found  %s >>\n",snodes[i]->content_data);
            }
        } else
        {
            printf("node %d not found\n",key);
        }

#else
        snode = search(root,key,int_comp);
        if(snode != NULL)
        {
            printf("Found it %s",snode->content_data);
            if(snode->left != NULL)
                printf("(L: %s)",snode->left->content_data);
            if(snode->right != NULL)
                printf("(R: %s)",snode->right->content_data);
            printf("\n");
        }
        else
        {
            printf("node %d not found\n",key);
        }

#endif
    }
    dispose(root);
}

int extractString(char s[100])
{
    //callback f= display;
    int i = 0, j = 0;
    char *ss = malloc(RECORD_MAX);
    int count = 0;
    while(fgets(ss, sizeof(ss), fp) != NULL)
    {
        ss[strlen(ss) - 1] = '\0';
        char *ptr = strtok(ss, "~");
        if(ptr != NULL) {
            sArr[i][j] = malloc(strlen(ptr)+1);
            strcpy(sArr[i][j] , ptr);
            ptr = strtok(NULL, " : ");
        }
        j++;
        if(j==3) {
            j = 0;
            i++;
            count++;
        }
    }
    return count;
}
