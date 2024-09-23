set term png
set output "duffing.png"

set title "Duffing Oscillator"
set xlabel "t"
set ylabel "x"
set grid
plot "duffing.dat" using 1:2 with lines title "duffing"

set term png
set output "duffing_phase_space.png"

set title "Duffing Oscillator"
set xlabel "x"
set ylabel "p"
set grid
plot "duffing.dat" using 2:3 with lines title "duffing"

set term png
set output "duffing_attractor.png"

set title "Duffing Oscillator attractor"
set xlabel "x"
set ylabel "p"
set grid
plot "duffing_attractor.dat" using 2:3 with points pt 7 pointsize 0.2 title "duffing"
# plot "duffing_attractor.dat" using 2:3 with lines title "duffing"