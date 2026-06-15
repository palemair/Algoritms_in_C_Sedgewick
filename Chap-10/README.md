# Chapitre 10 :

1. Comparez le nombre d'échanges effectués par le tri echange basique et le tri rapide
   pour un fichier constitué des clés :
   001, 011, 101, 110, 000, 001, 010, 111, 110, 010.

2. Pourquoi n'est-il pas aussi important de supprimer la récursion du tri
   échange basique que celà l'était pour le tri rapide ?

3. Transformez le tri-échange basique de manière à ignorer les bits de poids fort identiques
   pour toutes les clés. Dans quelles situations cette technique serait-elle avantageuse ?

4. Vrai ou faux : le temps d'exécution du tri basique direct ne dépend pas de l'ordre des clés dans le fichier d'entrée.
    Explicitez votre réponse. 

5. Quelle méthode basique risque d'être la plus efficace pour un fichier constitué de clés entièrement identiques.

6. Vrai ou faux : les 2 tris basiques examinent tous les bits de toutes les clés d'un fichier.
    Explicitez votre réponse. 

7. Mise à part la nécessité de disposer de suffisamment de place mémoire, quel est le désavantage majeur de la technique consistant à 
    trier la moitié gauche des bits à l'aide du tri basique direct puis de terminer par un tri par insertion ?

8. Quelle taille mémoire exacte est nécessaire pour permettre le tri basique direct, en 4 passes, de N clés sur b bits ?

9. Quel type de fichier rendra l'exécution du tri-échange basique la plus lente (pour de très grande valeurs de N)?

10. Comparer de manière empirique les 2 tris basiques pour un fichier aléatoire de 1000 clés sur 32 bits.
