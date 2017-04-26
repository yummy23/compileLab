#ifndef _TABLE_H
#define _TABLE_H

#include "stdio.h"

#define INTTYPE 0
#define FLOATTYPE 1
#define FUNCTYPE 2
#define FROMSTRUCT 3
#define FROMOTHER  4
/* type */
typedef struct Type_ *Type;
typedef struct FieldList_ *FieldList;

struct Type_{
    enum {BASIC, ARRAY, STRUCTER}kind;
    union
    {
        // 基本类型,int?float?
        int basic;
        // 数组类型信息包括元素类型与数组大小构成
        struct { Type elem; int size; } array;
        // 结构体类型信息是一个链表
        FieldList structure;
    } u;
};

struct FieldList_
{
    char* name; // 域的名字
    Type type;  // 域的类型
    FieldList next; // 下一个域
};

/* table */
typedef struct ImperStack_ *ImperStack;
typedef struct Table_ *Table;
typedef struct FuncName_ *FuncName;
typedef struct SymbolEntry_ *SymbolEntry;
typedef struct Var_ *Var;
typedef struct Expression_ *Expression;



struct ImperStack_{
    ImperStack next;
    SymbolEntry e;
};

struct Table_{
    char *name;/* the name for each SymbolEntry */
    SymbolEntry e;
};

struct SymbolEntry_{
    Type type;
    int row; 
    char *name;
    //int isDefinited;
    union{
        char *ProgramName;
        FuncName fn;
        Var var;
    }u;
    SymbolEntry stack_next;
    SymbolEntry table_next;
};

struct FuncName_ {
    FieldList param;
};

struct Var_{
    union{
	int val_int;
	float val_float;
    }val;
};

struct Expression_{
    Type type;
    union{
	int val_int;
	float val_float;
    }val;
};
/* Log all name */
typedef struct LogName_ *LogName;

struct LogName_{
    char *name;
    LogName next;
};



void addName(char *);
void Table_init();
int addToImperSlot(SymbolEntry e);
void ImperStack_push();
void ImperStack_pop();
int addToTable(SymbolEntry);
void refreshTable(SymbolEntry e,char *name);

#endif
