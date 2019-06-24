#include "vd.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include "partclone.h"

struct virtual_disk {
    int64_t offset;
    int debug;
    char *fmt;
};

virtual_disk_t vd_open(const char *file, const char *fmt, const int64_t offset, const int debug)
{
    virtual_disk_t vd = malloc(sizeof (struct virtual_disk));
    if (vd == NULL) {
        return vd;
    }
    
    memset(vd, 0, sizeof(struct virtual_disk));

    vd->offset = offset;
    vd->debug = debug;
    vd->fmt = strdup(fmt);

	log_mesg(0, 0, 1, debug, "open virtual disk. disk=%s, fmt=%s, offset=%lld, vd=%p\n", file, fmt, offset, vd);
    return vd;
}

void vd_close(const virtual_disk_t vd) {
    assert(vd != NULL);

	log_mesg(0, 0, 1, vd->debug, "close virtual disk. vd=%p\n", vd);
    if (vd->fmt) {
        free(vd->fmt);
    }
    free(vd);
}

int64_t vd_write(const virtual_disk_t vd, const int64_t offset, const void *buf, const int64_t size) {

	log_mesg(0, 0, 1, vd->debug, "write virtual disk. vd=%p, fmt=%s, base=%lld, offset=%lld, data=%p, size=%lld\n", vd, vd->fmt, vd->offset, offset, buf, size);
    return size;
}

int64_t vd_read(const virtual_disk_t vd, const int64_t offset, void *buf, int64_t max) {
	log_mesg(0, 0, 1, vd->debug, "read virtual disk. vd=%p, fmt=%s, base=%lld, offset=%lld, data=%p, size=%lld\n", vd, vd->fmt, vd->offset, offset, buf, max);
    return max;
}

void vd_sync(const virtual_disk_t vd) {

	log_mesg(0, 0, 1, vd->debug, "sync virtual disk. vd=%p, fmt=%s, base=%lld\n", vd, vd->fmt, vd->offset);
}