#!/usr/bin/perl

# Perl Program for Hash creation
# and accessing its elements

# Initializing Hash by
# directly assigning values
$Fruit{'Mango'} = 10;
$Fruit{'Apple'} = 20;
$Fruit{'Strawberry'} = 30;

# printing elements of Hash
print "Printing values of Hash:\n";
print "$Fruit{'Mango'}\n";
print "$Fruit{'Apple'}\n";
print "$Fruit{'Strawberry'}\n";

# Initializing Hash using '=>'
%Fruit2 = ('Mango' => 45, 'Apple' => 42, 'Strawberry' => 35);

# printing elements of Fruit2
print "\nPrinting values of Hash:\n";
print "$Fruit2{'Mango'}\n";
print "$Fruit2{'Apple'}\n";
print "$Fruit2{'Strawberry'}\n";
