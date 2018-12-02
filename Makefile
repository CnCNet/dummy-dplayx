-include config.mk

PROXY        = dplayx
LDFLAGS      = -mdll -Wl,--enable-stdcall-fixup -Wl,--strip-all -Wl,--exclude-all-symbols
CFLAGS       = -std=c99

OBJS = dllmain.o

.PHONY: default
default: $(PROXY).dll

$(PROXY).dll: $(OBJS) $(PROXY).def
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ -lmsvcrt

clean:
	$(RM) $(OBJS) $(PROXY).dll
