set terminal png size 1024,768
set output 'f.png'
set key left top
set style fill transparent solid 0.5 
set border linewidth 1
set style line 1 linecolor rgb 'light-blue' linetype 1 linewidth 1.5
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 1.5
set yrange [-50:200]
set grid
set xtics 1

set xlabel 'x'
set ylabel 'f(x)'

plot 'log.dat' u 1:2 title '10 * N * LgN - 2 * N^2' with filledcurves x1 linestyle 1,\
     'log.dat' u 1:3 title 'x = 0' with filledcurves x1 linestyle 2

