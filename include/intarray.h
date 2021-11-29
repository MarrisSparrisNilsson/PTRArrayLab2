
#ifndef _intarray_h
#define _intarray_h

#define CAPACITY 20
#define SENTINEL -1

enum SortOrder {ASCENDING, DESCENDING};
enum Uniqueness {UNIQUE, NONUNIQUE};
static enum SortOrder sortOrder = ASCENDING;
static enum Uniqueness uniqueness;

typedef int intArray[CAPACITY];

void printArray(intArray a);
int getIntArraySize(intArray a);
int getIntArray(intArray a);
void appendIntArray(intArray a, intArray b, intArray c);
void interleaveIntArray(intArray a, intArray b, intArray c);
void sortIntArray(intArray a);
void setSortOrder(void);
void setUniqueness(void);
void filterUnique(intArray a);
void bubbleSort(intArray a);
void swap(int *element1Ptr, int *element2Ptr);

/* 

intArray function prototypes

*/

#endif /*_intarray_h */