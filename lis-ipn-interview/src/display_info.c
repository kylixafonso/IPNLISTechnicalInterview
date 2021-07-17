#include <stdio.h>
#include "vars.h"

// just for debugging sake - shows the content of the list
void displayList(Node *head){
	Node *aux = head;
	while(aux != NULL){
		Content data = aux->content;
		printf("%s, %s, %s, %s, %s\n",data.id, data.idParent, data.name, data.quantity, data.price);
		aux = aux->next;
	}
}

// just for debugging sake - shows the content of the list containing the VSF of each family
void displayListVSF(NodeVSF *headVSF){
	NodeVSF *aux = headVSF;
	while(aux != NULL){
		printf("VSF of %s : %f Eur\n", aux->name, aux->VSF);
		aux = aux->next;
	}
}

