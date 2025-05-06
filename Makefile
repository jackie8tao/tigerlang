ROOTDIR := $(shell pwd)
$(info root directory: $(ROOTDIR))

export ROOTDIR

.PHOMY: tiger clean
tiger:
	$(MAKE) -C src $@

clean: 
	$(MAKE) -C src $@