# BrainFuck-Interpreter-in-C
Basic BrainFuck Interpreter written in C, the interpreter is really recent and basic, any suggestions are welcome. 

**Prerequistes:**
Must have gcc in PATH and make in PATH, if you are lazy to move it in path, just change the Makefile

**Compilation:**
First way: To compile the program you must download the tar.gz and extract it. When you are done move the Makefile corresponding to your OS on the main folder.
Just type make in the directory when you are done.
Second way: Compile with gcc :)

**Use:**
To use the program, you only need to type on the terminal:
./brainfuck.exe program_name.bf

**Specificities:**
The interpreter give you the choice between -2 147 483 648 and 2 147 483 647 values, so if you have a problem of performance you can change that.
It's in default bcs that gives more choices.
For cursor of pointer it must be between 0 and 30000 included, but you can change also if you need.
