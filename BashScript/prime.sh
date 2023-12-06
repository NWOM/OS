#!/bin/bash

echo "Enter a number:"
read number

# Check if the number is less than 2
if [ $number -lt 2 ]; then
    echo "$number is not a prime number."
    exit
fi

is_prime=true

# Loop to check for factors of the number
for ((i=2; i*i<=number; i++))
do
    if [ $((number % i)) -eq 0 ]; then
        is_prime=false
        break
    fi
done

# Display the result
if $is_prime; then
    echo "$number is a prime number."
else
    echo "$number is not a prime number."
fi
