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
