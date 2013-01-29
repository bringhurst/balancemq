include $(top_srcdir)/common.mk

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/balancemqd/comm/stomp/compiler \
           -I$(top_srcdir)/contrib/antlr/libantlr3c-3.4/include \
           -I$(top_srcdir)/contrib/antlr/libantlr3c-3.4

noinst_LTLIBRARIES = libprotocol_stomp_compiler.la

libprotocol_stomp_compiler_la_SOURCES = STOMPLexer.c STOMPParser.c
libprotocol_stomp_compiler_la_LIBADD = -lantlr3
libprotocol_stomp_compiler_la_LDFLAGS  = $(LIB_LDFLAGS)
