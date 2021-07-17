#include <stdlib.h>
#include "read_data.h"
#include "calc_vsf.h"
#include "display_info.h"
#include "vars.h"

void freeList(Node *head){
	Node *aux = head->next;
	while(aux != NULL){
		free(head);
		head = aux;
		aux = aux->next;
	}
}

void freeListVSF(NodeVSF *headVSF){
	NodeVSF *aux = headVSF->next;
	while(aux != NULL){
		free(headVSF);
		headVSF = aux;
		aux = aux->next;
	}
}

int main(void){
	Node *head = createList("data.txt");
	NodeVSF *headVSF = createListVSF(head);
	displayListVSF(headVSF);
	freeListVSF(headVSF);
	freeList(head);
	return 0;
}

