# Holtzman
Simple and minimal file share server on local area network

![](https://s21.ax1x.com/2024/06/29/pkckT0A.png)

powered by [cpp-httplib](https://github.com/yhirose/cpp-httplib)

## Installation

Download [here](https://github.com/Remelens/holtzman/releases/) (not recommended) or compile the project with:

```
make
```

## Usage

Execute the command on the root directory of the project

```
./server
```

The server will listen at port 8000 and you can view it at http://localhost:8000/

If you want to change the port, edit the variable "PORT" in `server.cpp`, then recompile the proj.
