.PHONY: all
all: gclean

.PHONY: gclean
gclean:
	git clean -Xdf
