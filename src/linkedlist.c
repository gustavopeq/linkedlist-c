#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;

}node;

node *createLinkedList(int size);
void displayLinkedList(node *head);
node* insertSortedNode(int data, node *headLinkedList);

int main(void) {

	node *headLinkedList = NULL;
	headLinkedList = createLinkedList(5);

	if(headLinkedList == NULL)
	{
		return -1;
	}else
	{
		printf("LinkedList: \n");
		displayLinkedList(headLinkedList);

		int newNodeValue;
		printf("\nNew element value: ");
		fflush(stdout);
		scanf("%d", &newNodeValue);

		headLinkedList = insertSortedNode(newNodeValue,headLinkedList);
		displayLinkedList(headLinkedList);
	}


	return EXIT_SUCCESS;
}

node *createLinkedList(int size)
{
	printf("Creating Linked list of size %d\n", size);
	node *head = NULL;
	node *newNode = NULL;

	for (int i  = 0; i < size; i++)
	{
		newNode = (node*)malloc(sizeof(node));

		if(newNode == NULL)
		{
			printf("Memory couldn't be allocated\n");
			return NULL;
		}else
		{
			printf("Data for node %d: ", i + 1);
			fflush(stdout);
			scanf("%d", &(newNode->data));
			printf("\n");
			newNode -> next = NULL;
			if(head == NULL)
			{
				head = newNode;
			}else
			{
				node *temp = head;

				while(temp->next != NULL)
				{
					temp = temp->next;
				}

				temp -> next = newNode;
			}

		}
	}

	return head;
}

void displayLinkedList(node *head)
{
	node *temp = head;

	if(temp == NULL)
	{
		printf("Linked list cannot be null!\n");
		return;
	}

	do
	{
		printf("%d", temp->data);
		temp = temp->next;

		if(temp != NULL)
		{
			printf(" -> ");
		}
	}while(temp != NULL);
	printf("\n");
}

//This insert node assume that the linkedlist is already sorted!
node* insertSortedNode(int data, node *headLinkedList)
{
	printf("Inserting %d into linkedlist\n", data);
	if(headLinkedList == NULL)
	{
		printf("Linked list cannot be null!\n");
		return NULL;
	}

	node *p = NULL;
	p = headLinkedList;

	while(p -> next != NULL && (p -> next -> data < data))
	{
		p = p -> next;
	}

	node *newNode = NULL;
	newNode = (node*)malloc(sizeof(node));

	if(newNode == NULL)
	{
		printf("Memory couldn't be allocated!\n");
		return NULL;
	}else
	{
		newNode -> data = data;

		if(p != headLinkedList || p -> data < data)
		{
			node* temp = p -> next;
			p -> next = newNode;
			newNode -> next = temp;

			return headLinkedList;
		}else
		{
			newNode -> next = p;

			return newNode;
		}
	}
}
