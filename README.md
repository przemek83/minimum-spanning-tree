## Web creator using DFS
Tool for finding minimum spanning tree in given social web with weights.

## Table of content
- [Problem description](#problem-description)
- [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Building](#building)
- [Built with](#built-with)
- [Usage](#usage)
- [Testing](#testing)
- [License](#license)

## Problem description
Given social network (graph) with people as nodes. Each person have weight which is a cost of taking over their account. Find minimum cost to take over the network. Network is taken over if each person (node) in network has account taken over or is connected to minimum one taken over account.

**Input**:  
In first line is expected number of people in social network. In following lines names and cost of taking over account (separated by space). After that number of connections and connections itself (one per line, names separated by space).

**Output**:  
In first line is displayed number of people in minimum spinning tree. In following lines names of people. In last line sum of weighs for minimum spinning tree.

## Getting Started
This section describes briefly how to setup environment and build project.

### Prerequisites
C++ compiler with C++17 support as a minimum and CMake 3.8+. Additionally Git tool for downloading Google Test library as it is needed by test subproject.

### Building
Recommended:  
Use Cmake directly or your favorite IDE supporting CMake projects.  

Alternative:  
Use bare compiler for building project binary:
```shell
$ g++ -Wall -std=c++17 -Isrc -O3 -c *.cpp
$ g++ -Wall -std=c++17 -O3 -o minimum-spanning-tree *.o
```

## Built with
| Tool |  Windows 10 | Lubuntu 20.04 |
| --- | --- | --- |
| GCC | 7.3.0 | 9.3.0 |
| Cmake | 3.14 | 3.17 |
| Git | 2.20 | 2.25 |
| QtCreator | 4.12.0 | 4.13.0 |

## Usage
Application expects first on std in number of people in network. Than lines containing names and cost of taking over account. After that number of connections followed by connections itself (names separated by space).
Example input:
```
5
Robert 12
Julia 23
Adam 1
Carol 10
Daniel 4
5
Robert Julia
Robert Carol
Adam Robert
Daniel Adam
Daniel Julia
```
Example output:
```
2
Adam
Robert
13
```

Examples of usage:  
1. Pass example file named `testFile.txt` from project repo:
    ```shell
    $ ./minimum-spanning-tree < testFile.txt
    2
    Adam
    Robert
    13
    ```
2. Use binary directly:
    ```shell
    $ ./minimum-spanning-tree
    5
    Robert 12
    Julia 23
    Adam 1
    Carol 10
    Daniel 4
    5
    Robert Julia
    Robert Carol
    Adam Robert
    Daniel Adam
    Daniel Julia
    2
    Adam
    Robert
    13
    ```
3. Pipe input:
    ```shell
    $ cat testFile.txt | ./minimum-spanning-tree
    2
    Adam
    Robert
    13
    ```
## Testing
Project contains test subproject based on Goggle Test framework. Compile testing subproject and launch tests via IDE or directly from console.  
Example run:
```
$ $ ./minimum-spanning-tree-test
(...)
[==========] Running 3 tests from 1 test suite.
[----------] Global test environment set-up.
[----------] 3 tests from SocialNetworkTest
[ RUN      ] SocialNetworkTest.emptyNetwork
[       OK ] SocialNetworkTest.emptyNetwork (0 ms)
[ RUN      ] SocialNetworkTest.oneNodeNetwork
[       OK ] SocialNetworkTest.oneNodeNetwork (0 ms)
[ RUN      ] SocialNetworkTest.complexNetwork
[       OK ] SocialNetworkTest.complexNetwork (0 ms)
[----------] 3 tests from SocialNetworkTest (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test suite ran. (0 ms total)
[  PASSED  ] 3 tests.
```

## License
Project is distributed under the MIT License. See `LICENSE` for more information.
