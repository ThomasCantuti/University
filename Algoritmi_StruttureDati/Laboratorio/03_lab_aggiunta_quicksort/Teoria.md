# Passi per algoritmi di ordinamento (confronto) efficienti in pratica
1. Quicksort
2. Strategia migliorativa (euristica) per il Quicksort
    - scegliere meglio il pivot per la partizione (es. mediana di 3)
    - scegliere perfettamente il pivot (scegliere la mediana di tutti gli elementi di un array ordinato)
        - posso usare una versione ottima di Select -> median of medians
    - agire sulla ricorsione (es. usare insertion sort per piccoli array)
        - eliminare la prima tail ricorsione
        - ottimizza la ... della chiamata ricorsiva (sulla parte più piccola dell'array)
        - eliminare anche la seconda chiamata tail-ricorsiva
    - ibridazione
        - con InsertionSort
        - con HeapSort
        - con entrambi
