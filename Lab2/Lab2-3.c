#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
  int val;
  struct ListNode* next;
  struct ListNode* prev;
} ListNode;

int createList(ListNode** start, ListNode** end) {
  char result[32];
  ListNode* newNode, * ptr;
  *start = NULL;
  int count = 0;
  while (1) {
    scanf("%s", result);
    if (strcmp(result, "END") == 0) {
      *end = ptr;
      break;
    }

    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = atoi(result);
    newNode->next = NULL;
    newNode->prev = NULL;
    if (*start == NULL) {
      *start = newNode;
    }
    else {
      ptr->next = newNode;
      newNode->prev = ptr;
    }
    ptr = newNode;
    count++;
  }
  return count;
}

int isPalindrome(ListNode* start, ListNode* end, int n) {
  ListNode* nextPtr = start, * prevPtr = end;
  for (int i = 0; i < n / 2; i++) {
    if (nextPtr->val != prevPtr->val)
      return 0;
    nextPtr = nextPtr->next;
    prevPtr = prevPtr->prev;
  }
  return 1;
}

int toPalindrome(ListNode* start, ListNode* end, int n) {
  ListNode* ptr = start;
  ListNode* temp = ptr;
  int index = 0;
  if (ptr == NULL || isPalindrome(start, end, n)) {
    return -1;
  }
  while (index < n - 1) {
    int checkPalindrome = 0;
    if (ptr == start) {
      checkPalindrome = isPalindrome(start->next, end, n);
    }
    else if (ptr == end) {
      checkPalindrome = isPalindrome(start, end->prev, n);
    }
    else {
      ptr->prev->next = ptr->next;
      ptr->next->prev = ptr->prev;
      checkPalindrome = isPalindrome(start, end, n);
      ptr->prev->next = ptr;
      ptr->next->prev = ptr;
    }

    if (checkPalindrome) {
      return index;
    }
    index++;
    ptr = ptr->next;
  }

  return -1;
}

int main(void) {
  ListNode* li, * reverseli;
  int n = createList(&li, &reverseli);
  int index = toPalindrome(li, reverseli, n);
  if (index == -1) {
    printf("None");
  }
  else {
    printf("%d", index);
  }
  return 0;
}