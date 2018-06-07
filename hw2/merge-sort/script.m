% Matlab/Octave Script for plotting the run-time graph

A = load("output.txt");
x_axis = A([1:2:200]);
y_axis = A([2:2:200]);
plot(x_axis, y_axis, 'y');
grid on;
hold on;

A = load("best.txt");
x_axis = A([1:2:200]);
y_axis = A([2:2:200]);
plot(x_axis, y_axis, 'g');
hold on;

A = load("worst.txt");
x_axis = A([1:2:200]);
y_axis = A([2:2:200]);
plot(x_axis, y_axis, 'r');
hold on;

title("Runtime Merge Sort");
xlabel("K");
ylabel("Time (seconds)");
legend("Average", "Best", "Worst");