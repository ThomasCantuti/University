.data
arr: .word 1, 2, 3, 4, 5, 6
output: .asciiz "Element found at position: "

.text
la $a0, arr # arr[n] = {1,2,3,4,5,6}
li $s0, 6 # n = 6
li $s1, 3 # key = 3

# chiamata a funzione
jal findElement

# termine programma
li $v0, 10
syscall


findElement:
# push di n e key
addi $sp, $sp, -8
sw $s0, 4($sp)
sw $s1, 0($sp)

li $s2, 0 # i = 0
lw $s3, 0($a0) # metto in $s3 il primo valore di arr[i]

# inizio for
for_loop:
blt $s2, $s0, branch_for # if i < n entra nel branch, else esci dal ciclo
j exit_for

# inizio ciclo for
branch_for:
beq $s3, $s1, branch_true # if $s3 (contiene arr[i]) == key entra nell'if, else prosegui sotto
addi $s2, $s2, 1 # i ++
sll $s4, $s2, 2 # i * 4 con risultato in $s4
add $s4, $s4, $a0 # arr[i+4] con indirizzo in $s4
lw $s3, 0($s4) # aggiorno $s3 con nuovo valore dell'array

j for_loop

# inizio if
branch_true:
# print output
li $v0, 4
la $a0, output
syscall
addi $s2, $s2, 1 # i ++
move $a0, $s2 # sposto i in $a0
# print i
li $v0, 1
syscall


exit_for:
# pop di n e key
lw $s1, 0($sp)
lw $s0, 4($sp)
addi $sp, $sp, 8
jr $ra