.data
.align 0 # allinea a multipli di 2^0 = 1
c: .byte 'c' # codice asii 0x63
.align 1 # aggiunge 2^1 = 2 di padding
s: .half 4 # allocazione in memoria di 0x0004