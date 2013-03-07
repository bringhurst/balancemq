include $(top_srcdir)/common.mk

BUILT_SOURCES = balancemq_conf.h
PARSER = balancemq_conf.y balancemq_conf.l
AM_YFLAGS = -d

INCLUDES = \
           -I$(top_srcdir) \
           -I$(top_srcdir)/src/libbalancemq/config

noinst_LTLIBRARIES = lib_config_compiler.la

lib_config_compiler_la_SOURCES = balancemq_conf.y
lib_config_compiler_la_LIBADD = $(LEXLIB)
lib_config_compiler_la_LDFLAGS = $(LIB_LDFLAGS)
