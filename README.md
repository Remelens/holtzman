# Holtzman
Simple and minimal file share server on local area network

## Installation

Make sure that you've installed [libcpp-httplib](https://github.com/yhirose/cpp-httplib). On a Debian/Ubuntu device, you can install this with this command:
```
sudo apt install libcpp-httplib-dev
```

Then compile the project with:

```
make
```

## Usage

Execute the command on the root directory of the project

```
./server
```

The server will listening at port 8000 and you can view it at http://localhost:8000/

If you want to change the port, edit the variable "PORT" in `server.cpp`, then recompile the proj.
