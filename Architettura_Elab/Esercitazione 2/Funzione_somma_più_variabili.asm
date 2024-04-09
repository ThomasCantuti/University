.data 
a: .word 15
b: .word 10
c: .word 7
d: .word 2
e: .word 18
f: .word -3
# z: .space 4
testo: .asciiz "Il risultato vale "

.text
lw $a0, a # carico valore nel registro NO INDIRIZZO
lw $a1, b
lw $a2, c
lw $a3, d
lw $s0, e
lw $s1, f

# più di 4 argomenti
# effettuo la push
addi $sp, $sp, -8
sw $s0, 4($sp) # e nello stack
sw $s1, 0($sp) # f nello stack

# chiamata a funzione
jal do_math

# effettuo la pop
addi $sp, $sp, +8

move $t0, $v0 # sposto il valore da $v0 a $t0

la $a0, testo
li $v0, 4
syscall

move $a0, $t0
li $v0, 1
syscall

li $v0, 10
syscall

do_math:
# devo importare $s0 e $s1
# serve un puntatore -> frame pointer
addi $sp, $sp, -12
sw $fp, 8($sp)
sw $s0, 4($sp)
sw $s1, 0($sp)

# fp = sp + framesize - 4 ---> fp = sp + 12 - 4
addi $fp, $sp, 8 # assegno nuova posizione al fp

add $t0, $a0, $a1
sub $t1, $a2, $a3
lw $s0, 8($fp)
lw $s1, 4($fp)
add $t2, $s0, $s1
sub $t3, $a0, $a2

add $t0, $t0, $t1
add $t0, $t0, $t2
sub $v0, $t0, $t3

lw $s1, 0($sp)
lw $s0, 4($sp)
lw $fp, 8($sp)
addi $sp, $sp, +12
jr $ra