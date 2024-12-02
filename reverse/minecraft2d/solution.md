# Challenge Reverse - Minecraft2D
Retrouver le flag dans le ciel.

## Solution
Il y a plusieurs solutions possibles, je vous en décrire une ici.

Une première solution est de patcher le fichier `.jar` en modifier directement le code compilé dans les fichiers class. Pour faire simple, il y a deux variables qui vont permettre d'augmenter la hauteur de saut du joueur ainsi que vitesse du saut. En modifiant ces deux variables, on peut aisément monter dans le ciel et trouver le flag.
```bash
# Installer Recaf
https://github.com/Col-E/Recaf/releases

# Lancer le logiciel Recaf pour decompiler Minecraft2D.jar
java -jar recafXXXX-with-dependencies.jar

# On ouvre Minecraft2D.jar
File -> Load

# On trouve le fichier "Mob"
classes -> model -> Mob

# On modifie les variables suivantes. Par défaut, on saute de 2 blocs en 200ms :
    public static long JUMP_DELAY = 200L;
    public static long JUMP_HEIGHT = BLOCK_SIZE * 2f;

# Par exemple, ici vous allez sauter de 400 blocs vers le haut en 3s
# Le flag est écrit sous forme de blocs à 300 blocs de hauteur.
# En sautant de 400 blocs en 3s, il y a assez de marge pour pouvoir retomber sur les lettres
    public static long JUMP_DELAY = 3000L;
    public static long JUMP_HEIGHT = BLOCK_SIZE * 400f;

# On peut par exemple, se poser sur une lettre du texte en hauteur puis changer
# la puissance du saut pour pouvoir sauter de lettre en lettre :
# 8 blocs de hauteur en 2s est plutot correct.
    public static long JUMP_DELAY = 2000L;
    public static long JUMP_HEIGHT = BLOCK_SIZE * 8f;

# On sauvegarde le fichier
Ctrl+S

# On exporte le nouveau ".jar"
File -> Export

# On execute le jeu
java -jar minecraft2D_patched.jar

#######################################################
# ATTENTION: parfois, il peut y avoir des problèmes   #
# lorsqu'on sauvegarde les modifications              #
#######################################################

# Ici, la variable "deltaY" n'est pas déclaré comme "int", à aucun moment
# (Pourtant c'est bien le cas dans le vrai code)
# Il semble donc qu'il peut parfois y avoir des problèmes lors de la décompilation du code
# Ici, ce problème est facilement résolvable en rajoutant un "int deltaY = 0;" au début de la fonction
public boolean update(Map map) {
    long elapsedTime;
    int x = this.getRealX();
    int y = this.getRealY();
    int deltaY = 0; ########################## ON RAJOUTE LA DECLARATION DE "deltaY" ICI
    if (this.isFalling()) {
        elapsedTime = System.currentTimeMillis() - this.moveStartTime;
        deltaY = this.getDistanceProgress(elapsedTime, JUMP_HEIGHT, JUMP_DELAY); ######### int ???
        y = this.moveStartY + deltaY;
    } else if (this.isJumping()) {
        elapsedTime = System.currentTimeMillis() - this.moveStartTime;
        deltaY = this.getDistanceProgress(elapsedTime, JUMP_HEIGHT, JUMP_DELAY); ######### int ???
        y = this.moveStartY - deltaY;
        if (elapsedTime >= JUMP_DELAY) {
            this.setJumping(false);
        }
    }
```

On précise que:
- le flag est écrit sous forme de blocs à 300 blocs de hauteur à l'origine de la map, c'est à dire les coordonnées où le personnage est placé au premier lancement du jeu.
- Si le jeu bug ou ne fonctionne plus correctement, vous pouvez "reset" la map en utilisant la backup (`cp minecraft2d.save.backup minecraft2d.save`)