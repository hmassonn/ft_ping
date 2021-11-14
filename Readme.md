http://sdz.tdct.org/sdz/les-sockets.html




#  Obtenir l'identifiant d'un processus  
pid_t getpid(void); 

# Obtenir l'identifiant de l'utilisateur  
uid_t getuid(void); 

#  Traduction d'adresses et de services réseau 
int getaddrinfo(const char *node, const char *service,
                const struct addrinfo *hints,
                struct addrinfo **res);

# Lire/écrire l'heure actuelle
int gettimeofday(struct timeval *tv, struct timezone *tz);

# Convertir des adresses IPv4 et IPv6 sous forme binaire en texte  
const char *inet_ntop(int af, const void *src,
                      char *dst, socklen_t cnt);

# Créer une structure d'adresse réseau
int inet_pton(int af, const char * src, void *dst);

void exit(int status);

sighandler_t signal(int signum, sighandler_t handler);   

#  Programmer un réveil pour l'émission d'un signal
unsigned int alarm(unsigned int nb_sec);

# écrire les options d'une socket.
int setsockopt(int sockfd, int level, int optname,
             const void *optval, socklen_t optlen);

#  Recevoir un message sur une socket  
ssize_t recvmsg(int s, struct msghdr *msg, int flags);

# envoyer un message a travers une socket
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
               const struct sockaddr *dest_addr, socklen_t addrlen);

# Créer un point de communication 
int socket(int domain, int type, int protocol);   
