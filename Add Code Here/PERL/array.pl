#!/usr/bin/perl

# Perl program to illustrate
# iteration through an array

# array creation
@arr = (11, 22, 33, 44, 55);

# Iterating through the range
print("Iterating through range:\n");

# size of array
$len = @arr;
	
for ($b = 0; $b < $len; $b = $b + 1)
{
	print "\@arr[$b] = $arr[$b]\n";
}

# Iterating through loops
print("\nIterating through loops:\n");

# foreach loop
foreach $a (@arr)
{
	print "$a ";
}
