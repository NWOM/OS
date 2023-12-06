#!/bin/bash

echo "Enter the range (start and end numbers separated by space):"
read start_num end_num

echo "Prime numbers between $start_num and $end_num are:"

for ((number=start_num; number<=end_num; number++))
do
    is_prime=true
    
    # Check if the number is less than 2
    if [ $number -lt 2 ]; then
        is_prime=false
    fi
    
    # Loop to check for factors of the number
    for ((i=2; i*i<=number; i++))
    do
        if [ $((number % i)) -eq 0 ]; then
            is_prime=false
            break
        fi
    done
    
    # Display the prime numbers
    if $is_prime; then
        echo $number
    fi
done
