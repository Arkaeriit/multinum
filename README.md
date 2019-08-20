# Multinum
A program to solve an useless question.

Take the number 125, consider each of its digits as a number and multiply them together, you will get `1 * 2 * 5 = 10`, then take the digits from 10 and multiply them together. You will get 0, a 1 digit number.

Whichever start number you take you will end up, doing this operation, with a 1 digit number. The question is how many time it will take.

This program tries to answer this question.

![Alt text](https://i.imgur.com/DVcVUqA.png "An example of results")

## User manual
To compile it just use `make` and it will create a binary file multinum.

Usage: `./multinum [option] <parameters...>`

Available options:
* reduce: Use `./multinum reduce [number]` to know how many times you have to reduce `number` to get a 1 digit number.
* analyze: Use `./multinum analyze [file] [start] [stop] <threads>` to know the witch numbers take the more time to be reduced to a single digit number between `start` and `stop`. The results will be stored in `file` where each interesting number will be stored and the number of steps go reduce them to 1 digit number will be written next to them after a space. The calculation will be spread between `threads` various threads.

