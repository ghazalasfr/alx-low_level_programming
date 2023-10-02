#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

#define ERROR_EXIT(message) \
    do { \
        fprintf(stderr, "%s\n", message); \
        exit(98); \
    } while (0)

#define PRINT_FIELD(label, format, value) \
    printf(label ": " format "\n", value)

void print_elf_header_info(Elf64_Ehdr *header) {
    PRINT_FIELD("Magic", "%02x %02x %02x", header->e_ident[0], header->e_ident[1], header->e_ident[2]);

    char *class_str = "Invalid";
    if (header->e_ident[EI_CLASS] == ELFCLASS32) class_str = "ELF32";
    else if (header->e_ident[EI_CLASS] == ELFCLASS64) class_str = "ELF64";
    PRINT_FIELD("Class", "%s", class_str);

    char *data_str = "Invalid";
    if (header->e_ident[EI_DATA] == ELFDATA2LSB) data_str = "2's complement, little-endian";
    else if (header->e_ident[EI_DATA] == ELFDATA2MSB) data_str = "2's complement, big-endian";
    PRINT_FIELD("Data", "%s", data_str);

    PRINT_FIELD("Version", "%d (current)", header->e_ident[EI_VERSION]);

    char *osabi_str = "Unknown";
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: osabi_str = "UNIX - System V"; break;
        case ELFOSABI_HPUX: osabi_str = "UNIX - HP-UX"; break;
        case ELFOSABI_NETBSD: osabi_str = "UNIX - NetBSD"; break;
        case ELFOSABI_LINUX: osabi_str = "UNIX - Linux"; break;
        case ELFOSABI_SOLARIS: osabi_str = "UNIX - Solaris"; break;
        case ELFOSABI_AIX: osabi_str = "UNIX - AIX"; break;
        case ELFOSABI_IRIX: osabi_str = "UNIX - IRIX"; break;
        case ELFOSABI_FREEBSD: osabi_str = "UNIX - FreeBSD"; break;
        case ELFOSABI_TRU64: osabi_str = "UNIX - TRU64"; break;
        case ELFOSABI_MODESTO: osabi_str = "Novell - Modesto"; break;
        case ELFOSABI_OPENBSD: osabi_str = "UNIX - OpenBSD"; break;
        case ELFOSABI_ARM_AEABI: osabi_str = "ARM - EABI"; break;
        case ELFOSABI_ARM: osabi_str = "ARM - "; break;
        case ELFOSABI_STANDALONE: osabi_str = "Standalone App"; break;
    }
    PRINT_FIELD("OS/ABI", "%s", osabi_str);

    PRINT_FIELD("ABI Version", "%d", header->e_ident[EI_ABIVERSION]);

    char *type_str = "Unknown";
    switch (header->e_type) {
        case ET_NONE: type_str = "No file type"; break;
        case ET_REL: type_str = "Relocatable file"; break;
        case ET_EXEC: type_str = "Executable file"; break;
        case ET_DYN: type_str = "Shared object file"; break;
        case ET_CORE: type_str = "Core file"; break;
        case ET_LOOS: type_str = "Operating system-specific"; break;
        case ET_HIOS: type_str = "Operating system-specific"; break;
        case ET_LOPROC: type_str = "Processor-specific"; break;
        case ET_HIPROC: type_str = "Processor-specific"; break;
    }
    PRINT_FIELD("Type", "%s", type_str);

    PRINT_FIELD("Entry point address", "0x%lx", header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        ERROR_EXIT("Usage: elf_header elf_filename");
    }

    const char *filename = argv[1];

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        ERROR_EXIT("Failed to open file");
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
    if (bytes_read == -1) {
        perror("read");
        ERROR_EXIT("Failed to read file");
    }

    if (bytes_read != sizeof(Elf64_Ehdr) || memcmp(header.e_ident, ELFMAG, SELFMAG) != 0) {
        ERROR_EXIT("Not an ELF file");
    }

    print_elf_header_info(&header);

    close(fd);

    return 0;
}

