filename = 'advent6.txt'

k = 0
u = 0
groups = []
letters = []

with open(filename) as file_object:
    lines = file_object.readlines()

for line in lines:
    if line == "\n":
        for group in groups:
            letters = letters + list(group)
        if len(groups) == 1:
            u += len(letters)
        else:
            letters.sort()
            k = 0
            for i in range(1, len(letters)):
                if letters[i] == letters[i-1]:
                    k += 1
                    if k == len(groups) - 1:
                        u += 1
                else:
                    k = 0;
        del groups[:]
        del letters[:]    
    else:
        line = line.replace("\n", "")
        groups.append(line)

print(u)
            