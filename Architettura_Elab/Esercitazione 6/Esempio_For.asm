.data

.text
# inizializzo registri
li $t0, 10 # fine conteggio
li $t1, 0 # indice i in $t1
li $v0, 1 # syscall per stampa

# verifico condizione
loop_label:
beq $t1, $t0, esci_label

# corpo del loop
move $a0, $t1
syscall

# aggiornamento indice
addi $t1, $t1, 1
j loop_label

esci_label:
li $v0, 10
syscall
