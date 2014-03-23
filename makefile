##
## PIN tools
##

##############################################################
#
# Here are some things you might want to configure
#
##############################################################

TARGET_COMPILER?=gnu
ifdef OS
    ifeq (${OS},Windows_NT)
        TARGET_COMPILER=ms
    endif
endif

##############################################################
#
# include *.config files
#
##############################################################

ifeq ($(TARGET_COMPILER),gnu)
    include ../makefile.gnu.config
    LINKER?=${CXX}
    CXXFLAGS ?= -I$(PIN_HOME)/InstLib -Wall -Werror -Wno-unknown-pragmas $(DBG) $(OPT) -MMD
endif

ifeq ($(TARGET_COMPILER),ms)
    include ../makefile.ms.config
    DBG?=
endif


##############################################################
#
# Tools sets
#
##############################################################

TOOL_ROOTS = trace
CONTEXT_TOOLS = 
SANITY_TOOLS = 

TOOL_ROOTS += $(CONTEXT_TOOLS)

TOOLS = $(TOOL_ROOTS:%=%$(PINTOOL_SUFFIX))

OBJS = Cache.o Set.o Block.o 


##############################################################
#
# build rules
#
##############################################################

all: tools

tools: $(TOOLS)
test: $(TOOL_ROOTS:%=%.test)
tests-sanity: $(SANITY_TOOLS:%=%.test)
control_detach.test : control_detach$(PINTOOL_SUFFIX) control_detach.tested control_detach.failed 
	touch $<.makefile.copy; rm $<.makefile.copy
	$(PIN) -t $< -skip 1000  -- $(TESTAPP) makefile $<.makefile.copy
	$(PIN_CMP) makefile $<.makefile.copy
	rm $<.makefile.copy; rm control_detach.failed

## build rules

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $(PIN_CXXFLAGS) ${OUTOPT}$@ $<
$(TOOLS): $(OBJS) $(PIN_LIBNAMES)

$(TOOLS): %$(PINTOOL_SUFFIX) : %.o
	${LINKER} $(PIN_LDFLAGS) $(LINK_DEBUG) $(OBJS) ${LINK_OUT}$@ $< ${PIN_LPATHS} $(PIN_LIBS) $(EXTRA_LIBS) $(DBG)

## cleaning
clean:
	-rm -f *.o $(TOOLS) *.out *.tested *.failed *.d *.exp *.lib

-include *.d
