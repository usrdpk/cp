#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

struct node *list_head = NULL;

void insert(struct node **head, int val)
{
	struct node *cur = *head;
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->val = val;
	new_node->next = NULL;

	if(cur == NULL){
		*head = new_node;
		return;
	}
	
	while(cur->next != NULL)
		cur = cur->next;
	cur->next = new_node;
}

int length(struct node *head)
{
	struct node *cur = head;
	int len = 0;
	while(cur != NULL){
		cur = cur->next;
		++len;
	}
	return len;
}

void delete(struct node **head, int val)
{
	struct node *cur = *head, *prev = NULL;
	while(cur != NULL && cur->val != val){
		prev = cur;
		cur = cur->next;
	}
	if(cur != NULL){
		if(prev == NULL){
			if(cur->next != NULL){
				printf("Deleting head\n");
				*head = cur->next;
				free(cur);
			}
			else
				*head = NULL;
		}
		else{
			prev->next = cur->next;
			free(cur);
		}
	}
}

void print(struct node *head)
{
	printf("List length: %d\n", length(head));
	struct node *cur = head;
	if(cur == NULL){
		printf("Empty list\n");
		return;
	}

	while(cur != NULL){
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}


int main()
{
	insert(&list_head, 1);
	print(list_head);
	insert(&list_head, 2);
	print(list_head);
	insert(&list_head, 3);
	print(list_head);
	insert(&list_head, 4);
	print(list_head);
	insert(&list_head, 5);
	print(list_head);
	delete(&list_head, 2);
	print(list_head);
	delete(&list_head, 2);
	print(list_head);
	delete(&list_head, 3);
	print(list_head);
	delete(&list_head, 4);
	print(list_head);
	delete(&list_head, 5);
	print(list_head);
	return 0;
}
