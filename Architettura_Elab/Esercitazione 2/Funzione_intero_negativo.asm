.text
li $a0, 2147483647 # 2^31 - 1
# con la subu si può fare il "nega" di -2^31

jal nega

li $v0, 10
syscall

nega:
# metodo 1:
# nor $v0, $a0, $a0
# addi $v0, $v0, 1

# metodo 2:
# sub $v0, $zero, $a0

# metodo 3:
# sub $v0, $zero, $a0

move $a0, $v0

li $v0, 1
syscall

jr $ra
