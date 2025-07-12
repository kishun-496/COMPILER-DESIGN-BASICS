# COMPILER-DESIGN-BASICS 
COMPANY: CODETECH IT SOLUTIONS

NAME:   KISHUN MURMU

INTERN ID: CT04DG1357

DOMAIN: C Programming

BATCH DURATION: 4 WEEKS

MENTOR NAME: NEELA SANTHOSH

TASK DESCRIPTION:

Creating a simple lexical analyzer in C involves building a program that scans an input source file and identifies fundamental components of a programming language, specifically keywords, operators, and identifiers. The lexical analyzer begins by reading the input file character by character and utilizes predefined lists or pattern-matching logic to classify tokens based on syntax rules. Keywords are recognized by comparing each parsed word against a set of reserved words (e.g., int, return, for, while), while operators are detected using symbol comparison for characters like +, -, =, *, /, and compound forms such as == or &&. Identifiers are parsed as sequences that begin with a letter or underscore and are followed by letters, digits, or underscores, ensuring they do not match any known keyword. The core logic uses buffers to capture tokens and conditions to validate their category, and the analyzer may skip irrelevant characters like whitespaces and newlines. For enhanced structure, each token type can be printed with its category label, e.g., Keyword: int, Operator: +, Identifier: sum. Implementing this tool involves string comparison, character classification (isalpha, isdigit from ctype.h), and file I/O using fopen, fgetc, and loop structures for continuous parsing. Through this task, programmers gain a deeper understanding of lexical parsing principles used in compiler design and language processing, building a robust foundation for more advanced analyzers or syntax checkers. This exercise also improves precision in handling input streams and dynamic text parsing, making it a valuable step toward mastering text-based logic and language interpretation in C programming.

