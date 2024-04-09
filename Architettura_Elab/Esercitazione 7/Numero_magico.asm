.data
input: .asciiz "Enter your guess: "
output_right: .asciiz "Right!!! "
output_magic_number: .asciiz " is the magic number\n"
output_wrong: .asciiz "Wrong..."
output_number_higher: .asciiz "too high\n"
output_number_lower: .asciiz "too low\n"

.text
li $s0, 1325 # magic number
li $s1, 0 # user's guess
li $s2, 0 # counter i

# for
for_loop:
# condizione uscita ciclo for
beq $s2, 10, exit_for

# aggiorno i
addi $s2, $s2, 1

# input user's guess
la $a0, input
li $v0, 4
syscall
li $v0, 5
syscall
move $s1, $v0

# if: guess == magic number? --> condizione uscita for
bne $s1, $s0, branch_false

# True:
la $a0, output_right
li $v0, 4
syscall
move $a0, $s1
li $v0, 1
syscall
la $a0, output_magic_number
li $v0, 4
syscall
j exit_for

# False
branch_false:
la $a0, output_wrong
li $v0, 4
syscall
# if: guess > magic ?
sgt $t0, $s1, $s0 # guess > magic --> $t0 = 1
beq $t0, $zero, branch_low
la $a0, output_number_higher
li $v0, 4
syscall
j for_loop

branch_low:
la $a0, output_number_lower
li $v0, 4
syscall
j for_loop

exit_for:
li $v0, 10
syscall