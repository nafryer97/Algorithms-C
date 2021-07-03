SRCDIR := src
OBJDIR := objects
BINDIR := bin
SRCS := $(addprefix $(SRCDIR)/,insertion_sort.c)
OBJS := $(addprefix $(OBJDIR)/,insertion_sort.o)
BINS := $(addprefix $(BINDIR)/,insertion_sort)
CC := gcc

all : $(BINS)

insertion_sort : $(OBJDIR)/insertion_sort.o
	$(CC) -Wall -O2 -std=c11 -o $(BINDIR)/$@ $^

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) -g -Wall -O2 -std=c11 -o $@ -c $<

clean : 
	rm -v $(BINS) $(OBJS)

$(BINS) : | $(BINDIR)

$(BINDIR) : 
	mkdir $(BINDIR)

$(OBJS) : | $(OBJDIR)

$(OBJDIR) : 
	mkdir $(OBJDIR)
