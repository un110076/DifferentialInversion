set encoding iso_8859_1
set terminal pdf
set output "memory.pdf"
set size square
set xlabel "size of state (n)"
set ylabel "memory (in mbytes)"
set logscale
plot [10:250] [1:5e4] "Alg3.2_max_rss" with linespoints, "Alg3.3_max_rss" with linespoints, "Alg3.3_tape_size" with linespoints

