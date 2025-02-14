#ifndef LIBC_IMPL_H
#define LIBC_IMPL_H

#include <stdint.h>

union FloatReg {
    float f[2];
    uint32_t w[2];
    //double d;
};

typedef uint64_t (*fptr_trampoline)(uint8_t* mem, uint32_t sp, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3,
                                    uint32_t fp_dest);


void mmap_initial_data_range(uint8_t *mem, uint32_t start, uint32_t end);
void setup_libc_data(uint8_t *mem);

uint32_t wrapper_sbrk(uint8_t *mem, int increment);
uint32_t wrapper_malloc(uint8_t *mem, uint32_t size);
uint32_t wrapper_calloc(uint8_t *mem, uint32_t num, uint32_t size);
uint32_t wrapper_realloc(uint8_t *mem, uint32_t data_addr, uint32_t size);
int wrapper_fscanf(uint8_t *mem, uint32_t fp_addr, uint32_t format_addr, uint32_t sp);
int wrapper_printf(uint8_t *mem, uint32_t format_addr, uint32_t sp);
int wrapper_sprintf(uint8_t *mem, uint32_t str_addr, uint32_t format_addr, uint32_t sp);
int wrapper_fprintf(uint8_t *mem, uint32_t fp_addr, uint32_t format_addr, uint32_t sp);
int wrapper__doprnt(uint8_t *mem, uint32_t format_addr, uint32_t params_addr, uint32_t fp_addr);
void wrapper_free(uint8_t *mem, uint32_t data_addr);
uint32_t wrapper_strlen(uint8_t *mem, uint32_t str_addr);
int wrapper_open(uint8_t *mem, uint32_t pathname_addr, int flags, int mode);
int wrapper_creat(uint8_t *mem, uint32_t pathname_addr, int mode);
int wrapper_access(uint8_t *mem, uint32_t pathname_addr, int mode);
int wrapper_rename(uint8_t *mem, uint32_t oldpath_addr, uint32_t newpath_addr);
int wrapper_utime(uint8_t *mem, uint32_t filename_addr, uint32_t times_addr);
int wrapper_flock(uint8_t *mem, int fd, int operation);
int wrapper_chmod(uint8_t *mem, uint32_t path_addr, uint32_t mode);
int wrapper_umask(int mode);
uint32_t wrapper_ecvt(uint8_t *mem, double number, int ndigits, uint32_t decpt_addr, uint32_t sign_addr);
uint32_t wrapper_fcvt(uint8_t *mem, double number, int ndigits, uint32_t decpt_addr, uint32_t sign_addr);
double wrapper_sqrt(double v);
float wrapper_sqrtf(float v);
int wrapper_atoi(uint8_t *mem, uint32_t nptr_addr);
int wrapper_atol(uint8_t *mem, uint32_t nptr_addr);
double wrapper_atof(uint8_t *mem, uint32_t nptr_addr);
int wrapper_strtol(uint8_t *mem, uint32_t nptr_addr, uint32_t endptr_addr, int base);
uint32_t wrapper_strtoul(uint8_t *mem, uint32_t nptr_addr, uint32_t endptr_addr, int base);
int64_t wrapper_strtoll(uint8_t *mem, uint32_t nptr_addr, uint32_t endptr_addr, int base);
uint64_t wrapper_strtoull(uint8_t *mem, uint32_t nptr_addr, uint32_t endptr_addr, int base);
double wrapper_strtod(uint8_t *mem, uint32_t nptr_addr, uint32_t endptr_addr);
uint32_t wrapper_strchr(uint8_t *mem, uint32_t str_addr, int c);
uint32_t wrapper_strrchr(uint8_t *mem, uint32_t str_addr, int c);
uint32_t wrapper_strcspn(uint8_t *mem, uint32_t str_addr, uint32_t invalid_addr);
uint32_t wrapper_strpbrk(uint8_t *mem, uint32_t str_addr, uint32_t accept_addr);
int wrapper_fstat(uint8_t *mem, int fildes, uint32_t buf_addr);
int wrapper_stat(uint8_t *mem, uint32_t pathname_addr, uint32_t buf_addr);
int wrapper_ftruncate(uint8_t *mem, int fd, int length);
int wrapper_truncate(uint8_t *mem, uint32_t pathname_addr, int length);
void wrapper_bcopy(uint8_t *mem, uint32_t src_addr, uint32_t dst_addr, uint32_t len);
uint32_t wrapper_memcpy(uint8_t *mem, uint32_t dst_addr, uint32_t src_addr, uint32_t len);
uint32_t wrapper_memccpy(uint8_t *mem, uint32_t dst_addr, uint32_t src_addr, int c, uint32_t len);
int wrapper_read(uint8_t *mem, int fd, uint32_t buf_addr, uint32_t nbytes);
int wrapper_write(uint8_t *mem, int fd, uint32_t buf_addr, uint32_t nbytes);
uint32_t wrapper_fopen(uint8_t *mem, uint32_t path_addr, uint32_t mode_addr);
uint32_t wrapper_freopen(uint8_t *mem, uint32_t path_addr, uint32_t mode_addr, uint32_t fp_addr);
int wrapper_fclose(uint8_t *mem, uint32_t fp_addr);
int wrapper_fflush(uint8_t *mem, uint32_t fp_addr);
int wrapper_fchown(uint8_t *mem, int fd, int owner, int group);
int wrapper_ftell(uint8_t *mem, uint32_t fp_addr);
void wrapper_rewind(uint8_t *mem, uint32_t fp_addr);
int wrapper_fseek(uint8_t *mem, uint32_t fp_addr, int offset, int origin);
int wrapper_lseek(uint8_t *mem, int fd, int offset, int whence);
int wrapper_dup(uint8_t *mem, int fd);
int wrapper_dup2(uint8_t *mem, int oldfd, int newfd);
int wrapper_pipe(uint8_t *mem, uint32_t pipefd_addr);
void wrapper_perror(uint8_t *mem, uint32_t str_addr);
int wrapper_fdopen(uint8_t *mem, int fd, uint32_t mode_addr);
uint32_t wrapper_memset(uint8_t *mem, uint32_t dest_addr, int byte, uint32_t n);
int wrapper_bcmp(uint8_t *mem, uint32_t s1_addr, uint32_t s2_addr, uint32_t n);
int wrapper_memcmp(uint8_t *mem, uint32_t s1_addr, uint32_t s2_addr, uint32_t n);
int wrapper_getpid(void);
int wrapper_getpgrp(uint8_t *mem);
int wrapper_remove(uint8_t *mem, uint32_t path_addr);
int wrapper_unlink(uint8_t *mem, uint32_t path_addr);
int wrapper_close(uint8_t *mem, int fd);
int wrapper_strcmp(uint8_t *mem, uint32_t s1_addr, uint32_t s2_addr);
int wrapper_strncmp(uint8_t *mem, uint32_t s1_addr, uint32_t s2_addr, uint32_t n);
uint32_t wrapper_strcpy(uint8_t *mem, uint32_t dest_addr, uint32_t src_addr);
uint32_t wrapper_strncpy(uint8_t *mem, uint32_t dest_addr, uint32_t src_addr, uint32_t n);
uint32_t wrapper_strcat(uint8_t *mem, uint32_t dest_addr, uint32_t src_addr);
uint32_t wrapper_strncat(uint8_t *mem, uint32_t dest_addr, uint32_t src_addr, uint32_t n);
uint32_t wrapper_strtok(uint8_t *mem, uint32_t str_addr, uint32_t delimiters_addr);
uint32_t wrapper_strstr(uint8_t *mem, uint32_t str1_addr, uint32_t str2_addr);
uint32_t wrapper_strdup(uint8_t *mem, uint32_t str_addr);
int wrapper_toupper(int c);
int wrapper_tolower(int c);
int wrapper_gethostname(uint8_t *mem, uint32_t name_addr, uint32_t len);
int wrapper_isatty(uint8_t *mem, int fd);
int wrapper_times(uint8_t *mem, uint32_t buffer_addr);
uint32_t wrapper_strftime(uint8_t *mem, uint32_t ptr_addr, uint32_t maxsize, uint32_t format_addr, uint32_t timeptr_addr);
int wrapper_clock(void);
uint32_t wrapper_ctime(uint8_t *mem, uint32_t timep_addr);
uint32_t wrapper_localtime(uint8_t *mem, uint32_t timep_addr);
int wrapper_setvbuf(uint8_t *mem, uint32_t fp_addr, uint32_t buf_addr, int mode, uint32_t size);
int wrapper___semgetc(uint8_t *mem, uint32_t fp_addr);
int wrapper___semputc(uint8_t *mem, int c, uint32_t fp_addr);
int wrapper_fgetc(uint8_t *mem, uint32_t fp_addr);
int wrapper_fgets(uint8_t *mem, uint32_t str_addr, int count, uint32_t fp_addr);
int wrapper___filbuf(uint8_t *mem, uint32_t fp_addr);
int wrapper___flsbuf(uint8_t *mem, int ch, uint32_t fp_addr);
int wrapper_ungetc(uint8_t *mem, int ch, uint32_t fp_addr);
uint32_t wrapper_gets(uint8_t *mem, uint32_t str_addr);
uint32_t wrapper_fread(uint8_t *mem, uint32_t data_addr, uint32_t size, uint32_t count, uint32_t fp_addr);
uint32_t wrapper_fwrite(uint8_t *mem, uint32_t data_addr, uint32_t size, uint32_t count, uint32_t fp_addr);
int wrapper_fputs(uint8_t *mem, uint32_t str_addr, uint32_t fp_addr);
int wrapper_puts(uint8_t *mem, uint32_t str_addr);
uint32_t wrapper_getcwd(uint8_t *mem, uint32_t buf_addr, uint32_t size);
int wrapper_time(uint8_t *mem, uint32_t tloc_addr);
void wrapper_bzero(uint8_t *mem, uint32_t str_addr, uint32_t n);
int wrapper_fp_class_d(double d);
double wrapper_ldexp(double d, int i);
uint64_t wrapper___ll_mul(uint64_t a0, uint64_t a1);
int64_t wrapper___ll_div(int64_t a0, int64_t a1);
int64_t wrapper___ll_rem(uint64_t a0, int64_t a1);
uint64_t wrapper___ll_lshift(uint64_t a0, uint64_t shift);
int64_t wrapper___ll_rshift(int64_t a0, uint64_t shift);
uint64_t wrapper___ull_div(uint64_t a0, uint64_t a1);
uint64_t wrapper___ull_rem(uint64_t a0, uint64_t a1);
uint64_t wrapper___ull_rshift(uint64_t a0, uint64_t shift);
uint64_t wrapper___d_to_ull(double d);
int64_t wrapper___d_to_ll(double d);
uint64_t wrapper___f_to_ull(float f);
int64_t wrapper___f_to_ll(float f);
float wrapper___ull_to_f(uint64_t v);
float wrapper___ll_to_f(int64_t v);
double wrapper___ull_to_d(uint64_t v);
double wrapper___ll_to_d(int64_t v);
void wrapper_abort(uint8_t *mem);
void wrapper_exit(uint8_t *mem, int status);
void wrapper__exit(uint8_t *mem, int status);
void wrapper__cleanup(uint8_t *mem);
uint32_t wrapper__rld_new_interface(uint8_t *mem, uint32_t operation, uint32_t sp);
void wrapper__exithandle(uint8_t *mem);
int wrapper__prctl(uint8_t *mem, int operation, uint32_t sp);
double wrapper__atod(uint8_t *mem, uint32_t buffer_addr, int ndigits, int dexp);
int wrapper_pathconf(uint8_t *mem, uint32_t path_addr, int name);
uint32_t wrapper_getenv(uint8_t *mem, uint32_t name_addr);
uint32_t wrapper_gettxt(uint8_t *mem, uint32_t msgid_addr, uint32_t default_str_addr);
uint32_t wrapper_setlocale(uint8_t *mem, int category, uint32_t locale_addr);
uint32_t wrapper_mmap(uint8_t *mem, uint32_t addr, uint32_t length, int prot, int flags, int fd, int offset);
int wrapper_munmap(uint8_t *mem, uint32_t addr, uint32_t length);
int wrapper_mprotect(uint8_t *mem, uint32_t addr, uint32_t length, int prot);
int wrapper_sysconf(uint8_t *mem, int name);
int wrapper_getpagesize(uint8_t *mem);
int wrapper_strerror(uint8_t *mem, int errnum);
int wrapper_ioctl(uint8_t *mem, int fd, uint32_t request, uint32_t sp);
int wrapper_fcntl(uint8_t *mem, int fd, int cmd, uint32_t sp);
uint32_t wrapper_signal(uint8_t *mem, int signum, fptr_trampoline trampoline, uint32_t handler_addr, uint32_t sp);
uint32_t wrapper_sigset(uint8_t *mem, int signum, fptr_trampoline trampoline, uint32_t disp_addr, uint32_t sp);
int wrapper_get_fpc_csr(uint8_t *mem);
int wrapper_set_fpc_csr(uint8_t *mem, int csr);
int wrapper_setjmp(uint8_t *mem, uint32_t addr);
void wrapper_longjmp(uint8_t *mem, uint32_t addr, int status);
uint32_t wrapper_tempnam(uint8_t *mem, uint32_t dir_addr, uint32_t pfx_addr);
uint32_t wrapper_tmpnam(uint8_t *mem, uint32_t str_addr);
uint32_t wrapper_mktemp(uint8_t *mem, uint32_t template_addr);
int wrapper_mkstemp(uint8_t *mem, uint32_t name_addr);
uint32_t wrapper_tmpfile(uint8_t *mem);
int wrapper_wait(uint8_t *mem, uint32_t wstatus_addr);
int wrapper_kill(uint8_t *mem, int pid, int sig);
int wrapper_execlp(uint8_t *mem, uint32_t file_addr, uint32_t sp);
int wrapper_execv(uint8_t *mem, uint32_t pathname_addr, uint32_t argv_addr);
int wrapper_execvp(uint8_t *mem, uint32_t file_addr, uint32_t argv_addr);
int wrapper_fork(uint8_t *mem);
int wrapper_system(uint8_t *mem, uint32_t command_addr);
uint32_t wrapper_tsearch(uint8_t *mem, uint32_t key_addr, uint32_t rootp_addr, uint32_t compar_addr);
uint32_t wrapper_tfind(uint8_t *mem, uint32_t key_addr, uint32_t rootp_addr, uint32_t compar_addr);
uint32_t wrapper_qsort(uint8_t *mem, uint32_t base_addr, uint32_t num, uint32_t size, fptr_trampoline trampoline, uint32_t compare_addr, uint32_t sp);
uint32_t wrapper_regcmp(uint8_t *mem, uint32_t string1_addr, uint32_t sp);
uint32_t wrapper_regex(uint8_t *mem, uint32_t re_addr, uint32_t subject_addr, uint32_t sp);
void wrapper___assert(uint8_t *mem, uint32_t assertion_addr, uint32_t file_addr, int line);
void wrapper_twalk(uint8_t *mem, uint32_t root_addr, fptr_trampoline trampoline, uint32_t action_addr, uint32_t sp);
int32_t wrapper_msync(uint8_t *mem, uint32_t addr_addr, uint32_t len, int32_t flags);
int32_t wrapper_mkdir(uint8_t *mem, uint32_t path_addr, uint32_t mode);
int32_t wrapper_fputc(uint8_t *mem, int32_t ch, uint32_t stream_addr);
int32_t wrapper_getopt(uint8_t *mem, int32_t argc, uint32_t argv_addr, uint32_t optstring_addr);
int32_t wrapper_link(uint8_t *mem, uint32_t oldpath_addr, uint32_t newpath_addr);
int32_t wrapper_vsprintf(uint8_t *mem, uint32_t buffer_addr, uint32_t format_addr, uint32_t vlist_addr);
double wrapper_fabs(double x);
int32_t wrapper_sysid(uint8_t *mem, uint32_t unknown_parameter_addr);
uint32_t wrapper_realpath(uint8_t *mem, uint32_t path_addr, uint32_t resolved_path_addr);
int32_t wrapper_fsync(uint8_t *mem, int32_t fd);
uint32_t wrapper_sleep(uint8_t *mem, uint32_t seconds);
int32_t wrapper_socket(uint8_t *mem, int32_t domain, int32_t type, int32_t protocol);
int32_t wrapper_connect(uint8_t *mem, int32_t sockfd, uint32_t addr_addr, uint32_t addrlen);
int32_t wrapper_recv(uint8_t *mem, int32_t sockfd, uint32_t buf_addr, uint32_t len, int32_t flags);
int32_t wrapper_send(uint8_t *mem, int32_t sockfd, uint32_t buf_addr, uint32_t len, int32_t flags);
int32_t wrapper_shutdown(uint8_t *mem, int32_t socket, int32_t how);
int32_t wrapper_sscanf(uint8_t *mem, uint32_t str_addr, uint32_t format_addr, uint32_t sp);

// C++ functions
uint32_t wrapper___nw__FUi(uint8_t *mem, uint32_t size);
void wrapper___dl__FPv(uint8_t *mem, uint32_t data_addr);

union FloatReg FloatReg_from_double(double d);
double double_from_FloatReg(union FloatReg floatreg);
double double_from_memory(uint8_t *mem, uint32_t address);

#endif
