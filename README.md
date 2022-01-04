# Computer Engineering Case Study - Concordance of a Text File

## Problem Identification and Statement
The objective is to develop a software that performs information retrieval and determines the
“most important concepts” in a text file. It processes a text file and produces a concordance: an
alphabetical listing of the words in the file and the frequency of these words. The program asks
the user to input the name of the text file containing the text and another text file where the
concordance will be finally printed.

## Gathering Information and Input Output Description
### Relevant Information
A task often performed in information retrieval is the determination of the "most important
concepts" of a text document. A concordance of a text file is an alphabetical list of the unique
words in the text file in which all the punctuation and other non-alphabetic symbols are ignored.
Here is a concordance of the sentence, “A concordance of a text file is an alphabetical list of the
unique words in the text file”, sorted alphabetically, along with the frequency of occurrence for
every word:

[Picture]

It is useful to track the number of times each unique word appears in the text file to identify the
most important concepts in the file.

Concordance can be used for various purposes:\
● Web Search: A search engine analyzes Web pages to determine whether their content
agrees with our search criteria.\
● Analysis of Literary Texts: Concordance programs have been used in literary and mostly
religious text analysis for decades. They aim to count and define the frequency and
function of a word or word groups in a given text. The aim is to give an inductive
understanding of the word/structure and its use in authentic texts (ref: The Use of
Concordancing programs in ELT).\
● Use in Classrooms: Another advantage of concordancing is that it aims to bridge the gap
between learners’ current language ability and expected ability (Sun, 2007). This is done
by giving the authentic texts to students and while analyzing them they will focus on the
structures or words which the teacher directs them (ref: The Use of Concordancing
programs in ELT).

An important step in the creation of a concordance is tokenizing the string into words. String
tokenization is a process where a string is broken into several parts. Each part is called a token
(ref: Developer.com). This is done by going through each character of the string and checking for
delimiters like spaces, punctuations, and all non-alphabetical characters. The alphabetical
characters are first converted into lowercase and then concatenated together to form words. The
string is split into words every time a delimiter is encountered. This is how the string is split into
multiple words and all non-alphabetical characters are removed.

Sorting the list of words in alphabetical order is a very important step to make a concordance.
This is done by implementing sorting algorithms like selection sort, bubble sort, etc. The
selection sort algorithm sorts a list by repeatedly finding the minimum element (considering
ascending order) from the unsorted part and putting it at the beginning of the list (ref:
GeeksforGeeks). While sorting a list of words, the algorithm checks the ASCII value of the
corresponding characters in the words and sorts them alphabetically (ascending order of ASCII
values).

The final step of creating a concordance is storing all the unique words from the list and their
frequencies. This is achieved by going through the list of strings, picking out unique words and
maintaining a count of their frequencies (since unique words occur together in an alphabetically
sorted list).


### Input Output Description

The program asks the user to input the name of the file where the text is stored. The concordance
has to be constructed from this text. The program also asks the user to input the name of the file
where the concordance of unique words and their frequency will be stored in the end. The output
of the program is two-fold: the concordance containing the list of unique words and their
frequency is printed in the output screen and in the output text file.

The following explains how the program executes:\
Enter the name of the input file\
abc.txt\
Enter the name of the output file\
xyz.txt

## Test Cases
### Test Case 1: Large amount of data
The following is the data inside the file:\
“Harry Potter is a series of seven fantasy novels written by
British author J. K. Rowling. The novels chronicle the lives of
a young wizard, Harry Potter, and his friends Hermione Granger
and Ron Weasley, all of whom are students at Hogwarts School of
Witchcraft and Wizardry.Harry Potter is a series of seven
fantasy novels written by British author J. K. Rowling. The
novels chronicle the lives of a young wizard, Harry Potter, and
his friends Hermione Granger and Ron Weasley, all of whom are
students at Hogwarts School of Witchcraft and Wizardry.Harry
Potter is a series of seven fantasy novels written by British
author J. K. Rowling. The novels chronicle the lives of a young
wizard, Harry Potter, and his friends Hermione Granger and Ron
Weasley, all of whom are students at Hogwarts School of
Witchcraft and Wizardry.Harry Potter is a series of seven
fantasy novels written by British author J. K. Rowling. The
novels chronicle the lives of a young wizard, Harry Potter, and
his friends Hermione Granger and Ron Weasley, all of whom are
students at Hogwarts School of Witchcraft and Wizardry.”

The expected output is:

a - 8\
all - 4\
and - 12\
are - 4\
at - 4\
author - 4\
british - 4\
by - 4\
chronicle - 4\
fantasy - 4\
friends - 4\
granger - 4\
harry - 8\
hermione - 4\
his - 4\
hogwarts - 4\
is - 4\
j - 4\
k - 4\
lives - 4\
novels - 8\
of - 16\
potter - 8\
ron - 4\
rowling - 4\
school - 4\
series - 4\
seven - 4\
students - 4\
the - 8\
weasley - 4\
whom - 4\
witchcraft- 4\
wizard - 4\
wizardry - 4\
written - 4\
young - 4

### Test Case 2: Text with a lot of punctuation
The following is the text in the file:\
“app.le#baLL cat.bAll_le’app dog-dOg$Apple^ cat.apple%@^&[ball}
:DoG~!@#$%^&****(jug<>?|}{‘APPLE$BALL_CAT.DOG==APP?LE ~```Ball”

The expected output is:

app - 3\
apple - 3\
ball - 5\
cat - 3\
dog - 4\
jug - 1\
le - 3


### Test Case 3: Text with numbers
The following is the text in the file:
“3a6quick9brown1456789098765456789098765fox3jumps6over3the9lazy0
dog7a3quick4brown8fox2jumps6over4the2lazy3dog8!@#$%^&*(a4quick7b
rown 8fox2jumps7over4the3lazy8dog12345678901234567890”

The expected output is:

a - 3\
brown - 3\
dog - 3\
fox - 3\
jumps - 3\
lazy - 3\
over - 3\
quick - 3\
the - 3

## Software Testing and Verification

[To be filled]

## User Guide
The program will help you determine the most important concepts in a text file. You can provide
the program with a text file containing data. The program will give you the list of unique words
in the document (concordance) and their frequencies. It will also prompt you to provide the name
of the output file. The program will then print the concordance list in the output file and provide
you with a confirmation of the same.
