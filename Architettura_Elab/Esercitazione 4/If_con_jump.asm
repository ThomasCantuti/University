.data
i: .word 3
j: .word 6

.text
# preparo condizione con registri
lw $s0, i
lw $s1, j

# condizione
slt $t0, $s0, $s1 # $t0 = 1 se i < j
bne $t0, $zero, ramo_then

# ramo else
li $s0, 1
j exit

# ramo then
ramo_then:
li $s0, 0

# Fuori dall'if
exit:
move $a0, $s0
li $v0, 1
syscall
li $v0, 10
syscall