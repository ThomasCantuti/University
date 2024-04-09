.data
input: .asciiz "Enter a number to check whether prime or not: "
output_1: .asciiz "Entered number "
output_prime_number2: .asciiz " is a prime number."
output_not_prime_number2: .asciiz " is not a prime number."

.text
li $s0, 0 # num = 0
li $s1, 0 # i = 0
li $s2, 0 # flag = 0
# printf("Enter a number to check whether prime or not: ")
li $v0, 4
la $a0, input
syscall
# scanf("%d", &num)
li $v0, 5
syscall
move $s0, $v0
# se num == 0 o num == 1 mette flag = 1
beq $s0, 0, branch_equal
beq $s0, 1, branch_equal
j exit_if

branch_equal:
addi $s2, $s2, 1 # flag = 1

exit_if:
# inizializzo ciclo
addi $s1, $s1, 2 # i = 2
div $t0, $s0, 2 # $t0 è num / 2
for_loop:
beq $s2, 1, exit_for_loop # se flag == 1 esce dal for
ble $s1, $t0, branch_true # se i <= num/2 allora entra nel for
j exit_for_loop

branch_true:
div $s0, $s1 # num / i
mfhi $t1 # resto in $t1
beq $t1, 0, flag_1 # se resto == 0 allora flag = 1
addi $s1, $s1, 1 # incremento i di 1
j for_loop

flag_1:
addi $s2, $s2, 1 # flag = 1

exit_for_loop:
beq $s2, 0, prime_number
# print not prime number
li $v0, 4
la $a0, output_1
syscall
move $a0, $s0
li $v0, 1
syscall
li $v0, 4
la $a0, output_not_prime_number2
syscall
j termine

# print prime number
prime_number:
li $v0, 4
la $a0, output_1
syscall
move $a0, $s0
li $v0, 1
syscall
li $v0, 4
la $a0, output_prime_number2
syscall

# termine programma
termine:
li $v0, 10
syscall
