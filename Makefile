ROOTDIR := $(shell pwd)
PROJ := tiger

$(info project name: $(PROJ))
$(info root directory: $(ROOTDIR))

export ROOTDIR PROJ

.PHONY: tiger
tiger:
	@$(MAKE) -C src $@

.PHONY: lex
lex:
	@$(MAKE) -C src $@

.PHONY: clean
clean: 
	@rm -rf $(PROJ) && $(MAKE) -C src $@