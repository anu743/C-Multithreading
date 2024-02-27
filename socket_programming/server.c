#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#define PORT 8080

int main()
{
	int server_fd,new_socket;
	ssize_t valread;
	struct sockaddr_in address;
	int opt=1;
	socklen_t addrlen = sizeof(address);
	char buf[1024]={0};
	char *hello="hello from the server";


	if((server_fd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	address.sin_family=AF_INET;
	address.sin_addr.s_addr=INADDR_ANY;
	address.sin_port=htons(PORT);

	if(bind(server_fd,(struct sockaddre *) &address,sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	if(listen(server_fd,3)<0)
	{
		perror("listen failed");
		exit(EXIT_FAILURE);
	}

	if((new_socket=accept(server_fd,(struct sockaddr*)&address,&addrlen))<0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}

	valread=read(new_socket,buf,1024-1);

	printf("%s\n",buf);

	send(new_socket,hello,strlen(hello),0);

	printf("\nmessage sent fron the server\n");
	close(new_socket);
	close(server_fd);

	return 0;
}
