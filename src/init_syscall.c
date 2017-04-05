#include "ft_strace.h"
#include "sys.h"

int		*init_args(int i, int n)
{
	int	*ret;

	ret = (int *)malloc(sizeof(int) * n);
	switch (i)
	{
		case READ:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case WRITE:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case OPEN:
			ret[0] = STRING;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case CLOSE:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case STAT:
			ret[0] = STRING;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case FSTAT:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case LSTAT:
			ret[0] = STRING;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case POLL:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case LSEEK:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case MMAP:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
			ret[5] = INT;
			ret[6] = PTR;
		break ;
		case MPROTECT:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case MUNMAP:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case BRK:
			ret[0] = PTR;
			ret[1] = INT;
		break ;
		case SIGACTION:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case SIGPROCMASK:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case SIGRETURN:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case IOCTL:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = VARGS;
			ret[3] = INT;
		break ;
		case READV:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case WRITEV:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case ACCESS:
			ret[0] = STRING;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case PIPE:
			ret[0] = PTR;
			ret[1] = INT;
		break ;
		case SELECT:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = PTR;
			ret[3] = PTR;
			ret[4] = STRUCT;
			ret[5] = INT;
		break ;
		case SCHED_YIELD:
			ret[0] = VOID;
			ret[1] = INT;
		break ;
		case MREMAP:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = PTR;
			ret[5] = PTR;
		break ;
		case MSYNC:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case MINCORE:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = STRING;
			ret[3] = INT;
		break ;
		case MADVISE:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case SHMGET:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case SHMAT:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
			ret[3] = PTR;
		break ;
		case SHMCTL:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case DUP:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case DUP2:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case PAUSE:
			ret[0] = VOID;
			ret[1] = INT;
		break ;
		case NANOSLEEP:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case GETITIMER:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case ALARM:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case SETITIMER:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case GETPID:
			ret[0] = VOID;
			ret[1] = STRUCT;
		break ;
		case SENDFILE:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case SOCKET:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case CONNECT:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case ACCEPT:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case SENDTO:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = STRUCT;
			ret[5] = STRUCT;
			ret[6] = INT;
		break ;
		case RECVFROM:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = STRUCT;
			ret[5] = PTR;
			ret[6] = INT;
		break ;
		case SENDMSG:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case RECVMSG:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case SHUTDOWN:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case BIND:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case LISTEN:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case GETSOCKNAME:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case GETPEERNAME:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case SOCKETPAIR:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = PTR;
			ret[4] = INT;
		break ;
		case SETSOCKOPT:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = PTR;
			ret[4] = STRUCT;
			ret[5] = INT;
		break ;
		case GETSOCKOPT:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = PTR;
			ret[4] = PTR;
			ret[5] = INT;
		break ;
		case CLONE:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
			ret[3] = PTR;
			ret[4] = PTR;
			ret[5] = STRUCT;
			ret[6] = PTR;
			ret[7] = INT;
		break ;
		case FORK:
			ret[0] = VOID;
			ret[1] = STRUCT;
		break ;
		case VFORK:
			ret[0] = VOID;
			ret[1] = STRUCT;
		break ;
		case EXECVE:
			ret[0] = STRING;
			ret[1] = STRINGSTAR;
			ret[2] = STRINGSTAR;
			ret[3] = INT;
		break ;
		case EXIT:
			ret[0] = INT;
			ret[1] = VOID;
		break ;
		case WAIT4:
			ret[0] = PTR;
			ret[1] = PTR;
			ret[2] = INT;
			ret[3] = STRUCT;
			ret[4] = INT;
		break ;
		case KILL:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case UNAME:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case SEMGET:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case SEMOP:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case SEMCTL:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = VARGS;
			ret[4] = INT;
		break ;
		case SHMDT:
			ret[0] = PTR;
			ret[1] = INT;
		break ;
		case MSGGET:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case MSGSND:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case MSGRCV:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
			ret[5] = INT;
		break ;
		case MSGCTL:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case FCNTL:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case FLOCK:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case FSYNC:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case FDATASYNC:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case TRUNCATE:
			ret[0] = STRING;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case FTRUNCATE:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case GETDENTS:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case GETCWD:
			ret[0] = STRING;
			ret[1] = INT;
			ret[2] = STRING;
		break ;
		case CHDIR:
			ret[0] = STRING;
			ret[1] = INT;
		break ;
		case FCHDIR:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case RENAME:
			ret[0] = STRING;
			ret[1] = STRING;
			ret[2] = INT;
		break ;
		case MKDIR:
			ret[0] = STRING;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case RMDIR:
			ret[0] = STRING;
			ret[1] = INT;
		break ;
		case CREAT:
			ret[0] = STRING;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case LINK:
			ret[0] = STRING;
			ret[1] = STRING;
			ret[2] = INT;
		break ;
		case UNLINK:
			ret[0] = STRING;
			ret[1] = INT;
		break ;
		case SYMLINK:
			ret[0] = STRING;
			ret[1] = STRING;
			ret[2] = INT;
		break ;
		case READLINK:
			ret[0] = STRING;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case CHMOD:
			ret[0] = STRING;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case FCHMOD:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case CHOWN:
			ret[0] = STRING;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case FCHOWN:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case LCHOWN:
			ret[0] = STRING;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case UMASK:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
		break ;
		case GETTIMEOFDAY:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case GETRLIMIT:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case GETRUSAGE:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case SYSINFO:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case TIMES:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
		break ;
		case PTRACE:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = PTR;
			ret[3] = PTR;
			ret[4] = INT;
		break ;
		case GETUID:
			ret[0] = INT;
		break ;
		case SYSLOG:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case GETGID:
			ret[0] = INT;
		break ;
		case SETUID:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case SETGID:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case GETEUID:
			ret[0] = INT;
		break ;
		case GETEGID:
			ret[0] = INT;
		break ;
		case SETPGID:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case GETPPID:
			ret[0] = VOID;
			ret[1] = STRUCT;
		break ;
		case GETPGRP:
			ret[0] = VOID;
			ret[1] = STRUCT;
		break ;
		case SETSID:
			ret[0] = VOID;
			ret[1] = STRUCT;
		break ;
		case SETREUID:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case SETREGID:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case GETGROUPS:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case SETGROUPS:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
		break ;
		case SETRESUID:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case GETRESUID:
			ret[0] = PTR;
			ret[1] = PTR;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case SETRESGID:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case GETRESGID:
			ret[0] = PTR;
			ret[1] = PTR;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case GETPGID:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
		break ;
		case SETFSUID:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case SETFSGID:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case GETSID:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
		break ;
		case CAPGET:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case CAPSET:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case SIGPENDING:
			ret[0] = PTR;
			ret[1] = INT;
		break ;
		case SIGTIMEDWAIT:
			ret[0] = PTR;
			ret[1] = PTR;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case RT_SIGQUEUEINFO:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case SIGSUSPEND:
			ret[0] = PTR;
			ret[1] = INT;
		break ;
		case SIGALTSTACK:
			ret[0] = PTR;
			ret[1] = PTR;
			ret[2] = INT;
		break ;
		case UTIME:
			ret[0] = STRING;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case MKNOD:
			ret[0] = STRING;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case USELIB:
			ret[0] = STRING;
			ret[1] = INT;
		break ;
		case PERSONALITY:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case USTAT:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case STATFS:
			ret[0] = STRING;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case FSTATFS:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case SYSFS:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = INT;
		break ;
		case GETPRIORITY:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case SETPRIORITY:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case SCHED_SETPARAM:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case SCHED_GETPARAM:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case SCHED_SETSCHEDULER:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case SCHED_GETSCHEDULER:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case SCHED_GET_PRIORITY_MAX:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case SCHED_GET_PRIORITY_MIN:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case SCHED_RR_GET_INTERVAL:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case MLOCK:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case MUNLOCK:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case MLOCKALL:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case MUNLOCKALL:
			ret[0] = VOID;
			ret[1] = INT;
		break ;
		case VHANGUP:
			ret[0] = VOID;
			ret[1] = INT;
		break ;
		case MODIFY_LDT:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case PIVOT_ROOT:
			ret[0] = STRING;
			ret[1] = STRING;
			ret[2] = INT;
		break ;
		case _SYSCTL:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case PRCTL:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
			ret[5] = INT;
		break ;
		case ADJTIMEX:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case SETRLIMIT:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case CHROOT:
			ret[0] = STRING;
			ret[1] = INT;
		break ;
		case SYNC:
			ret[0] = VOID;
			ret[1] = VOID;
		break ;
		case ACCT:
			ret[0] = STRING;
			ret[1] = INT;
		break ;
		case SETTIMEOFDAY:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case MOUNT:
			ret[0] = STRING;
			ret[1] = STRING;
			ret[2] = STRING;
			ret[3] = INT;
			ret[4] = PTR;
			ret[5] = INT;
		break ;
		case UMOUNT2:
			ret[0] = STRING;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case SWAPON:
			ret[0] = STRING;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case SWAPOFF:
			ret[0] = STRING;
			ret[1] = INT;
		break ;
		case REBOOT:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = PTR;
			ret[4] = INT;
		break ;
		case SETHOSTNAME:
			ret[0] = STRING;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case SETDOMAINNAME:
			ret[0] = STRING;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case IOPL:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case IOPERM:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case INIT_MODULE:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = STRING;
			ret[3] = INT;
		break ;
		case RESTART_SYSCALL:
			ret[0] = INT;
		break;
		case QUOTACTL:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = STRUCT;
			ret[4] = INT;
		break ;
		case READAHEAD:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case TKILL:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case TIME:
			ret[0] = PTR;
			ret[1] = STRUCT;
		break ;
		case FUTEX:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = STRUCT;
			ret[4] = INT;
			ret[5] = INT;
			ret[6] = INT;
		break ;
		case SCHED_SETAFFINITY:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case SCHED_GETAFFINITY:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case SET_THREAD_AREA:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case IO_SETUP:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
		break ;
		case IO_DESTROY:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case IO_GETEVENTS:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = STRUCT;
			ret[4] = STRUCT;
			ret[5] = INT;
		break ;
		case IO_SUBMIT:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case IO_CANCEL:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case GET_THREAD_AREA:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case LOOKUP_DCOOKIE:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case EPOLL_CREATE:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case REMAP_FILE_PAGES:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
			ret[5] = INT;
		break ;
		case SET_TID_ADDRESS:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		break ;
		case SEMTIMEDOP:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = STRUCT;
			ret[4] = INT;
		break ;
		case TIMER_CREATE:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case TIMER_SETTIME:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = STRUCT;
			ret[3] = STRUCT;
			ret[4] = INT;
		break ;
		case TIMER_GETTIME:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case TIMER_GETOVERRUN:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case TIMER_DELETE:
			ret[0] = STRUCT;
			ret[1] = INT;
		break ;
		case CLOCK_SETTIME:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case CLOCK_GETTIME:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case GETTID:
			ret[0] = INT;	
		break ;
		case CLOCK_GETRES:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case CLOCK_NANOSLEEP:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = STRUCT;
			ret[3] = STRUCT;
			ret[4] = INT;
		break ;
		case EXIT_GROUP:
			ret[0] = INT;
			ret[1] = VOID;
		break ;
		case EPOLL_WAIT:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case EPOLL_CTL:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = STRUCT;
			ret[4] = INT;
		break ;
		case TGKILL:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case UTIMES:
			ret[0] = STRING;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case MBIND:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
			ret[5] = INT;
			ret[6] = INT;
		break ;
		case GET_MEMPOLICY:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
			ret[5] = INT;
		break ;
		case MQ_OPEN:
			ret[0] = STRING;
			ret[1] = INT;
			ret[2] = STRUCT;
		break ;
		case MQ_UNLINK:
			ret[0] = STRING;
			ret[1] = INT;
		break ;
		case MQ_TIMEDSEND:
			ret[0] = STRUCT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = STRUCT;
			ret[5] = INT;
		break ;
		case MQ_TIMEDRECEIVE:
			ret[0] = STRUCT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = PTR;
			ret[4] = STRUCT;
			ret[5] = INT;
		break ;
		case MQ_NOTIFY:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case MQ_GETSETATTR:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case KEXEC_LOAD:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = STRUCT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case WAITID:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = PTR;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case ADD_KEY:
			ret[0] = STRING;
			ret[1] = STRING;
			ret[2] = PTR;
			ret[3] = INT;
			ret[4] = STRUCT;
			ret[5] = STRUCT;
		break ;
		case REQUEST_KEY:
			ret[0] = STRING;
			ret[1] = STRING;
			ret[2] = STRING;
			ret[3] = STRUCT;
			ret[4] = STRUCT;
		break ;
		case KEYCTL:
			ret[0] = INT;
			ret[1] = VARGS;
			ret[2] = INT;
		break ;
		case IOPRIO_SET:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case IOPRIO_GET:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case INOTIFY_INIT:
			ret[0] = VOID;
			ret[1] = INT;
		break ;
		case INOTIFY_ADD_WATCH:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case INOTIFY_RM_WATCH:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case MIGRATE_PAGES:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case OPENAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case MKDIRAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case MKNODAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = STRUCT;
			ret[3] = STRUCT;
			ret[4] = INT;
		break ;
		case ARCH_PRCTL:
			ret[0] = INT;
			ret[1] = PTR;
			ret[2] = INT;
		break ;
		case FCHOWNAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = STRUCT;
			ret[3] = STRUCT;
			ret[4] = INT;
			ret[5] = INT;
		break ;
		case FUTIMESAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case UNLINKAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case RENAMEAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = STRING;
			ret[4] = INT;
		break ;
		case LINKAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = STRING;
			ret[4] = INT;
			ret[5] = INT;
		break ;
		case SYMLINKAT:
			ret[0] = STRING;
			ret[1] = INT;
			ret[2] = STRING;
			ret[3] = INT;
		break ;
		case READLINKAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = STRING;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case FCHMODAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = STRUCT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case FACCESSAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case PPOLL:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = PTR;
			ret[4] = INT;
		break ;
		case UNSHARE:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case SET_ROBUST_LIST:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case GET_ROBUST_LIST:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = PTR;
			ret[3] = INT;
		break ;
		case SPLICE:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
			ret[5] = INT;
			ret[6] = INT;
		break ;
		case TEE:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case SYNC_FILE_RANGE:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = STRUCT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case VMSPLICE:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case MOVE_PAGES:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = PTR;
			ret[3] = INT;
			ret[4] = INT;
			ret[5] = INT;
			ret[6] = INT;
		break ;
		case UTIMENSAT:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = STRUCT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case EPOLL_PWAIT:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = PTR;
			ret[5] = INT;
		break ;
		case TIMERFD_CREATE:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case EVENTFD:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case FALLOCATE:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case TIMERFD_SETTIME:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = STRUCT;
			ret[3] = STRUCT;
			ret[4] = INT;
		break ;
		case TIMERFD_GETTIME:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
		break ;
		case ACCEPT4:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = PTR;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case EPOLL_CREATE1:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case DUP3:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case PIPE2:
			ret[0] = PTR;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case INOTIFY_INIT1:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case PREADV:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case PWRITEV:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case PERF_EVENT_OPEN:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
			ret[5] = INT;
		break ;
		case RECVMMSG:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = STRUCT;
			ret[5] = INT;
		break ;
		case PRLIMIT:
			ret[0] = STRUCT;
			ret[1] = INT;
			ret[2] = STRUCT;
			ret[3] = STRUCT;
			ret[4] = INT;
		break ;
		case SYNCFS:
			ret[0] = INT;
			ret[1] = INT;
		break ;
		case SENDMMSG:
			ret[0] = INT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
		break ;
		case SETNS:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
		break ;
		case GETCPU:
			ret[0] = PTR;
			ret[1] = PTR;
			ret[2] = STRUCT;
			ret[3] = INT;
		break ;
		case PROCESS_VM_READV:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = STRUCT;
			ret[4] = INT;
			ret[5] = INT;
			ret[6] = INT;
		break ;
		case PROCESS_VM_WRITEV:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = STRUCT;
			ret[4] = INT;
			ret[5] = INT;
			ret[6] = INT;
		break ;
		case KCMP:
			ret[0] = STRUCT;
			ret[1] = STRUCT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
			ret[5] = INT;
		break ;
		case FINIT_MODULE:
			ret[0] = INT;
			ret[1] = STRING;
			ret[2] = INT;
			ret[3] = INT;
		break ;
		case FADVISE64:
			ret[0] = INT;
			ret[1] = INT;
			ret[2] = INT;
			ret[3] = INT;
			ret[4] = INT;
			ret[5] = INT;
		break ;
	}
	return (ret);
}

