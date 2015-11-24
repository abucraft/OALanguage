#include <stdio.h>
#include <stdlib.h>
#include "oa.h"



struct ParseTree *parseTree;
void initTree(){
	struct TreeNode *node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = VAR_DEFINE_NODE;
	node->str = (char*)malloc(11);
	node->str = "int @a = 1";
	parseTree->root = node;
	
	node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->type = IF_ELSE_NODE;
	node->str = (char*)malloc(8);
	node->str = "if(2>1)";
	node->next = 0;
	parseTree->root->next = node;
	
	node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->str = (char*)malloc(11);
	node->str = "int @d = 3";
	node->next = 0;
	
	struct IfElseNode *inode = (struct IfElseNode*)malloc(sizeof(struct IfElseNode));
	inode->ifBlock = node;
	inode->elseBlock = NULL;
	parseTree->root->next->ifElseNode = inode;
	
}

