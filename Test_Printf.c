#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	// printf("\n\n----- Test lettre %%s ----- = a string of characters 'str123'\n");
	// printf("----- Test 1 ----- = 'Bonjour %%s'\n");
	// printf("PRINTF = (Bonjour %s)\n", "str123");
	// printf("----- Test 2 ----- = 'Bonjour %%7s'\n");
	// printf("PRINTF = (Bonjour %7s)\n", "str123");
	// printf("----- Test 3 ----- = 'Bonjour %%-7s'\n");
	// printf("PRINTF = (Bonjour %-7s)\n", "str123");
	// printf("----- Test 5 ----- = 'Bonjour %%7.50s'\n");
	// printf("PRINTF = (Bonjour %7.50s)\n", "str123");
	// printf("----- Test 6 ----- = 'Bonjour %%--7s'(peut importe le nbr de '-')\n");
	// printf("PRINTF = (Bonjour %--7s)\n", "str123");
	// printf("----- Test 8 ----- = 'Bonjour %%07s' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %07s)\n", "str123");
	// printf("----- Test 9 ----- = 'Bonjour %%@7s' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %@7$s)\n", "str123");
	// printf("----- Test 10 ----- = 'Bonjour %%7#s' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %7#s)\n", "str123");

	// printf("\n\n----- Test lettre %%c ----- = a character 'c'\n");
	// printf("----- Test 1 ----- = 'Bonjour %%c'\n");
	// printf("PRINTF = (Bonjour %c)\n", 'c');
	// printf("----- Test 2 ----- = 'Bonjour %%7c'\n");
	// printf("PRINTF = (Bonjour %7c)\n", 'c');
	// printf("----- Test 3 ----- = 'Bonjour %%-7c'\n");
	// printf("PRINTF = (Bonjour %-7c)\n", 'c');
	// printf("----- Test 4 ----- = 'Bonjour %%+7c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %+7c)\n", 'c');
	// printf("----- Test 5 ----- = 'Bonjour %%7.50c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %7.50c)\n", 'c');
	// printf("----- Test 6 ----- = 'Bonjour %%--7c' (peut importe le nbr de '-')\n");
	// printf("PRINTF = (Bonjour %--7c)\n", 'c');
	// printf("----- Test 7 ----- = 'Bonjour %%++7c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %++7c)\n", 'c');
	// printf("----- Test 8 ----- = 'Bonjour %%07c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %07c)\n", 'c');
	// printf("----- Test 9 ----- = 'Bonjour %%@7c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %@7$c)\n", 'c');
	// printf("----- Test 10 ----- = 'Bonjour %%7#c' == Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %7#c)\n", 'c');

	// printf("\n\n----- Test lettre %%d ----- = a number 123\n");
	// printf("----- Test 1 ----- = 'Bonjour [%%d]'		== Affiche simplement le chiffre\n");
	// printf("PRINTF = (Bonjour %d)\n", 123);
	// printf("----- Test 2 ----- = 'Bonjour [%%7d]' 		== Met 7 'espace' avant le chiffre\n");
	// printf("PRINTF = (Bonjour %7d)\n", 123);
	// printf("----- Test 3 ----- = 'Bonjour [%%-7d]'		== Met 7 'espace' apres le chiffre grace au '-'\n");
	// printf("PRINTF = (Bonjour %-7d)\n", 123);
	// printf("----- Test 3 ----- = 'Bonjour [%%-+7d]'		== Met 7 'espace' apres le chiffre grace au '-' et ajoute '+' devant le chiffre\n");
	// printf("PRINTF = (Bonjour %-+7d)\n", 123);
	// printf("----- Test 3 bis ----- = 'Bonjour [%%-d]'	== Ne fait rien de plus qu'afficher le chiffre\n");
	// printf("PRINTF = (Bonjour %-d)\n", 123);
	// printf("----- Test 4 ----- = 'Bonjour [%%+7d]' 		== Met un '+' devant le chiffre\n");
	// printf("PRINTF = (Bonjour %+7d)\n", 123);
	// printf("----- Test 7 ----- = 'Bonjour [%%++7d]'		== Peut importe le nbr de '+' met un plus devant le chiffre\n");
	// printf("PRINTF = (Bonjour %++7d)\n", 123);
	// printf("----- Test 4bis ----- = 'Bonjour [%%+7d]'	== Sauf si chiffre negatif (ici -123), laisse en negatif\n");
	// printf("PRINTF = (Bonjour %+7d)\n", -123);
	// printf("----- Test 5 ----- = 'Bonjour [%%7.5d]' 	== Tient compte du 7 pour les espaces avant le chiffre et met 5 '0' -> le chiffre et les 0 on la priorite et reduise les espaces\n");
	// printf("PRINTF = (Bonjour %7.1d)\n", 123);
	// printf("----- Test 5 ----- = 'Bonjour [%%-7.5d]' 	== Tient compte du 7 pour les espaces avant le chiffre et met 5 '0' -> le chiffre et les 0 on la priorite et reduise les espaces\n");
	// printf("PRINTF = (Bonjour %-7.5d)\n", 123);
	// printf("----- Test 5bis ----- = 'Bonjour [%%.5d]' 	== C'est le '.' qui permet de mettre 5 '0' devant le chiffre moins les chiffres de %%d\n");
	// printf("PRINTF = (Bonjour %.5d)\n", 123);
	// printf("----- Test 6 ----- = 'Bonjour [%%--7d]' 	== Peut importe le nbr de '-' met des espace apres le chiffre\n");
	// printf("PRINTF = (Bonjour %--7d)\n", 123);
	// printf("----- Test 8 ----- = 'Bonjour [%%07d]'		== Remplis de '0' en soustrayant le nombre de chiffre a afficher\n");
	// printf("PRINTF = (Bonjour %07d)\n", 123);
	// printf("----- Test 8 ----- = 'Bonjour [%%-07d]'		== Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %07d)\n", 123);
	// printf("----- Test 8 ----- = 'Bonjour [%%+07d]'		== Remplis de '0' et met un '+' devant le nombre de chiffre a afficher\n");
	printf("PRINTF = (Bonjour %-0*d)\n", 50,  123);
	// printf("----- Test 8 ----- = 'Bonjour [%%70d]'		== Met des 70 espace avant d'afficher le nombre\n");
	// printf("PRINTF = (Bonjour %70d)\n", 123);
	// printf("----- Test 9 ----- = 'Bonjour [%%@7d]' 		== Caractere non reconnue - Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %@7$d)\n", 123);
	// printf("----- Test 10 ----- = 'Bonjour [%%7#d]' 	== Caractere non reconnue - Undifined behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %7#d)\n", 123);
	// printf("----- Test 11 ----- = 'Bonjour [%%*d]'		== * Prend le chiffre en parametre et remplace '*'\n");
	// printf("PRINTF = (Bonjour %*d)\n", 10, 456);

	// printf("\n\n----- Test lettre %%u ----- = a unsigned int\n");
	// printf("----- Test 1 ----- = 'Bonjour [%%u]' 123		== Affiche simplement le chiffre\n");
	// printf("PRINTF = (Bonjour %u)\n", 123);
	// printf("----- Test 2 ----- = 'Bonjour [%%u]' -123	== Bug -> il faut un unsigned\n");
	// printf("PRINTF = (Bonjour %u)\n", -123);
	// printf("----- Test 3 ----- = 'Bonjour [%%100u]' 123	== Espace a gauchedu chiffre (soustrayant les 3 chiffres)\n");
	// printf("PRINTF = (Bonjour %100u)\n", 123);
	// printf("----- Test 3 ----- = 'Bonjour [%%-100u]' 123	== Espace a droite du chiffre (soustrayant les 3 chiffres)\n");
	// printf("PRINTF = (Bonjour %-100u)\n", 123);


	// printf("\n\n----- Test lettre %%i ----- = print an integer 123\n");
	// printf("----- Test 1 ----- = 'Bonjour [%%i]'		== Affiche simplement le chiffre\n");
	// printf("PRINTF = (Bonjour %i)\n", 123);
	// printf("----- Test 2 ----- = 'Bonjour [%%7i]' 		== Met 7 'espace' avant le chiffre\n");
	// printf("PRINTF = (Bonjour %7i)\n", 123);
	// printf("----- Test 3 ----- = 'Bonjour [%%-7i]'		== Met 7 'espace' apres le chiffre grace au '-'\n");
	// printf("PRINTF = (Bonjour %-7i)\n", 123);
	// printf("----- Test 5 ----- = 'Bonjour [%%-i]'		== Ne fait rien ie plus qu'afficher le chiffre\n");
	// printf("PRINTF = (Bonjour %-i)\n", 123);
	// printf("----- Test 9 ----- = 'Bonjour [%%7.5i]' 		== Tient compte iu 7 pour les espaces avant le chiffre et met 5 '0' -> le chiffre et les 0 on la priorite et reiuise les espaces\n");
	// printf("PRINTF = (Bonjour %7.1i)\n", 123);
	// printf("----- Test 10 ----- = 'Bonjour [%%-7.5i]' 	== Tient compte iu 7 pour les espaces avant le chiffre et met 5 '0' -> le chiffre et les 0 on la priorite et reiuise les espaces\n");
	// printf("PRINTF = (Bonjour %-7.5i)\n", 123);
	// printf("----- Test 11 ----- = 'Bonjour [%%.5i]' 		== C'est le '.' qui permet ie mettre 5 '0' ievant le chiffre moins les chiffres ie %%i\n");
	// printf("PRINTF = (Bonjour %.4i)\n", 123);
	// printf("----- Test 12 ----- = 'Bonjour [%%--7i]' 	== Peut importe le nbr ie '-' met ies espace apres le chiffre\n");
	// printf("PRINTF = (Bonjour %--7i)\n", 123);
	// printf("----- Test 13 ----- = 'Bonjour [%%07i]'		== Remplis ie '0' en soustrayant le nombre ie chiffre a afficher\n");
	// printf("PRINTF = (Bonjour %07i)\n", 123);
	// printf("----- Test 14 ----- = 'Bonjour [%%-07i]'		== Uniifinei behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %-07i)\n", 123);
	// printf("----- Test 16 ----- = 'Bonjour [%%70i]'		== Met ies 70 espace avant i'afficher le nombre\n");
	// printf("PRINTF = (Bonjour %70i)\n", 123);
	// printf("----- Test 17 ----- = 'Bonjour [%%@7i]' 		== Caractere non reconnue - Uniifinei behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %@7$i)\n", 123);
	// printf("----- Test 18 ----- = 'Bonjour [%%7#i]' 		== Caractere non reconnue - Uniifinei behavior avec -Werror\n");
	// // printf("PRINTF = (Bonjour %7#i)\n", 123);
	// printf("----- Test 19 ----- = 'Bonjour [%%*i]'		== * Preni le chiffre en parametre et remplace '*'\n");
	// printf("PRINTF = (Bonjour %*i)\n", -10, 456);

	// printf("\n\n----- Test lettre %%s ----- = print an array Bonjour\n");
	// printf("----- Test 1 ----- = '[%%s]'	== Affiche simplement la string\n");
	// printf("PRINTF = (%s)\n", "Bonjour");
	// printf("----- Test 2 ----- = '[%%.4s]'	== Permet de Limiter l'affichage de la variable a 4 WIDTH\n");
	// printf("PRINTF = (%.4s)\n", "Bonjour");
	// printf("----- Test 3 ----- = '[%%6s]'	== Alloue 6 WIDTH MIN a l'argument a afficher et printf imprime le tout\n");
	// printf("PRINTF = (%6s)\n", "Bonjour");
	// printf("----- Test 3 ----- = '[%%1.6s]'	== Alloue 6 WIDTH MIN a l'argument a afficher et limite a 4 WIDTH la variable\n");
	// printf("PRINTF = (%6.6s)\n", "Bonjour");


	// int a = 10;
	// int *ptr_a = &a;

	// printf("\n\n----- Test lettre p ----- = a pointer argument is printed in hexadecimal\n");
	// printf("----- Test 1 ----- = 'Bonjour [%%p]' 123\n");
	// printf("PRINTF = (Bonjour %.p)\n", ptr_a);

	return (0);
}