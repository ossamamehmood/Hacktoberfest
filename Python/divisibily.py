# Give the number as static input and store it in a variable.
gvn_numb = 123456
# Give the other number k as static input and store it in another variable.
gvn_k = 5
# Convert the given number to a string using the str() function and store it in
# another variable.
stringnum = str(gvn_numb)
# Create a list of digits say "digtslst" using map(),list(),int functions.
digtslst = list(map(int, stringnum))
# Take another variable say "evn_prodt" and initialize it with 1.
evn_prodt = 1
# Loop in the above list of digits until the length of the "digtslst" using the for loop.
for itr in range(len(digtslst)):
    # Check if the iterator value is even or not using
    # the if conditional statement.
    if(itr % 2 == 0):
        # If the statement is true, then multiply the element of digits list at iterator value to
        # the "evn_prodt" and store it in the same variable evn_prodt.
        evn_prodt *= digtslst[itr]
# Check if the evn_prodt modulus given number k is equal to 0 or not using the if conditional
# statement.
if(evn_prodt % gvn_k == 0):
    # If the statement is true, then print "The product of digits at even places of the given
    # number is divisible by the another given number k.
    print("The Product of digits at even places of the given number{", gvn_numb,
          "} is divisible by the another given number k{", gvn_k, "}")
else:
    # If the statement is false, then print "The product of digits at even places of the given
    # number is Not divisible by the another given number k.
    print("The Product of digits at even places of the given number{", gvn_numb,
          "} is not divisible by the another given number k{", gvn_k, "}")
