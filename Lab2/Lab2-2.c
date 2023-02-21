#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode { 
  int val;
  struct ListNode *next;
} ListNode ;

int createList(ListNode **start) {
  
  char text[1000];
  fgets(text,1000,stdin);
  if(strcmp(text,"\n") == 0) {return 0;}

  ListNode *newNode, *ptr;
  *start = NULL;

  //Split text and add to num
  int num;
  char* result = strtok(text, " ");
  while (strcmp(result,"END\n") != 0) {
    
    //Change str to int
    sscanf(result,"%d",&num);
    
    //Generate new node
    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = num;    //define val
    newNode->next = NULL;   //no link

    //Link new node to the linked list
    if(*start==NULL) {*start = newNode;} //if first node, link from header
    else {ptr->next = newNode;} //if latter node, link from current
    ptr = newNode; //move current to new node
    
    result = strtok(NULL, " ");
    
  }
  return 1;
}

void display(ListNode **start)
{
    ListNode *ptr = *start; //start
    while(ptr != NULL)
    {
        printf("%d ",ptr->val); //print val of current node
        ptr = ptr->next; //move current to the next node
    }
    printf("\n");
}

void reverseList(ListNode **start, int m, int n) {
    ListNode *curr = *start, *prev = NULL, *temp = NULL;
    int i;
    for (i = 1; i < m; i++) {
        prev = curr;
        curr = curr->next;
    }
    ListNode *tail = curr;
    for (; i <= n; i++) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    tail->next = curr;
    if (m == 1) {
        *start = prev;
    } else {
        temp = *start;
        for (i = 1; i < m - 1; i++) {
            temp = temp->next;
        }
        temp->next = prev;
    }
}

int main() {
  ListNode *ll;
  createList(&ll);
  int m, n;
  scanf("%d %d", &m, &n);
  reverseList(&ll, m, n);
  display(&ll);
  return 0;
}