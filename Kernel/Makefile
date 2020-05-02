SUBPROJECT_CPP_FLAGS += -pie -fPIE -ffreestanding -fbuiltin -mno-80387 -mno-mmx -mno-sse -mno-sse2 -fno-asynchronous-unwind-tables
SUBPROJECT_CPP_FLAGS += -nostdlib -nostdinc -nostdinc++

all:
	make -sC boot
	make -sC init
	make -sC kernel
	@sh scripts/compile.sh "$(LD)" "$(LD_FLAGS)"

include ../Makefile.common
