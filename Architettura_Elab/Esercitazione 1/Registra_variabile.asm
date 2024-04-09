.data
a: .word 5 #variabile a = 5

.text
#caricamento di a in $a0
lw $a0, a
#caricamento della syscall in $v0
li $v0, 1 #syscall 1 = stampa intero di $a0
syscall
#esegue di nuovo il comando e termina
addi $v0, $zero, 10 #syscall 10 = exit
syscall
#$zero -> registro con valore 0

#Codice assemblatore#
#.text
#lui $1, 0x00001001
#lw $1, 0x00000000($1)
#addi $2, $0, 0x00000001
#syscall
#Codice assemblatore#