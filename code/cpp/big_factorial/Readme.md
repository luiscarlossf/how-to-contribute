# Using GMP
The code must be compiled using `-lgmpxx -lgmp` g++/clang++ flags, and GNU GMP library must be available on the system for that.

# Using array
This method is far slower than GMP, but is not library dependent and can be optimized by, say, using better storage methods than vectors.
