include $(top_srcdir)/common.mk

SUBDIRS = plugins

INCLUDES = \
		-I$(top_srcdir) \
		-I$(top_srcdir)/src/libbalancemq/include \
		-I$(top_srcdir)/src/common

bin_PROGRAMS = balancemqd
balancemqd_SOURCES = balancemqd.c
balancemqd_LDADD = \
				   ../common/libbalancemq_common.la \
				   ../libbalancemq/libbalancemq.la
balancemqd_CPPFLAGS = 
