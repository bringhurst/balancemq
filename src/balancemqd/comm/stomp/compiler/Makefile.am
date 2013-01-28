include $(top_srcdir)/common.mk

INCLUDES = -I$(top_srcdir) -I$(top_srcdir)/src/balancemqd/comm/stomp/compiler

noinst_LTLIBRARIES = libprotocol_stomp_compiler.la

libprotocol_stomp_compiler_la_SOURCES = STOMPLexer.c STOMPParser.c
libprotocol_stomp_compiler_la_LIBADD = -lantlr3
libprotocol_stomp_compiler_la_LDFLAGS  = $(LIB_LDFLAGS)
