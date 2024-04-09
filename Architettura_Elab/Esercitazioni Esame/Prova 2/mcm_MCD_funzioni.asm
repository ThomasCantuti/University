.data
input: .asciiz "Inserire due numeri interi: "
output: .asciiz "Il minimo comune multiplo vale "

.text
li $s2, 0 # mcm
li $a0, 0 # num1
li $a1, 0 # num2
# print("inserire due numeri")
li $v0, 4
la $a0, input
syscall
# scanf("num1 e num2")
li $v0, 5
syscall
move $a0, $v0
li $v0, 5
syscall
move $a1, $v0
# chiamata funzione
jal mcm
move $s2, $v0 # valore della funzione in $s0
# stampa mcm
li $v0, 4
la $a0, output
syscall
li $v0, 1
move $a0, $s2
syscall
# termine
li $v0, 10
syscall


mcm:
# push
addi $sp, $sp, -12
sw $ra, 8($sp)
sw $a0, 4($sp)
sw $a1, 0($sp)
jal mcd
# pop di $a0, $a1 perchè mi servono
lw $a0, 4($sp)
lw $a1, 0($sp)
# programma
mult $a0, $a1 # n1 * n2
mflo $t0 # risultato in $t0
div $t0, $v1 # n1*n2 / mcd
mflo $v0 # risultato in $v0
# pop di $ra
lw $ra, 8($sp)
addi $sp, $sp, 12
jr $ra


mcd:
li $t1, 0 # resto = 0
li $s0, 0 # a
li $s1, 0 # b
move $s0, $a0
move $s1, $a1
loop:
bgt $s1, 0, branch_true # se num2 > 0 salta a branch_true
j exit_while_loop

branch_true:
div $s0, $s1
mfhi $t1
move $s0, $s1
move $s1, $t1
move $v1, $s0
j loop

exit_while_loop:
jr $ra






