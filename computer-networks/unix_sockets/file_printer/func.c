#include <stdio.h>
int main()
{
	return 0;
}








/*struct sockaddr_un {
               sa_family_t sun_family;               /* AF_UNIX 
               char        sun_path[108];            /* pathname 
           };
****msghdr
void         *msg_name        optional address
socklen_t     msg_namelen     size of address
struct iovec *msg_iov         scatter/gather array
int           msg_iovlen      members in msg_iov
void         *msg_control     ancillary data, see below
socklen_t     msg_controllen  ancillary data buffer len
int           msg_flags       flags on received message

The <sys/socket.h> header defines the *****cmsghdr structure that includes at least the following members:

socklen_t     cmsg_len        data byte count, including the cmsghdr
int           cmsg_level      originating protocol
int           cmsg_type       protocol-specific type

struct iovec {
               void  *iov_base;    /* Starting address 
               size_t iov_len;     /* Number of bytes to transfer 
           };


       CMSG_FIRSTHDR() returns a pointer to the first cmsghdr in the
       ancillary data buffer associated with the passed msghdr.

       CMSG_NXTHDR() returns the next valid cmsghdr after the passed
       cmsghdr.  It returns NULL when there isn't enough space left in the
       buffer.

       CMSG_ALIGN(), given a length, returns it including the required
       alignment.  This is a constant expression.

       CMSG_SPACE() returns the number of bytes an ancillary element with
       payload of the passed data length occupies.  This is a constant
       expression.

       CMSG_DATA() returns a pointer to the data portion of a cmsghdr.

       CMSG_LEN() returns the value to store in the cmsg_len member of the
       cmsghdr structure, taking into account any necessary alignment.  It
       takes the data length as an argument.  This is a constant expression.
*/