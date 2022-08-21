# My Competitve Programming Set For CPP In VSCode

In this quick tutorial, I will teach you how to use this tool.

## Installation

You have to clone this repo then run the following:

* `` chmod +x reset new case test ``
* `` ./reset all ``

## Create new files for a problem

To create new files for a problem, then you have to run the `` ./new `` command in the following format:

`` ./new problems <template> <website> <problem name>  ``

and this will create new folder named as the problem name in the problems folder inside the webstie folder, and the new created folder there will contains files named:

* sol.cpp
* input
* correct_output
* output

### Example

```bash
./new problems default uva 10360
```

## Create new files for a contest

To create new files for a contest, then you have to run the `` ./new `` command in the following format:

`` ./new contests <website> <contest name> ``

and this will create new folder named as the contest name in the contests folder inside the webstie folder, and inside the new created folder there will be 6 folders named from A to F and each will contains files named:

* sol.cpp
* input
* correct_output
* output

### Example

```bash
./new contests codeforces 151
```

## Create new test case file for a problem

To create a new test case file for a problem you have to go throw the following to steps:

* Create a new cpp file (or use an existing one) in `` test_case_creator `` folder and write code that will create the test case (output to the stdin directly)

* Then, run the `` ./case `` command in the following format:
`` ./case test_case_creator/<cpp test case creator file> <path to the testcase file to be created> ``

> NOTE: Don't forget to type the correct output file in the correct_output file associated with the input file

> NOTE: You can create your test case manually by create a new input, output and correct_output files for this test case, then type your test case input and correct output

### Example
```bash
./case test_case_creator/create_test_case.cpp problems/uva/1062/input
```

## Test your code against test case(s)

To test your code against the main test case file (`` input ``), you have to run the `` ./test `` command in the following format:

`` ./test <path to the solution cpp file> ``

and to test your code against all test case files, you have to run the `` ./test `` command in the following format:

`` ./test -m <path to the solution cpp file> ``

### Example

```bash
./test problems/uva/10107/sol.cpp

./test -m problems/uva/10107/sol.cpp
```

## Rest your tool

To reset your tool, you have many options:

* Remove all problems `` ./reset problems ``
* Remove all contests `` ./reset contests ``
* Remove all quick files `` ./reset quick ``
* Remove all input/output files `` ./reset inout ``
* Remove all input files `` ./reset inputs ``
* Remove all output files `` ./reset outputs ``
* Remove everything `` ./reset all ``