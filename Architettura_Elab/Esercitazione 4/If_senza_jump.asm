.data
i: .word 6
j: .word 6

.text
# preparo condizione con registri
lw $s0, i
lw $s1, j

# salta se condizione è falsa
slt $t0, $s0, $s1 # $t0 = 1 se i < j
beq $t0, $zero, ramo_false
li $t0, 1

ramo_false:
move $a0, $t0
li $v0, 1
syscall
li $v0, 10
syscall
