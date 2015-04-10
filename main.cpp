#include <stdio.h>
#include <limits.h>

void print_int_array(const int a[], int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d\t", a[i]);
	}

	printf("\n");
}

/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once
 * and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example, Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
 */

int remove_dups_from_sorted_array(int a[], int size)
{

	if(size <= 1)
	{
		return size;
	}

	// duplcates must be adjacent 
	int pivot_index = 0;
	int move_index = 1;
	while(move_index < size)
	{
		// If the next item is not equal to the pivot item
		// copy it over the pivot+1 position, it might be 
		// redundant to do so
		if(a[pivot_index] != a[move_index])
		{
			a[pivot_index+1] = a[move_index];
			pivot_index++;

		}

		move_index++;
	}

	return ++pivot_index;
}


/* 
 * Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice?
 * For example, Given sorted array A = [1,1,1,2,2,3],
 * Your function should return length = 5, and A is now [1,1,2,2,3]
 */
int remove_dups_from_sorted_array_ii(int a[], int size)
{

	if(size <= 1)
	{
		return size;
	}

	// duplcates must be adjacent 
	int pivot_index = 0;
	int move_index = 1;

	// have a variable to track how many times this item has shown up
	// default is 1
	int occur = 1;
	while(move_index < size)
	{
		// If the next item is not equal to the pivot item
		// copy it over the pivot+1 position, it might be 
		// redundant to do so
		// or if it has occurred twice already, move the pivot
		bool not_equal = a[pivot_index] != a[move_index];

		if(not_equal || occur >= 2)
		{
			a[pivot_index+1] = a[move_index];
			pivot_index++;

			if(not_equal)
			{
				// they are not duplcates anymore, reset the occurance
				occur = 1;
			}
		}
		else
		{
			occur++;
		}

		move_index++;
	}

	return ++pivot_index;
}

void test_remove_dups_from_sorted_array()
{
	int test_array[] = {1, 1, 1, 3, 4, 6, 6, 6};
	int test_array_size = sizeof(test_array)/sizeof(int);

	printf("IN:\t");

	print_int_array(test_array, test_array_size);

	int size = remove_dups_from_sorted_array_ii(test_array, test_array_size);
	
	printf("OUT:\t");

	print_int_array(test_array, size);	
}

int find_k_th_element(int a[], int a_size, int b[], int b_size, int k)
{
	int i = 0, j = 0;

	int k_th;

	if((a_size == 0 && b_size == 0) || (k > (a_size + b_size)))
	{
		return -1;
	}
	else if (a_size == 0)
	{
		return b[k];
	}
	else if(b_size == 0)
	{
		return a[k];
	}

	while(i + j < k)
	{
		if(a[i] > b[j])
		{
			k_th = b[j];
			
			if(j < b_size - 1)
			{
				j++;
			}
			else
			{
				
			}
		}
		else
		{
			k_th = a[i];
			i++;
		}
	}

	return k_th;
}

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void build_tree(TreeNode** node, int output[], int min, int max)
{
    if(min > max) return;
    
    int middle = min + (max - min)/2;
    TreeNode* t = new TreeNode(output[middle]);
    *node = t;
    build_tree(&t->left, output, min, middle);
    build_tree(&t->right, output, middle, max);
}

TreeNode* reconstruct_binary_tree(int output[], int size)
{

    TreeNode* root = NULL;
    build_tree(&root, output, 0, size-1);

    return root;
}

bool isValid(TreeNode *node, int min, int max)
{
    if(node == NULL) return true;

    printf("%d\n", node->val);
    
    return (node->val > min) 
                && (node->val < max)
                    && isValid(node->left, min, node->val)
                        && isValid(node->right, node->val, max);
}

bool isValidBST(TreeNode *root) 
{
    if(root == NULL) return true;
    
    return isValid(root, INT_MIN, INT_MAX);
}

int main()
{
	printf("Hello World!\n");

	//test_remove_dups_from_sorted_array();

	TreeNode a = TreeNode(1);

	TreeNode b = TreeNode(1);

	a.right = &b;

	printf("BST(%s)\n", isValidBST(&a)?"true":"false");


	return 0;
}

