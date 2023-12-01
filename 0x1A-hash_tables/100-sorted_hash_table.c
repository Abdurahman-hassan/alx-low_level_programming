#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Description:
 * This function creates a sorted hash table.
 *
 * Return: A pointer to the newly created sorted hash table, or NULL
 * if something went wrong.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *ht = (shash_table_t *)malloc(sizeof(shash_table_t));

	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = (shash_node_t **)calloc(ht->size, sizeof(shash_node_t *));
	ht->shead = NULL;
	ht->stail = NULL;

	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}

/**
 * insert_sorted_node - Inserts a node into a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @new_node: A pointer to the node to be inserted.
 *
 * Description:
 * This function inserts a node into a sorted hash table in ascending
 * order based on the ASCII values of the keys.
 *
 * Return: 1 on success, 0 on failure.
 */
int insert_sorted_node(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *current_node;

	if (!ht || !new_node)
		return (0);

	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		new_node->sprev = NULL;
		new_node->snext = NULL;
		return (1);
	}

	current_node = ht->shead;
	while (current_node)
	{
		if (strcmp(new_node->key, current_node->key) < 0)
		{
			if (current_node->sprev != NULL)
				current_node->sprev->snext = new_node;
			else
				ht->shead = new_node;
			new_node->sprev = current_node->sprev;
			new_node->snext = current_node;
			current_node->sprev = new_node;
			return (1);
		}

		if (current_node->snext == NULL)
		{
			current_node->snext = new_node;
			new_node->sprev = current_node;
			new_node->snext = NULL;
			ht->stail = new_node;
			return (1);
		}
		current_node = current_node->snext;
	}
	return (0);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key string.
 * @value: The value string.
 *
 * Description:
 * This function adds an element to a sorted hash table.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *tmp;

	if (!ht || !key || !*key || !value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp)
	{
		if (strcmp(key, tmp->key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			if (!tmp->value)
				return (0);
			return (1);
		}
		tmp = tmp->next;
	}

	new_node = (shash_node_t *)malloc(sizeof(shash_node_t));
	if (!new_node)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (!new_node->key || !new_node->value)
	{
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	if (insert_sorted_node(ht, new_node) == 0)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: A pointer to the sorted hash table.
 * @key: The key string.
 *
 * Description:
 * This function retrieves a value associated with a key.
 *
 * Return: The value associated with the element, or NULL if key
 * couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];

	while (tmp)
	{
		if (strcmp(key, tmp->key) == 0)
			return (tmp->value);

		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: A pointer to the sorted hash table to be printed.
 *
 * Description:
 * This function prints the key/value pairs of the sorted hash table
 * in ascending order based on the ASCII values of the keys.
 *
 * Return: void.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (!ht)
		return;

	current_node = ht->shead;

	printf("{");

	while (current_node)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->snext;
		if (current_node)
			printf(", ");
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse.
 * @ht: A pointer to the sorted hash table to be printed.
 *
 * Description:
 * This function prints the key/value pairs of the sorted hash table
 * in reverse order based on the ASCII values of the keys.
 *
 * Return: void.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (!ht)
		return;

	current_node = ht->stail;

	printf("{");

	while (current_node)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->sprev;
		if (current_node)
			printf(", ");
	}

	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table to be deleted.
 *
 * Description:
 * This function deletes a sorted hash table.
 *
 * Return: void.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *tmp, *current_node;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current_node = ht->array[i];
		while (current_node)
		{
			tmp = current_node;
			current_node = current_node->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}

	free(ht->array);
	free(ht);
}
