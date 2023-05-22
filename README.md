# LanParty Project
## Made by Ana-Maria Brinzea
### Data Structures:
1. struct Player:
* firstName: pointer to the first name of the player (string)
* secondName: pointer to the last name of the player (string)
* points: integer representing the points scored by the player
2. struct Team:
* nr: integer representing the number of players in the team
* name: pointer to the name of the team (string)
* p: pointer to an array of players in the team
* next: pointer to the next team in the list
3. struct Match:
* team1: pointer to the first team in the match
* team2: pointer to the second team in the match
* score1: float representing the score of team1
* score2: float representing the score of team2
4. struct Queue_element:
* match: pointer to a match
* next: pointer to the next element in the queue
5. struct Queue:
* front: pointer to the front of the queue
* rear: pointer to the rear of the queue
6. struct stiva:
* team: pointer to a team
* next: pointer to the next element in the stack
7. struct tree :
* team: pointer to a team
* left: pointer to the left child node in the binary search tree
* right: pointer to the right child node in the binary search tree
8. struct AVL :
* key: integer representing the key value of the AVL node
* left: pointer to the left child node in the AVL tree
* right: pointer to the right child node in the AVL tree
* height: integer representing the height of the AVL node
### Functions :
1. addAtBeginning
* This function adds a new Team node at the beginning of a linked list.
* It takes a double pointer to the head of the list and a Team structure (tmp) as parameters.
* It creates a new node, copies the data from tmp into the new node, and inserts it at the beginning of the list.
2. addAtBeginning2
* This function is similar to addAtBeginning, but it takes a pointer to a Team structure (tmp) instead of a structure itself.
* It creates a new node, copies the data from tmp into the new node, and inserts it at the beginning of the list.
3.  display_file
* This function displays the names of teams stored in the linked list.
* It takes a pointer to the head of the list and a file pointer (g) as parameters.
* It iterates through the list and writes each team's name to the file using fprintf.
4. free_list
* This function frees the memory allocated for the linked list.
* It takes a double pointer to the head of the list as a parameter.
* It iterates through the list, frees the memory for each team's name and players' names, and then frees the memory for each node.
5.  calculeazaPunctajEchipa
* This function calculates the average score of a team.
* It takes a pointer to a Team structure (head) as a parameter.
* It iterates through the players of the team and adds up their points.
* Finally, it returns the average score by dividing the total points by the number of players.
6. verificare
* This function calculates the number of teams needed to have a power of two.
* It takes an integer (nrTeams) as a parameter.
* It iteratively doubles a variable (n) until it becomes greater than or equal to nrTeams, and then returns half of n.
7. removeLowest
* This function removes the teams with the lowest scores from the linked list until only half of the teams remain.
* It takes a double pointer to the head of the list as a parameter.
* It calculates the number of teams in the list and determines the number of teams to remove based on that.
* It iteratively finds the team with the lowest score, removes it from the list, and frees the memory.
* The process is repeated until the desired number of teams is reached.
8. nrElem
* This function calculates the number of elements (teams) in the linked list.
* It takes a pointer to the head of the list as a parameter.
* It iteratively counts the number of teams and returns the count.
9. nrElemStack 
* This function calculates the number of elements in a stack.
* It takes a pointer to the top of the stack (head) as a parameter.
* It iteratively counts the number of elements and returns the count.
10. createQueue
* This function creates a new queue and returns a pointer to it.
* It allocates memory for the queue structure (Queue), initializes the front and rear pointers to NULL, and returns the pointer to the queue.
11. enQueue
* This function adds a new match to the end of the queue.
12. isEmptyQueue
* This function checks if the queue is empty.
13. deQueue
* This function removes the first match from the queue and returns it.
14. create_match
* This function creates a match between each pair of adjacent teams in the linked list of teams and adds it to the queue.
15. createFromStack
* This function creates a match from each pair of adjacent teams in the stack and adds it to the queue.
16. push
* This function adds a new team to the top of the stack.
17. addPoints
* This function adds a point to each player of the given team.
18. isEmptyStack 
* This function checks if the stack is empty.
19. pop
* This function removes the top team from the stack and returns it.
20. newNode
* This function creates a new node for the binary search tree with the given team.
21. insert
* This function inserts a new team node in the binary search tree.
22. inorder
* This function traverses the binary search tree in-order and adds the teams to the beginning of the linked list.
23. height 
* This function returns the height of the AVL tree node.
24. max
* This function returns the maximum of two integers.
25. newNodeAVL
* This function creates a new AVL tree node with the given key.
26. rightRotate
* This function performs a right rotation on the AVL tree node 'y'.
27. leftRotate
* This function performs a left rotation on the AVL tree node 'x'.
28. getBalance
* This function calculates the balance factor of the AVL tree node 'N'.
29. insertAVL
* This function inserts a new AVL tree node with the given key into the AVL tree.
* It maintains the balance of the tree by performing rotations when necessary.
30.  preOrderAVL
* This function performs a pre-order traversal of the AVL tree and prints the keys of the nodes.
31. printLevel
* This function prints the names of the teams at a given level of the AVL tree, using a file pointer 'g' and a linked list 'Top8' as input.
### Main :
The code uses file handling to read input from "c.in.txt" and "d.in.txt" and write output to "r.out".
1. Task 1:
* Read teams from a file and create a linked list of teams.
* Display the contents of the linked list in an output file.
2. Task 2:
* Remove the team with the lowest score from the linked list.
* Display the updated linked list in an output file.
3. Task 3:
* Create matches between teams using a queue data structure.
* Determine winners based on the scores of each team.
* Store the winners and losers in stack data structures.
* Repeat the process for multiple rounds, reducing the number of teams each time.
* Display the winners of each round in an output file.
4. Task 4:
* Create a binary search tree from the top 8 teams stored in a stack.
* Insert teams into the binary search tree based on their scores.
* Perform an inorder traversal of the binary search tree and store the teams in a linked list.
* Display the top 8 teams, along with their scores, in an output file.
5. Task 5:
* Create an AVL tree and insert values from 0 to 7 into the tree.
* Print the names of teams at a specific level in the AVL tree.
* Display the names of teams at the specified level in an output file.
