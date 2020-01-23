/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/*
 * Please fill in the following student struct
 */
team_t team = {
    "2237691",              /* Student ID */
    "Zeynep Özalp",     /* full name */
    "zeynep.ozalp@metu.edu.tr",  /* email address */
    "",                   /* leave blank */
    ""                    /* leave blank */
};


/***************
 * Sobel KERNEL
 ***************/

/******************************************************
 * Your different versions of the sobel functions  go here
 ******************************************************/

/*
 * naive_sobel - The naive baseline version of Sobel
 */
char naive_sobel_descr[] = "sobel: Naive baseline implementation";
void naive_sobel(int dim,int *src, int *dst) {
    int i,j,k,l;
    int ker[3][3] = {{-1, 0, 1},
                     {-2, 0, 2},
                     {-1, 0, 1}};

    for(i = 0; i < dim; i++){
      for(j = 0; j < dim; j++){
	          dst[j*dim+i]=0;
            if(!((i == 0) || (i == dim-1) || (j == 0) || (j == dim-1))){
                for(k = -1; k < 1; k++){
                    for(l = -1; l < 1; l++) {
                        dst[j*dim+i]=dst[j*dim+i]+src[(j + l)*dim+(i + k)] * ker[l+1][k+1];
                      }
                }
            }
      }
    }
}
/*
 * sobel - Your current working version of sobel
 * IMPORTANT: This is the version you will be graded on
 */

 char sobel1_descr[] = "sobel1 implementation";
 void sobel1(int dim,int *src, int *dst) {
   int i,j;

  for(j = 0; j < dim; j++){
     for(i = 0; i < dim; i++){
          dst[j*dim+i]=0;
          if(!((i == 0) || (i == dim-1) || (j == 0) || (j == dim-1))){
            dst[j*dim+i]=dst[j*dim+i]+src[(j - 1)*dim+(i - 1)] * -1;
            dst[j*dim+i]=dst[j*dim+i]+src[(j)*dim+(i - 1)] * -2;
           }
     }
   }
 }

 char sobel2_descr[] = "sobel2 16x16 blocking implementation";
 void sobel2(int dim,int *src, int *dst) {
   int i,j,i1,j1;
   int b=16;

for(j = 0; j < dim; j+=b){
   for(i = 0; i < dim; i+=b){
        for(j1=j; j1<j+b; j1++){
          for(i1=i; i1<i+b; i1++){
            dst[j1*dim+i1]=0;
            if(!((i1 == 0) || (i1 == dim-1) || (j1 == 0) || (j1 == dim-1))){
              dst[j1*dim+i1]=dst[j1*dim+i1]+src[(j1 - 1)*dim+(i1 - 1)] * -1;
              dst[j1*dim+i1]=dst[j1*dim+i1]+src[(j1)*dim+(i1 - 1)] * -2;
             }
          }
        }
   }
 }
 }

 char sobel3_descr[] = "sobel3 1x4 unrolling implementation";
 void sobel3(int dim,int *src, int *dst) {
   int i,j;

  for(j = 0; j < dim; j++){
     for(i = 0; i < dim; i+=4){
          dst[j*dim+i]=0;
            if(!((j == 0) || (j == dim-1) || (i==0) || (i==dim-1))){
              dst[j*dim+i]=dst[j*dim+i]+src[(j - 1)*dim+(i - 1)] * -1;
              dst[j*dim+i]=dst[j*dim+i]+src[(j)*dim+(i - 1)] * -2;
            }
            dst[j*dim+i+1]=0;
            if(!((j == 0) || (j == dim-1) || (i+1==0) || (i+1==dim-1))){
              dst[j*dim+i+1]=dst[j*dim+i+1]+src[(j - 1)*dim+i] * -1;
              dst[j*dim+i+1]=dst[j*dim+i+1]+src[(j)*dim+i] * -2;
            }
            dst[j*dim+i+2]=0;
            if(!((j == 0) || (j == dim-1) || (i+2==0 || i+2==dim-1))){
              dst[j*dim+i+2]=dst[j*dim+i+2]+src[(j - 1)*dim+(i + 1)] * -1;
              dst[j*dim+i+2]=dst[j*dim+i+2]+src[(j)*dim+(i + 1)] * -2;
            }
            dst[j*dim+i+3]=0;
            if(!((j == 0) || (j == dim-1) || (i+3==0 || i+3==dim-1))){
              dst[j*dim+i+3]=dst[j*dim+i+3]+src[(j - 1)*dim+(i+2)] * -1;
              dst[j*dim+i+3]=dst[j*dim+i+3]+src[(j)*dim+(i+2)] * -2;
            }
     }
   }
 }

 char sobel4_descr[] = "sobel4 1x8 unrolling implementation";
 void sobel4(int dim,int *src, int *dst) {
   int i,j;

  for(j = 0; j < dim; j++){
     for(i = 0; i < dim; i+=8){
          dst[j*dim+i]=0;
            if(!((j == 0) || (j == dim-1) || (i==0) || (i==dim-1))){
              dst[j*dim+i]=dst[j*dim+i]+src[(j - 1)*dim+(i - 1)] * -1;
              dst[j*dim+i]=dst[j*dim+i]+src[(j)*dim+(i - 1)] * -2;
            }
            dst[j*dim+i+1]=0;
            if(!((j == 0) || (j == dim-1) || (i+1==0) || (i+1==dim-1))){
              dst[j*dim+i+1]=dst[j*dim+i+1]+src[(j - 1)*dim+i] * -1;
              dst[j*dim+i+1]=dst[j*dim+i+1]+src[(j)*dim+i] * -2;
            }
            dst[j*dim+i+2]=0;
            if(!((j == 0) || (j == dim-1) || (i+2==0 || i+2==dim-1))){
              dst[j*dim+i+2]=dst[j*dim+i+2]+src[(j - 1)*dim+(i + 1)] * -1;
              dst[j*dim+i+2]=dst[j*dim+i+2]+src[(j)*dim+(i + 1)] * -2;
            }
            dst[j*dim+i+3]=0;
            if(!((j == 0) || (j == dim-1) || (i+3==0 || i+3==dim-1))){
              dst[j*dim+i+3]=dst[j*dim+i+3]+src[(j - 1)*dim+(i+2)] * -1;
              dst[j*dim+i+3]=dst[j*dim+i+3]+src[(j)*dim+(i+2)] * -2;
            }
            dst[j*dim+i+4]=0;
              if(!((j == 0) || (j == dim-1) || (i+4==0) || (i+4==dim-1))){
                dst[j*dim+i+4]=dst[j*dim+i+4]+src[(j - 1)*dim+(i+3)] * -1;
                dst[j*dim+i+4]=dst[j*dim+i+4]+src[(j)*dim+(i+3)] * -2;
              }
              dst[j*dim+i+5]=0;
              if(!((j == 0) || (j == dim-1) || (i+5==0) || (i+5==dim-1))){
                dst[j*dim+i+5]=dst[j*dim+i+5]+src[(j - 1)*dim+i+4] * -1;
                dst[j*dim+i+5]=dst[j*dim+i+5]+src[(j)*dim+i+4] * -2;
              }
              dst[j*dim+i+6]=0;
              if(!((j == 0) || (j == dim-1) || (i+6==0 || i+6==dim-1))){
                dst[j*dim+i+6]=dst[j*dim+i+6]+src[(j - 1)*dim+(i + 5)] * -1;
                dst[j*dim+i+6]=dst[j*dim+i+6]+src[(j)*dim+(i + 5)] * -2;
              }
              dst[j*dim+i+7]=0;
              if(!((j == 0) || (j == dim-1) || (i+7==0 || i+7==dim-1))){
                dst[j*dim+i+7]=dst[j*dim+i+7]+src[(j - 1)*dim+(i+6)] * -1;
                dst[j*dim+i+7]=dst[j*dim+i+7]+src[(j)*dim+(i+6)] * -2;
              }
     }
   }
 }

