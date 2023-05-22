#include "player.h"

int main(int argc, char * argv[])
{
    Team* head = NULL;
    Team * StackTop8=NULL;
    Team *OrderTop8=NULL;

    FILE *taskFile=fopen(argv[1],"rt");
    FILE * fp = fopen(argv[2], "rt");
    FILE *g = fopen(argv[3],"wt");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    if (g == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    if (taskFile == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    int x[5];
    for(int i=0; i<5; i++)
    {
        fscanf(taskFile,"%d",&x[i]);
    }

    if(x[0]==1)
    {
        int nr_teams;
        fscanf(fp, "%d", &nr_teams);
        for (int i = 0; i < nr_teams; i++)
        {
            Team tmp;
            char *buffer;
            buffer=(char*)malloc(40*sizeof(char));
            fscanf(fp,"%d ",&tmp.nr);
            tmp.name=(char*)malloc(40*sizeof(char));
            fgets(buffer, 40, fp);
            if (buffer[strlen(buffer) - 3] == ' ')
                buffer[strlen(buffer) - 3] = '\0';
            else
                buffer[strlen(buffer) - 2] = '\0';

            strcpy(tmp.name, buffer);
            tmp.p=(Player*)malloc(tmp.nr*sizeof(Player));
            for(int j=0; j<tmp.nr; j++)
            {
                tmp.p[j].firstName=(char*)malloc(30*sizeof(char));
                fscanf(fp,"%s",tmp.p[j].firstName);
                tmp.p[j].secondName=(char*)malloc(30*sizeof(char));
                fscanf(fp,"%s",tmp.p[j].secondName);
                fscanf(fp,"%d",&tmp.p[j].points);
            }
            addAtBeginning(&head,tmp);
        }
        if (x[1]==0) display_file(head,g);


    }
    if(x[1]==1)
    {
        removeLowest(&head);
        display_file(head,g);
    }
    if(x[2]==1)
    {
        Queue *q;
        Team *tmp;
        Match *match;
        Stack *winners=NULL, *losers=NULL;
        int nr_teams=nrElem(head);
        int nr_runde=0;
        for(int i=nr_teams; i>1; i/=2)
        {
            nr_runde++;
        }

        q=createQueue();
        create_match(head,q);
        for(int i=0; i<nr_runde; i++)
        {
            fprintf(g,"\n--- ROUND NO:%d\n",i+1);

            while(!isEmptyQueue(q))
            {
                match=deQueue(q);
                fprintf(g,"%-33s-%33s\n",match->team1->name,match->team2->name);

                match->score1=calculeazaPunctajEchipa(match->team1);
                match->score2=calculeazaPunctajEchipa(match->team2);
                if(match->score1>match->score2)
                {
                    push(&winners,match->team1);
                    addPoints(match->team1);
                    push(&losers,match->team2);
                }
                else
                {
                    push(&winners,match->team2);
                    addPoints(match->team2);
                    push(&losers,match->team1);
                }
            }
            q->front = q->rear = NULL;

            if(nrElemStack(winners) == 8)
            {
                Team aux;
                for(Stack * var =winners; var!=NULL; var=var->next) {
                    aux.nr= var->team->nr;
                    aux.name=(char*)malloc(30*sizeof(char));
                    strcpy(aux.name,var->team->name);
                    aux.p=(Player*)malloc(aux.nr*sizeof(Player));
                    for(int i=0; i<var->team->nr; i++)
                    {
                       aux.p[i].firstName=(char*)malloc(30*sizeof(char));
                       strcpy(aux.p[i].firstName,var->team->p[i].firstName);
                       aux.p[i].secondName=(char*)malloc(30*sizeof(char));
                       strcpy(aux.p[i].secondName,var->team->p[i].secondName);
                       aux.p[i].points=var->team->p[i].points;
                    }
                    addAtBeginning(&StackTop8,aux);
                }
            }

            fprintf(g,"\nWINNERS OF ROUND NO:%d \n",i+1);

            if (i < nr_runde - 1)
                createFromStack(winners, q);

            while(!isEmptyStack(winners))
            {
                tmp=pop(&winners);
                fprintf(g,"%-34s-  %.2f\n",tmp->name,calculeazaPunctajEchipa(tmp));
            }

            while(!isEmptyStack(losers))
            {
                tmp=pop(&losers);
            }

        }
    }
    if (x[3] == 1) {

        Tree *root=NULL;
        while(StackTop8!=NULL)
        {
            root=insert(root,StackTop8);
            StackTop8=StackTop8->next;
        }
        inorder(root,&OrderTop8);
        fprintf(g,"\nTOP 8 TEAMS:\n");
        Team *headcopy= OrderTop8;
        while(headcopy!=NULL)
        {
            fprintf(g,"%-34s-  %.2f\n",headcopy->name,calculeazaPunctajEchipa(headcopy));
            headcopy=headcopy->next;
        }

    }

    if(x[4]==1)
    {
      AVL * avlRoot=NULL;
      for(int i=0;i<8;i++)
      {
          avlRoot=insertAVL(avlRoot,i);
      }
      fprintf(g,"\nTHE LEVEL 2 TEAMS ARE: \n");
      printLevel(avlRoot,3,g, OrderTop8);
    }

    free_list(&head);
    free_list(&StackTop8);
    free_list(&OrderTop8);

    head = NULL;
    StackTop8 = NULL;
    OrderTop8 = NULL;

    return 0;
}

