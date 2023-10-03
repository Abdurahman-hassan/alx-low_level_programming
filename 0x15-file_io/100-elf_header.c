#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

/**
 * displayMagicNumbers - checks and prints magic numbers from ELF header
 * @header: pointer to the ELF header structure
 * @fileName: name of the ELF file
 * @fileDesc: file descriptor of the opened ELF file
 */
void displayMagicNumbers(Elf64_Ehdr *header, char *fileName, int fileDesc)
{
	size_t index = 0;
	unsigned char *magic = header->e_ident;

	if (magic[EI_MAG0] == ELFMAG0 &&
			magic[EI_MAG1] == ELFMAG1 &&
			magic[EI_MAG2] == ELFMAG2 &&
			magic[EI_MAG3] == ELFMAG3)
	{
		printf("Magic:  ");
		while (index < EI_NIDENT)
			printf(" %02x", header->e_ident[index++]);
		printf("\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", fileName);
		if (close(fileDesc))
			dprintf(STDERR_FILENO, "Problem closing fd %d", fileDesc);
		exit(98);
	}
}

/**
 * displayFileClass - prints the class of the ELF file
 * @header: pointer to the ELF header structure
 */
void displayFileClass(Elf64_Ehdr *header)
{
	printf("%-35s", "Class:");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("INVALID\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
	}
}

/**
 * displayDataFormat - prints the data format of the ELF file
 * @header: pointer to the ELF header structure
 */
void displayDataFormat(Elf64_Ehdr *header)
{
	printf("%-35s", "Data:");
	switch (header->e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("Unknown data format\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little-endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement big-endian\n");
			break;
	}
}

/**
 * displayFileVersion - prints the version of the ELF file
 * @header: pointer to the ELF header structure
 */
void displayFileVersion(Elf64_Ehdr *header)
{
	printf("%-35s", "Version:");
	switch (header->e_ident[EI_VERSION])
	{
		case EV_NONE:
			printf("%d (invalid)\n", EV_NONE);
			break;
		case EV_CURRENT:
			printf("%d (current)\n", EV_CURRENT);
			break;
	}
}

/**
 * displayABI - prints the Application Binary Interface (ABI) of the ELF file
 * @header: pointer to the ELF header structure
 */
void displayABI(Elf64_Ehdr *header)
{
	printf("%-35s", "OS/ABI:");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
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
			printf("Stand-alone (embedded)\n");
			break;
		default:
			printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
	}
}

/**
 * displayABIVersion - prints the ABI version of the ELF file
 * @header: pointer to the ELF header structure
 */
void displayABIVersion(Elf64_Ehdr *header)
{
	printf("%-35s%d\n", "ABI Version:", header->e_ident[EI_ABIVERSION]);

}

/**
 * displayFileType - prints the type of the ELF file
 * @header: pointer to the ELF header structure
 */
void displayFileType(Elf64_Ehdr *header)
{
	printf("%-35s", "Type:");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
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
	}
}

/**
 * displayEntryPoint - prints the entry point address of the ELF file
 * @header: pointer to the ELF header structure
 */
void displayEntryPoint(Elf64_Ehdr *header)
{
	printf("%-35s0x%lx\n", "Entry point address:",
			(unsigned long) header->e_entry);

}

/**
 * main - reads and displays various information from the ELF file header
 * @argCount: number of command-line arguments
 * @argValues: array containing command-line arguments
 * Return: EXIT_SUCCESS if successful, otherwise 98 on error
 */
int main(int argCount, char *argValues[])
{
	int fileDesc;
	ssize_t bytesRead;
	Elf64_Ehdr *elfHeader;

	if (argCount != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <elf_file>\n", argValues[0]);
		exit(98);
	}
	fileDesc = open(argValues[1], O_RDONLY);
	if (fileDesc == -1)
	{
		dprintf(STDERR_FILENO, "Error: could not open %s\n", argValues[1]);
		exit(98);
	}
	elfHeader = malloc(sizeof(Elf64_Ehdr));
	if (elfHeader == NULL)
	{
		dprintf(STDERR_FILENO, "Error: out of memory\n");
		close(fileDesc);
		exit(98);
	}
	bytesRead = read(fileDesc, elfHeader, sizeof(Elf64_Ehdr));
	if (bytesRead == -1)
	{
		free(elfHeader);
		dprintf(STDERR_FILENO, "Error: could not read %s\n", argValues[1]);
		close(fileDesc);
		exit(98);
	}
	if (close(fileDesc))
		dprintf(STDERR_FILENO, "Problem closing fd %d", fileDesc);
	displayMagicNumbers(elfHeader, argValues[1], fileDesc);
	displayFileClass(elfHeader);
	displayDataFormat(elfHeader);
	displayFileVersion(elfHeader);
	displayABI(elfHeader);
	displayABIVersion(elfHeader);
	displayFileType(elfHeader);
	displayEntryPoint(elfHeader);
	free(elfHeader);
	exit(EXIT_SUCCESS);
}
