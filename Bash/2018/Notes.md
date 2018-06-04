# Notes from Udemy course

## Setup

```bash

# change hostname
hostnamectl set-hostname --static "new_name"

```

## Unique Characters

### hash ```#```

```bash

# Used to make inline comments

# Used to define wich interpreter will be used like shown below
#!/bin/bash

# Used to get the number of characters of a variable
var=hello
echo "The word $var has ${#var} characters"

# Also used to convert numbers from one base to another
echo $(( 2#111 )) # This should print 7

```

### Semicolon ;

```bash

# The semicolon can be used to put multiple commands on the same line
echo "Hello"; echo "World!"

```

### Dot .

```bash

# The dot can be used to represent the current directory
cd .

# Or the previous directory using two dots
cd ..

```
### Quotes " "

Double and single quotes:

```bash

# Double quotes will preserve most special characters within a string
colors="red black white"
for col in $colors   # This will print one color at a time
for col in "$colors" # This won't print one color at a time
do
    echo $col
done

# Single quotes won't allow referencing variables
echo '$colors' # This will print $colors

```

### Comma

```bash

# The comma is used as separator
let "var1=((var2=20, 10/2))"

# Using comma to transform the first letter to lower case
var="Hello World!"
echo ${var,}

# It can also be used to transform all letters to lower case
echo ${var,,}

```

```bash

```