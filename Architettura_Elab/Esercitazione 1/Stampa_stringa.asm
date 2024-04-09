.data
stringa: .asciiz "Ciao\n" #allocazione di una stringa in memoria

.text
la $a0, stringa #carico indirizzo di stringa in $a0
li $v0, 4 #carico codice della syscall in $v0
syscall

#codice assemblatore#
#.text
#lui $1, 0x00001001
#ori $4, $1, 0x00000000
#addi $2, $0, 0x00000004
#syscall
#codice assemblatore#