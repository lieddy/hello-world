EXCUTABLE := Test
CPPFLAGS := -g -O2 
LIBS := -lpthread
OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
DEPS := $(patsubst %.o,%.d,$(OBJS))
CPPFLAGS += -MD
.phony:everything deps objs clean veryclean
everything:$(EXCUTABLE)
deps:$(DEPS)
objs:$(objs)
clean:
	@$(RM) *.o *.d
veryclean:
	@$(RM) $(EXCUTABLE)
-include $(DEPS)
$(EXCUTABLE):$(OBJS)
	g++ $(CPPFLAGS) $(OBJS) $(LIBS) -o$(EXCUTABLE)
