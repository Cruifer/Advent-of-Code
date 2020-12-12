filename = 'advent3.txt'
rcount = 0
treecounter = 0
char = '#'

with open(filename) as file_object:
    lines = file_object.readlines()

for i in range(1, len(lines)):
    chars = list(lines[i])
    rcount += 3
    if rcount >= len(chars) - 1:
        rcount -= len(chars) - 1
    if chars[rcount] == char:
        treecounter += 1
print(treecounter)

