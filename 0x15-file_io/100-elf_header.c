#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void elf_validate(unsigned char *e_ident);
void elf_print_magic_numbers(unsigned char *e_ident);
void elf_print_header_class(unsigned char *e_ident);
void elf_print_data_format(unsigned char *e_ident);
void elf_print_header_version(unsigned char *e_ident);
void elf_print_abi_version(unsigned char *e_ident);
void elf_print_os_abi(unsigned char *e_ident);
void elf_print_header_type(unsigned int e_type, unsigned char *e_ident);
void elf_print_entry_point(unsigned long int e_entry, unsigned char *e_ident);
void elf_close_file(int elf);

/**
 * elf_validate - Validates whether the given file
 * header is consistent with the ELF format.
 * @e_ident: A pointer to an array
 * containing the ELF magic numbers.
 */
void elf_validate(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
				e_ident[index] != 'E' &&
				e_ident[index] != 'L' &&
				e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * elf_print_magic_numbers - Prints the
 * magic numbers found in the ELF header.
 * @e_ident: A pointer to an array
 * containing the ELF magic numbers.
 */
void elf_print_magic_numbers(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * elf_print_header_class - Displays the class
 * (32-bit or 64-bit) of the ELF header.
 * @e_ident: A pointer to an array containing
 * the ELF class.
 */
void elf_print_header_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * elf_print_data_format - Prints the data
 * format (endianess) of the ELF header.
 * @e_ident: A pointer to an array
 * containing the ELF data format.
 */
void elf_print_data_format(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * elf_print_header_version - Displays
 * the version of the ELF header.
 * @e_ident: A pointer to an array
 * containing the ELF version.
 */
void elf_print_header_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * elf_print_os_abi - Prints the OS/ABI
 * (Operating System / Application Binary Interface)
 * information from the ELF header.
 * @e_ident: A pointer to an array
 * containing the ELF OS/ABI details.
 */
void elf_print_os_abi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * elf_print_abi_version - Displays
 * the ABI version of the ELF header.
 * @e_ident: A pointer to an array
 * containing the ELF ABI version.
 */
void elf_print_abi_version(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * elf_print_header_type - Prints the type
 * (e.g., executable, shared, etc.)
 * of the ELF file based on its header.
 * @e_type: The ELF type identifier.
 * @e_ident: A pointer to an array
 * containing the ELF class.
 */
void elf_print_header_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * elf_print_entry_point - Displays
 * the entry point address from the ELF header,
 * where the system starts executing the binary.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing
 * the ELF class.
 */
void elf_print_entry_point(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * elf_close_file - Closes the given ELF file
 * and handles potential errors during the process.
 * @elf: The file descriptor of the ELF file.
 */
void elf_close_file(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		elf_close_file(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		elf_close_file(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	elf_validate(header->e_ident);
	printf("ELF Header:\n");
	elf_print_magic_numbers(header->e_ident);
	elf_print_header_class(header->e_ident);
	elf_print_data_format(header->e_ident);
	elf_print_header_version(header->e_ident);
	elf_print_os_abi(header->e_ident);
	elf_print_abi_version(header->e_ident);
	elf_print_header_type(header->e_type, header->e_ident);
	elf_print_entry_point(header->e_entry, header->e_ident);

	free(header);
	elf_close_file(o);
	return (0);
}
