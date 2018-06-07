% Matlab/Octave Script for plotting the run-time graph

A = load("fib_naive.txt");
x_axis = log2(A([1:2:32]));
y_axis = A([2:2:32]);
plot(x_axis, y_axis, 'b');
grid on;
hold on;

A = load("fib_closed_form.txt");
x_axis = log2(A([1:2:146]));
y_axis = A([2:2:146]);
plot(x_axis, y_axis, 'r');
hold on;

A = load("fib_matrix.txt");
x_axis = log2(A([1:2:146]));
y_axis = A([2:2:146]);
plot(x_axis, y_axis, 'y');
hold on;

A = load("fib_bottom_up.txt");
x_axis = log2(A([1:2:82]));
y_axis = A([2:2:82]);
plot(x_axis, y_axis, 'g');
hold on;

title("Runtime of Fibonacci Approaches");
xlabel("lg(N)");
ylabel("Time (seconds)");
legend("Naive approach", "Closed Form", "Matrix", "Bottom Up");




