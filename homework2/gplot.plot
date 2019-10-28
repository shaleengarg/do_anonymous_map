set terminal png size 800,500 enhanced font "Helvetica,20"
set output 'output.png'

#set yrange [0:20]
set style line 2 lc rgb 'black' lt 1 lw 1
set style data histogram
set style histogram cluster gap 1
set style fill pattern border -1
set boxwidth 0.9
set xtics format ""
set grid ytics

set title "A Sample Bar Chart"
plot "bar.dat" using 2:xtic(1) title "Dan" ls 2, \
            '' using 3 title "Sophia" ls 2, \
            '' using 4 title "Jody" ls 2, \
            '' using 5 title "Christina" ls 2

