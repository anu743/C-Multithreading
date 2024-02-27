#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#define PORT 8080

int main()
{
	int status , valread, client_fd;
        struct sockaddr_in serv_addr;

	char *hello="hello from client";
	char buff[1024]={0};

	if((client_fd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("socket creation failed");
		return -1;
	}

	serv_addr.sin_family=AF_INET;

	serv_addr.sin_port=htons(PORT);


	if(inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr)<0)
	{
		printf("invalid address, not supported");
		return -1;
	}

	if(status=connect(client_fd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
	{
		printf("connect failed on client");
		return -1;
	}


	send(client_fd, hello,strlen(hello),0);

	printf("\nhello message sent from client\n");

	valread=read(client_fd,buff,1024-1);

	printf("%s\n",buff);
	close(client_fd);

	return 0;
}
