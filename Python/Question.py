#1. WAP to take two input list and form a list.
'''
listK = ["Mon", "Tue", "Wed"]
listV = [3, 6, 5]
# Given lists
print("List of K : ", listK)
print("list of V : ", listV)
# Empty dictionary
res = {}
# COnvert to dictionary
for key in listK:
    for value in listV:
        print(key,value)
        res[key] = value
        listV.remove(value)
        break
print("Dictionary from lists :",res)

'''

# 2. WAP to remove given key from a dictionary.
'''
Rainfall = {
    'SUNDAY':3.4,
    'MONDAY':5.6,
    'TEUSDAY':4.2,
    'WEDNESDAY':1.0,
    'THURSDAY':0.0,
    'FRIDAY':2.5,
    'SATURDAY':3.1
    }
print("Initial dictionary")
print(Rainfall)
key=input("Enter the key to delete(MONDAY-SATURDAY ):")
if key in Rainfall: 
    del Rainfall[key]
else:
    print("Key not found!")
    exit(0)
print("Updated dictionary")
print(Rainfall)
'''

# 3. Python prgram to check if given key exist in the dictionary or not. if exist then print it's values
'''
Rainfall = {
    'SUNDAY':3.4,
    'MONDAY':5.6,
    'TEUSDAY':4.2,
    'WEDNESDAY':1.0,
    'THURSDAY':0.0,
    'FRIDAY':2.5,
    'SATURDAY':3.1
    }
print("Rainfall=",Rainfall)
key=input("Enter the key to Find(MONDAY-SATURDAY ):")
if key in Rainfall: 
    print("Value of ",key, " is ",Rainfall[key])
else:
    print("Key not found!")
'''

# Write a python programme to find the maximum frequency of a character in a given string.
'''
string= "asansol engineering college"
print(string)

char_freq={}

for i in string:
    if i in char_freq:
        char_freq[i]=char_freq[i]+1
    else:
        char_freq[i] = 1
result= max(char_freq, key = char_freq.get)

print("Most frequent character: ",result)
'''

# write a python program to add "ing" at the end of  given string (length to should be atlest 3). If the givne stirng already ends with "ing" then add "ly" insteaed . if the stirng length of the given string is less than 3, leave it unchanged.
'''
string=input("Enter a string of length greater than equal to 3.")
if len(string) >= 3:
    # Check if the string ends with "ing"
    if string.endswith("ing"):
        # If it ends with "ing", add "ly" instead
        modified_string = string + "ly"
    else:
        # If it doesn't end with "ing", add "ing"
        modified_string = string + "ing"
else:
    # If the string length is less than 3, leave it unchanged
    modified_string = string
print("modified string = ",modified_string)
'''

# WAP to input integer values in a list and perform Linear search or Binary search. Also display the position of the number in the list.
'''
def linear_search(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1

def binary_search(arr, x):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            low = mid + 1
        else:
            high = mid - 1
    return -1

# Input integer values into a list
arr = list(map(int, input("Enter integer values separated by space: ").split()))

# Choose search algorithm
search_algorithm = input("Enter 'linear' for Linear search or 'binary' for Binary search: ")

# Input the number to search
x = int(input("Enter the number to search: "))

# Perform the search
if search_algorithm.lower() == 'linear':
    position = linear_search(arr, x)
elif search_algorithm.lower() == 'binary':
    arr.sort()  # Binary search requires the list to be sorted
    position = binary_search(arr, x)
else:
    print("Invalid search algorithm")
    position = -1

# Display the result
if position != -1:
    print(f"The number {x} is found at position {position}.")
else:
    print(f"The number {x} is not found in the list.")

'''

# Write a python prgram to remove duplicates from a an integer first(Elements supplied by the user).  Find 2 largest number from the list.
# Take input for the list of integers
numbers_str = input("Enter integer values separated by space: ")

# Convert the input string into a list of integers
numbers = [int(num) for num in numbers_str.split()]

# Remove duplicates from the list
numbers = list(set(numbers))

# Find the two largest numbers
if len(numbers) < 2:
    print("The list does not contain at least two distinct numbers.")
else:
    max1 = max(numbers)
    numbers.remove(max1)
    max2 = max(numbers)
    print(f"The two largest numbers are: {max1} and {max2}.")


# Program to determine wether a given number is happy number. The happy number is defined as a number which will yield 1 when it is replaced by the sum of the squares of its digits repeatedly, if this process results in an endless cycle of number containing 4, then the number is called an unhappy number(use math moduel.)
import math

def is_happy_number(n):
    def get_next_number(num):
        next_num = 0
        while num > 0:
            digit = num % 10
            next_num += digit * digit
            num //= 10
        return next_num

    seen = set()
    while n != 1 and n not in seen:
        seen.add(n)
        n = get_next_number(n)

    return n == 1





# Write a prgram in python to input the lower and upper limit and print all the prime number lies between the ranges . Also print the following informatio
# a. Count number of prime numbers.
# b. Count number of 2-digit prime number.
def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

lower_limit = int(input("Enter the lower limit: "))
upper_limit = int(input("Enter the upper limit: "))

prime_numbers = []
two_digit_primes = []

for num in range(lower_limit, upper_limit + 1):
    if is_prime(num):
        prime_numbers.append(num)
        if 10 <= num <= 99:
            two_digit_primes.append(num)

print("Prime numbers between", lower_limit, "and", upper_limit, "are:", prime_numbers)
print("Number of prime numbers:", len(prime_numbers))
print("Number of 2-digit prime numbers:", len(two_digit_primes))
