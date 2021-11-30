#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include<unistd.h>
#define SIZE 1024
int main(int argc,char *argv[]){
  int e;FILE *fp;char name[100],a[100];int flag=0;char name1[100],pass1[100],pass[100];

  int sockfd, new_sock;
  struct sockaddr_in server_addr, new_addr;
  socklen_t addr_size;
  char buffer[SIZE];
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("--->Error in socket<---");
    exit(1);
  }
  printf("///Server socket created successfully///.\n");

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = atoi(argv[1]);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  e = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if(e < 0) {
    perror("Error in bind");
    exit(1);
  }
  printf("--->Binding successful<---\n");

  if(listen(sockfd, 10) == 0){
		printf("....Listening....\n");
	}else{
		perror("Error in listening");
    exit(1);
	}
  addr_size = sizeof(new_addr);
  new_sock = accept(sockfd, (struct sockaddr*)&new_addr, &addr_size);
  recv(new_sock,&name,sizeof(name),0);
  recv(new_sock,&pass,sizeof(pass),0);
	    fp=fopen("/home/ssv/Desktop/compare.txt","r");
	    while(1)
	    {
	        if(fscanf(fp,"%s",name1)==EOF)
	          break;
	        if(fscanf(fp,"%s",pass1)==EOF)
	          break;
	        if(strcmp(name1,name)==0 && strcmp(pass1,pass)==0)
	        {
	            flag=1;
	            break;
	        }
	    }
	    if(flag==1)
	       send(new_sock,&flag,sizeof(flag),0);
	   else
	    send(new_sock,&flag,sizeof(flag),0);
	    fclose(fp);
  printf("...Result Sent Successfully...\n");

	printf("-->Closing the connection<--\n");
  close(sockfd);
  return 0;
}

