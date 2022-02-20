#include "stdio.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "memory.h"


// provide three input parameters , will provide res or results   
int getaddrinfo(const char *node // example.com
		,const char *service // http , port number
		,const struct addrinfo *hints 
		,struct addrinfo **res);

int main(){ 
	int status;
	struct addrinfo hints; 
	struct addrinfo *servinfo; 

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC; // IPV4 , ipv6 doesn' matter 
	hints.ai_socktype = SOCK_STREAM; // TCP
	hints.ai_flags = AI_PASSIVE; // fill in IP for me 

	if((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo erro %s\n", gai_strerror(status));
		exit(1);
	}

 return 0;
}

