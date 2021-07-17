#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vars.h"

// find children of target id, searches for id's whose parentId == targetId
int *getChildren(Node *head, int targetId, int *counter){
	Node *aux = head;
	int *children = malloc(sizeof(int));
	if(!children){
		perror("couldn't allocate dynamic array containing children ID\n");
		free(children);
		while(aux != NULL){
			free(head);
			head = aux;
			aux = aux->next;
		}
		exit(0);
	}
	int *tmp;
	children[0] = targetId;
	while(aux != NULL){
		if(atoi(aux->content.idParent) == targetId){
			tmp = realloc(children, sizeof(int)*(*counter+1));
			if(!tmp){
				free(children);
				while(aux != NULL){
					free(head);
					head = aux;
					aux = aux->next;
				}
				exit(0);
			} else {
				children = tmp;
			}
			children[*counter] = atoi(aux->content.id);
			(*counter)++;
		}
		aux = aux->next;
	}
	return children;
}

// calculating "valorização stock artigo" of a product
float calcVSA(Node *node){
	return atoi(node->content.quantity) * atoi(node->content.price);
}

// calulating "valorização stock familia" of a family of products
float calcVSF(Node *node){
	Node *aux;
	int counter = 0;
	float VSF = 0;
	int *children = getChildren(node, atoi(node->content.id), &counter);
	for(int i = 0; i < counter; i++){
		aux = node;
		while(aux != NULL){
			if(atoi(aux->content.id) == children[i]){
				if(atoi(aux->content.quantity)){
					VSF += calcVSA(aux);
				} else {
					VSF += calcVSF(aux);
				}
				break;
			}
			aux = aux->next;
		}
	}
	free(children);
	return VSF;
}

// adds a node to the VSF linked list based on the vsf for a specific family of products
void addNodeVSF(Node *node, NodeVSF **headVSF, float vsf){
	NodeVSF *newNode = malloc(sizeof(NodeVSF));
	if(!newNode){
		perror("couldn't allocate memory for new node");
		return;
	}
	newNode->VSF = vsf;
	strcpy(newNode->name, node->content.name);
	newNode->next = NULL;
	if(*headVSF == NULL)
		*headVSF = newNode;
	else{
		NodeVSF *lastNode = *headVSF;
		while(lastNode->next != NULL){
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
	}
}

// creates a list containing the names and vsf's of all families of products in the original linked list
NodeVSF *createListVSF(Node *head){
	Node *aux = head;
	NodeVSF *headVSF = NULL;
	float vsf = 0;
	while(aux != NULL){
		if(!strcmp(aux->content.quantity, "null")){
			vsf = calcVSF(aux);
			addNodeVSF(aux, &headVSF, vsf);
		}
		aux = aux->next;
	}
	return headVSF;
}

