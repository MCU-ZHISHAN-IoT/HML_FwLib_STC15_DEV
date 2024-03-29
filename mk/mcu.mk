#!/usr/bin/make

# ------------------------------------------------------------------------
# Author     : Weilun Fong | wlf@zhishan-iot.tk
# Date       : 2020-02-26
# Description: MCU parameters config Makefile
# E-mail     : mcu@zhishan-iot.tk
# Make-tool  : GNU Make (http://www.gnu.org/software/make/manual/make.html)
# Page       : https://hw.zhishan-iot.tk/page/hml/detail/fwlib_stc15.html
# Project    : HML_FwLib_STC15
# Version    : v0.4.2
# ------------------------------------------------------------------------

# Print note information
$(info $(SPACE)- Collect MCU config information)

# Configuration parameter translation
# [CLKFRE] frequency of MCU clock
ifneq ($(CLKFRE),)
    ifeq ($(shell $(ECHO) $(CLKFRE) | $(GREP) '^[[:digit:]]*$$'),)
        $(error Invalid CLKFRE value)
    else
        CLOCK_FREQUENCY := $(CLKFRE)
    endif
else
    CLOCK_FREQUENCY := 11059200
endif
# [PRESCALER] MCU prescaler
ifeq ($(PRESCALER),)
    PRESCALER_FACTOR ?= 12
else ifeq ($(PRESCALER),6)
    PRESCALER_FACTOR := 6
else ifeq ($(PRESCALER),12)
    PRESCALER_FACTOR := 12
else
    $(error Invalid PRESCALER value, the value must be 6 or 12!)
endif

# [CODE] internal ROM
ifneq ($(CODE),)
    export CODE_SIZE := $(shell $(ECHO) $(CODE) | $(AWK) '{printf("%d",$$1*1024)}')
endif
# [XRAM] external RAM
ifneq ($(XRAM),)
    export XRAM_SIZE := $(shell $(ECHO) $(XRAM) | $(AWK) '{printf("%d",$$1*1024)}')
endif

