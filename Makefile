ROOTDIR := $(shell pwd)
PROJ := tiger

$(info project name: $(PROJ))
$(info root directory: $(ROOTDIR))

export ROOTDIR PROJ

tiger:
	@$(MAKE) -C src $@

.PHONY: clean
clean: 
	@rm -rf $(PROJ) && $(MAKE) -C src $@