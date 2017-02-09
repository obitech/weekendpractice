# Matrix Encryption

## Explanation

One basic encryption technique is that of using linear algebra to encode and decode a message. This works as follows (example taken from [here](http://web.csulb.edu/~jchang9/m247/m247_fa11_David_Diego_Alissa_Daniel.pdf "CSU - Cryptography and Linear Algebra - McClelland, Perilla, Clark, Lopez")):

### 1. Choose a Message
Take a plain-text message we want to encrypt. In this example we'll choose  ```PENGUINS ARE ONE TO ONE```

### 2. Choose a cipher natrix
For our encryption key, we'll create a square (n-by-n) cipher matrix. **This matrix has to be [invertible](https://en.wikipedia.org/wiki/Invertible_matrix "Wikipedia.org - Invertible Matrix")!** For this example we'll use a 3-by-3 matrix:
``` 
[-3 -3 -4]
| 0  1  1|
[ 4  3  4]
```
### 3. Transform the message into numbers
Assign a numerical value to each character in our message. This could follow any method (we could also use a [ROT-Cipher](https://github.com/obitech/weekendpractice/blob/master/7/challenge.md "weekendpractice 7 - rotx.c") for this) but for now we will use the value each letter represents in the alphabet (A = 1, B = 2, ... , Space = 27). Thus, our text ```PENGUINS ARE ONE TO ONE``` will be represented as:
```
[16, 5, 14, 7, 21, 9, 14, 19, 27, 1, 18, 5, 27, 15, 14, 5, 27, 
20, 15, 27, 15, 14, 5]
```
### 4. Create a new matrix
Before we create a matrix with our new numbers, we can transform them into **n-by-1** vectors (in your code, this step could be skipped). If necessary, we need to fill up any remaining values with spaces (0):
```
[16] [ 7] [14] [ 1] [27] [ 5] [15] [14]
| 5| |21| |19| |18| |15| |27| |27| | 5|
[14] [ 9] [27] [ 5] [14] [20] [15] [27] 
````
Now it's easy to see how our new matrix will look like:
```
[16   7  14   1  27  5   15  14]
| 5  21  19  18  15  27  27   5|
[14   9  27   5  14  20  15  27]
```
### 5. Multiply with cipher matrix
Now we multiply with our previously chosen cipher matrix:
```
[-3 -3 -4]   [16   7  14   1  27  5   15  14]
| 0  1  1| * | 5  21  19  18  15  27  27   5|
[ 4  3  4]   [14   9  27   5  14  20  15  27]
```
And get a new matrix containing our encoded cipher text:
```
[-119 -120 -207 -77 -182 -176 -186 -166]
|  19   30   46  23   29   47   42   32|
[ 135  127  221  78  209  181  201  179]
```
### 6. Decrypt by multiplying with inverse cipher matrix
To decrypt our decoded message simply multiply the matrix with our **inverted** cipher matrix:
```
[ 1  0  1]   [-119 -120 -207 -77 -182 -176 -186 -166]
| 4  4  3| * |  19   30   46  23   29   47   42   32|
[−4 −3 −3]   [ 135  127  221  78  209  181  201  179]
```
Which gets us:
```
[16  7 14  1 27  5 15 14]     [ P G N A _ E O N ]
| 5 21 19 18 15 27 27  5| --> | E U S R O _ _ E |
[14  9 27  5 14 20 15 27]     [ N I _ E N T O _ ]
```

## Tasks
### Main
* Create a program that is able to decode and encode a message using the above described method.
* Make your program modular with your function definitions outside the main file.

### Optional
* Make sure the entered cipher matrix is invertible, if not display an error message an re-prompt the entry.
* For encoding, let the user choose a different conversion key when transforming plain text into numbers.
* Let your program take inputs from the command line.
* Offer functionality to import/export parts of your program from/into additional files.
* Whatever additional functionalities you can think of :) 

## Structure

### File structure
Your file structure should be modular, similar to [Challenge 7](https://github.com/obitech/weekendpractice/blob/master/7/challenge.md). It could look like this:
* matrix_cipher.h -- libraries, constants,  declarations of structs (if necessary), declarations of functions **that need to be called by other programs**
* matrix_cipher_functions.c -- definitions of your functions
* matrix_cipher.c -- main program: calling functions and printing outputs

### Menu structure
Create an easy to use menu to navigate your program. Make sure to catch wrong inputs! Your program could use this structure:
```
Program start: What would you like to do?
   Encode:
      - Enter message
         -(Optional: Choose key for transformation into numbers) 
      - Choose size of cipher matrix (n)
         - (Optional: check if cipher matrix is valid / invertible)
      - <Print encoded matrix>
   Decode:
      - Enter encoded matrix
      - Enter size & values of cipher matrix
         - Check if cipher matrix is valid (cipher & message matrix need to have same amout of rows!)
      - <Print decoded message>
```
