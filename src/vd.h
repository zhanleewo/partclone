#ifndef VIRTUAL_DISK_H
#define VIRTUAL_DISK_H

#include <sys/types.h>

struct virtual_disk;
typedef struct virtual_disk* virtual_disk_t;

virtual_disk_t vd_open(const char *file, const char *fmt, const int64_t offset, const int debug);
void vd_close(const virtual_disk_t vd);

int64_t vd_write(const virtual_disk_t vd, const int64_t offset, const void *buf, const int64_t size);
int64_t vd_read(const virtual_disk_t vd, const int64_t offset, void *buf, int64_t max);

void vd_sync(const virtual_disk_t vd);
#endif