char sobel_descr[] = "Dot product: Current working version";
void sobel(int dim,int *src,int *dst)
{

       sobel4(dim,src,dst);

}

/*********************************************************************
 * register_sobel_functions - Register all of your different versions
 *     of the sobel functions  with the driver by calling the
 *     add_sobel_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_sobel_functions() {
    add_sobel_function(&naive_sobel, naive_sobel_descr);
    add_sobel_function(&sobel, sobel_descr);
    /* ... Register additional test functions here */
    add_sobel_function(&sobel1, sobel1_descr);
    add_sobel_function(&sobel2, sobel2_descr);
    add_sobel_function(&sobel3, sobel3_descr);
    add_sobel_function(&sobel4, sobel4_descr);
}




/***************
 * MIRROR KERNEL
 ***************/

/******************************************************
 * Your different versions of the mirror func  go here
 ******************************************************/

/*
 * naive_mirror - The naive baseline version of mirror
 */
char naive_mirror_descr[] = "Naive_mirror: Naive baseline implementation";
void naive_mirror(int dim,int *src,int *dst) {

 	 int i,j;

    for(j = 0; j < dim; j++)
        for(i = 0; i < dim; i++) {
            dst[RIDX(i,dim-j,dim)]=src[RIDX(i,j,dim)];

        }

}

