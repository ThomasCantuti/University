.data
input: .asciiz "Enter a value to check divisibility with 6\n"
divisible: .asciiz "The number is divisible by 6.\n"
not_divisible: "The number is not divisible by 6.\n"

.text
li $v0, 4
la $a0, input
syscall
li $v0, 5
syscall
move $a0, $v0
jal div_6
li $v0, 10
syscall

div_6:
# push di $ra e $a0 perchè sovrascritti
addi $sp, $sp, -8
sw $ra, 4($sp)
sw $a0, 0($sp)
jal div_2
# pop di $a0 perchè mi serve
lw $a0, 0($sp)

beq $v1, $zero, branch_not_divisible
li $t0, 0
div $t0, $a0, 3
mfhi $t0
bne $t0, $zero, branch_not_divisible
li $v0, 4
la $a0, divisible
syscall
j exit

branch_not_divisible:
li $v0, 4
la $a0, not_divisible
syscall

exit:
# pop
lw $ra, 4($sp)
addi $sp, $sp, 8
jr $ra


div_2:
div $t0, $a0, 2
mfhi $t0
beq $t0, $zero, return_1
addi $t0, $t0, -1
j exitif
return_1:
addi $t0, $t0, 1
move $v1, $t0
exitif:
jr $ra