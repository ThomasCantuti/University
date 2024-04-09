.data
#uso come etichetta op1 al posto del registro $t0
.eqv op1 $t0 
.eqv op2, $t1
.eqv risultato, $t2

.text
#somma di op1 e op2 nel registro risultato
addi op1, op1, 1
addi op2, op2, 2
add risultato, op1, op2

addi $v0, $zero, 10
syscall