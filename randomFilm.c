#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>


int count (DIR *dir)
{
  int i = 0;
  
  while((readdir(dir)) != NULL)
      i++;

  rewinddir(dir);
  return i;
}


int main (int argc, char **argv)
{
  DIR *dir;
  struct dirent *p;
  int cpt = 0;
  int alea = 0;
  char reponse = 0;

  srand(time(NULL));

  dir = opendir(argv[1]);

  char *tab[count(dir)];

  while((p = readdir(dir)) != NULL)
    {
      if (strcmp(p->d_name, ".") == 0 || strcmp(p->d_name, "..") == 0)
      {
	continue;
      }
      else
      {
      	tab[cpt] = p->d_name;
      	//fprintf(stdout, "Type Fichier : %s\n", tab[cpt]);
      	cpt++;
      }
    }
  alea = (rand() % cpt) + 1;
  fprintf(stdout, "\n\n\t\tFichier aléatoirement choisi : %s\n\n", tab[alea]);

  closedir(dir);

  
      fprintf(stdout, "\nVoulez-vous lancer ' %s ' : (y) (n) ?\n", tab[alea]);
      scanf("%c", &reponse);
      if (reponse == 'y')
	{
	  // strcat(strcat(argv[1],"/"), argv[1]);
	  execlp("vlc","vlc",strcat(strcat(argv[1],"/"),tab[alea]),NULL);
	}
      if(reponse == 'n')
	fprintf(stdout, "Maoooooooooow !\n\n");  

  return 0;
}
