#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
	int data;
	struct node *next;
};

struct node *reverseNode(node *root);

int main() {
	struct node *a = malloc(sizeof(struct node));
	struct node *b = malloc(sizeof(struct node));

	a->data = 4;
	b->data = 5;
	b->next = NULL;

	a->next = b;

	struct node *c = reverseNode(a);

	while (c != NULL) {
		printf("%d\n", c->data);
		c = c->next;
	}

	return 0;
}

struct node *reverseNode(node *root) {
	node *currentNode = root;
	node *nextNode, *prevNode = NULL;

	while (currentNode != NULL) {
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}

	return prevNode;
}
