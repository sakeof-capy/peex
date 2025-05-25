1. Valgrind / cargo valgrind
2. Visual Studio Profiler

Valgrind's Essential Flags:
Flag	                    Description
--leak-check=full	        Detailed info on each memory leak
--show-leak-kinds=all	    Show all types: definitely, indirectly, possibly lost
--track-origins=yes	        Show origin of uninitialized values (slow but super helpful)
--verbose	                Detailed output
--log-file=valgrind.log	    Write output to a file instead of stdout
--num-callers=40	        Show more stack frames for better backtraces
