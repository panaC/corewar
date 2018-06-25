# ToDo

## 06/06

- op_code : RAF :
	- lld
	- xor
	- or
	- and
	- live (Ajout distrubution live adverse) -> Mark OK
		- creation last_live
		- utilisation de nb_live dans env

- Corriger le bug nombre signed dans op_decod -> pierre
- Faire le test unique de chaque op_code avec les 3 types arg -> pierre
- Mettre des commentaire Verbose adapter a la visus corewar suivant lvl -> Mark/Pierre
- Faire un script de test valdrind avec differnte commande shell -> Mark
	- ex : faire un fichier script avec chaque ligne une nouvelle commande valfrind corewar differente
- Faire un script de test avec tout les champions fournis pour verifier que le joueur gagnant est le meme entre notre vm et l'officiel -> Mark
- Mettre a la norme et repasser les scripts de test pour voir si tout est OK -> Pierre/Mark
- Faire un champion a fournir avec le corewar -> Mark/Pierre
- Verifier tout les fichiers present dans le git 42 et la bon fonctionnenement avec l'asm de Lou -> Mark/Pierre


### test OP_code

 - ld : -> gestion direct et indirect corection bug indirect memoire rotative et signed
 		- gerer le carry : carry == 1 si resulat == 0 mais qu'elle resultat


## 09/06

 - Rajouter un usage lors d'un ./corewar
 - Rajouter verbose sur live avec niveau 2
 - Printer le parsing en niveau 0
 - reorganiser le verbose lvl
 - trouver l'erreur nb cycle checks
 - faire un script de test
 - reorganiser fichier git
 - faire la norme sur game_iter_process


# attention a modifier le makefile printf avant de l'envoyer sur le serveur ecole

## 25/06

- Desasm : segv sur fichier inconnu
- Desasm : n'efface pas completement le fichier precedent
- Rajouter un usage sur le corewar
- Norme sur tous les fichiers
