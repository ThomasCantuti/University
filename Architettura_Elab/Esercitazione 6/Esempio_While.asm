.data

.text
# inizializza i registri
li $t0, 10 # fine conteggio
li $t1, 0 # indice i
li $v0, 1 # syscall stampa
loop_label:
move $a0, $t1
syscall

# aggiornamento
addi $t1, $t1, 1

# Verifica condizione
slt $t2, $t1, $t0 # $t2 = 1 quando $t1 < $t0, $t2 = 0 quando $t1 == $t0
bne $t2, $zero, loop_label # $t2 = 0 -> esce, $t2 = 1 -> loop_label

li $v0, 10
syscall