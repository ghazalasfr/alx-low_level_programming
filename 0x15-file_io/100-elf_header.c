#define _ELF_HEADER
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
/**
 * printclass - prints the class from an elf header
 *
 * @head: header information
 *
 * Return: void
 */
void printclass(char *head)
{
	 printf("  %-40s", "Class:");
	 switch (head[4]) {
		 case 2:
			 printf("ELF64\n");
			 break;
		 case 1:
			 printf("ELF32\n");
			 break;
		 default:
			 printf("<invalid class: %02hx>", head[4]);
	 }
}

/**
 * printdata - prints the information about data organization
 * from the elf header
 *
 * @head: header information
 *
 * Return: void
 */
void printdata(char *head)
{
	printf("  %-40s", "Data:");
	switch (head[5]) {
		case 1:
			printf("2's complement, little endian\n");
			break;
		case 2:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<invalid data: %02hx>", head[5]);
	}
}

/**
 * printversion - prints version info from elf header
 *
 * @head: header information
 *
 * Return: void
 */
void printversion(char *head)
{
	printf("  %-40s", "Version:");
	if (head[6] <= EV_CURRENT)
	{
		printf("%d", head[6]);
		if (head[6] == EV_CURRENT)
			printf(" (current)\n");
		else
			printf("\n");
	}
	else
	{
		printf("49 <unknown %%lx>");
	}
}

/**
 * printabi - prints abi version from header information
 *
 * @head: header information
 *
 * Return: void
 */
void printabi(char *head)
{
	printf("  %-40s", "OS/ABI:");
	switch (head[7])
	{
		case 0:
			printf("UNIX - System V\n");
			break;
		case 1:
			printf("UNIX - HP-UX\n");
			break;
		case 2:
			printf("UNIX - NetBSD\n");
			break;
		case 3:
			printf("UNIX - Linux\n");
			break;
		case 4:
			printf("UNIX - GNU Hurd\n");
			break;
		case 6:
			printf("UNIX - Solaris\n");
			break;
		case 7:
			printf("UNIX - AIX\n");
			break;
		case 8:
			printf("UNIX - IRIX\n");
			break;
		case 9:
			printf("UNIX - FreeBSD\n");
			break;
		case 10:
			printf("UNIX - Tru64\n");
			break;
		case 11:
			printf("UNIX - Novell Modesto\n");
			break;
		case 12:
			printf("UNIX - OpenBSD\n");
			break;
		case 13:
			printf("UNIX - Open VMS\n");
			break;
		case 14:
			printf("UNIX - NonStop Kernel\n");
			break;
		case 15:
			printf("UNIX - AROS\n");
			break;
		case 16:
			printf("UNIX - Fenix OS\n");
			break;
		case 17:
			printf("UNIX - CloudABI\n");
			break;
		default:
			printf("<unknown: %02x>\n", head[7]);
			break;
	}
	printf("  %-40s%d\n", "ABI Version:", head[8]);
}

/**
 * printabiversion - prints the ABI version
 * from the elf header
 *
 * @head: header information
 *
 * Return: void
 */
void printabiversion(char *head)
{
        printf("  %-40s", "ABI Version:");
        switch (head[8]) {
                case 0:
                        printf("0\n");
                        break;
                case 1:
                        printf("1\n");
                        break;
                default:
                        printf("<not specieifed: %02hx>", head[5]);
        }
}


/**
 * printtype - prints elf filetype from header info
 *
 * @head: header information
 *
 * Return: void
 */
void printtype(char *head)
{
	int index;

	if (head[5] == 1)
		index = 16;
	else
		index = 17;
	printf("  %-40s", "Type:");
	case (head[index])
	{
		case 1:
			printf("REL (Relocatable file)\n");
			break;
		case 2:
			printf("EXEC (Executable file)\n");
			break;
		case 3:
			printf("DYN (Shared object file)\n");
			break;
		case 4:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown>: %02x%02x\n", head[16], head[17]);
}

/**
 * printentry - prints entry address of executable from header
 *
 * @head: header information
 *
 * Return: void
 */
void printentry(char *head)
{
	int i, end;

	printf("  %-40s0x", "Entry point address:");
	if (head[4] == 2)
		end = 0x1f;
	else
		end = 0x1b;
	if (head[5] == 1)
	{
		i = end;
		while (head[i] == 0 && i > 0x18)
			i--;
		printf("%x", head[i--]);
		while (i >= 0x18)
			printf("%02x", (unsigned char) head[i--]);
		printf("\n");
	}
	else
	{
		i = 0x18;
		while (head[i] == 0)
			i++;
		printf("%x", head[i++]);
		while (i <= end)
			printf("%02x", (unsigned char) head[i++]);
		printf("\n");
	}
}

/**
 * main - parses an elf header file
 *
 * @ac: number of args
 * @av: arugment strings
 *
 * Return: 0 on success
 * 1 on incorrect arg number
 * 2 on file open failure
 * 3 on read failure
 * 4 on failure to read enough bytes for a 32 bit file
 * 98 if elf magic is not matched
 */
int main(int ac, char *av[])
{
	int ifile, i;
	char head[32];

	if (ac != 2)
		return (1);
	ifile = open(av[1], O_RDONLY);
	if (ifile == -1)
		return (1);
	i = read(ifile, head, 32);
	if (i == -1)
		return (1);
	if (i < 28)
		return (1);
	if (head[0] != 0x7f || head[1] != 'E' || head[2] != 'L' || head[3] != 'F')
	{
		dprintf(STDERR_FILENO,
			"readelf: Error: hellofile: Failed to read file header\n");
		return (98);
	}
	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", (unsigned int) head[i]);
	printf("\n");
	printclass(head);
	printdata(head);
	printversion(head);
	printabi(head);
	printabiversion(head);
	printtype(head);
	printentry(head);
	return (0);
}
