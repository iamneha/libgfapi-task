#include <glusterfs/api/glfs.h>

int main () {
    glfs_t *fs = NULL;
    glfs_fd_t *fd = NULL;
    char *host = "192.168.0.106";
    int port = 24007;
	char *filename = "example_file.txt";

    // Create a new 'virtual mount' object for testvol
	fs = glfs_new ("testvol");

    // Set gluster volume server
	glfs_set_volfile_server (fs, "tcp", host, port);
	glfs_init (fs);

    // Create a file
	fd = glfs_creat (fs, filename, O_WRONLY, 644);

    glfs_write (fd, "libgfapi C APIs\n", 16, 0);  //Write
	glfs_close (fd);
	return 0;
}
