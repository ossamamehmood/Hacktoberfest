# Distribute Money to Maximum Children

## Table of Contents

1. [Introduction](#introduction)
2. [Problem Description](#problem-description)
3. [Approach](#approach)
4. [Usage](#usage)
5. [Complexity](#complexity)

## Introduction

This repository contains a C++ solution to a programming problem. The problem involves distributing a given amount of money to a specified number of children while adhering to certain rules. The goal is to maximize the number of children who receive exactly 8 dollars without anyone receiving 4 dollars.

## Problem Description

You are given an integer `money` denoting the amount of money (in dollars) that you have and another integer `children` denoting the number of children that you must distribute the money to. You have to distribute the money according to the following rules:

- All money must be distributed.
- Everyone must receive at least 1 dollar.
- Nobody receives 4 dollars.

The task is to return the maximum number of children who may receive exactly 8 dollars if you distribute the money according to the aforementioned rules. If there is no way to distribute the money satisfying these rules, return -1.

## Approach

The solution follows the following approach:

1. If `money` is less than `children`, return -1 as it's not possible to distribute.
2. Subtract one dollar from `money` for each child to distribute one dollar to each child initially.
3. Calculate `ans` as `money / 7` since there are 7 remaining dollars to distribute to make it 8 dollars for some children.

