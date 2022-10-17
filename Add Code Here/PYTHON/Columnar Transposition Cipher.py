key = input("Enter key: ")
pl_txt = input("Enter plain text: ")
# Declaring grid to store plain text in format
grid = []
# Declaring res to store string chars
res = []

dp = []
for char in pl_txt:
    if char != " ":
        dp.append(char)
        if len(dp) == len(key):
            grid.append(dp)
            dp = []

if len(dp):
    while len(dp) != len(key):
        dp.append("?")
    grid.append(dp)

grid.insert(0, list(key))

print("This is Grid")
for row in grid:
    print(row)

for row in sorted(list(zip(*grid)), key=lambda x: x[0]):
    for alpha in row[1:]:
        if alpha != "?":
            res.append(alpha)

print("\n", "".join(res))
