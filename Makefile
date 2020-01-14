# N-Browser Makefile

TARGET    =nBrowser
OBJS      =nBrowser.o
CFLAGS    =-Wall -g
CXX       =g++
INCLUDES  =-I./ 
INCLUDES += $(shell pkg-config --cflags webkit2gtk-4.0 gtkmm-3.0)
LIBS      = $(shell pkg-config --libs webkit2gtk-4.0 gtkmm-3.0)

$(TARGET): ${OBJS}
	${CXX} -o $@ ${OBJS} ${LIBS}

%.o: %.cpp
	${CXX} -o $@ -c ${CFLAGS} ${INCLUDES} $<

clean:
	rm -f $(TARGET) $(OBJS) core *.core
