/**
 * monty_push - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *top = *stack;

	if (!ex.data.value)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_resources_and_exit();
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_resources_and_exit();
	}

	new_node->n = ex.int_value;

	if (!top)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = NULL;
		new_node->prev = top;
		top->next = new_node;
		*stack = new_node;
	}
}

/**
 * monty_pall - Prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
}
