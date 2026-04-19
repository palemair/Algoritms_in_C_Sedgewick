set terminal png size 1024,768
set output 'curves2.png'

set logscale y 2
set key left top
set style fill transparent solid 0.5 
set border linewidth 1
set xrange[100:1000]
set style line 1 linecolor rgb 'blue' linetype 1 linewidth 1.5
set style line 2 linecolor rgb 'green' linetype 1 linewidth 1.5
set style line 3 linecolor rgb 'red' linetype 1 linewidth 1.5

set xlabel 'data size'
set ylabel 'Time in s'

plot 'ex3.dat' u 1:4 title 'N^3' with filledcurves x1 linestyle 1,\
     'ex3.dat' u 1:3 title '100 000 * N lgN' with filledcurves x1 linestyle 2,\
     'ex3.dat' u 1:2 title 'N lgN' with filledcurves x1 linestyle 3
