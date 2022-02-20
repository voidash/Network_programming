
#include <stdio.h>
#include <string.h>
#include <sys/types.h> // defines system data types in system source code, for example pid_t type
#include <netdb.h> //definitions for network database operations
#include <arpa/inet.h> //definitions for internet operations
#include <netinet/in.h> //contains definitions for internet protocol family


int main(int argc, char* argv[]) {
	struct addrinfo hints, *res, *p;

	int status;
	char ipstr[INET6_ADDRSTRLEN];

	if(argc != 2) {
		fprintf(stderr, "usage: showip hostname \n");
		return 1;
	}

	memset(&hints,0,sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0){
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		return 2;
	}

	printf("IP Address for %s: \n\n", argv[1]);
	for(p=res; p!=NULL;p = p->ai_next){
		void *addr;
		char *ipver;

		if(p->ai_family == AF_INET) {

		}
	}
	

}
