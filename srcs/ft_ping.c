/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ping.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:05:58 by hmassonn          #+#    #+#             */
/*   Updated: 2021/06/12 19:26:56 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ping.h"

void		run_socket(void)
{
  /* Socket et contexte d'adressage du serveur */
    SOCKADDR_IN sin;
    SOCKET sock;
    socklen_t recsize = sizeof(sin);
    
    /* Socket et contexte d'adressage du client */
    SOCKADDR_IN csin;
    SOCKET csock;
    socklen_t crecsize = sizeof(csin);
	
	/* Création d'une socket */
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		printf("error in socket");
	printf("La socket %d est maintenant ouverte en mode TCP/IP\n", sock);
	/* Configuration */
	sin.sin_addr.s_addr = htonl(INADDR_ANY);  /* Adresse IP automatique */
	sin.sin_family = AF_INET;                 /* Protocole familial (IP) */
	sin.sin_port = htons(PORT);               /* Listage du port */
	if (bind(sock, (SOCKADDR*)&sin, recsize) == SOCKET_ERROR)
		printf("error in bind");
	/* Démarrage du listage (mode server) */
	if (listen(sock, 5) == SOCKET_ERROR)
		printf("error in listen");
	/* Attente pendant laquelle le client se connecte */
	printf("Listage du port %d...\n", PORT);
	printf("Patientez pendant que le client se connecte sur le port %d...\n", PORT);
	if ((csock = accept(sock, (SOCKADDR*)&csin, &crecsize)) == INVALID_SOCKET)
		printf("error in accept");
	printf("Un client se connecte avec la socket %d de %s:%d\n", csock, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
	/* Fermeture de la socket client et de la socket serveur */
	printf("Fermeture de la socket client\n");
	closesocket(csock);
	printf("Fermeture de la socket serveur\n");
	closesocket(sock);
	printf("Fermeture du serveur terminée\n");}

int			main(int ac, char **av)
{
	if (ac < 2 || (av[1][0] == '-' && av[1][1] == 'h'))
	{
		printf("Usage: %s [-hv] destination\n", av[0]);
		return (EXIT_FAILURE);
	}

	run_socket();

    return 1;
}