# [MCU] MCU model enumeration
ifneq ($(MCU),)
    mcu_model := $(shell $(ECHO) $(MCU) | $(TR) '[a-z]' '[A-Z]')
    MCU_MACRO := MCU_MODEL_$(mcu_model)
    ifeq ($(mcu_model), STC15F2K08S2)
        CODE_SIZE ?= 8192
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15F2K16S2)
        CODE_SIZE ?= 16384
        IRAM_SIZE := 256
        XRAM_SIZE ?= 8192
    else ifeq ($(mcu_model), STC15F2K32S2)
        CODE_SIZE ?= 32768
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15F2K40S2)
        CODE_SIZE ?= 40960
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15F2K48S2)
        CODE_SIZE ?= 49152
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15F2K56S2)
        CODE_SIZE ?= 57344
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15F2K60S2)
        CODE_SIZE ?= 61440
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), IAP15F2K61S2)
        CODE_SIZE ?= 62464
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), IRC15F2K63S2)
        CODE_SIZE ?= 65024
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15F2K32S)
        CODE_SIZE ?= 32768
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15F2K60S)
        CODE_SIZE ?= 61440
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), IAP15F2K61S)
        CODE_SIZE ?= 62464
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15F2K24AS)
        CODE_SIZE ?= 24576
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15F2K48AS)
        CODE_SIZE ?= 49152
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K08S2)
        CODE_SIZE ?= 8192
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K16S2)
        CODE_SIZE ?= 16384
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K24S2)
        CODE_SIZE ?= 24576
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K32S2)
        CODE_SIZE ?= 32768
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K40S2)
        CODE_SIZE ?= 40960
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K48S2)
        CODE_SIZE ?= 49152
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K56S2)
        CODE_SIZE ?= 57344
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K60S2)
        CODE_SIZE ?= 61440
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), IAP15L2K61S2)
        CODE_SIZE ?= 62464
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K32S)
        CODE_SIZE ?= 32768
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K60S)
        CODE_SIZE ?= 61440
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), IAP15L2K61S)
        CODE_SIZE ?= 62464
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K24AS)
        CODE_SIZE ?= 24576
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15L2K48AS)
        CODE_SIZE ?= 49152
        IRAM_SIZE := 256
        XRAM_SIZE ?= 1792
    else ifeq ($(mcu_model), STC15F100W)
        CODE_SIZE ?= 512
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15F101W)
        CODE_SIZE ?= 1024
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15F102W)
        CODE_SIZE ?= 2048
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15F103W)
        CODE_SIZE ?= 3072
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15F104W)
        CODE_SIZE ?= 4096
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), IAP15F105W)
        CODE_SIZE ?= 5120
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), IRC15F107W)
        CODE_SIZE ?= 7168
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15L100W)
        CODE_SIZE ?= 512
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15L101W)
        CODE_SIZE ?= 1024
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15L102W)
        CODE_SIZE ?= 2048
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15L104W)
        CODE_SIZE ?= 4096
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), IAP15L105W)
        CODE_SIZE ?= 5120
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15W100)
        CODE_SIZE ?= 512
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15W101)
        CODE_SIZE ?= 1024
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15W102)
        CODE_SIZE ?= 2048
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15W103)
        CODE_SIZE ?= 3072
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15W104)
        CODE_SIZE ?= 4096
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), IAP15W105)
        CODE_SIZE ?= 5120
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), IRC15W107)
        CODE_SIZE ?= 7168
        IRAM_SIZE := 128
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15W201S)
        CODE_SIZE ?= 1024
        IRAM_SIZE := 256
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15W202S)
        CODE_SIZE ?= 2048
        IRAM_SIZE := 256
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15W203S)
        CODE_SIZE ?= 3072
        IRAM_SIZE := 256
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15W204S)
        CODE_SIZE ?= 4096
        IRAM_SIZE := 256
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), IAP15W205S)
        CODE_SIZE ?= 4096
        IRAM_SIZE := 256
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), IRC15W207S)
        CODE_SIZE ?= 7680
        IRAM_SIZE := 256
        XRAM_SIZE ?= 0
    else ifeq ($(mcu_model), STC15W401AS)
        CODE_SIZE ?= 1024
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC15W402AS)
        CODE_SIZE ?= 2048
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC15W404AS)
        CODE_SIZE ?= 4096
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC15W408AS)
        CODE_SIZE ?= 8192
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), IAP15W413AS)
        CODE_SIZE ?= 13312
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), IRC15W415AS)
        CODE_SIZE ?= 15872
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC15W404S)
        CODE_SIZE ?= 4096
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC15W408S)
        CODE_SIZE ?= 8192
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC15W410S)
        CODE_SIZE ?= 10240
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), IAP15W413S)
        CODE_SIZE ?= 13312
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), IRC15W415S)
        CODE_SIZE ?= 15872
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC15W1K16S)
        CODE_SIZE ?= 16384
        IRAM_SIZE := 256
        XRAM_SIZE ?= 768
    else ifeq ($(mcu_model), STC15W1K24S)
        CODE_SIZE ?= 24576
        IRAM_SIZE := 256
        XRAM_SIZE ?= 768
    else ifeq ($(mcu_model), IAP15W1K29S)
        CODE_SIZE ?= 29696
        IRAM_SIZE := 256
        XRAM_SIZE ?= 768
    else ifeq ($(mcu_model), IRC15W1K31S)
        CODE_SIZE ?= 32256
        IRAM_SIZE := 256
        XRAM_SIZE ?= 768
    else ifeq ($(mcu_model), STC15W1K08PWM)
        CODE_SIZE ?= 8192
        IRAM_SIZE := 256
        XRAM_SIZE ?= 768
    else ifeq ($(mcu_model), STC15W1K16PWM)
        CODE_SIZE ?= 16384
        IRAM_SIZE := 256
        XRAM_SIZE ?= 768
    else ifeq ($(mcu_model), STC15W1K20S)
        CODE_SIZE ?= 20480
        IRAM_SIZE := 256
        XRAM_SIZE ?= 768
    else ifeq ($(mcu_model), STC15W4K16S4)
        CODE_SIZE ?= 16384
        IRAM_SIZE := 256
        XRAM_SIZE ?= 3840
    else ifeq ($(mcu_model), STC15W4K32S4)
        CODE_SIZE ?= 32768
        IRAM_SIZE := 256
        XRAM_SIZE ?= 3840
    else ifeq ($(mcu_model), STC15W4K40S4)
        CODE_SIZE ?= 40960
        IRAM_SIZE := 256
        XRAM_SIZE ?= 3840
    else ifeq ($(mcu_model), STC15W4K48S4)
        CODE_SIZE ?= 49152
        IRAM_SIZE := 256
        XRAM_SIZE ?= 3840
    else ifeq ($(mcu_model), STC15W4K56S4)
        CODE_SIZE ?= 57344
        IRAM_SIZE := 256
        XRAM_SIZE ?= 3840
    else ifeq ($(mcu_model), IAP15W4K58S4)
        CODE_SIZE ?= 59392
        IRAM_SIZE := 256
        XRAM_SIZE ?= 3840
    else ifeq ($(mcu_model), IAP15W4K61S4)
        CODE_SIZE ?= 62464
        IRAM_SIZE := 256
        XRAM_SIZE ?= 3840
    else ifeq ($(mcu_model), IRC15W4K63S4)
        CODE_SIZE ?= 65024
        IRAM_SIZE := 256
        XRAM_SIZE ?= 3840
    else ifeq ($(mcu_model), STC15F408AD)
        CODE_SIZE ?= 8192
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), IAP15F413AD)
        CODE_SIZE ?= 13312
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), STC15L408AD)
        CODE_SIZE ?= 8192
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else ifeq ($(mcu_model), IAP15L413AD)
        CODE_SIZE ?= 13312
        IRAM_SIZE := 256
        XRAM_SIZE ?= 256
    else
        $(error Unknow or unsupport MCU model $(MCU))
    endif
