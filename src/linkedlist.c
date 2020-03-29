#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;

}node;

node *createLinkedList(int size);
void displayLinkedList(node *head);
node* insertSortedNode(int data, node *head);
node* deleteNode(int data, node *head);

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

		int nodeToRemoveValue;
		printf("\nElement value to remove: ");
		fflush(stdout);
		scanf("%d", &nodeToRemoveValue);
		headLinkedList = deleteNode(nodeToRemoveValue, headLinkedList);
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
node* insertSortedNode(int data, node *head)
{
	printf("Inserting %d into linkedlist\n", data);
	if(head == NULL)
	{
		printf("Linked list cannot be null!\n");
		return NULL;
	}

	node *p = NULL;
	p = head;

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

		if(p != head || p -> data < data)
		{
			node* temp = p -> next;
			p -> next = newNode;
			newNode -> next = temp;

			return head;
		}else
		{
			newNode -> next = p;

			return newNode;
		}
	}
}

node* deleteNode(int data, node *head)
{
	node  *p = NULL;
	node *temp = NULL;
	p = head;
	if  (head->data == data)
	{
		head = p -> next;
		free(p);
		p = NULL;
	}else
	{
		while((p != NULL) && (p->data != data))
		{
			temp = p;
			p =  p->next;
		}

		if  (p == NULL)
		{
			printf("\nNode with data %d not found... Deletion failed!!\n", data);
		}else if (p->data == data)
		{
			temp->next  =  p->next;
			free(p);
			p = NULL;
		}
	}


	return head;
}
