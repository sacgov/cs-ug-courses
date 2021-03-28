struct bufwrap {
	char buffer[1024];
	unsigned int size;
};

struct file_args_r {
	char filename[128];
	unsigned int offset;
	unsigned int size;
};

struct file_args_w {
	char filename[128];
	unsigned int offset;
	char buffer[1024];
	unsigned int size;
};

program nfs_rpc {
	version nfs {
		int nfs_write(file_args_w)=1;
		bufwrap nfs_read(file_args_r)=2;
	}=1;
} = 0x2fffffff;
