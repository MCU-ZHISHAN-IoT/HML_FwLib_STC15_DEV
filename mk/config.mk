#!/usr/bin/make

# ------------------------------------------------------------------------
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2020-02-26
# Description: config Makefile
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : GNU Make (http://www.gnu.org/software/make/manual/make.html)
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc15.html
# Project    : HML_FwLib_STC15
# Version    : v0.4.2
# ------------------------------------------------------------------------

# @Note: Specify value of config variable via command line has higher priority

# Options for print format
#  [VERBOSE] Print control option, when its value is "1", Makefile will print
#   more details, or it will only print brief
VERBOSE   ?= 0

# Options for MCU configurations
#  [MCU] MCU model option, user can get model support list via reading Makefile.mcu.
#   This parameters is case-insensitive.
#  [PACKAGING] Some functions is depend on MCU's packaging. You can get support
#   list via hml/macro.h
MCU       ?= STC15W1K08PWM
PACKAGING ?= NULL
#  [CLKFRE] Specify frequency of MCU clock, the unit is Hz.
#  [PRESCALER] Specify MCU prescaler factor, the value must be 6(6T mode) or
#    12(12T mode).
CLKFRE    ?= 11059200
PRESCALER ?= 12
#  [CODE] Specify total size of ROM(external+ on-chip) during compilation
#    manually (unit: KB)
#  [XRAM] Specify total size of external RAM during compilation manually (unit: KB)
CODE      ?=
XRAM      ?=

# Options for build target
#  [EXE_C] Specify user source file or Makefile will fill it with "test.c".
#    It's noticed that once use this option to compile specified .c file,
#    user should add this option when do all targets related to build operation,
#    such as clean and rebuild.
EXE_C     ?= example/hello/hello.c

# Options for number of parallel build jobs
# [JOBS] Specify number of parallel build jobs, this variable only works
#    during run <rebuild> target
JOBS      ?= $(shell $(NPROC))
