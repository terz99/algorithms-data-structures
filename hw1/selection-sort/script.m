% Matlab/Octave Script for plotting the run-time graph

A = load("output.txt");
x_axis = A([1:2:100]);
y_axis = A([2:2:100]);
plot(x_axis, y_axis, 'b');
title("Runtime Selection Sort");
xlabel("N");
ylabel("Time (seconds)");
grid on;
hold on;

A = load("best_cases.txt");
x_axis = A([1:2:100]);
y_axis = A([2:2:100]);
plot(x_axis, y_axis, 'r');
hold on;

A = load("worst_cases.txt");
x_axis = A([1:2:100]);
y_axis = A([2:2:100]);
plot(x_axis, y_axis, 'y');
hold on;