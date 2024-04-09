.data
a: .word 15
b: .word 10

.text
lw $a0, a
lw $a1, b

jal do_match
add $a0, $v0, $zero

li $v0, 1
syscall

li $v0, 10
syscall


do_match:
add $v0, $a1, $a0
jr $ra
