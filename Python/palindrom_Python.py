
test_cases = int(input())
i = 0
results = []
while(i < test_cases):
    word_1 = []
    String_1 = input()
    word_1 = list(String_1.lower())
    reverse_1 = []

    reverse_1 = word_1[::-1]

    if(word_1 == reverse_1):
        results.append("true")
    else:
        results.append("false")

    i = i+1


for i in range(len(results)):
    print(results[i])
