# Equalize Frequency of Letters in a Word

## Table of Contents
- [Introduction](#introduction)
- [Problem Description](#problem-description)
- [Approach](#approach)
- [Usage](#usage)
- [Complexity](#complexity)

## Introduction

This Python solution addresses the problem of determining whether it's possible to remove one letter from a word to make the frequency of all letters equal.

## Problem Description

Given a string consisting of lowercase English letters, the goal is to select one index and remove the letter at that index from the word so that the frequency of every letter present in the word is equal.

### Example:

**Input:** "abcc"
**Output:** true
**Explanation:** Select index 3 and delete it: the word becomes "abc," and each character has a frequency of 1.

**Input:** "aazz"
**Output:** false
**Explanation:** We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.

## Approach

The approach involves counting the frequency of each letter in the word and sorting the frequencies. We then check various conditions to determine if it's possible to remove one letter to make all frequencies equal.

1. Count the frequency of each letter in the word.

2. Sort the frequencies in ascending order.

3. Check if there is only one unique frequency in the sorted list. If there's only one unique frequency, it means that all letters already have the same frequency.

4. If one letter appears exactly once (minimum frequency is 1), and all other letters have the same frequency, we return `True`. This is the case when deleting the unique letter with a frequency of 1 would equalize all frequencies.

5. Lastly, we check if the last letter appears exactly once more than every other letter, which would allow us to delete it to equalize frequencies.
