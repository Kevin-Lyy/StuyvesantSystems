#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[]){
  int shmid;
  char * data;

  shmid = shmget(0,200,0644 | IPC_CREAT);
  data = shmat(shmid,(void *)0,0);

  if(data == (char*)(-1)){
    perror("shmat");
  }
  printf("Segment was just created!\n");


  while(1){
    printf("Would you like to change the data? \n");

    char path[100];
    fgets(path,100,stdin);
    path[strlen(path)-1] = '\0';


    if(strcmp(path,"yes") == 0){
      printf("Enter the new string \n");
      fgets(path,100,stdin);
      path[strlen(path)-1] = '\0';
      strcpy(data,path);
      printf("you put in: %s \n",data);

    }

    if(strcmp(path,"no") ==0){
      printf("Fine I wasnt gonna change it anyways \n");
      printf("but do you want to delete it? \n");


      fgets(path,100,stdin);
      path[strlen(path)-1] = '\0';

      if(!strcmp(path,"yes")){
        printf("deleted\n");
        break;
      }
      else{
        printf("Shared memory: %s \n",data);
      }
    }

  }


  shmctl(shmid, IPC_RMID, NULL);
  exit(0);
  return 0;

}
