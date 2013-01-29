AC_INIT([BalanceMQ],[0.0.1],[jon@bringhurst.org],[BalanceMQ],[http://www.balancemq.com/])

# Keep artifacts in directories as much as possible.
AC_CONFIG_AUX_DIR(auxdir)
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# Check for programs
AC_PROG_CC
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Needed for docs
X_AC_BMQ_DOXYGEN

# Needed for tests
#X_AC_BMQ_CHECK

# Pull in libtool.
LT_INIT

# Checks for headers.
AC_CHECK_HEADERS([inttypes.h limits.h stdint.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Check for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset realpath strerror])

# Check for libev.
AC_CHECK_HEADERS([ev.h], [], [AC_MSG_ERROR("ev.h not found")])
AC_CHECK_LIB([ev], [ev_time], [
	LIBS="-lev ${LIBS}"
	AC_DEFINE([HAVE_LIBEV], [1], [ev_time in -lev])
	], [AC_MSG_ERROR("libev not found")])

# Build antlr3 C headers.
AC_CONFIG_SUBDIRS([contrib/antlr/libantlr3c-3.4])

AC_CONFIG_FILES([Makefile                                    \
                 contrib/Makefile                            \
                 contrib/antlr/Makefile                      \
                 src/Makefile                                \
                 src/balancemqd/Makefile                     \
                 src/balancemqd/comm/Makefile                \
                 src/balancemqd/comm/stomp/Makefile          \
                 src/balancemqd/comm/stomp/compiler/Makefile \
                 examples/Makefile                           \
                 examples/filesystem_treewalk/Makefile       \
                 examples/filesystem_treewalk/c/Makefile     \
                 doc/Makefile                                \
                 doc/man/Makefile                            \
                 doc/man/man1/Makefile                       \
])

AC_OUTPUT
