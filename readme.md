
# Corewar

Last project on the branch first internship. The Corewar is a complete final project with 3 students per teams. The purpose of a project is the coding an arena that fights ASM minimalist software.

The project is split in 3 softwares :
- Vm Arena
- ASM Compiler
- ASM Decompiler

> What is Corewar?
- Corewar is a very peculiar game. It’s about bringing “players” together around a
“virtual machine”, which will load some “champions” who will fight against one another
with the support of “processes”, with the objective being for these champions
to stay “alive”.
- The processes are executed sequentially within the same virtual machine and memory
space. They can therefore, among other things, write and rewrite on top of
each others so to corrupt one another, force the others to execute instructions that
can damage them, try to rewrite on the go the coding equivalent of a Côtes du
Rhône 1982 (that is one delicious French wine!), etc...
- The game ends when all the processes are dead. The winner is the last player
reported to be “alive”

## VM arena

Virtual Machine arena built in C with implementation specification from both PDF file and VM provide in example

> It’s the “arena” in which your champions will be executed.
It offers various functions, all of which will be useful for the battle of the champions.
Obviously, the virtual machine should allow for numerous simultaneous processes;
we are asking you for a gladiator fight, not a one-man show simulator.

The ncurses graphical option :
![arena](https://github.com/panaC/corewar/blob/master/img/Screen%20Shot%202018-10-16%20at%204.08.05%20PM.png)

During the fights with 4 players :

> ./corewar -s champs/championships/2017/agregoir/Kittystrophic.cor champs/championships/2017/iburel/gateau.cor champs/championships/2017/adenis/Explosive_Kitty.cor -n 2 champs/championships/2017/tbillard/Douceur_power.cor

![fights](https://github.com/panaC/corewar/blob/master/img/Screen%20Shot%202018-10-16%20at%204.20.02%20PM.png)

### op-code

![op-code](https://github.com/panaC/corewar/blob/master/img/Screen%20Shot%202018-05-14%20at%204.07.37%20PM.png)

- lfork: means long-fork, to be able to fork abut straw from a distance of 15 meters,
exactly like with its opcode. Same as a fork without modulo in the address.
- sti: Opcode 11. Take a registry, and two indexes (potentially registries) add the
two indexes, and use this result as an address where the value of the first parameter
will be copied.
- fork: there is no argument’s coding byte, take an index, opcode 0x0c. Create a
new process that will inherit the different states of its father, except its PC, which
will be put at (PC + (1st parameter % IDX_MOD)).
- lld: Means long-load, so it’s opcode is obviously 13. It the same as ld, but
without % IDX_MOD. Modify the carry.
- ld: Take a random argument and a registry. Load the value of the first argument
in the registry. Its opcode is 10 in binary and it will change the carry.
- add: Opcode 4. Take three registries, add the first two, and place the result in the
third, right before modifying the carry.
- zjmp: there’s never been, isn’t and will never be an argument’s coding byte behind
this operation where the opcode is 9. It will take an index and jump to this address
if the carry is 1.
- sub: Same as add, but with the opcode est 0b101, and uses a substraction.
- ldi: ldi, ldi, as per the name, does not imply to go swimming in chestnut cream,
even if its code is 0x0a. Instead, it will use 2 indexes and 1 registry, adding the first
two, treating that like an address, reading a value of a registry’s size and putting
it on the third.
- or: This operation is an bit-to-bit OR, in the same spirit and principle of and, its
opcode is obviously 7.
- st: take a registry and a registry or an indirect and store the value of the registry
toward a second argument. Its opcode is 0x03. For example, st r1, 42 store the
value of r1 at the address (PC + (42 % IDX_MOD))
- aff: The opcode is 10 in the hexadecimal. There is an argument’s coding byte,
even if it’s a bit silly because there is only 1 argument that is a registry, which is a
registry, and its content is interpreted by the character’s ASCII value to display on
the standard output. The code is modulo 256.
- live: The instruction that allows a process to stay alive. It can also record that
the player whose number is the argument is indeed alive. No argument’s coding
byte, opcode 0x01. Oh and its only argument is on 4 bytes.
14
Algorithmic Project I corewar
- xor: Acts like and with an exclusive OR. As you will have guessed, its opcode in
octal is 10.
- lldi: Opcode 0x0e. Same as ldi, but does not apply any modulo to the addresses.
It will however, modify the carry.
- and: Apply an & (bit-to-bit AND) over the first two arguments and store the result
in a registry, which is the third argument. Opcode 0x06. Modifies the carry.

## ASM Compiler

> this is the program that will compile your champions and translate
them from the language you will write them in (assembly language) into “Bytecode”.Bytecode
is a machine code, which will be directly interpreted by the virtual
machine.

## Usage

`ONLY MAC COMPATIBLE`
> Compatible with UBUNTU/Debian when libtools is installing

```
~/Documents ❯❯❯ cd corewar
~/D/corewar ❯❯❯ ./corewar
./corewar [-v 0-8 -s] [-dump nbr_cycles] [[-n number] champ1.cor] ...

The Corewar ASM Championship Arena VM

 Option :
	-v : 1 to 8 verbose level
	-s : GUI option with ncurses
	-dump : print the memory at nbr_cycles then exit
	-h : print this help then exit

 For each champions -n number allow the place modification

~/D/corewar ❯❯❯ ./asm
./asm [champs.s]
~/D/corewar ❯❯❯ ./desasm
Usage : ./desasm file_name
~/D/corewar ❯❯❯
```

## ressources

- [PDF subject](https://cdn.intra.42.fr/pdf/pdf/963/corewar.en.pdf)
- [Flowchart](https://drive.google.com/file/d/1uXV56JA1NcN8Y7EfY1jYNp7gSHuubK4f/view?usp=sharing)
-
