.data
str_input: .asciiz "Inserisci un numero"
output_string_pari: .asciiz "Il numero è pari"
output_string_dispari: .asciiz "Il numero è dispari"

.text
Main:
li $v0, 4
la $a0, str_input
syscall
li $v0, 5
syscall
move $a0, $v0
jal F_pari_dispari
beq $v0, $zero, F_pari_main
la $a0, output_string_dispari
li $v0, 4
syscall
j exit_main

F_pari_main:
la $a0, output_string_pari
li $v0, 4
syscall

exit_main:
li $v0, 10
syscall

F_pari_dispari:
#li $t0, 2
#div $a0, $t0
#mfhi $t0
#beq $t0, $zero, pari
andi $v0, $a0, 0x0001
li $v0, 1
j exit

pari:
li $v0, 0

exit:
jr $ra
