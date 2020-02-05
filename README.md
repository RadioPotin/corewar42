# Corewar_42

Corewar is the final project of the Algorithm branch of 42. It is a team project of 4 individuals who's 42logins can be found in the auteur file.

### First, what is Corewar ?

Core War is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language called Redcode.

### How does it work ?

Well, the subject requirements consists in two distinct programs and a Redcode warrior :

1. The first program is the Virtual Machine (also called Arena), where the warriors are to fight for victory. Victory goes to the warrior that has executed the `live` command last, meaning the last one alive.
2. The second one is the assembler of said warriors (also called asm), which is to turn into a binary file, any *.s* file written in the Redcode langage.
3. The Redcode warrior does not have to be overpowered, it just needs to beat a very basic one called *zork.s*. Here's our hero that has been specifically designed to beat *zork*. Its efficiency against other warriors remains unproven.

```Redcode
.name "Ricardinho Milos"
.comment "Il est juste trop bg mec. Tu vas perdre loser."

live %42
ld %0, r3
zjmp %511
```

### How did we proceed ?

The workload was distributed in pairs. Two of us, jpelleti and gjuste, would work on the coding of the arena, and casautou and myself would work on the assembler program. Both programs are so intertwined that there were many an occasions for each of us to call upon the help of our peers when in doubt which happened and allowed us to work efficiently.

When significant progress was made on both sides, we merged workflows and debugged the remaining benign issues together.

### How did we make it work ?

I will now focus on the part of the project I have designed and coded: the assembler.

As far as the main data structure goes its fairy simple: to translate and encode the source material (ie: the *.s* file), we created a linked-list of heads to linked-lists of tokens where each head is the beginning of a new line in the file and each node is a token that the lexer has identified.

A hashmap is also used to manade label declaration and mention in the file.

Like any compiler-like program, its functionning is separated in two distinct parts:
#### I. The front part that focuses on the source langage.
1. The lexing of the file. Each sequence of character in the file that corresponds to a regular definition of a token allocates a new node in the data structure.
2. The parsing of the data structure to assert validity of the syntax of the file.
3. A set of semantic verifications and assertions in order to prepare the encoding of the file. 

#### II. The back part that focuses on the destination langage/the output file/binary translation of the source file.
1. The writing of the header. It has a fixed size and some immutable parts. 
2. The encoding of the executable code of the file, the conversion of each instruction of the file to their corresponding sequence of binary values and the writing of them. More details about header and instruction encoding [here](https://github.com/VBrazhnik/Corewar/wiki/%D0%98%D0%B7-%D0%B0%D1%81%D1%81%D0%B5%D0%BC%D0%B1%D0%BB%D0%B5%D1%80%D0%B0-%D0%B2-%D0%B1%D0%B0%D0%B9%D1%82-%D0%BA%D0%BE%D0%B4).

### 
