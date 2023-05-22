#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Player
{
    char* firstName;
    char* secondName;
    int points;
};
typedef struct Player Player;

struct team
{
    int nr;
    char* name;
    Player *p;
    struct team *next;
};
typedef struct team Team;
struct Match
{
    Team *team1,*team2;
    float score1,score2;
};
typedef struct Match Match;
struct Queue_element
{
    Match *match;
    struct Queue_element *next;
};
typedef struct Queue_element Elem;
struct Queue
{
    Elem *front,*rear;
};
typedef struct Queue Queue;

struct stiva
{
    Team *team;
    struct stiva *next;
};
typedef struct stiva Stack;

struct tree
{
    Team *team;
    struct tree *left, *right;
};
typedef struct tree Tree;
struct AVL
{
    int key;
    struct AVL *left;
    struct AVL *right;
    int height;
};
typedef struct AVL AVL;
void addAtBeginning(Team **head, Team tmp);
void addAtBeginning2(Team **head, Team *tmp);
void display_file(Team *head,FILE *g);
void free_list(Team **head);
int verificare(int nrTeams);
float calculeazaPunctajEchipa(Team* t);
void removeLowest(Team** head);
int nrElem(Team *head);
int nrElemStack(Stack *head);
Queue* createQueue();
void enQueue(Queue *q, Match *match);
int isEmptyQueue(Queue*q);
Match *deQueue(Queue*q);
void create_match(Team *head,Queue *q);
void createFromStack(Stack *head,Queue *q);
void push(Stack** top, Team* team);
int isEmptyStack ( Stack *top );
Team *pop(Stack **top);
void push(Stack** top, Team* team);
void addPoints(Team *team);
int isEmptyStack ( Stack *top );
Team *pop(Stack **top);
Tree* newNode(Team * data);
Tree* insert(Tree* node, Team * data);
void inorder(Tree *root,Team **head);
int height(AVL *N);
int max(int a, int b);
AVL * newNodeAVL(int key);
AVL *rightRotate(AVL *y);
AVL *leftRotate(AVL *x);
int getBalance(AVL *N);
AVL* insertAVL(AVL* node, int key);
void preOrderAVL(AVL *root);
void printLevel(AVL * rootTree, int level, FILE * g, Team * StackTop8);
