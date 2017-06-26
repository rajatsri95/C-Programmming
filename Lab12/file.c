#include "file.h"
/* how we print your linked list to test if it is correct or not*/
void print(){
	node *ptr = head;
	while(ptr != NULL){
                printf("%d->",ptr->data);
                ptr = ptr->next;
        }
	printf("\n");
}
/* function to add a node to the list for you use in fwrite*/
void append(node * n){
	n->next = head->next;
	head->next = n;
}
/*function to get the last node for you to allow you to save it a file*/
node * getLast(){
	if(!head->next){
		return NULL;	
	}
	node * ptr = head->next->next; 
	node * tmp = head->next;
	node * prev = head;
	while(ptr != NULL){
		prev = tmp;	
		tmp = ptr;
		ptr = ptr->next;
	}
	prev->next = NULL;
	return tmp;	
}
/* read a node from file until you reach an EOF. Each node you read please save to the linked list with append()*/ 
void read_node(char * filename){
	FILE * file = fopen(filename, "rb");
	node* newNode = (node*) malloc(sizeof(node));
	while(fread(newNode,sizeof(node),1,file) > 0) {
		append(newNode);
		newNode = (node*) malloc(sizeof(node));
	}
	fclose(file);
	
	return;

}

/* USING get last keep writing to file until getLast() returns NULL
 * Please use fwrite in binary mode to do this
 * Make sure that you are setting node->next = NULL*/
void write_node(char * filename){
	FILE* file = fopen(filename,"wb");
	node* last = getLast();
	while(last != NULL) {	
		fwrite(last,sizeof(node),1,file);
		last = getLast();
	}
	fclose(file);
	return;
	
}


