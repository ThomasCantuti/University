.text
li $v0, 5 #carico codice della syscall in $v0
syscall

#stampo valore letto

add $a0, $v0, $zero #travaso dal valore letto a $a0
li $v0, 1 #syscall per la scrittura di un intero
syscall