else
    $(error Unspecify MCU model!)
endif

# [PACKAGING] MCU packaging
ifneq ($(PACKAGING),)
    MCU_PACKAGING := $(shell $(ECHO) $(PACKAGING) | $(TR) '[a-z]' '[A-Z]')
else
    $(error Uspecify MCU packaging!)
endif

# Generate and export CFLAGS
#   Details:
#    --fsigned-char     Make "char" signed by default
#    -mmcs51            Generate code for the Intel MCS51 family of processors.
#                       This is the default processor target.
#    --std-sdcc99       Use ISO C99 standard with SDCC extensions
#    --opt-code-size    Optimize for code size rather than speed
#    --code-loc         Code Segment Location
#    --code-size        Code Segment size
#    --iram-size        Internal Ram size
#    --xram-size        External Ram size
#    --Werror           Treat the warnings as errors
export CFLAGS := -c -I$(INCDIR) \
-mmcs51 -D__CONF_MCU_MODEL=$(MCU_MACRO) \
-D__CONF_MCU_PACKAGING=$(MCU_PACKAGING) \
-D__CONF_FRE_CLKIN=$(CLOCK_FREQUENCY)UL \
--std-sdcc99 --fsigned-char \
--opt-code-size \
--code-loc 0x0000 --code-size $(CODE_SIZE) \
--iram-size $(IRAM_SIZE) \
--xram-size $(XRAM_SIZE)

# Generate and export AFLAGS
#     -c      do not warn if the library had to be created
#     -s      act as ranlib
#     -r      replace existing or insert new file(s) into the archive
AFLAGS        := -rcs

# Print final MCU information according to all configurations
$(info [mcu-model] $(mcu_model) (code=$(CODE_SIZE)B, iram=$(IRAM_SIZE)B, xram=$(XRAM_SIZE)B))
$(info [mcu-clock] $(shell $(ECHO) $(CLOCK_FREQUENCY) | $(AWK) '{printf("%.6f",$$1/1000000)}') MHz)
$(info [prescaler] $(PRESCALER_FACTOR)T mode)
