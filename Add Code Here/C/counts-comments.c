#include<stdio.h>
#include<string.h>
#include<unistd.h>
int flag=0;
int mc=0;
int checker(int i, char s[]){
	flag=0;
	while(i<strlen(s)){	
		if(s[i]=='*' && s[i+1]=='/'){
			flag=1;mc++; break;
		}
		i++;
	}
	return flag;
}
int main(){
	FILE * fptr;
	char *s;
	int k=0,sc=0,i=0;
	size_t len;	
	ssize_t read;
	fptr=fopen("comment_input_file.txt","r"); //opening the file
	while((read=getline(&s, &len, fptr)) !=(-1)){
		/*printf("%s",s); */
		//printf("\n%d",strlen(s));
		//printf("%c", s[strlen(s)]-1);
		for(i=0;i<strlen(s);i++){
			if(s[i]=='/' && s[i+1]=='/'){	
				sc++;break;
			}
			if(s[i]=='/' && s[i+1]=='*'){
				flag = checker(i,s);
				while(flag==0){
					getline(&s, &len, fptr);
					flag=checker(i,s);
					
				}
			}
			
		}
	}
	printf("\nSingle line comment - %d\n",sc);
	printf("\nMulti line comments - %d\n",mc);
	return 0;
}
