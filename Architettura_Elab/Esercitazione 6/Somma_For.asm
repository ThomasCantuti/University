.data
input: .asciiz "Enter a positive number: "

.text
# inizializzo registri
li $s0, 0 # count
li $s1, 0 # sum
li $s2, 0 # num
li $s3, 10 # fine conteggio
la $a0, input
li $v0, 4
syscall
li $v0, 5
syscall
move $s2, $v0

# for_loop
loop_label:
beq $s0, $s3, esci_label
add $s1, $s1, $s0

# aggiornamento count
addi $s0, $s0, 1
j loop_label

esci_label:
move $a0, $s1
li $v0, 1
syscall
li $v0, 10
syscall