#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

void print_error(const char* message) {
    fprintf(stderr, "%s\n", message);
    exit(98);
}

void print_elf_header_info(Elf64_Ehdr *header) {
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class:                              %s\n",
           header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
           (header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid"));

    printf("Data:                               %s\n",
           header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little-endian" :
           (header->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big-endian" : "Invalid"));

    printf("Version:                            %d (current)\n", header->e_ident[EI_VERSION]);

    printf("OS/ABI:                             %s\n",
           header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
           (header->e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
           (header->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
           (header->e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
           (header->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
           (header->e_ident[EI_OSABI] == ELFOSABI_AIX ? "UNIX - AIX" :
           (header->e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
           (header->e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
           (header->e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "UNIX - TRU64" :
           (header->e_ident[EI_OSABI] == ELFOSABI_MODESTO ? "Novell - Modesto" :
           (header->e_ident[EI_OSABI] == ELFOSABI_OPENBSD ? "UNIX - OpenBSD" :
           (header->e_ident[EI_OSABI] == ELFOSABI_ARM_AEABI ? "ARM - EABI" :
           (header->e_ident[EI_OSABI] == ELFOSABI_ARM ? "ARM - " :
           (header->e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone App" : "Unknown"))))))))))));

    printf("ABI Version:                        %d\n", header->e_ident[EI_ABIVERSION]);

    printf("Type:                               %s\n",
           header->e_type == ET_NONE ? "No file type" :
           (header->e_type == ET_REL ? "Relocatable file" :
           (header->e_type == ET_EXEC ? "Executable file" :
           (header->e_type == ET_DYN ? "Shared object file" :
           (header->e_type == ET_CORE ? "Core file" :
           (header->e_type == ET_LOOS ? "Operating system-specific" :
           (header->e_type == ET_HIOS ? "Operating system-specific" :
           (header->e_type == ET_LOPROC ? "Processor-specific" :
           (header->e_type == ET_HIPROC ? "Processor-specific" : "Unknown"))))))));

    printf("Entry point address:                0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    const char *filename = argv[1];

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        print_error("Failed to open file");
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
    if (bytes_read == -1) {
        perror("read");
        print_error("Failed to read file");
    }

    if (bytes_read != sizeof(Elf64_Ehdr) || memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        print_error("Not an ELF file");
    }

    print_elf_header_info(&header);

    close(fd);

    return 0;
}

