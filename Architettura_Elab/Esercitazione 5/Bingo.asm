.data
win: .asciiz "Bingo!\n"
lose: .asciiz "no!!\n"
a: .word 6
b: .word 8
c: .word 190

.text
lw $t0, a
lw $t1, b
lw $t2, c

beq $t2, 10, next_1

exit:
li $v0, 4
la $a0, lose
syscall
li $v0, 10
syscall

next_1:
beq $t1, 8, next_2

next_2:
beq $t0, 1, exit_win
beq $t0, 2, exit_win
beq $t0, 4, exit_win
beq $t0, 6, exit_win
j exit


exit_win:
li $v0, 4
la $a0, win
syscall
li $v0, 10
syscall