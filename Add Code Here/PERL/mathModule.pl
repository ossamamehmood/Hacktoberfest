#!/usr/bin/perl

# Using the Package 'Calculator'
use Calculator;

print "Enter two numbers to multiply";

# Defining values to the variables
$a = 5;
$b = 10;

# Subroutine call
Calculator::multiplication($a, $b);

print "\nEnter two numbers to divide";

# Defining values to the variables
$a = 45;
$b = 5;

# Subroutine call
Calculator::division($a, $b);
