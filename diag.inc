#ifndef DIAG
#define DIAG(ID, KIND, MSG)
#endif

DIAG(err_unknown_char, Error, "unknown char '{0}'")
DIAG(err_expected, Error, "expected '{0}', but found '{1}'")
DIAG(err_redefined, Error, "redefined symbol '{0}'")
DIAG(err_undefined, Error, "undefined symbol '{0}'")
DIAG(err_lvalue, Error, "required lvalue in assign operation left side")


#undef DIAG