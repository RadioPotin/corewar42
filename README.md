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

A hashmap is also used to manage label declaration and mention in the file. In order to prevent label double declaration or such semantic issues.

Like any compiler-like program, its functionning is separated in two distinct parts:
#### I. The front part that focuses on the source langage.
1. The lexing of the file. Each sequence of character in the file that corresponds to a regular definition of a token allocates a new node in the data structure.
2. The parsing of the data structure to assert validity of the syntax of the file.
3. A set of semantic verifications and assertions in order to prepare the encoding of the file. 

#### II. The back part that focuses on the destination langage/the output file/binary translation of the source file.
1. The writing of the header. It has a fixed size and some immutable parts. 
2. The encoding of the executable code of the file, the conversion of each instruction of the file to their corresponding sequence of binary values and the writing of them. <br> More details about header and instruction encoding [here](https://github.com/VBrazhnik/Corewar/wiki/%D0%98%D0%B7-%D0%B0%D1%81%D1%81%D0%B5%D0%BC%D0%B1%D0%BB%D0%B5%D1%80%D0%B0-%D0%B2-%D0%B1%D0%B0%D0%B9%D1%82-%D0%BA%D0%BE%D0%B4).

## Usage

```
USAGE:	./asm [Path/To/Filename.s] [--help | --h] [--token-explanation | --exp]
							[--verbose-full | --vf || --verbose | --v ]
	[asm]:
		Binary Assembler for Corewar Project.
		Arguments hierarchy go from top to low: [Filename.s] > [--h] > [--exp] > [--vf] > [--v].
		[asm] will only accept from one to the total number of available options number of
		arguments.
		See below for more info.

	[Path/To/Filename.s]:
		Filename must obey <*.s> otherwise usage will be displayed, its presence is mandatory.

OPTIONS: Options may be placed in whichever order. Unknown options will be ignored.
	[--help] or [--h]:
		Displays usage.

	[--token-explanation] or [--exp]:
		Shows meaning of tokens displayed via verbose options.

	[--verbose] or [--v]:
		Displays nature of lexical units in order of appearance in the file.
		Information on said lexical units is limited.
		Also gives limited information in case of error.

	[--verbose-full] or [--vf]:
		Displays nature of lexical units in order of appearance in the file.
		Information on said lexical units is extensive.
		Also gives extensive information in case of error.
		[--vf] also displays extensive information on the encoding of each instruction found in
		source file.
```

## Features

#### I. `make analyze`.

A rule in the makefile that launches a non-protected script that downloads clang's static analyzer, launches it while compiling the project and launches the `scanview` binary to generate a Error Log Web Page in your favourite browser.

#### II. Token explanation.

An option `[--token-explanation] or [--exp]` that displays the entierety of the lexical units that the asm's lexer can generate. It is meant to clarify the verbose options.

#### III. Verbose options.

`[--verbose] or [--v]` and `[--verbose-full] or [--vf]` are similar but distinc options.

`--vf` is more interesting for the unacquainted eye because:
1. It displays the entire sequence of tokens found in the file with extensive information about position and content of every given token.

2. It also breaks down every step of the encoding before outputing the binary file. This was indeed very useful for debugging and understanding the background of the encoding for every possible instruction.

3. Finally, it gives extensive information on the reason of any possible error. Meaning: reason of error, and possibly its position.
