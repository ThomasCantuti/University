.data
stringa: .space 8

.text
li $v0, 8 #carico codice syscall in $v0
la $a0, stringa #indirizzo del buffer
li $a1, 8 #numero di caratteri da leggere (+ 1)
syscall # -> syscall con codice 8
li $v0, 4 #stampo la stringa letta
syscall