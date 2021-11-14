http://sdz.tdct.org/sdz/les-sockets.html





pid_t getpid(void); 
#  Obtenir l'identifiant d'un processus  

uid_t getuid(void); 
# Obtenir l'identifiant de l'utilisateur  

int getaddrinfo(const char *node, const char *service,
                const struct addrinfo *hints,
                struct addrinfo **res);
#  Traduction d'adresses et de services réseau 

int gettimeofday(struct timeval *tv, struct timezone *tz);
# Lire/écrire l'heure actuelle

const char *inet_ntop(int af, const void *src,
                      char *dst, socklen_t cnt);
# Convertir des adresses IPv4 et IPv6 sous forme binaire en texte  

int inet_pton(int af, const char * src, void *dst);
# Créer une structure d'adresse réseau

void exit(int status);

sighandler_t signal(int signum, sighandler_t handler);   

unsigned int alarm(unsigned int nb_sec);
#  Programmer un réveil pour l'émission d'un signal

int setsockopt(int sockfd, int level, int optname,
             const void *optval, socklen_t optlen);
# écrire les options d'une
       socket.
       
ssize_t recvmsg(int s, struct msghdr *msg, int flags);
#  Recevoir un message sur une socket  

ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
               const struct sockaddr *dest_addr, socklen_t addrlen);
# envoyer un message a travers une socket

int socket(int domain, int type, int protocol);   
# Créer un point de communication   -->
