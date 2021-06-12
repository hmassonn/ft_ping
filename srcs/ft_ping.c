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

int		client(void)
{
	SOCKET sock;
    SOCKADDR_IN sin;
    char buffer[500] = "";
 
    /* Création de la socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);

    /* Configuration de la connexion */
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);

    /* Si l'on a réussi à se connecter */
    if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
    {
        printf("Connection à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
        
        /* Si l'on reçoit des informations : on les affiche à l'écran */
        if(recv(sock, buffer, 500, 0) != SOCKET_ERROR)
            printf("Recu : %s\n", buffer);
    }
    /* sinon, on affiche "Impossible de se connecter" */
    else
    {
        printf("Impossible de se connecter\n");
    }

    /* On ferme la socket */
    closesocket(sock);
 
    /* On attend que l'utilisateur tape sur une touche, puis on ferme */
    getchar();
 
    return EXIT_SUCCESS;
}

int			main(int ac, char **av)
{
	if (ac < 2 || (av[1][0] == '-' && av[1][1] == 'h'))
	{
		printf("Usage: %s [-hv] destination\n", av[0]);
		return (EXIT_FAILURE);
	}

	client();

    return 1;
}