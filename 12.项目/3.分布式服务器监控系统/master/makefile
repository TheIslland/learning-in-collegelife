CC := gcc
CFALGS := -Wall -g -Os -pthread
OBJS = master.o 

all: pihealthd-1.0 install
	@echo "this is OK"

pihealthd-1.0: $(OBJS)
	@$(CC) -o $@ $(CFALGS) $(OBJS)

$(OBJS) : %.o: %.c
	@$(CC) -c $(CFALGS) $< -o $@

.PHONY: clean
clean:
	@rm -rf *.o pihealthd-1.0
	@rm -rf ../common/*.o
	@echo Done cleaning

install: 
	@test -f /etc/pihealthd.conf || cp pihealthd.conf.sample /etc/pihealthd.conf
	@cp -f pihealthd-1.0 /usr/bin/
	@echo "Pihealthd installed"
