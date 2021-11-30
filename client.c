#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#define SIZE 1024
int main(int agrc,char *argv[]){
  int e;char fname[100],a[100],b[100];int res;
  int filesize;
  int sockfd;
  struct sockaddr_in server_addr;
  FILE *fp;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("Error in socket");
    exit(1);
  }
  printf("///Client socket created successfully///\n");
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = atoi(argv[2]);
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);

  e = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if(e == -1) {
    perror("Error in socket");
    exit(1);
  }
	printf("--->Connected to Server<---\n");
printf("Enter User name:- ");
scanf("%s",a);
printf("Enter Password:- ");
scanf("%s",b);
send(sockfd,&a,sizeof(a),0);
send(sockfd,&b,sizeof(b),0);
recv(sockfd,&res,sizeof(res),0);
if(res==1)
{
    printf("--->Login is Successful<---\n");
}
else
{
  printf("--->Login is Unsuccessful<---\n");
}
  printf("....Closing the connection....\n");
 close(sockfd);

  return 0;
}
