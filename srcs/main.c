#include <netdb.h>
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("ping: usage error: Destination address required");
    return 1;
  }
  struct hostent *host_entry;

  host_entry = gethostbyname(argv[1]);
  printf("Adress length: %s\n", host_entry->h_aliases[0]);
  return 0;
}
