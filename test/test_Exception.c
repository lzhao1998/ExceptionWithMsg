#include "unity.h"
#include "Exception.h"
#include "CException.h"
#include <stdio.h>
#include <malloc.h>
#include <stdarg.h>

void setUp(void){}
void tearDown(void){}
void test_Exception_NeedToImplement(void){}

//name is array 3 of pointes to char
char *names[] = {"Ali", "David", "Ah Beng", "Sally"};

void throwError2(int errorCode, char *msg)
{
  Exception *ex = (Exception *)malloc(sizeof(Exception));
  ex->errorCode = errorCode;
  ex->errorMsg = msg;
  Throw(ex);
}

//Do add function by using variable argument
int add(int num, ...)
{
  va_list valist;
  int i, sum = 0;
  va_start(valist,num);
  for(i =0; i < num; i++)
  {
    sum += va_arg(valist,int);
  }
  va_end(valist);
  return sum;
}

//this function behave like printf
int throwError(int errorCode, char *format, ...)
{
  va_list valist;
  int neededSize;
  char *buffer;

  Exception *ex = (Exception *)malloc(sizeof(Exception));
  ex->errorCode = errorCode;
  va_start(valist,format);
  neededSize = vsnprintf(NULL, 0, format, valist)+ 1;
  buffer = malloc(neededSize);
  vsnprintf(buffer,neededSize, format, valist);

  va_end(valist);
  ex->errorCode = errorCode;
  ex->errorMsg = buffer;
  Throw(ex);
}

char *getName(int index)
{
  if(index >= 4 || index < 0)
  {
    //static Exception exception = {3 , "Error: Out of bound of the array. Please try again."};
    throwError(3,"Error: Out of bound of the array. Please try again. Index is %d", index);
  }
  return names[index];
}

void test_getName_given_1_expect_David(void)
{
  CEXCEPTION_T e;
  char *name;
  Try
  {
  name = getName(1);
  TEST_ASSERT_EQUAL_STRING("David", name);
  printf("Name is %s \n", name);
  }
  Catch(e)
  {
    TEST_FAIL_MESSAGE(e->errorMsg);
  //  printf("\t%s\n",e->errorMsg);
    freeError(e);
  }
}

void test_add_given_12345_expect_15(void)
{
  int result = add(5,1,2,3,4,5);

  TEST_ASSERT_EQUAL(15,result);
}

void test_add_given_987_expect_24(void)
{
  int result = add(3,9,8,7);

  TEST_ASSERT_EQUAL(24,result);
}

void test_print_all_number(void)
{
  printAllNumber("%f, %d ,%x, %s",12345.1235,45678912,255, "WALA~");
}
/*void test_getName_given_minus_1_expect_ERR_OUT_OF_BOUND(void)
{
  CEXCEPTION_T e;
  char *name;
  Try
  {
  name = getName(-1);
  }
  Catch(e)
  {
    printf("ERR OUT OF BOUND\n");
    printf("Error code: %d\n", e);
  }
}*/
