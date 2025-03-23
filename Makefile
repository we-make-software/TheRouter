KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

EXTRA_CFLAGS += -I../ExpiryWorkBase -I../TheMailConditioner -I../TheMaintainer
KBUILD_EXTRA_SYMBOLS := ../ExpiryWorkBase/Module.symvers ../TheMailConditioner/Module.symvers ../TheMaintainer/Module.symvers


COMMIT_MSG = Update on $(shell date '+%Y-%m-%d %H:%M:%S')

obj-m := TheRouter.o

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean

start:
	make all
	sudo insmod TheRouter.ko

stop:
	sudo rmmod TheRouter.ko
	make clean

commit:
	@if ! git diff-index --quiet HEAD; then \
		git add . && \
		git commit -m "$(COMMIT_MSG)" && \
		git push origin main; \
	else \
		echo "No changes in $(PWD) to commit."; \
	fi

pull:
	git pull origin main --rebase

