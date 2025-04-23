set terminal pdf
set output "runtime.pdf"
set size square
set xlabel "size of state (n)"
set ylabel "run time (in seconds)"
plot [0:250][0:120] "Alg3.1_elapsed_time" with linespoints, "Alg3.1_user_time" with linespoints, "Alg3.2_elapsed_time" with linespoints, "Alg3.2_user_time" with linespoints, "Alg3.3_elapsed_time" with linespoints, "Alg3.3_user_time" with linespoints

