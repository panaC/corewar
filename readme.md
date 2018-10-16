
# Corewar

Last project on the branch first internship. The Corewar is a complete final project with 3 student per teams. The purpose of a project is the coding an arena that fights ASM minimalist software.

The project is split in 3 softwares :
- Vm Arena
- ASM Compiler
- ASM Decompiler

## VM arena

Virtual Machine arena built in C with implementation specification from both PDF file and VM provide in example

The ncurses graphical option :
![arena](https://github.com/panaC/corewar/blob/master/img/Screen%20Shot%202018-10-16%20at%204.08.05%20PM.png)

During the fights with 4 players :
![fights](https://github.com/panaC/corewar/blob/master/img/Screen%20Shot%202018-10-16%20at%204.20.02%20PM.png)

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
