.data
input_rows: .asciiz "Enter the number of rows: "
input_columns: .asciiz "Enter the number of columns: "
a_capo: .asciiz "\n"
spazio: .asciiz " "

.text
li $s0, 0 # rows = 0
li $s1, 0 # columns = 0
li $t0, 1 # k = 1
li $t1, 1 # i = 1
li $t2, 1 # j = 1
# print(numero righe)
li $v0, 4
la $a0, input_rows
syscall
# scanf(numero righe)
li $v0, 5
syscall
move $s0, $v0
# print(numero colonne)
li $v0, 4
la $a0, input_columns
syscall
# scanf(numero colonne)
li $v0, 5
syscall
move $s1, $v0
# primo while(i <= rows)
while_loop_rows:
ble $t1, $s0, while_loop_columns # if i <= rows entra nel ciclo, else termina
j termine

while_loop_columns:
# secondo while(j <= columns)
ble $t2, $s1, branch_true_columns # if j <= columns entra nel ciclo, else termina
addi $t1, $t1, 1 # i ++
sub $t2, $t2, $t2 # j = 0
addi $t2, $t2, 1 # j = 1
# print con \n
li $v0, 4
la $a0, a_capo
syscall
j while_loop_rows # salta a loop delle righe

branch_true_columns:
# print k
move $a0, $t0
li $v0, 1
syscall
# print spazio
li $v0, 4
la $a0, spazio
syscall
addi $t0, $t0, 1 # k ++
addi $t2, $t2, 1 # j ++
j while_loop_columns # salta a loop delle colonne

# termine programma
termine:
li $v0, 10
syscall