t_syscall	*get_syscall(int sys_number)
{
	t_syscall	*sc;

	sc = (t_syscall *)malloc(sizeof(t_syscall));
	switch (sys_number)
	{
		case READ:
			sc->name = ft_strdup("read");
			sc->n_args = 3;
		break ;
		case WRITE:
			sc->name = ft_strdup("write");
			sc->n_args = 3;
		break ;
		case OPEN:
			sc->name = ft_strdup("open");
			sc->n_args = 2;
		break ;
		case CLOSE:
			sc->name = ft_strdup("close");
			sc->n_args = 1;
		break ;
		case STAT:
			sc->name = ft_strdup("stat");
			sc->n_args = 2;
		break ;
		case FSTAT:
			sc->name = ft_strdup("fstat");
			sc->n_args = 2;
		break ;
		case LSTAT:
			sc->name = ft_strdup("lstat");
			sc->n_args = 2;
		break ;
		case POLL:
			sc->name = ft_strdup("poll");
			sc->n_args = 3;
		break ;
		case LSEEK:
			sc->name = ft_strdup("lseek");
			sc->n_args = 3;
		break ;
		case MMAP:
			sc->name = ft_strdup("mmap");
			sc->n_args = 6;
		break ;
		case MPROTECT:
			sc->name = ft_strdup("mprotect");
			sc->n_args = 3;
		break ;
		case MUNMAP:
			sc->name = ft_strdup("munmap");
			sc->n_args = 2;
		break ;
		case BRK:
			sc->name = ft_strdup("brk");
			sc->n_args = 1;
		break ;
		case SIGACTION:
			sc->name = ft_strdup("rt_sigaction");
			sc->n_args = 3;
		break ;
		case SIGPROCMASK:
			sc->name = ft_strdup("rt_sigprocmask");
			sc->n_args = 3;
		break ;
		case SIGRETURN:
			sc->name = ft_strdup("rt_sigreturn");
			sc->n_args = 1;
		break ;
		case IOCTL:
			sc->name = ft_strdup("ioctl");
			sc->n_args = 3;
		break ;
		case READV:
			sc->name = ft_strdup("readv");
			sc->n_args = 3;
		break ;
		case WRITEV:
			sc->name = ft_strdup("writev");
			sc->n_args = 3;
		break ;
		case ACCESS:
			sc->name = ft_strdup("access");
			sc->n_args = 2;
		break ;
		case PIPE:
			sc->name = ft_strdup("pipe");
			sc->n_args = 1;
		break ;
		case SELECT:
			sc->name = ft_strdup("select");
			sc->n_args = 5;
		break ;
		case SCHED_YIELD:
			sc->name = ft_strdup("sched_yield");
			sc->n_args = 1;
		break ;
		case MREMAP:
			sc->name = ft_strdup("mremap");
			sc->n_args = 5;
		break ;
		case MSYNC:
			sc->name = ft_strdup("msync");
			sc->n_args = 3;
		break ;
		case MINCORE:
			sc->name = ft_strdup("mincore");
			sc->n_args = 3;
		break ;
		case MADVISE:
			sc->name = ft_strdup("madvise");
			sc->n_args = 3;
		break ;
		case SHMGET:
			sc->name = ft_strdup("shmget");
			sc->n_args = 3;
		break ;
		case SHMAT:
			sc->name = ft_strdup("shmat");
			sc->n_args = 3;
		break ;
		case SHMCTL:
			sc->name = ft_strdup("shmctl");
			sc->n_args = 3;
		break ;
		case DUP:
			sc->name = ft_strdup("dup");
			sc->n_args = 1;
		break ;
		case DUP2:
			sc->name = ft_strdup("dup2");
			sc->n_args = 2;
		break ;
		case PAUSE:
			sc->name = ft_strdup("pause");
			sc->n_args = 1;
		break ;
		case NANOSLEEP:
			sc->name = ft_strdup("nanosleep");
			sc->n_args = 2;
		break ;
		case GETITIMER:
			sc->name = ft_strdup("getitimer");
			sc->n_args = 2;
		break ;
		case ALARM:
			sc->name = ft_strdup("alarm");
			sc->n_args = 1;
		break ;
		case SETITIMER:
			sc->name = ft_strdup("setitimer");
			sc->n_args = 3;
		break ;
		case GETPID:
			sc->name = ft_strdup("getpid");
			sc->n_args = 1;
		break ;
		case SENDFILE:
			sc->name = ft_strdup("sendfile");
			sc->n_args = 4;
		break ;
		case SOCKET:
			sc->name = ft_strdup("socket");
			sc->n_args = 3;
		break ;
		case CONNECT:
			sc->name = ft_strdup("connect");
			sc->n_args = 3;
		break ;
		case ACCEPT:
			sc->name = ft_strdup("accept");
			sc->n_args = 3;
		break ;
		case SENDTO:
			sc->name = ft_strdup("sendto");
			sc->n_args = 6;
		break ;
		case RECVFROM:
			sc->name = ft_strdup("recvfrom");
			sc->n_args = 6;
		break ;
		case SENDMSG:
			sc->name = ft_strdup("sendmsg");
			sc->n_args = 3;
		break ;
		case RECVMSG:
			sc->name = ft_strdup("recvmsg");
			sc->n_args = 3;
		break ;
		case SHUTDOWN:
			sc->name = ft_strdup("shutdown");
			sc->n_args = 2;
		break ;
		case BIND:
			sc->name = ft_strdup("bind");
			sc->n_args = 3;
		break ;
		case LISTEN:
			sc->name = ft_strdup("listen");
			sc->n_args = 2;
		break ;
		case GETSOCKNAME:
			sc->name = ft_strdup("getsockname");
			sc->n_args = 3;
		break ;
		case GETPEERNAME:
			sc->name = ft_strdup("getpeername");
			sc->n_args = 3;
		break ;
		case SOCKETPAIR:
			sc->name = ft_strdup("socketpair");
			sc->n_args = 4;
		break ;
		case SETSOCKOPT:
			sc->name = ft_strdup("setsockopt");
			sc->n_args = 5;
		break ;
		case GETSOCKOPT:
			sc->name = ft_strdup("getsockopt");
			sc->n_args = 5;
		break ;
		case CLONE:
			sc->name = ft_strdup("clone");
			sc->n_args = 7;
		break ;
		case FORK:
			sc->name = ft_strdup("fork");
			sc->n_args = 1;
		break ;
		case VFORK:
			sc->name = ft_strdup("vfork");
			sc->n_args = 1;
		break ;
		case EXECVE:
			sc->name = ft_strdup("execve");
			sc->n_args = 3;
		break ;
		case EXIT:
			sc->name = ft_strdup("exit");
			sc->n_args = 1;
		break ;
		case WAIT4:
			sc->name = ft_strdup("wait4");
			sc->n_args = 4;
		break ;
		case KILL:
			sc->name = ft_strdup("kill");
			sc->n_args = 2;
		break ;
		case UNAME:
			sc->name = ft_strdup("uname");
			sc->n_args = 1;
		break ;
		case SEMGET:
			sc->name = ft_strdup("semget");
			sc->n_args = 3;
		break ;
		case SEMOP:
			sc->name = ft_strdup("semop");
			sc->n_args = 3;
		break ;
		case SEMCTL:
			sc->name = ft_strdup("semctl");
			sc->n_args = 4;
		break ;
		case SHMDT:
			sc->name = ft_strdup("shmdt");
			sc->n_args = 1;
		break ;
		case MSGGET:
			sc->name = ft_strdup("msgget");
			sc->n_args = 2;
		break ;
		case MSGSND:
			sc->name = ft_strdup("msgsnd");
			sc->n_args = 4;
		break ;
		case MSGRCV:
			sc->name = ft_strdup("msgrcv");
			sc->n_args = 5;
		break ;
		case MSGCTL:
			sc->name = ft_strdup("msgctl");
			sc->n_args = 3;
		break ;
		case FCNTL:
			sc->name = ft_strdup("fcntl");
			sc->n_args = 3;
		break ;
		case FLOCK:
			sc->name = ft_strdup("flock");
			sc->n_args = 2;
		break ;
		case FSYNC:
			sc->name = ft_strdup("fsync");
			sc->n_args = 1;
		break ;
		case FDATASYNC:
			sc->name = ft_strdup("fdatasync");
			sc->n_args = 1;
		break ;
		case TRUNCATE:
			sc->name = ft_strdup("truncate");
			sc->n_args = 2;
		break ;
		case FTRUNCATE:
			sc->name = ft_strdup("ftruncate");
			sc->n_args = 2;
		break ;
		case GETDENTS:
			sc->name = ft_strdup("getdents");
			sc->n_args = 3;
		break ;
		case GETCWD:
			sc->name = ft_strdup("getcwd");
			sc->n_args = 2;
		break ;
		case CHDIR:
			sc->name = ft_strdup("chdir");
			sc->n_args = 1;
		break ;
		case FCHDIR:
			sc->name = ft_strdup("fchdir");
			sc->n_args = 1;
		break ;
		case RENAME:
			sc->name = ft_strdup("rename");
			sc->n_args = 2;
		break ;
		case MKDIR:
			sc->name = ft_strdup("mkdir");
			sc->n_args = 2;
		break ;
		case RMDIR:
			sc->name = ft_strdup("rmdir");
			sc->n_args = 1;
		break ;
		case CREAT:
			sc->name = ft_strdup("creat");
			sc->n_args = 2;
		break ;
		case LINK:
			sc->name = ft_strdup("link");
			sc->n_args = 2;
		break ;
		case UNLINK:
			sc->name = ft_strdup("unlink");
			sc->n_args = 1;
		break ;
		case SYMLINK:
			sc->name = ft_strdup("symlink");
			sc->n_args = 2;
		break ;
		case READLINK:
			sc->name = ft_strdup("readlink");
			sc->n_args = 3;
		break ;
		case CHMOD:
			sc->name = ft_strdup("chmod");
			sc->n_args = 2;
		break ;
		case FCHMOD:
			sc->name = ft_strdup("fchmod");
			sc->n_args = 2;
		break ;
		case CHOWN:
			sc->name = ft_strdup("chown");
			sc->n_args = 3;
		break ;
		case FCHOWN:
			sc->name = ft_strdup("fchown");
			sc->n_args = 3;
		break ;
		case LCHOWN:
			sc->name = ft_strdup("lchown");
			sc->n_args = 3;
		break ;
		case UMASK:
			sc->name = ft_strdup("umask");
			sc->n_args = 1;
		break ;
		case GETTIMEOFDAY:
			sc->name = ft_strdup("gettimeofday");
			sc->n_args = 2;
		break ;
		case GETRLIMIT:
			sc->name = ft_strdup("getrlimit");
			sc->n_args = 2;
		break ;
		case GETRUSAGE:
			sc->name = ft_strdup("getrusage");
			sc->n_args = 2;
		break ;
		case SYSINFO:
			sc->name = ft_strdup("sysinfo");
			sc->n_args = 1;
		break ;
		case TIMES:
			sc->name = ft_strdup("times");
			sc->n_args = 1;
		break ;
		case PTRACE:
			sc->name = ft_strdup("ptrace");
			sc->n_args = 4;
		break ;
		case GETUID:
			sc->name = ft_strdup("getuid");
			sc->n_args = 0;
		break ;
		case SYSLOG:
			sc->name = ft_strdup("syslog");
			sc->n_args = 3;
		break ;
		case GETGID:
			sc->name = ft_strdup("getgid");
			sc->n_args = 0;
		break ;
		case SETUID:
			sc->name = ft_strdup("setuid");
			sc->n_args = 1;
		break ;
		case SETGID:
			sc->name = ft_strdup("setgid");
			sc->n_args = 1;
		break ;
		case GETEUID:
			sc->name = ft_strdup("geteuid");
			sc->n_args = 0;
		break ;
		case GETEGID:
			sc->name = ft_strdup("getegid");
			sc->n_args = 0;
		break ;
		case SETPGID:
			sc->name = ft_strdup("setpgid");
			sc->n_args = 2;
		break ;
		case GETPPID:
			sc->name = ft_strdup("getppid");
			sc->n_args = 1;
		break ;
		case GETPGRP:
			sc->name = ft_strdup("getpgrp");
			sc->n_args = 1;
		break ;
		case SETSID:
			sc->name = ft_strdup("setsid");
			sc->n_args = 1;
		break ;
		case SETREUID:
			sc->name = ft_strdup("setreuid");
			sc->n_args = 2;
		break ;
		case SETREGID:
			sc->name = ft_strdup("setregid");
			sc->n_args = 2;
		break ;
		case GETGROUPS:
			sc->name = ft_strdup("getgroups");
			sc->n_args = 2;
		break ;
		case SETGROUPS:
			sc->name = ft_strdup("setgroups");
			sc->n_args = 2;
		break ;
		case SETRESUID:
			sc->name = ft_strdup("setresuid");
			sc->n_args = 3;
		break ;
		case GETRESUID:
			sc->name = ft_strdup("getresuid");
			sc->n_args = 3;
		break ;
		case SETRESGID:
			sc->name = ft_strdup("setresgid");
			sc->n_args = 3;
		break ;
		case GETRESGID:
			sc->name = ft_strdup("getresgid");
			sc->n_args = 3;
		break ;
		case GETPGID:
			sc->name = ft_strdup("getpgid");
			sc->n_args = 1;
		break ;
		case SETFSUID:
			sc->name = ft_strdup("setfsuid");
			sc->n_args = 1;
		break ;
		case SETFSGID:
			sc->name = ft_strdup("setfsgid");
			sc->n_args = 1;
		break ;
		case GETSID:
			sc->name = ft_strdup("getsid");
			sc->n_args = 1;
		break ;
		case CAPGET:
			sc->name = ft_strdup("capget");
			sc->n_args = 2;
		break ;
		case CAPSET:
			sc->name = ft_strdup("capset");
			sc->n_args = 2;
		break ;
		case SIGPENDING:
			sc->name = ft_strdup("rt_sigpending");
			sc->n_args = 1;
		break ;
		case SIGTIMEDWAIT:
			sc->name = ft_strdup("rt_sigtimedwait");
			sc->n_args = 3;
		break ;
		case RT_SIGQUEUEINFO:
			sc->name = ft_strdup("rt_sigqueueinfo");
			sc->n_args = 3;
		break ;
		case SIGSUSPEND:
			sc->name = ft_strdup("rt_sigsuspend");
			sc->n_args = 1;
		break ;
		case SIGALTSTACK:
			sc->name = ft_strdup("sigaltstack");
			sc->n_args = 2;
		break ;
		case UTIME:
			sc->name = ft_strdup("utime");
			sc->n_args = 2;
		break ;
		case MKNOD:
			sc->name = ft_strdup("mknod");
			sc->n_args = 3;
		break ;
		case USELIB:
			sc->name = ft_strdup("uselib");
			sc->n_args = 1;
		break ;
		case PERSONALITY:
			sc->name = ft_strdup("personality");
			sc->n_args = 1;
		break ;
		case USTAT:
			sc->name = ft_strdup("ustat");
			sc->n_args = 2;
		break ;
		case STATFS:
			sc->name = ft_strdup("statfs");
			sc->n_args = 2;
		break ;
		case FSTATFS:
			sc->name = ft_strdup("fstatfs");
			sc->n_args = 2;
		break ;
		case SYSFS:
			sc->name = ft_strdup("sysfs");
			sc->n_args = 2;
		break ;
		case GETPRIORITY:
			sc->name = ft_strdup("getpriority");
			sc->n_args = 2;
		break ;
		case SETPRIORITY:
			sc->name = ft_strdup("setpriority");
			sc->n_args = 3;
		break ;
		case SCHED_SETPARAM:
			sc->name = ft_strdup("sched_setparam");
			sc->n_args = 2;
		break ;
		case SCHED_GETPARAM:
			sc->name = ft_strdup("sched_getparam");
			sc->n_args = 2;
		break ;
		case SCHED_SETSCHEDULER:
			sc->name = ft_strdup("sched_setscheduler");
			sc->n_args = 3;
		break ;
		case SCHED_GETSCHEDULER:
			sc->name = ft_strdup("sched_getscheduler");
			sc->n_args = 1;
		break ;
		case SCHED_GET_PRIORITY_MAX:
			sc->name = ft_strdup("sched_get_priority_max");
			sc->n_args = 1;
		break ;
		case SCHED_GET_PRIORITY_MIN:
			sc->name = ft_strdup("sched_get_priority_min");
			sc->n_args = 1;
		break ;
		case SCHED_RR_GET_INTERVAL:
			sc->name = ft_strdup("sched_rr_get_interval");
			sc->n_args = 2;
		break ;
		case MLOCK:
			sc->name = ft_strdup("mlock");
			sc->n_args = 2;
		break ;
		case MUNLOCK:
			sc->name = ft_strdup("munlock");
			sc->n_args = 2;
		break ;
		case MLOCKALL:
			sc->name = ft_strdup("mlockall");
			sc->n_args = 1;
		break ;
		case MUNLOCKALL:
			sc->name = ft_strdup("munlockall");
			sc->n_args = 1;
		break ;
		case VHANGUP:
			sc->name = ft_strdup("vhangup");
			sc->n_args = 1;
		break ;
		case MODIFY_LDT:
			sc->name = ft_strdup("modify_ldt");
			sc->n_args = 3;
		break ;
		case PIVOT_ROOT:
			sc->name = ft_strdup("pivot_root");
			sc->n_args = 2;
		break ;
		case _SYSCTL:
			sc->name = ft_strdup("_sysctl");
			sc->n_args = 1;
		break ;
		case PRCTL:
			sc->name = ft_strdup("prctl");
			sc->n_args = 5;
		break ;
		case ARCH_PRCTL:
			sc->name = ft_strdup("arch_prctl");
			sc->n_args = 2;
		break ;
		case ADJTIMEX:
			sc->name = ft_strdup("adjtimex");
			sc->n_args = 1;
		break ;
		case SETRLIMIT:
			sc->name = ft_strdup("setrlimit");
			sc->n_args = 2;
		break ;
		case CHROOT:
			sc->name = ft_strdup("chroot");
			sc->n_args = 1;
		break ;
		case SYNC:
			sc->name = ft_strdup("sync");
			sc->n_args = 1;
		break ;
		case ACCT:
			sc->name = ft_strdup("acct");
			sc->n_args = 1;
		break ;
		case SETTIMEOFDAY:
			sc->name = ft_strdup("settimeofday");
			sc->n_args = 2;
		break ;
		case MOUNT:
			sc->name = ft_strdup("mount");
			sc->n_args = 5;
		break ;
		case UMOUNT2:
			sc->name = ft_strdup("umount2");
			sc->n_args = 2;
		break ;
		case SWAPON:
			sc->name = ft_strdup("swapon");
			sc->n_args = 2;
		break ;
		case SWAPOFF:
			sc->name = ft_strdup("swapoff");
			sc->n_args = 1;
		break ;
		case REBOOT:
			sc->name = ft_strdup("reboot");
			sc->n_args = 4;
		break ;
		case SETHOSTNAME:
			sc->name = ft_strdup("sethostname");
			sc->n_args = 2;
		break ;
		case SETDOMAINNAME:
			sc->name = ft_strdup("setdomainname");
			sc->n_args = 2;
		break ;
		case IOPL:
			sc->name = ft_strdup("iopl");
			sc->n_args = 1;
		break ;
		case IOPERM:
			sc->name = ft_strdup("ioperm");
			sc->n_args = 3;
		break ;
		case INIT_MODULE:
			sc->name = ft_strdup("init_module");
			sc->n_args = 3;
		break ;
		case QUOTACTL:
			sc->name = ft_strdup("quotactl");
			sc->n_args = 4;
		break ;
		case GETTID:
			sc->name = ft_strdup("gettid");
			sc->n_args = 0;
		break ;
		case READAHEAD:
			sc->name = ft_strdup("readahead");
			sc->n_args = 3;
		break ;
		case TKILL:
			sc->name = ft_strdup("tkill");
			sc->n_args = 2;
		break ;
		case TIME:
			sc->name = ft_strdup("time");
			sc->n_args = 1;
		break ;
		case FUTEX:
			sc->name = ft_strdup("futex");
			sc->n_args = 6;
		break ;
		case SCHED_SETAFFINITY:
			sc->name = ft_strdup("sched_setaffinity");
			sc->n_args = 3;
		break ;
		case SCHED_GETAFFINITY:
			sc->name = ft_strdup("sched_getaffinity");
			sc->n_args = 3;
		break ;
		case SET_THREAD_AREA:
			sc->name = ft_strdup("set_thread_area");
			sc->n_args = 1;
		break ;
		case IO_SETUP:
			sc->name = ft_strdup("io_setup");
			sc->n_args = 2;
		break ;
		case IO_DESTROY:
			sc->name = ft_strdup("io_destroy");
			sc->n_args = 1;
		break ;
		case RESTART_SYSCALL:
			sc->name = ft_strdup("restart_syscall");
			sc->n_args = 0;
		break ;
		case IO_GETEVENTS:
			sc->name = ft_strdup("io_getevents");
			sc->n_args = 5;
		break ;
		case IO_SUBMIT:
			sc->name = ft_strdup("io_submit");
			sc->n_args = 3;
		break ;
		case IO_CANCEL:
			sc->name = ft_strdup("io_cancel");
			sc->n_args = 3;
		break ;
		case GET_THREAD_AREA:
			sc->name = ft_strdup("get_thread_area");
			sc->n_args = 1;
		break ;
		case LOOKUP_DCOOKIE:
			sc->name = ft_strdup("lookup_dcookie");
			sc->n_args = 3;
		break ;
		case EPOLL_CREATE:
			sc->name = ft_strdup("epoll_create");
			sc->n_args = 1;
		break ;
		case REMAP_FILE_PAGES:
			sc->name = ft_strdup("remap_file_pages");
			sc->n_args = 5;
		break ;
		case GETDENTS64:
			sc->name = ft_strdup("getdents64");
			sc->n_args = 3;
		break ;
		case SET_TID_ADDRESS:
			sc->name = ft_strdup("set_tid_address");
			sc->n_args = 1;
		break ;
		case SEMTIMEDOP:
			sc->name = ft_strdup("semtimedop");
			sc->n_args = 4;
		break ;
		case FADVISE64:
			sc->name = ft_strdup("fadvise64");
			sc->n_args = 4;
		break ;
		case TIMER_CREATE:
			sc->name = ft_strdup("timer_create");
			sc->n_args = 3;
		break ;
		case TIMER_SETTIME:
			sc->name = ft_strdup("timer_settime");
			sc->n_args = 4;
		break ;
		case TIMER_GETTIME:
			sc->name = ft_strdup("timer_gettime");
			sc->n_args = 2;
		break ;
		case TIMER_GETOVERRUN:
			sc->name = ft_strdup("timer_getoverrun");
			sc->n_args = 1;
		break ;
		case TIMER_DELETE:
			sc->name = ft_strdup("timer_delete");
			sc->n_args = 1;
		break ;
		case CLOCK_SETTIME:
			sc->name = ft_strdup("clock_settime");
			sc->n_args = 2;
		break ;
		case CLOCK_GETTIME:
			sc->name = ft_strdup("clock_gettime");
			sc->n_args = 2;
		break ;
		case CLOCK_GETRES:
			sc->name = ft_strdup("clock_getres");
			sc->n_args = 2;
		break ;
		case CLOCK_NANOSLEEP:
			sc->name = ft_strdup("clock_nanosleep");
			sc->n_args = 4;
		break ;
		case EXIT_GROUP:
			sc->name = ft_strdup("exit_group");
			sc->n_args = 1;
		break ;
		case EPOLL_WAIT:
			sc->name = ft_strdup("epoll_wait");
			sc->n_args = 4;
		break ;
		case EPOLL_CTL:
			sc->name = ft_strdup("epoll_ctl");
			sc->n_args = 4;
		break ;
		case TGKILL:
			sc->name = ft_strdup("tgkill");
			sc->n_args = 3;
		break ;
		case UTIMES:
			sc->name = ft_strdup("utimes");
			sc->n_args = 2;
		break ;
		case MBIND:
			sc->name = ft_strdup("mbind");
			sc->n_args = 6;
		break ;
		case GET_MEMPOLICY:
			sc->name = ft_strdup("get_mempolicy");
			sc->n_args = 5;
		break ;
		case MQ_OPEN:
			sc->name = ft_strdup("mq_open");
			sc->n_args = 2;
		break ;
		case MQ_UNLINK:
			sc->name = ft_strdup("mq_unlink");
			sc->n_args = 1;
		break ;
		case MQ_TIMEDSEND:
			sc->name = ft_strdup("mq_timedsend");
			sc->n_args = 5;
		break ;
		case MQ_TIMEDRECEIVE:
			sc->name = ft_strdup("mq_timedreceive");
			sc->n_args = 5;
		break ;
		case MQ_NOTIFY:
			sc->name = ft_strdup("mq_notify");
			sc->n_args = 2;
		break ;
		case MQ_GETSETATTR:
			sc->name = ft_strdup("mq_getsetattr");
			sc->n_args = 3;
		break ;
		case KEXEC_LOAD:
			sc->name = ft_strdup("kexec_load");
			sc->n_args = 4;
		break ;
		case WAITID:
			sc->name = ft_strdup("waitid");
			sc->n_args = 4;
		break ;
		case ADD_KEY:
			sc->name = ft_strdup("add_key");
			sc->n_args = 5;
		break ;
		case REQUEST_KEY:
			sc->name = ft_strdup("request_key");
			sc->n_args = 4;
		break ;
		case KEYCTL:
			sc->name = ft_strdup("keyctl");
			sc->n_args = 2;
		break ;
		case IOPRIO_SET:
			sc->name = ft_strdup("ioprio_set");
			sc->n_args = 3;
		break ;
		case IOPRIO_GET:
			sc->name = ft_strdup("ioprio_get");
			sc->n_args = 2;
		break ;
		case INOTIFY_INIT:
			sc->name = ft_strdup("inotify_init");
			sc->n_args = 1;
		break ;
		case INOTIFY_ADD_WATCH:
			sc->name = ft_strdup("inotify_add_watch");
			sc->n_args = 3;
		break ;
		case INOTIFY_RM_WATCH:
			sc->name = ft_strdup("inotify_rm_watch");
			sc->n_args = 2;
		break ;
		case MIGRATE_PAGES:
			sc->name = ft_strdup("migrate_pages");
			sc->n_args = 4;
		break ;
		case OPENAT:
			sc->name = ft_strdup("openat");
			sc->n_args = 3;
		break ;
		case MKDIRAT:
			sc->name = ft_strdup("mkdirat");
			sc->n_args = 3;
		break ;
		case MKNODAT:
			sc->name = ft_strdup("mknodat");
			sc->n_args = 4;
		break ;
		case FCHOWNAT:
			sc->name = ft_strdup("fchownat");
			sc->n_args = 5;
		break ;
		case FUTIMESAT:
			sc->name = ft_strdup("futimesat");
			sc->n_args = 3;
		break ;
		case UNLINKAT:
			sc->name = ft_strdup("unlinkat");
			sc->n_args = 3;
		break ;
		case RENAMEAT:
			sc->name = ft_strdup("renameat");
			sc->n_args = 4;
		break ;
		case LINKAT:
			sc->name = ft_strdup("linkat");
			sc->n_args = 5;
		break ;
		case SYMLINKAT:
			sc->name = ft_strdup("symlinkat");
			sc->n_args = 3;
		break ;
		case READLINKAT:
			sc->name = ft_strdup("readlinkat");
			sc->n_args = 4;
		break ;
		case FCHMODAT:
			sc->name = ft_strdup("fchmodat");
			sc->n_args = 4;
		break ;
		case FACCESSAT:
			sc->name = ft_strdup("faccessat");
			sc->n_args = 4;
		break ;
		case PSELECT6:
			sc->name = ft_strdup("pselect6");
			sc->n_args = 3;
		break ;
		case PPOLL:
			sc->name = ft_strdup("ppoll");
			sc->n_args = 4;
		break ;
		case UNSHARE:
			sc->name = ft_strdup("unshare");
			sc->n_args = 1;
		break ;
		case SET_ROBUST_LIST:
			sc->name = ft_strdup("set_robust_list");
			sc->n_args = 2;
		break ;
		case GET_ROBUST_LIST:
			sc->name = ft_strdup("get_robust_list");
			sc->n_args = 3;
		break ;
		case SPLICE:
			sc->name = ft_strdup("splice");
			sc->n_args = 6;
		break ;
		case TEE:
			sc->name = ft_strdup("tee");
			sc->n_args = 4;
		break ;
		case SYNC_FILE_RANGE:
			sc->name = ft_strdup("sync_file_range");
			sc->n_args = 4;
		break ;
		case VMSPLICE:
			sc->name = ft_strdup("vmsplice");
			sc->n_args = 4;
		break ;
		case MOVE_PAGES:
			sc->name = ft_strdup("move_pages");
			sc->n_args = 6;
		break ;
		case UTIMENSAT:
			sc->name = ft_strdup("utimensat");
			sc->n_args = 4;
		break ;
		case EPOLL_PWAIT:
			sc->name = ft_strdup("epoll_pwait");
			sc->n_args = 5;
		break ;
		case SIGNALFD:
			sc->name = ft_strdup("signalfd");
			sc->n_args = 3;
		break ;
		case TIMERFD_CREATE:
			sc->name = ft_strdup("timerfd_create");
			sc->n_args = 2;
		break ;
		case EVENTFD:
			sc->name = ft_strdup("eventfd");
			sc->n_args = 2;
		break ;
		case FALLOCATE:
			sc->name = ft_strdup("fallocate");
			sc->n_args = 4;
		break ;
		case TIMERFD_SETTIME:
			sc->name = ft_strdup("timerfd_settime");
			sc->n_args = 4;
		break ;
		case TIMERFD_GETTIME:
			sc->name = ft_strdup("timerfd_gettime");
			sc->n_args = 2;
		break ;
		case ACCEPT4:
			sc->name = ft_strdup("accept4");
			sc->n_args = 4;
		break ;
		case SIGNALFD4:
			sc->name = ft_strdup("signalfd4");
			sc->n_args = 9;
		break ;
		case EVENTFD2:
			sc->name = ft_strdup("eventfd2");
			sc->n_args = 14;
		break ;
		case EPOLL_CREATE1:
			sc->name = ft_strdup("epoll_create1");
			sc->n_args = 1;
		break ;
		case DUP3:
			sc->name = ft_strdup("dup3");
			sc->n_args = 3;
		break ;
		case PIPE2:
			sc->name = ft_strdup("pipe2");
			sc->n_args = 2;
		break ;
		case INOTIFY_INIT1:
			sc->name = ft_strdup("inotify_init1");
			sc->n_args = 1;
		break ;
		case PREADV:
			sc->name = ft_strdup("preadv");
			sc->n_args = 4;
		break ;
		case PWRITEV:
			sc->name = ft_strdup("pwritev");
			sc->n_args = 4;
		break ;
		case PERF_EVENT_OPEN:
			sc->name = ft_strdup("perf_event_open");
			sc->n_args = 5;
		break ;
		case RECVMMSG:
			sc->name = ft_strdup("recvmmsg");
			sc->n_args = 5;
		break ;
		case PRLIMIT:
			sc->name = ft_strdup("prlimit");
			sc->n_args = 4;
		break ;
		case SYNCFS:
			sc->name = ft_strdup("syncfs");
			sc->n_args = 1;
		break ;
		case SENDMMSG:
			sc->name = ft_strdup("sendmmsg");
			sc->n_args = 4;
		break ;
		case SETNS:
			sc->name = ft_strdup("setns");
			sc->n_args = 2;
		break ;
		case GETCPU:
			sc->name = ft_strdup("getcpu");
			sc->n_args = 3;
		break ;
		case PROCESS_VM_READV:
			sc->name = ft_strdup("process_vm_readv");
			sc->n_args = 6;
		break ;
		case PROCESS_VM_WRITEV:
			sc->name = ft_strdup("process_vm_writev");
			sc->n_args = 6;
		break ;
		case KCMP:
			sc->name = ft_strdup("kcmp");
			sc->n_args = 5;
		break ;
		case FINIT_MODULE:
			sc->name = ft_strdup("finit_module");
			sc->n_args = 3;
		break ;
		default:
			sc->name = ft_strdup("unknown syscall");
			sc->n_args = 1;
	}
	sc->args = init_args(sys_number, sc->n_args + 1);
	return (sc);
}

t_syscall	**init_syscall(void)
{
	int		i;
	t_syscall	**tab;

	i = 0;
	tab = (t_syscall **)malloc(sizeof(t_syscall *) * 315);
	while (i < 314)
	{
		tab[i] = get_syscall(i);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
