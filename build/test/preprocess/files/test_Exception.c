#include "build/temp/_test_Exception.c"
#include "CException.h"
#include "Exception.h"
#include "unity.h"






void setUp(void){}

void tearDown(void){}

void test_Exception_NeedToImplement(void){}





char *names[] = {"Ali", "David", "Ah Beng", "Sally"};



void throwError2(int errorCode, char *msg)

{

  Exception *ex = (Exception *)malloc(sizeof(Exception));

  ex->errorCode = errorCode;

  ex->errorMsg = msg;

  Throw(ex);

}





int add(int num, ...)

{

  va_list valist;

  int i, sum = 0;

  

 __builtin_va_start(

 valist

 ,

 num

 )

                     ;

  for(i =0; i < num; i++)

  {

    sum += 

          __builtin_va_arg(

          valist

          ,

          int

          )

                            ;

  }

  

 __builtin_va_end(

 valist

 )

               ;

  return sum;

}





int throwError(int errorCode, char *format, ...)

{

  va_list valist;

  int neededSize;

  char *buffer;



  Exception *ex = (Exception *)malloc(sizeof(Exception));

  ex->errorCode = errorCode;

  

 __builtin_va_start(

 valist

 ,

 format

 )

                        ;

  neededSize = vsnprintf(

                        ((void *)0)

                            , 0, format, valist)+ 1;

  buffer = malloc(neededSize);

  vsnprintf(buffer,neededSize, format, valist);



  

 __builtin_va_end(

 valist

 )

               ;

  ex->errorMsg = buffer;

  Throw(ex);

}



char *getName(int index)

{

  if(index >= 4 || index < 0)

  {



    throwError(3,"Error: Out of bound of the array. Please try again. Index is %d", index);

  }

  return names[index];

}



void test_getName_given_1_expect_David(void)

{

  Exception * e;

  char *name;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((Exception *)0x5A5A5A5A); ; if (

 _setjmp((

 NewFrame

 ), __builtin_frame_address (0)) 

 == 0) { if (1)

  {

  name = getName(1);

  UnityAssertEqualString((const char*)(("David")), (const char*)((name)), (

 ((void *)0)

 ), (UNITY_UINT)(73));

  printf("Name is %s \n", name);

  }

  else { } CExceptionFrames[MY_ID].Exception = ((Exception *)0x5A5A5A5A); ; } else { e = CExceptionFrames[MY_ID].Exception; (void)e; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((Exception *)0x5A5A5A5A))

  {

    UnityFail( ((e->errorMsg)), (UNITY_UINT)(78));



    free(e);

  }

}



void test_add_given_12345_expect_15(void)

{

  int result = add(5,1,2,3,4,5);



  UnityAssertEqualNumber((UNITY_INT)((15)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);

}



void test_add_given_987_expect_24(void)

{

  int result = add(3,9,8,7);



  UnityAssertEqualNumber((UNITY_INT)((24)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_INT);

}



void test_print_all_number(void)

{

  printAllNumber("%f, %d ,%x, %s",12345.1235,45678912,255, "WALA~");

}
