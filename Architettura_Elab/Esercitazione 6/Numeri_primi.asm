.data
input: .asciiz "Input a number larger than 1: "
prime_number: .asciiz " is a prime number"
no_prime_number: .asciiz " is not a prime number"

.text
li $s0, 0 # x
li $s1, 0 # z
li $s2, 2 # y
la $a0, input
li $v0, 4
syscall
li $v0, 5
syscall
move $s0, $v0

for_loop:
slt $t0, $s2, $s0 # $s3 = 1 se y < x
beq $t0, $zero, exit_for # se y < x è falso esce dal for
#condizione y < x vera:
div $s0, $s2 # x / y
addi $s2, $s2, 1 # aggiorno y
mfhi $t0 # prendo resto
bne $t0, $zero, for_loop # se resto != 0 torno al for
# se resto == 0:
move $a0, $s0
li $v0, 1
syscall
la $a0, no_prime_number
li $v0, 4
syscall
addi $s1, $s1, 1


exit_for:
beq $s1, $zero, print_prime_number # se z == 0 -> x numero primo, else esci
li $v0, 10
syscall

print_prime_number:
move $a0, $s0
li $v0, 1
syscall
la $a0, prime_number
li $v0, 4
syscall
addi $s1, $s1, -1
j exit_for


