AC_INIT([BalanceMQ],[0.0.1],[jon@bringhurst.org],[BalanceMQ],[http://www.balancemq.com/])

AC_LANG_CONFTEST(
   [AC_LANG_SOURCE([[const char hw[] = "Hello, World\n";]])])

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

# Check for compiler compilers.
AC_PROG_YACC
AC_PROG_LEX

AC_CONFIG_FILES([Makefile                                              \
                 doc/Makefile                                          \
                 doc/man/Makefile                                      \
                 doc/man/man1/Makefile                                 \
                 etc/Makefile                                          \
                 examples/Makefile                                     \
                 examples/filesystem_treewalk/Makefile                 \
                 examples/filesystem_treewalk/c/Makefile               \
                 src/Makefile                                          \
                 src/balancemqd/Makefile                               \
                 src/balancemqd/balancemqctl/Makefile                  \
                 src/balancemqd/plugins/Makefile                       \
                 src/balancemqd/plugins/protocol/Makefile              \
                 src/balancemqd/plugins/protocol/posixmq/Makefile      \
                 src/balancemqd/plugins/protocol/stomp/Makefile        \
                 src/balancemqd/plugins/protocol/stomp/parser/Makefile \
                 src/libbalancemq/Makefile                             \
                 src/libbalancemq/common/Makefile                      \
                 src/libbalancemq/include/Makefile                     \
                 src/libbalancemq/plugins/Makefile                     \
                 src/libbalancemq/plugins/auth/Makefile                \
                 src/libbalancemq/plugins/auth/munge/Makefile          \
                 src/libbalancemq/plugins/auth/none/Makefile           \
                 src/libbalancemq/plugins/protocol/Makefile            \
                 src/libbalancemq/plugins/protocol/asn_1/Makefile      \
                 src/libbalancemq/plugins/protocol/mpi/Makefile        \
                 src/libbalancemq/runtime/Makefile                     \
                 src/libbalancemq/startup/Makefile                     \
                 src/libbalancemq/startup/plugin_loader/Makefile       \
                 src/libbalancemq/startup/settings/Makefile            \
])

AC_OUTPUT
