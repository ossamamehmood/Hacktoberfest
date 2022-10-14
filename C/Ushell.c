#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

//Prototipos de funciones
void prompt(){
	printf("[juan@aguilera-ushell] $ ");
	fflush(stdout);
}

void trim(char* str){
	int i = 0;
	while (str[i] != '\n' ){
		i+=1;
	}
	str[i] = 0;
}

int wcount(char* line){
	int i = 0;
        int count = 0;

        //EL ciclo ayudara a contener el arreglo de strings
        while (line[i] != 0){
                while (line[i] == ' ' || line[i] == '\t'){
                        i+=1;
                }

                if(line[i] != 0){
                        count += 1;
                }else{
                        break;
                }

                while (line[i] != ' ' && line[i] != '\t' && line[i] != 0){
                        i+=1;
                }
        }
	return count;
}


char** get_args(char* line){
	char** array;
	char* ptr;

	int nstr = wcount(line);

	array = (char**)malloc((nstr+1)*sizeof(char*));
	
	ptr = strtok(line, " \t");
	array[0] = (char*)malloc((strlen(ptr)+1)*sizeof(char));
	strcpy(array[0], ptr);
		
	for(int i = 1; i < nstr; i+=1){
		ptr = strtok(NULL, " \t");
	        array[i] = (char*)malloc((strlen(ptr)+1)*sizeof(char));
		strcpy(array[i], ptr);
	}

	array[nstr] = NULL;
	return array;
}

void print_args(char** args){
	int i = 0;
	while (args[i] != NULL){
		printf("\"%s\"\n", args[i]);
		
		i+=1;
	}
}

//LIBERAR MEMORIA DINAMICA
void free_args(char** args){
	int i = 0;
	while (args[i] != NULL){
		free(args[i]);
		i+=1;
	}
	free(args);
}


int main (void){
	char buffer[256];
	char** args;

	while(1) {	
	
		prompt();
		
		fgets(buffer, 256, stdin);
		trim(buffer);

                if(strcmp(buffer, "exit") == 0){
                        return 0;

                }
	       
		if(strcmp(buffer, "quit") == 0){
                        return 0;
		}

		args = get_args(buffer);
		
		if(strcmp(args[0], "cd") == 0){
			//Devuelve al directorio principal si es erroneo
			if(chdir(args[1]) != 0){
				fprintf(stderr, "Wrong path.\n");
			}

		}else{
	
			pid_t pid = fork();

			if(pid==0){
				//Codigo del proceso hijo
			
				execvp(args[0], args);
		
				fprintf(stderr, "ERROR: wrong command.\n");
				
				free_args(args);
	
				return 1;

			}else{
				//Codigo del proceso padre
				int status;
				waitpid(pid,&status,0);
			}	
		}
	      	free_args(args);
	}
	return 0;
}
