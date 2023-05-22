#include "player.h"

void addAtBeginning(Team **head, Team tmp)
{
    Team * newNode = (Team *)malloc(sizeof(Team));
    newNode->nr=tmp.nr;
    newNode->name=(char*)malloc(30*sizeof(char));
    strcpy(newNode->name,tmp.name);
    newNode->p=(Player*)malloc(newNode->nr*sizeof(Player));
    for(int i=0; i<newNode->nr; i++)
    {
        newNode->p[i].firstName=(char*)malloc(30*sizeof(char));
        strcpy(newNode->p[i].firstName,tmp.p[i].firstName);
        newNode->p[i].secondName=(char*)malloc(30*sizeof(char));
        strcpy(newNode->p[i].secondName,tmp.p[i].secondName);
        newNode->p[i].points=tmp.p[i].points;
    }
    newNode->next = *head;
    *head = newNode;
}

void addAtBeginning2(Team **head, Team *tmp)
{
    Team * newNode = (Team *)malloc(sizeof(Team));
    newNode->nr=tmp->nr;
    newNode->name=(char*)malloc(30*sizeof(char));
    strcpy(newNode->name,tmp->name);
    newNode->p=(Player*)malloc(newNode->nr*sizeof(Player));
    for(int i=0; i<newNode->nr; i++)
    {
        newNode->p[i].firstName=(char*)malloc(30*sizeof(char));
        strcpy(newNode->p[i].firstName,tmp->p[i].firstName);
        newNode->p[i].secondName=(char*)malloc(30*sizeof(char));
        strcpy(newNode->p[i].secondName,tmp->p[i].secondName);
        newNode->p[i].points=tmp->p[i].points;
    }
    newNode->next = *head;
    *head = newNode;
}


void display_file(Team *head,FILE *g)
{
    while(head!=NULL)
    {
        fprintf(g,"%s\n",head->name);
        head=head->next;
    }
}

void free_list(Team **head)
{
    Team *headcopy=*head;
    while (*head!=NULL)
    {
        free((*head)->name);
        for(int j=0; j< (*head)->nr; j++)
        {
            free((*head)->p[j].firstName);
            free((*head)->p[j].secondName);
        }
        free((*head)->p);
        headcopy=*head;
        *head=(*head)->next;
        free(headcopy);
    }
}

float calculeazaPunctajEchipa(Team* head)
{
    float sum = 0;
    int nrJucatori = head->nr;
    for (int i = 0; i < nrJucatori; i++)
    {
        sum += head->p[i].points;
    }
    return sum / nrJucatori;
}

int verificare(int nrTeams)
{
    int n=1;
    while(n<=nrTeams)
        n=n*2;
    return n /2;
}

void removeLowest(Team** head)
{

    int nrTeams = 0;

    Team* headcopy = *head, *teamMin;
    while (headcopy != NULL)
    {
        nrTeams++;
        headcopy = headcopy->next;
    }

    int n= verificare(nrTeams);
    float lowestScore, punctaj;

    for (int i = 0; i < nrTeams - n; i++)
    {
        lowestScore = 20;
        headcopy = *head;
        while (headcopy != NULL)
        {
            punctaj = calculeazaPunctajEchipa(headcopy);
            if (punctaj < lowestScore)
            {
                teamMin = headcopy;
                lowestScore = punctaj;
            }
            headcopy = headcopy->next;
        }

        headcopy = *head;
        if(headcopy==teamMin)
        {

            *head=(*head)->next;
            free(headcopy);

        }
        else
        {
            while(headcopy!=NULL)
            {
                if(headcopy->next==teamMin)
                {
                    headcopy->next=teamMin->next;
                    free(teamMin);
                    break;
                }
                headcopy=headcopy->next;
            }
        }
    }
}
int nrElem(Team *head)
{
    int nr=0;
    Team *headcopy=head;
    while(headcopy!=NULL)
    {
        nr++;
        headcopy=headcopy->next;
    }
    return nr;
}
int nrElemStack(Stack *head)
{
    int nr=0;
    while(head!=NULL)
    {
        nr++;
        head=head->next;
    }
    return nr;
}
Queue* createQueue()
{
    Queue *q;
    q=(Queue *)malloc(sizeof(Queue));
    if (q==NULL) return NULL;
    q->front=q->rear=NULL;
    return q;
}
void enQueue(Queue *q, Match *match)
{
    Elem* newNode=(Elem*)malloc(sizeof(Elem));
    newNode->match=match;
    newNode->next=NULL;
    if (q->rear==NULL)
        q->rear=newNode;
    else
    {
        (q->rear)->next=newNode;
        (q->rear)=newNode;
    }
    if (q->front==NULL)
        q->front=q->rear;
}
int isEmptyQueue(Queue*q)
{
    return (q->front==NULL);
}
Match *deQueue(Queue*q)
{
    Elem* aux;
    Match *matchaux;
    if (isEmptyQueue(q))
        return NULL;
    aux=q->front;
    matchaux=aux->match;
    q->front=(q->front)->next;
    free(aux);
    return matchaux;
}

