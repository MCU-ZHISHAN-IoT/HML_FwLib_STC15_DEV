#!/usr/bin/make

# ------------------------------------------------------------------------
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2020-07-12
# Description: project Makefile
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : GNU Make (http://www.gnu.org/software/make/manual/make.html)
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/FWLIB_N_stc15.html
# Project    : HML_FWLIB_N_STC15
# Version    : v0.3.2
# ------------------------------------------------------------------------

export SHELL       := /bin/bash

# Definition of toolchain
#  @note: this part can be configured via a extra script
CROSS_COMPILE      := sd
AR                 := $(CROSS_COMPILE)ar
CC                 := $(CROSS_COMPILE)cc
MAKE               ?= make --no-print-directory
PACKIHX            ?= packihx

# Mark special phony targets
PHONY_LIST_IN      := clean distclean help rebuild version

# Definition of project basic path
ROOTDIR            := ..
INCDIR             := $(ROOTDIR)/inc
OBJDIR             := $(ROOTDIR)/obj
SRCDIR             := $(ROOTDIR)/src

# Configure all custom parameters
SPACE              := $(empty) $(empty)
TEXT_COLOR         := \033[36m
ifeq ($(findstring $(MAKECMDGOALS), $(PHONY_LIST_IN)),)
    ifneq ($(CONF),)
        include $(CONF)
    else
        include Makefile.config
    endif
    include Makefile.mcu
endif

#  Definition of of print format
ifeq ("$(VERBOSE)", "1")
    Q :=
    VECHO := @true
else
    Q := @
    VECHO := @echo
endif

# Important file
SRCS   := $(wildcard $(SRCDIR)/*.c)
RELS   := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.rel, $(SRCS))
MYFILE ?= test.c
    # file check
    ifeq ($(findstring $(MAKECMDGOALS),$(PHONY_LIST_IN)),)
        ifneq ($(wildcard $(MYFILE)),$(MYFILE))
            $(error no such file $(CURDIR)/$(MYFILE))
        endif
    endif
MYFILE_NAME := $(shell basename $(MYFILE) .c)
MYFILE_REL  := $(OBJDIR)/$(MYFILE_NAME).rel
# Target file
TARGET      ?= output
FWLIB_N     := libhml_stc15.lib
FWLIB       := $(OBJDIR)/$(FWLIB_N)

all: $(OBJDIR)/$(TARGET).hex
	@echo "==================================================="
	@echo " Make $(MAKECMDGOALS) done!"
	@echo "---------------------------------------------------"
	@echo " completed at `date "+%Y-%m-%d %H:%M:%S"`"
	@echo "==================================================="

# Startup
startup:
	@echo -e "$(TEXT_COLOR) - Start to build!\033[0m"

# Compile HML source file(*.c)
$(SRCS): startup
$(RELS): $(OBJDIR)/%.rel:$(SRCDIR)/%.c
	$(VECHO) "CC  $<"
	$(Q)$(CC) $< $(CFLAGS) -o $@

# Generate static library
$(FWLIB): $(RELS)
	@echo -e "$(TEXT_COLOR) - Make static link library `basename $@` \033[0m"
	$(VECHO) "AR  $@"
	$(Q)$(AR) $(ARFLAGS) $@ $^

# Compile user file
$(MYFILE_REL): $(MYFILE) $(FWLIB)
	@echo -e "$(TEXT_COLOR) - Compile user source code \033[0m"
	$(VECHO) "CC  $<"
	$(Q)$(CC) $< $(CFLAGS) -L$(OBJDIR) -lhml_stc15 -o $@

# Generate .hex file
$(OBJDIR)/$(TARGET).ihx: $(MYFILE_REL)
	@echo -e "$(TEXT_COLOR) - Generate .ihx file \033[0m"
	$(VECHO) "CC $@"
	$(Q)$(CC) $^ $(OBJDIR)/$(FWLIB) -o $@
$(OBJDIR)/$(TARGET).hex: $(OBJDIR)/$(TARGET).ihx
	@echo -e "\033[36m - Generate .hex file \033[0m"
	$(Q)$(PACKIHX) $< > $@

# Phony targets
# [+] clean
.PHONY: clean
clean:
	cd $(OBJDIR) && ls | grep -vE -e ".gitkeep" -e ^$(MYFILE_NAME) -e *.lib$$ -e *.hex$$ | xargs rm -f
# [+] distclean
.PHONY: distclean
distclean:
	cd $(OBJDIR) && ls | grep -v ".gitkeep" | xargs rm -f
# [+] help
.PHONY: help
help:
	@echo  "Build:"
	@echo  "    all        - Build target(include HML library file and user code)"
	@echo  "    library    - Only build HML library file"
	@echo -e "    rebuild    - Rebuild target(include HML library file and user code). In this case, \
-j can't work and please pass \033[3mJOBS\033[0m variable via command line instead of it, such as \"make rebuild JOBS=8\""
	@echo  ""
	@echo  "Cleaning:"
	@echo  "    clean      - Delete temporary files created by build, except for the .lib and .hex files"
	@echo  "    distclean  - Delete all temporary files and generated library file"
	@echo  ""
	@echo  "Info:"
	@echo  "    help       - Show help information"
	@echo  "    version    - Show version information"
	@echo  ""
	@echo  "+ MCU config variable:"
	@echo  "    MCU        - Specify MCU model(case-insensitive), this variable is required by all \
compilation target, including all, library and rebuild"
	@echo  "    CLKFRE     - Specify clock frequency manually(unit: Hz)"
	@echo  "    PRESCALER  - Specify MCU prescaler factor, the value must be 6(6T mode) or 12(12T mode)"
	@echo  "    CODE       - Specify total size of ROM(external+ on-chip) during compilation manually (unit: KB)"
	@echo  "    XRAM       - Specify total size of external RAM during compilation manually (unit: KB)"
	@echo  ""
	@echo  "+ command line variable:"
	@echo  "    CONF       - Specify config Makefile(default: Makefile.config)"
	@echo  "    JOBS       - Specify number of make job(only for make rebuild)"
	@echo  "    MYFILE     - Specify user source file or Makefile will fill it with \"test.c\". It's \
noticed that once use this option to compile specified .c file, user should add this option during doing \
other works, such as clean and rebuild."
	@echo  "    VERBOSE    - When the value is 1, Makefile will print more details during build"
	@echo  ""
	@echo  "Examples:"
	@echo  "    (1) make -j"
	@echo  "    (2) make -j MCU=stc89c52rc"
	@echo  "    (3) make rebuild MCU=stc89c52rc JOBS=4"
	@echo  "    (4) make -j library MCU=stc89c52rc"
# [+] library
.PHONY: library
library: $(FWLIB)
	@echo ===================================================
	@echo Make $(MAKECMDGOALS) done!
	@echo ---------------------------------------------------
	@echo completed at `$(DATE) "+%Y-%m-%d %H:%M:%S"`
	@echo ===================================================
# [+] rebuild
.PHONY: rebuild
rebuild:
	@echo -e "$(TEXT_COLOR) - Clean previous files \033[0m"
	@$(MAKE) distclean
	@$(MAKE) -f Makefile -j$(JOBS) $(MAKEFLAGS)
# [+] version
.PHONY: version
version:
	@$(MAKE) -s -f Makefile.version

