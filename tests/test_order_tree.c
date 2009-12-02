#include <stdio.h>
#include <string.h>

#include "tree.h"
#include "order_tree.h"
#include "tree_stubs.h"
#include "to_newick.h"

int test_order_lbl()
{
	const char *test_name = "test_order_lbl";
	struct rooted_tree tree = tree_13();
	order_tree_lbl(&tree);
	char *obt_newick = to_newick(tree.root);
	char *exp_newick = "((Ant,Bee),((Cat,Dog),Eel));";

	if (0 != strcmp(obt_newick, exp_newick)) {
		printf ("%s: expected '%s', got '%s'.\n",
			test_name, exp_newick,
			obt_newick);
		return 1;
	}

	printf("%s ok.\n", test_name);
	return 0;
}

int main()
{
	int failures = 0;
	printf("Starting reordering test...\n");
	failures += test_order_lbl();
	if (0 == failures) {
		printf("All tests ok.\n");
	} else {
		printf("%d test(s) FAILED.\n", failures);
		return 1;
	}

	return 0;
}
