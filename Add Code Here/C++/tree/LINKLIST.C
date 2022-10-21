#include<stdio.h>
#include<stdlib.h>
struct node{
	int no;
	struct node *next;
};
int main(){
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	struct node *go=head;
	int ascii10=0;
	char ans;
	int counter=1;
	while(1){
		printf("Enter value to the node :\n");
		printf("(%d). ",counter);
		scanf("%d",&go->no);
		go->next=(struct node*)malloc(sizeof(struct node));
		go=go->next;
		go->next==NULL;
		printf("a nother node?(Y/y/N/n):");
		scanf(" %c",&ans);
		printf("%c",ans);
		while(1){
			if((ans=='Y')||(ans=='y')||(ans=='N')||(ans=='n')){
				break;
			}else{
				printf("Wrong letter : ");
				scanf(" %c",&ans);
				
			}
		}
		if((ans=='N')||(ans=='n')){
			break;
		}
		counter++;
	}
	printf("The values in the linked list are :");
	go=head;
	while(go->next!=NULL){
		printf("%d ",go->no);
		go=go->next;
	}
	printf("\n");

	
	return 0;
}