void create_match(Team *head,Queue *q)
{
    Team *headcopy=head,*team1,*team2;
    Match *match;
    while(headcopy!=NULL)
    {
        team1=headcopy;
        team2=headcopy->next;
        match=(Match*)malloc(sizeof(Match));
        match->team1=team1;
        match->team2=team2;
        enQueue(q,match);
        headcopy=headcopy->next->next;
    }
}
void createFromStack(Stack *head,Queue *q)
{
    Match *match;
    while(head!=NULL)
    {
        match=(Match*)malloc(sizeof(Match));
        match->team1=head->team;
        match->team2=head->next->team;
        enQueue(q,match);
        head=head->next->next;
    }
}

void push(Stack **top, Team *team)
{
    Stack* newnode = (Stack*) malloc(sizeof(Stack));
    newnode->team = team;
    newnode->next = *top;
    *top = newnode;
}

void addPoints(Team *team)
{
    int i;
    for(i=0; i<team->nr; i++)
    {
        team->p[i].points++;
    }
}
int isEmptyStack ( Stack *top )
{
    return top == NULL ;
}

Team *pop(Stack **top)
{
    if(isEmptyStack(*top))
        return NULL;
    Stack *temp= *top;
    Team *aux =temp->team;
    *top=(*top)->next;
    free(temp);
    return aux;
}

Tree* newNode(Team * data) {
	Tree* node = (Tree*)malloc(sizeof(Tree));
	node->team = data;
	node->left = node->right = NULL;
	return node;
}

Tree * insert(Tree * myNode, Team * data)
{
	if (myNode == NULL) {
		return newNode(data);
	}
	if (fabs(calculeazaPunctajEchipa(data) - calculeazaPunctajEchipa(myNode->team))<0.001) {

		if (strcmp(data->name, myNode->team->name) < 0) {
			myNode->left = insert(myNode->left, data);
		}
		else {
			myNode->right = insert(myNode->right, data);
		}
	} else if (calculeazaPunctajEchipa(data) < calculeazaPunctajEchipa(myNode->team)) {
		myNode->left = insert(myNode->left, data);
	} else {
		myNode->right = insert(myNode->right, data);
	}

	return myNode;
}


void inorder(Tree *root,Team **head) {
	if (root){
		inorder(root->left,head);
		addAtBeginning2(head,root->team);
		inorder(root->right,head);
	}
}

int height(AVL *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

AVL * newNodeAVL(int key)
{
    AVL* node = (AVL*) malloc(sizeof(AVL));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}

AVL *rightRotate(AVL *y)
{
    AVL *x = y->left;
    AVL *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;

    return x;
}

AVL *leftRotate(AVL *x)
{
    AVL *y = x->right;
    AVL *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;

    return y;
}

int getBalance(AVL *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

AVL* insertAVL(AVL* node, int key)
{
    if (node == NULL)
        return(newNodeAVL(key));

    if (key < node->key)
        node->left  = insertAVL(node->left, key);
    else if (key > node->key)
        node->right = insertAVL(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
void preOrderAVL(AVL *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrderAVL(root->left);
        preOrderAVL(root->right);
    }
}

void printLevel(AVL * rootTree, int level, FILE * g, Team * Top8)
{
	if (rootTree == NULL) {
		return;
	} else if (level == 1) {
	    Team * var =  Top8;
		for (int i = 0; i < rootTree->key;i++)
            var = var->next;
		fprintf(g, "%s\n", var->name);
	} else if (level > 1) {
		printLevel(rootTree->left, level - 1, g, Top8);
		printLevel(rootTree->right, level - 1, g, Top8);
	}
}

