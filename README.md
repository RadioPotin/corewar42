# Corewar_42

Corewar is the final project of the Algorithm branch of 42. It is a team project of 4 individuals.

### First, what is Corewar ?

Core War is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language called Redcode.

### How does it work ?

Well, the subject requirements consists in two distinct programs and a Redcode warrior :

1. The first program is the Virtual Machine (also called Arena), where the warriors are to fight for victory. Victory goes to the warrior that has executed the `live` command last, meaning the last one alive.
2. The second one is the assembler of said warriors (also called asm), which is to turn into a binary file, any *.s* file written in the Redcode langage.
3. The Redcode warrior does not have to be overpowered, it just needs to beat a very basic one called *zork.s*. 

```Redcode
.name "Ricardinho Milos"
.comment "Il est juste trop bg mec. Tu vas perdre loser."

live %42
ld %0, r3
zjmp %511
```
