.data
a: .word 15
b: .word 10
c: .word 7
d: .word 2
e: .word 18
f: .word -3
z: .space 4

.text
li $t7, 0x1001
lw $t0, a
lw $t1, b
lw $t2, c
lw $t3, d
lw $t4, e
lw $t5, f
lw $t6, z

addi $s0, $t0, 10
addi $s1, $t2, -2
addi $s2, $t4, -3
addi $s3, $t0, -7

add $t0, $s0, $s1
sub $t1, $s2, $s3

li $v0, 1
add $t6, $t0, $t1
add $a0, $t6, $zero
syscall