#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
} Node;
Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}
void append(Node** head,int value){
	Node* newNode = createNode(value);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}
Node* reverseList(Node* head){
	Node* pre = NULL;
	Node* current = head;
	Node* next = NULL;
	while(current != NULL){
		next = current->next;
		current->next = pre;
		pre = current;
		current = next;
	}
	return pre;
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
	Node* head = NULL;
	int n,value;
	printf("nhap so luong pt trong ds:");
	scanf("%d",&n);
	printf("nhap cac ptu:\n");
	for(int i = 0; i < n; i++){
		printf("phan tu %d:",i + 1);
		scanf("%d",&value);
		append(&head,value);
	}
	printf("danh sach ban dau:");
	printList(head);
	head = reverseList(head);
	printf("ds sau khi dao nguoc.\n");
	printList(head);
	return 0;
}

