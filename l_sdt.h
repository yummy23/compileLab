#ifndef _L_SDD_H
#define _L_SDD_H

#include <stdio.h>

#include "tree.h"
#include "table.h"

/* high-level definition */
void Program(Node *n);
void ExtDefList(Node *n);
void ExtDef(Node *n);//
void ExtDecList(Node *n,Type type);//

/* specifiers */ 
Type Specifier(Node *n);
Type StructSpecifier(Node *n);//
void OptTag(Node *n);//
void Tag(Node *n);//

/* Declarators */
FieldList VarDec(Node *n, Type type, int from);
SymbolEntry FunDec(Node *n,Type type);
FieldList VarList(Node *n);
FieldList ParamDec(Node *n);//

/* statements */
void CompSt(Node *n, Type type, int from);//
void StmtList(Node *n, Type type);//
void Stmt(Node *n, Type type);//

/* local definition */
FieldList DefList(Node *n,int from);//
FieldList Def(Node *n, int from);//
FieldList DecList(Node *n,Type type,int from);//
FieldList Dec(Node *n,Type type, int from);//

/* Expressions */
Type Exp(Node *n);

int typeEqual(Type t1,Type t2);
int Args(Node* n,FieldList f);
void printparam(FieldList f);
void printargs(Node *n);
void printtype(Type t);
#endif