char mirror1_descr[] = "mirror1 implementation with 4x1 unrolling";
void mirror1(int dim,int *src,int *dst) {

  int i,j;

   for(i = 0; i < dim; i+=4)
       for(j = 0; j < dim; j++) {
           dst[RIDX(i,dim-j,dim)]=src[RIDX(i,j,dim)];
           dst[RIDX(i+1,dim-j,dim)]=src[RIDX(i+1,j,dim)];
           dst[RIDX(i+2,dim-j,dim)]=src[RIDX(i+2,j,dim)];
           dst[RIDX(i+3,dim-j,dim)]=src[RIDX(i+3,j,dim)];
       }
}

char mirror2_descr[] = "mirror2 implementation with 4x4 unrolling";
void mirror2(int dim,int *src,int *dst) {

  int i,j;

   for(i = 0; i < dim; i+=4)
       for(j = 0; j < dim; j+=4) {
           dst[RIDX(i,dim-j,dim)]=src[RIDX(i,j,dim)];
           dst[RIDX(i+1,dim-j,dim)]=src[RIDX(i+1,j,dim)];
           dst[RIDX(i+2,dim-j,dim)]=src[RIDX(i+2,j,dim)];
           dst[RIDX(i+3,dim-j,dim)]=src[RIDX(i+3,j,dim)];

           dst[RIDX(i,dim-j-1,dim)]=src[RIDX(i,j+1,dim)];
           dst[RIDX(i+1,dim-j-1,dim)]=src[RIDX(i+1,j+1,dim)];
           dst[RIDX(i+2,dim-j-1,dim)]=src[RIDX(i+2,j+1,dim)];
           dst[RIDX(i+3,dim-j-1,dim)]=src[RIDX(i+3,j+1,dim)];

           dst[RIDX(i,dim-j-2,dim)]=src[RIDX(i,j+2,dim)];
           dst[RIDX(i+1,dim-j-2,dim)]=src[RIDX(i+1,j+2,dim)];
           dst[RIDX(i+2,dim-j-2,dim)]=src[RIDX(i+2,j+2,dim)];
           dst[RIDX(i+3,dim-j-2,dim)]=src[RIDX(i+3,j+2,dim)];

           dst[RIDX(i,dim-j-3,dim)]=src[RIDX(i,j+3,dim)];
           dst[RIDX(i+1,dim-j-3,dim)]=src[RIDX(i+1,j+3,dim)];
           dst[RIDX(i+2,dim-j-3,dim)]=src[RIDX(i+2,j+3,dim)];
           dst[RIDX(i+3,dim-j-3,dim)]=src[RIDX(i+3,j+3,dim)];
       }
}

char mirror3_descr[] = "mirror3 with 4x1 blocking";
void mirror3(int dim, int *src,int *dst) {
  int i,j;

   for(i = 0; i < dim; i+=4)
       for(j = 0; j < dim; j++) {
           dst[RIDX(i,dim-j,dim)]=src[RIDX(i,j,dim)];
           dst[RIDX(i+1,dim-j,dim)]=src[RIDX(i+1,j,dim)];
           dst[RIDX(i+2,dim-j,dim)]=src[RIDX(i+2,j,dim)];
           dst[RIDX(i+3,dim-j,dim)]=src[RIDX(i+3,j,dim)];
       }
}

