def print_start(file):
    file.write("<table border='1'>\n")
    file.write("""<tr>\n
        <th>N</th><th>Matrix O(lg(N))</th><th>Closed form O(lg(N))</th><th>Bottom Up O(N)</th><th>Naive approach O(2^N)</th>\n
    </tr>\n""")

def print_end(file):
    file.write("</table>")

def write(line, file):
    if line == None or line == "" or len(line) == 0:
        file.write("<td align='right'>N/A</td>")
    else:
        file.write("<td align='right'>{:19.6f}</td>".format(float(line)))

fwrite = open("table.html", "w")
print_start(fwrite)

f1 = open("fib_matrix.txt", "r")
f2 = open("fib_closed_form.txt", "r")
f3 = open("fib_bottom_up.txt", "r")
f4 = open("fib_naive.txt", "r")

max_lines = 45

count = 0
while count < max_lines:
    count += 1

    fwrite.write("<tr>\n")

    # matrix
    line = f1.readline().strip()
    fwrite.write("<td>{:19d}</td>".format(int(line))) # write N
    line = f1.readline().strip()
    write(line, fwrite) 

    # closed form
    line = f2.readline().strip() # skip N 
    line = f2.readline().strip()
    write(line, fwrite) 

    # bottom up
    line = f3.readline().strip() # skip N
    line = f3.readline().strip()
    write(line, fwrite) 

    # naive
    line = f4.readline().strip() # skip N
    line = f4.readline().strip()
    write(line, fwrite) 

    fwrite.write("</tr>\n")

print_end(fwrite)