#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("ping: usage error: Destination address required");
    return 1;
  }
  struct hostent *host_entry;

  host_entry = gethostbyname(argv[1]);

  if (!host_entry) {
    perror("gethostbyname");
    return 1;
  }

  if (host_entry->h_addrtype != AF_INET) {
    perror("Adress is not IPV4");
    return 1;
  }

  struct in_addr **addr_list;

  addr_list = (struct in_addr **)host_entry->h_addr_list;

  if (addr_list[0] != NULL) {
    // inet_ntoa convertit l'adresse binaire en chaîne de caractères
    printf("Adresse IP: %s\n", inet_ntoa(*addr_list[0]));
  } else {
    printf("Aucune adresse IP trouvée pour cet hôte.\n");
  }

  return 0;
}
