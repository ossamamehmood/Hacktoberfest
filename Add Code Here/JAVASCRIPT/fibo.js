var a, b, i;
[a, b] = [0, 1]
for (i = 0; i <= 5; i++) {
    [a, b] = [b, a + b]
    console.log(a)
}