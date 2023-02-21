#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
  int data;
  struct ListNode *next;
} ListNode;

void createList(ListNode **start)
{
  char result[20];
  int num, check;
  ListNode *newNode, *ptr, *preptr;
  *start = NULL;

  scanf("%s", result);
  check = atoi(result);

  if (check > 10000 || check < -10000)
  {
    scanf("%s", result);
  }

  while (strcmp(result, "END") != 0)
  {
    num = atoi(result);
    newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->data = num;  
    newNode->next = NULL;
    if (*start == NULL)
    {
      *start = newNode;
    }
    else
    {
      ptr->next = newNode;
    }
    ptr = newNode;
    scanf("%s", result);
  }
}

void display(ListNode *start)
{
  ListNode *ptr = start;
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }

  if (start == NULL)
  {
    printf("None");
  }
}

void deleteDuplicate(ListNode **start)
{
  ListNode *ptr = *start, *preptr = NULL, *temp = NULL;

  while (ptr && ptr->next)
  {
    if (ptr->data == ptr->next->data)
    {
      int duplicate = ptr->data;
      while (ptr && ptr->data == duplicate)
      {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
      }

      if (preptr == NULL)
      {
        *start = ptr;
      }
      else
      {
        preptr->next = ptr;
      }
    }
    else
    {
      preptr = ptr;
      ptr = ptr->next;
    }
  }
}

int main()
{
  ListNode *ll;

  createList(&ll);
  deleteDuplicate(&ll);
  display(ll);

  return 0;
}