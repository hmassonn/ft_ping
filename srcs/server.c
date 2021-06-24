
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

#include <stdio.h>
#include <stdlib.h>
#define PORT 23

int main(void)
{ 
	int sock_err;
  /* Socket et contexte d'adressage du serveur */
    SOCKADDR_IN sin;
    SOCKET sock;
    socklen_t recsize = sizeof(sin);
    
    /* Socket et contexte d'adressage du client */
    SOCKADDR_IN csin;
    SOCKET csock;
    socklen_t crecsize = sizeof(csin);
	char buffer[32] = "Bonjour !";
	sock = socket(AF_INET, SOCK_STREAM, 0);	
	/* Création d'une socket */
	if (sock == INVALID_SOCKET) {
		printf("error in socket: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);
	/* Configuration */
	sin.sin_addr.s_addr = htonl(INADDR_ANY);  /* Adresse IP automatique */
	sin.sin_family = AF_INET;                 /* Protocole familial (IP) */
	sin.sin_port = htons(PORT);               /* Listage du port */
	sock_err = bind(sock, (SOCKADDR*)&sin, recsize);
	if (sock_err == SOCKET_ERROR) {
		printf("error in bind: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	/* Démarrage du listage (mode server) */
	if (listen(sock, 5) == SOCKET_ERROR) {
		printf("error in listen: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	/* Attente pendant laquelle le client se connecte */
	printf("Listage du port %d...\n", PORT);
	printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);
	if ((csock = accept(sock, (SOCKADDR*)&csin, &crecsize)) == INVALID_SOCKET) {
		printf("error in accept: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	send(csock, buffer, 32, 0);
	printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
	/* Fermeture de la socket client et de la socket serveur */
	printf("Fermeture de la socket client\n");
	closesocket(csock);
	printf("Fermeture de la socket serveur\n");
	closesocket(sock);
	printf("Fermeture du serveur terminée\n");
	return EXIT_SUCCESS;
}
