.data
a: .word 15
b: .word 10
c: .word 7
d: .word 2
e: .word 18
f: .word -3
z: .space 4 #sto allocando 4 byte in memoria

.text
lui $t0, 0x1001
lw $t1, 0($t0) #a = 15
lw $t2, 4($t0) #b = 10
lw $t3, 8($t0) #c
lw $t4, 12($t0) #d
lw $t5, 16($t0) #e
lw $t6, 20($t0) #f
lw $t7, 24($t0) #z = 0

add $s0, $t1, $t2
sub $s1, $t3, $t4
add $s2, $t5, $t6
sub $s3, $t1, $t3

add $t1, $s0, $s1
sub $t2, $s2, $s3

li $v0, 1
add $t7, $t1, $t2
add $a0, $t7, $zero
syscall
