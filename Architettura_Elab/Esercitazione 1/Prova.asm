.data
#dati statici
#array: .word 1, 6, 0, 8
#array è l'identificatore (etichetta)
#array è l'indirizzo di base
#a: .word 8
#b: .word 9
#c: .byte 8
#d: .byte 9
#e: .byte 10, 11, 12
#f: .word 5


.text
#istruzioni
#addi $s0, $zero, 0x10010000
#lb $t0, 0($s0)


#addi $v0, $zero, 10
#syscall


#li $v0, 1
#li $a0, 42
#syscall

#stampare 5 (f) a video
#la $s0, f
#addi $v0, $zero, 1
##addi $s0, $zero, 0x10010000
#li $s0, 0x10010000
#lw $a0, 0($s0)
#addi $a0, $zero, 1
#syscall
#termina esecuzione
#addi $v0, $zero, 10
#syscall
