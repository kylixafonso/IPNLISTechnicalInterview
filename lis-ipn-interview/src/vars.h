#ifndef VARS_H
#define VARS_H

#define MSL 255

typedef struct Content {
	char id[MSL];
	char idParent[MSL];
	char name[MSL];
	char quantity[MSL];
	char price[MSL];
} Content;

typedef struct Node {
	Content content;
	struct Node *next;
} Node;

typedef struct NodeVSF {
	char name[MSL];
	float VSF;
	struct NodeVSF *next;
} NodeVSF;

#endif // VARS_H
