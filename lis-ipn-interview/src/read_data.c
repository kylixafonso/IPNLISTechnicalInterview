#include <stdlib.h>
#include <stdio.h>
#include "vars.h"

// add a node to the linked list with content
void addNode(Node **head, Content content){
	Node *newNode = malloc(sizeof(Node));
	if(!newNode){
		perror("couldn't allocate memory for new node");
		newNode = (*head)->next;
		while(newNode != NULL){
			free(head);
			*head = newNode;
			newNode = newNode->next;
		}
		exit(0);
	}
    newNode->content = content;
    newNode->next = NULL;
    if(*head == NULL)
         *head = newNode;
    else{
        Node *lastNode = *head;
        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

// create the linked list from a txt file
Node *createList(char *path){
	FILE *fp = fopen(path, "rt");
	if(!fp){
		perror("couldn't read data file");
		exit(0);
	}
	Node *head = NULL;
	Content tmp;
	while(fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]", tmp.id, tmp.idParent, tmp.name, tmp.quantity, tmp.price) == 5)
		addNode(&head, tmp);	
	fclose(fp);
	return head;
}

