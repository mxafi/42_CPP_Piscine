.PHONY: all
all: gclean reset

.PHONY: gclean
gclean:
	git clean -xdf

.PHONY: reset
reset:
	git reset --hard