char mirror4_descr[]= "mirror4 with 8x1 blocking";
void mirror4(int dim,int *src,int *dst){
    int i,j;

     for(i = 0; i < dim; i+=8)
         for(j = 0; j < dim; j++) {
             dst[RIDX(i,dim-j,dim)]=src[RIDX(i,j,dim)];
             dst[RIDX(i+1,dim-j,dim)]=src[RIDX(i+1,j,dim)];
             dst[RIDX(i+2,dim-j,dim)]=src[RIDX(i+2,j,dim)];
             dst[RIDX(i+3,dim-j,dim)]=src[RIDX(i+3,j,dim)];
             dst[RIDX(i+4,dim-j,dim)]=src[RIDX(i+4,j,dim)];
             dst[RIDX(i+5,dim-j,dim)]=src[RIDX(i+5,j,dim)];
             dst[RIDX(i+6,dim-j,dim)]=src[RIDX(i+6,j,dim)];
             dst[RIDX(i+7,dim-j,dim)]=src[RIDX(i+7,j,dim)];
         }
}

char mirror5_descr[]= "mirror5 with 16x1 blocking";
void mirror5(int dim,int *src,int *dst){
    int i,j;

     for(i = 0; i < dim; i+=16)
         for(j = 0; j < dim; j++) {
             dst[RIDX(i,dim-j,dim)]=src[RIDX(i,j,dim)];
             dst[RIDX(i+1,dim-j,dim)]=src[RIDX(i+1,j,dim)];
             dst[RIDX(i+2,dim-j,dim)]=src[RIDX(i+2,j,dim)];
             dst[RIDX(i+3,dim-j,dim)]=src[RIDX(i+3,j,dim)];
             dst[RIDX(i+4,dim-j,dim)]=src[RIDX(i+4,j,dim)];
             dst[RIDX(i+5,dim-j,dim)]=src[RIDX(i+5,j,dim)];
             dst[RIDX(i+6,dim-j,dim)]=src[RIDX(i+6,j,dim)];
             dst[RIDX(i+7,dim-j,dim)]=src[RIDX(i+7,j,dim)];
             dst[RIDX(i+8,dim-j,dim)]=src[RIDX(i+8,j,dim)];
             dst[RIDX(i+9,dim-j,dim)]=src[RIDX(i+9,j,dim)];
             dst[RIDX(i+10,dim-j,dim)]=src[RIDX(i+10,j,dim)];
             dst[RIDX(i+11,dim-j,dim)]=src[RIDX(i+11,j,dim)];
             dst[RIDX(i+12,dim-j,dim)]=src[RIDX(i+12,j,dim)];
             dst[RIDX(i+13,dim-j,dim)]=src[RIDX(i+13,j,dim)];
             dst[RIDX(i+14,dim-j,dim)]=src[RIDX(i+14,j,dim)];
             dst[RIDX(i+15,dim-j,dim)]=src[RIDX(i+15,j,dim)];
         }
}

/*
 * mirror - Your current working version of mirror
 * IMPORTANT: This is the version you will be graded on
 */
char mirror_descr[] = "Mirror: Current working version";
void mirror(int dim,int *src,int *dst)
{


 	//naive_mirror(dim,src,dst);
  //mirror4(dim,src,dst);
  int i,j;

   for(i = 0; i < dim; i+=8)
       for(j = 0; j < dim; j++) {
           dst[RIDX(i,dim-j,dim)]=src[RIDX(i,j,dim)];
           dst[RIDX(i+1,dim-j,dim)]=src[RIDX(i+1,j,dim)];
           dst[RIDX(i+2,dim-j,dim)]=src[RIDX(i+2,j,dim)];
           dst[RIDX(i+3,dim-j,dim)]=src[RIDX(i+3,j,dim)];
           dst[RIDX(i+4,dim-j,dim)]=src[RIDX(i+4,j,dim)];
           dst[RIDX(i+5,dim-j,dim)]=src[RIDX(i+5,j,dim)];
           dst[RIDX(i+6,dim-j,dim)]=src[RIDX(i+6,j,dim)];
           dst[RIDX(i+7,dim-j,dim)]=src[RIDX(i+7,j,dim)];
       }

}

/*********************************************************************
 * register_mirror_functions - Register all of your different versions
 *     of the mirror functions  with the driver by calling the
 *     add_mirror_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_mirror_functions() {
    add_mirror_function(&naive_mirror, naive_mirror_descr);
    add_mirror_function(&mirror, mirror_descr);
    /* ... Register additional test functions here */
    add_mirror_function(&mirror1, mirror1_descr);
    add_mirror_function(&mirror2, mirror2_descr);
    add_mirror_function(&mirror3, mirror3_descr);
    add_mirror_function(&mirror4, mirror4_descr);
    add_mirror_function(&mirror5, mirror5_descr);
}
