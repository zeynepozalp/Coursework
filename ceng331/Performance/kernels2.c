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
   int ker[3][3] = {{-1, 0, 1},
                    {-2, 0, 2},
                    {-1, 0, 1}};

  for(i = 0; i < dim; i++){
     for(j = 0; j < dim; j++){
          dst[j*dim+i]=0;
          if(!((i == 0) || (i == dim-1) || (j == 0) || (j == dim-1))){
            dst[j*dim+i]=dst[j*dim+i]+src[(j - 1)*dim+(i - 1)] * ker[0][0];
            dst[j*dim+i]=dst[j*dim+i]+src[(j)*dim+(i - 1)] * ker[1][0];

            dst[j*dim+i]=dst[j*dim+i]+src[(j - 1)*dim+(i)] * ker[0][1];
            dst[j*dim+i]=dst[j*dim+i]+src[(j)*dim+(i)] * ker[1][1];
           }
     }
   }
 }

 char sobel2_descr[] = "sobel2 implementation";
 void sobel2(int dim,int *src, int *dst) {
   int i,j;
   int ker[3][3] = {{-1, 0, 1},
                    {-2, 0, 2},
                    {-1, 0, 1}};



 }

char sobel_descr[] = "Dot product: Current working version";
void sobel(int dim,int *src,int *dst)
{

       sobel2(dim,src,dst);

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

char mirror1_descr[] = "mirror1 implementation with 1x4 unrolling";
void mirror1(int dim,int *src,int *dst) {

  int i,j;

   for(j = 0; j < dim; j++)
       for(i = 0; i < dim; i+=4) {
           dst[RIDX(i,dim-j,dim)]=src[RIDX(i,j,dim)];
           dst[RIDX(i+1,dim-j,dim)]=src[RIDX(i+1,j,dim)];
           dst[RIDX(i+2,dim-j,dim)]=src[RIDX(i+2,j,dim)];
           dst[RIDX(i+3,dim-j,dim)]=src[RIDX(i+3,j,dim)];
       }
}

char mirror2_descr[] = "mirror2 implementation with 4x4 unrolling";
void mirror2(int dim,int *src,int *dst) {

  int i,j;

   for(j = 0; j < dim; j+=4)
       for(i = 0; i < dim; i+=4) {
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

char mirror3_descr[] = "mirror3 implementation with 16x16 unrolling";
void mirror3(int dim, int *src,int *dst) {

  int i,j;

   for(j = 0; j < dim; j+=16)
       for(i = 0; i < dim; i+=16) {
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
           dst[RIDX(i+31,dim-j,dim)]=src[RIDX(i+31,j,dim)];

           dst[RIDX(i,dim-(j+1),dim)]=src[RIDX(i,(j+1),dim)];
           dst[RIDX(i+1,dim-(j+1),dim)]=src[RIDX(i+1,(j+1),dim)];
           dst[RIDX(i+2,dim-(j+1),dim)]=src[RIDX(i+2,(j+1),dim)];
           dst[RIDX(i+3,dim-(j+1),dim)]=src[RIDX(i+3,(j+1),dim)];
           dst[RIDX(i+4,dim-(j+1),dim)]=src[RIDX(i+4,(j+1),dim)];
           dst[RIDX(i+5,dim-(j+1),dim)]=src[RIDX(i+5,(j+1),dim)];
           dst[RIDX(i+6,dim-(j+1),dim)]=src[RIDX(i+6,(j+1),dim)];
           dst[RIDX(i+7,dim-(j+1),dim)]=src[RIDX(i+7,(j+1),dim)];
           dst[RIDX(i+8,dim-(j+1),dim)]=src[RIDX(i+8,(j+1),dim)];
           dst[RIDX(i+9,dim-(j+1),dim)]=src[RIDX(i+9,(j+1),dim)];
           dst[RIDX(i+10,dim-(j+1),dim)]=src[RIDX(i+10,(j+1),dim)];
           dst[RIDX(i+11,dim-(j+1),dim)]=src[RIDX(i+11,(j+1),dim)];
           dst[RIDX(i+12,dim-(j+1),dim)]=src[RIDX(i+12,(j+1),dim)];
           dst[RIDX(i+13,dim-(j+1),dim)]=src[RIDX(i+13,(j+1),dim)];
           dst[RIDX(i+14,dim-(j+1),dim)]=src[RIDX(i+14,(j+1),dim)];
           dst[RIDX(i+15,dim-(j+1),dim)]=src[RIDX(i+15,(j+1),dim)];

           dst[RIDX(i,dim-(j+2),dim)]=src[RIDX(i,(j+2),dim)];
           dst[RIDX(i+1,dim-(j+2),dim)]=src[RIDX(i+1,(j+2),dim)];
           dst[RIDX(i+2,dim-(j+2),dim)]=src[RIDX(i+2,(j+2),dim)];
           dst[RIDX(i+3,dim-(j+2),dim)]=src[RIDX(i+3,(j+2),dim)];
           dst[RIDX(i+4,dim-(j+2),dim)]=src[RIDX(i+4,(j+2),dim)];
           dst[RIDX(i+5,dim-(j+2),dim)]=src[RIDX(i+5,(j+2),dim)];
           dst[RIDX(i+6,dim-(j+2),dim)]=src[RIDX(i+6,(j+2),dim)];
           dst[RIDX(i+7,dim-(j+2),dim)]=src[RIDX(i+7,(j+2),dim)];
           dst[RIDX(i+8,dim-(j+2),dim)]=src[RIDX(i+8,(j+2),dim)];
           dst[RIDX(i+9,dim-(j+2),dim)]=src[RIDX(i+9,(j+2),dim)];
           dst[RIDX(i+10,dim-(j+2),dim)]=src[RIDX(i+10,(j+2),dim)];
           dst[RIDX(i+11,dim-(j+2),dim)]=src[RIDX(i+11,(j+2),dim)];
           dst[RIDX(i+12,dim-(j+2),dim)]=src[RIDX(i+12,(j+2),dim)];
           dst[RIDX(i+13,dim-(j+2),dim)]=src[RIDX(i+13,(j+2),dim)];
           dst[RIDX(i+14,dim-(j+2),dim)]=src[RIDX(i+14,(j+2),dim)];
           dst[RIDX(i+15,dim-(j+2),dim)]=src[RIDX(i+15,(j+2),dim)];

           dst[RIDX(i,dim-(j+3),dim)]=src[RIDX(i,(j+3),dim)];
           dst[RIDX(i+1,dim-(j+3),dim)]=src[RIDX(i+1,(j+3),dim)];
           dst[RIDX(i+2,dim-(j+3),dim)]=src[RIDX(i+2,(j+3),dim)];
           dst[RIDX(i+3,dim-(j+3),dim)]=src[RIDX(i+3,(j+3),dim)];
           dst[RIDX(i+4,dim-(j+3),dim)]=src[RIDX(i+4,(j+3),dim)];
           dst[RIDX(i+5,dim-(j+3),dim)]=src[RIDX(i+5,(j+3),dim)];
           dst[RIDX(i+6,dim-(j+3),dim)]=src[RIDX(i+6,(j+3),dim)];
           dst[RIDX(i+7,dim-(j+3),dim)]=src[RIDX(i+7,(j+3),dim)];
           dst[RIDX(i+8,dim-(j+3),dim)]=src[RIDX(i+8,(j+3),dim)];
           dst[RIDX(i+9,dim-(j+3),dim)]=src[RIDX(i+9,(j+3),dim)];
           dst[RIDX(i+10,dim-(j+3),dim)]=src[RIDX(i+10,(j+3),dim)];
           dst[RIDX(i+11,dim-(j+3),dim)]=src[RIDX(i+11,(j+3),dim)];
           dst[RIDX(i+12,dim-(j+3),dim)]=src[RIDX(i+12,(j+3),dim)];
           dst[RIDX(i+13,dim-(j+3),dim)]=src[RIDX(i+13,(j+3),dim)];
           dst[RIDX(i+14,dim-(j+3),dim)]=src[RIDX(i+14,(j+3),dim)];
           dst[RIDX(i+15,dim-(j+3),dim)]=src[RIDX(i+15,(j+3),dim)];

           dst[RIDX(i,dim-(j+4),dim)]=src[RIDX(i,(j+4),dim)];
           dst[RIDX(i+1,dim-(j+4),dim)]=src[RIDX(i+1,(j+4),dim)];
           dst[RIDX(i+2,dim-(j+4),dim)]=src[RIDX(i+2,(j+4),dim)];
           dst[RIDX(i+3,dim-(j+4),dim)]=src[RIDX(i+3,(j+4),dim)];
           dst[RIDX(i+4,dim-(j+4),dim)]=src[RIDX(i+4,(j+4),dim)];
           dst[RIDX(i+5,dim-(j+4),dim)]=src[RIDX(i+5,(j+4),dim)];
           dst[RIDX(i+6,dim-(j+4),dim)]=src[RIDX(i+6,(j+4),dim)];
           dst[RIDX(i+7,dim-(j+4),dim)]=src[RIDX(i+7,(j+4),dim)];
           dst[RIDX(i+8,dim-(j+4),dim)]=src[RIDX(i+8,(j+4),dim)];
           dst[RIDX(i+9,dim-(j+4),dim)]=src[RIDX(i+9,(j+4),dim)];
           dst[RIDX(i+10,dim-(j+4),dim)]=src[RIDX(i+10,(j+4),dim)];
           dst[RIDX(i+11,dim-(j+4),dim)]=src[RIDX(i+11,(j+4),dim)];
           dst[RIDX(i+12,dim-(j+4),dim)]=src[RIDX(i+12,(j+4),dim)];
           dst[RIDX(i+13,dim-(j+4),dim)]=src[RIDX(i+13,(j+4),dim)];
           dst[RIDX(i+14,dim-(j+4),dim)]=src[RIDX(i+14,(j+4),dim)];
           dst[RIDX(i+15,dim-(j+4),dim)]=src[RIDX(i+15,(j+4),dim)];

           dst[RIDX(i,dim-(j+5),dim)]=src[RIDX(i,(j+5),dim)];
           dst[RIDX(i+1,dim-(j+5),dim)]=src[RIDX(i+1,(j+5),dim)];
           dst[RIDX(i+2,dim-(j+5),dim)]=src[RIDX(i+2,(j+5),dim)];
           dst[RIDX(i+3,dim-(j+5),dim)]=src[RIDX(i+3,(j+5),dim)];
           dst[RIDX(i+4,dim-(j+5),dim)]=src[RIDX(i+4,(j+5),dim)];
           dst[RIDX(i+5,dim-(j+5),dim)]=src[RIDX(i+5,(j+5),dim)];
           dst[RIDX(i+6,dim-(j+5),dim)]=src[RIDX(i+6,(j+5),dim)];
           dst[RIDX(i+7,dim-(j+5),dim)]=src[RIDX(i+7,(j+5),dim)];
           dst[RIDX(i+8,dim-(j+5),dim)]=src[RIDX(i+8,(j+5),dim)];
           dst[RIDX(i+9,dim-(j+5),dim)]=src[RIDX(i+9,(j+5),dim)];
           dst[RIDX(i+10,dim-(j+5),dim)]=src[RIDX(i+10,(j+5),dim)];
           dst[RIDX(i+11,dim-(j+5),dim)]=src[RIDX(i+11,(j+5),dim)];
           dst[RIDX(i+12,dim-(j+5),dim)]=src[RIDX(i+12,(j+5),dim)];
           dst[RIDX(i+13,dim-(j+5),dim)]=src[RIDX(i+13,(j+5),dim)];
           dst[RIDX(i+14,dim-(j+5),dim)]=src[RIDX(i+14,(j+5),dim)];
           dst[RIDX(i+15,dim-(j+5),dim)]=src[RIDX(i+15,(j+5),dim)];

           dst[RIDX(i,dim-(j+6),dim)]=src[RIDX(i,(j+6),dim)];
           dst[RIDX(i+1,dim-(j+6),dim)]=src[RIDX(i+1,(j+6),dim)];
           dst[RIDX(i+2,dim-(j+6),dim)]=src[RIDX(i+2,(j+6),dim)];
           dst[RIDX(i+3,dim-(j+6),dim)]=src[RIDX(i+3,(j+6),dim)];
           dst[RIDX(i+4,dim-(j+6),dim)]=src[RIDX(i+4,(j+6),dim)];
           dst[RIDX(i+5,dim-(j+6),dim)]=src[RIDX(i+5,(j+6),dim)];
           dst[RIDX(i+6,dim-(j+6),dim)]=src[RIDX(i+6,(j+6),dim)];
           dst[RIDX(i+7,dim-(j+6),dim)]=src[RIDX(i+7,(j+6),dim)];
           dst[RIDX(i+8,dim-(j+6),dim)]=src[RIDX(i+8,(j+6),dim)];
           dst[RIDX(i+9,dim-(j+6),dim)]=src[RIDX(i+9,(j+6),dim)];
           dst[RIDX(i+10,dim-(j+6),dim)]=src[RIDX(i+10,(j+6),dim)];
           dst[RIDX(i+11,dim-(j+6),dim)]=src[RIDX(i+11,(j+6),dim)];
           dst[RIDX(i+12,dim-(j+6),dim)]=src[RIDX(i+12,(j+6),dim)];
           dst[RIDX(i+13,dim-(j+6),dim)]=src[RIDX(i+13,(j+6),dim)];
           dst[RIDX(i+14,dim-(j+6),dim)]=src[RIDX(i+14,(j+6),dim)];
           dst[RIDX(i+15,dim-(j+6),dim)]=src[RIDX(i+15,(j+6),dim)];

           dst[RIDX(i,dim-(j+7),dim)]=src[RIDX(i,(j+7),dim)];
           dst[RIDX(i+1,dim-(j+7),dim)]=src[RIDX(i+1,(j+7),dim)];
           dst[RIDX(i+2,dim-(j+7),dim)]=src[RIDX(i+2,(j+7),dim)];
           dst[RIDX(i+3,dim-(j+7),dim)]=src[RIDX(i+3,(j+7),dim)];
           dst[RIDX(i+4,dim-(j+7),dim)]=src[RIDX(i+4,(j+7),dim)];
           dst[RIDX(i+5,dim-(j+7),dim)]=src[RIDX(i+5,(j+7),dim)];
           dst[RIDX(i+6,dim-(j+7),dim)]=src[RIDX(i+6,(j+7),dim)];
           dst[RIDX(i+7,dim-(j+7),dim)]=src[RIDX(i+7,(j+7),dim)];
           dst[RIDX(i+8,dim-(j+7),dim)]=src[RIDX(i+8,(j+7),dim)];
           dst[RIDX(i+9,dim-(j+7),dim)]=src[RIDX(i+9,(j+7),dim)];
           dst[RIDX(i+10,dim-(j+7),dim)]=src[RIDX(i+10,(j+7),dim)];
           dst[RIDX(i+11,dim-(j+7),dim)]=src[RIDX(i+11,(j+7),dim)];
           dst[RIDX(i+12,dim-(j+7),dim)]=src[RIDX(i+12,(j+7),dim)];
           dst[RIDX(i+13,dim-(j+7),dim)]=src[RIDX(i+13,(j+7),dim)];
           dst[RIDX(i+14,dim-(j+7),dim)]=src[RIDX(i+14,(j+7),dim)];
           dst[RIDX(i+15,dim-(j+7),dim)]=src[RIDX(i+15,(j+7),dim)];

           dst[RIDX(i,dim-(j+8),dim)]=src[RIDX(i,(j+8),dim)];
           dst[RIDX(i+1,dim-(j+8),dim)]=src[RIDX(i+1,(j+8),dim)];
           dst[RIDX(i+2,dim-(j+8),dim)]=src[RIDX(i+2,(j+8),dim)];
           dst[RIDX(i+3,dim-(j+8),dim)]=src[RIDX(i+3,(j+8),dim)];
           dst[RIDX(i+4,dim-(j+8),dim)]=src[RIDX(i+4,(j+8),dim)];
           dst[RIDX(i+5,dim-(j+8),dim)]=src[RIDX(i+5,(j+8),dim)];
           dst[RIDX(i+6,dim-(j+8),dim)]=src[RIDX(i+6,(j+8),dim)];
           dst[RIDX(i+7,dim-(j+8),dim)]=src[RIDX(i+7,(j+8),dim)];
           dst[RIDX(i+8,dim-(j+8),dim)]=src[RIDX(i+8,(j+8),dim)];
           dst[RIDX(i+9,dim-(j+8),dim)]=src[RIDX(i+9,(j+8),dim)];
           dst[RIDX(i+10,dim-(j+8),dim)]=src[RIDX(i+10,(j+8),dim)];
           dst[RIDX(i+11,dim-(j+8),dim)]=src[RIDX(i+11,(j+8),dim)];
           dst[RIDX(i+12,dim-(j+8),dim)]=src[RIDX(i+12,(j+8),dim)];
           dst[RIDX(i+13,dim-(j+8),dim)]=src[RIDX(i+13,(j+8),dim)];
           dst[RIDX(i+14,dim-(j+8),dim)]=src[RIDX(i+14,(j+8),dim)];
           dst[RIDX(i+15,dim-(j+8),dim)]=src[RIDX(i+15,(j+8),dim)];

           dst[RIDX(i,dim-(j+9),dim)]=src[RIDX(i,(j+9),dim)];
           dst[RIDX(i+1,dim-(j+9),dim)]=src[RIDX(i+1,(j+9),dim)];
           dst[RIDX(i+2,dim-(j+9),dim)]=src[RIDX(i+2,(j+9),dim)];
           dst[RIDX(i+3,dim-(j+9),dim)]=src[RIDX(i+3,(j+9),dim)];
           dst[RIDX(i+4,dim-(j+9),dim)]=src[RIDX(i+4,(j+9),dim)];
           dst[RIDX(i+5,dim-(j+9),dim)]=src[RIDX(i+5,(j+9),dim)];
           dst[RIDX(i+6,dim-(j+9),dim)]=src[RIDX(i+6,(j+9),dim)];
           dst[RIDX(i+7,dim-(j+9),dim)]=src[RIDX(i+7,(j+9),dim)];
           dst[RIDX(i+8,dim-(j+9),dim)]=src[RIDX(i+8,(j+9),dim)];
           dst[RIDX(i+9,dim-(j+9),dim)]=src[RIDX(i+9,(j+9),dim)];
           dst[RIDX(i+10,dim-(j+9),dim)]=src[RIDX(i+10,(j+9),dim)];
           dst[RIDX(i+11,dim-(j+9),dim)]=src[RIDX(i+11,(j+9),dim)];
           dst[RIDX(i+12,dim-(j+9),dim)]=src[RIDX(i+12,(j+9),dim)];
           dst[RIDX(i+13,dim-(j+9),dim)]=src[RIDX(i+13,(j+9),dim)];
           dst[RIDX(i+14,dim-(j+9),dim)]=src[RIDX(i+14,(j+9),dim)];
           dst[RIDX(i+15,dim-(j+9),dim)]=src[RIDX(i+15,(j+9),dim)];

           dst[RIDX(i,dim-(j+10),dim)]=src[RIDX(i,(j+10),dim)];
           dst[RIDX(i+1,dim-(j+10),dim)]=src[RIDX(i+1,(j+10),dim)];
           dst[RIDX(i+2,dim-(j+10),dim)]=src[RIDX(i+2,(j+10),dim)];
           dst[RIDX(i+3,dim-(j+10),dim)]=src[RIDX(i+3,(j+10),dim)];
           dst[RIDX(i+4,dim-(j+10),dim)]=src[RIDX(i+4,(j+10),dim)];
           dst[RIDX(i+5,dim-(j+10),dim)]=src[RIDX(i+5,(j+10),dim)];
           dst[RIDX(i+6,dim-(j+10),dim)]=src[RIDX(i+6,(j+10),dim)];
           dst[RIDX(i+7,dim-(j+10),dim)]=src[RIDX(i+7,(j+10),dim)];
           dst[RIDX(i+8,dim-(j+10),dim)]=src[RIDX(i+8,(j+10),dim)];
           dst[RIDX(i+9,dim-(j+10),dim)]=src[RIDX(i+9,(j+10),dim)];
           dst[RIDX(i+10,dim-(j+10),dim)]=src[RIDX(i+10,(j+10),dim)];
           dst[RIDX(i+11,dim-(j+10),dim)]=src[RIDX(i+11,(j+10),dim)];
           dst[RIDX(i+12,dim-(j+10),dim)]=src[RIDX(i+12,(j+10),dim)];
           dst[RIDX(i+13,dim-(j+10),dim)]=src[RIDX(i+13,(j+10),dim)];
           dst[RIDX(i+14,dim-(j+10),dim)]=src[RIDX(i+14,(j+10),dim)];
           dst[RIDX(i+15,dim-(j+10),dim)]=src[RIDX(i+15,(j+10),dim)];

           dst[RIDX(i,dim-(j+11),dim)]=src[RIDX(i,(j+11),dim)];
           dst[RIDX(i+1,dim-(j+11),dim)]=src[RIDX(i+1,(j+11),dim)];
           dst[RIDX(i+2,dim-(j+11),dim)]=src[RIDX(i+2,(j+11),dim)];
           dst[RIDX(i+3,dim-(j+11),dim)]=src[RIDX(i+3,(j+11),dim)];
           dst[RIDX(i+4,dim-(j+11),dim)]=src[RIDX(i+4,(j+11),dim)];
           dst[RIDX(i+5,dim-(j+11),dim)]=src[RIDX(i+5,(j+11),dim)];
           dst[RIDX(i+6,dim-(j+11),dim)]=src[RIDX(i+6,(j+11),dim)];
           dst[RIDX(i+7,dim-(j+11),dim)]=src[RIDX(i+7,(j+11),dim)];
           dst[RIDX(i+8,dim-(j+11),dim)]=src[RIDX(i+8,(j+11),dim)];
           dst[RIDX(i+9,dim-(j+11),dim)]=src[RIDX(i+9,(j+11),dim)];
           dst[RIDX(i+10,dim-(j+11),dim)]=src[RIDX(i+10,(j+11),dim)];
           dst[RIDX(i+11,dim-(j+11),dim)]=src[RIDX(i+11,(j+11),dim)];
           dst[RIDX(i+12,dim-(j+11),dim)]=src[RIDX(i+12,(j+11),dim)];
           dst[RIDX(i+13,dim-(j+11),dim)]=src[RIDX(i+13,(j+11),dim)];
           dst[RIDX(i+14,dim-(j+11),dim)]=src[RIDX(i+14,(j+11),dim)];
           dst[RIDX(i+15,dim-(j+11),dim)]=src[RIDX(i+15,(j+11),dim)];

           dst[RIDX(i,dim-(j+12),dim)]=src[RIDX(i,(j+12),dim)];
           dst[RIDX(i+1,dim-(j+12),dim)]=src[RIDX(i+1,(j+12),dim)];
           dst[RIDX(i+2,dim-(j+12),dim)]=src[RIDX(i+2,(j+12),dim)];
           dst[RIDX(i+3,dim-(j+12),dim)]=src[RIDX(i+3,(j+12),dim)];
           dst[RIDX(i+4,dim-(j+12),dim)]=src[RIDX(i+4,(j+12),dim)];
           dst[RIDX(i+5,dim-(j+12),dim)]=src[RIDX(i+5,(j+12),dim)];
           dst[RIDX(i+6,dim-(j+12),dim)]=src[RIDX(i+6,(j+12),dim)];
           dst[RIDX(i+7,dim-(j+12),dim)]=src[RIDX(i+7,(j+12),dim)];
           dst[RIDX(i+8,dim-(j+12),dim)]=src[RIDX(i+8,(j+12),dim)];
           dst[RIDX(i+9,dim-(j+12),dim)]=src[RIDX(i+9,(j+12),dim)];
           dst[RIDX(i+10,dim-(j+12),dim)]=src[RIDX(i+10,(j+12),dim)];
           dst[RIDX(i+11,dim-(j+12),dim)]=src[RIDX(i+11,(j+12),dim)];
           dst[RIDX(i+12,dim-(j+12),dim)]=src[RIDX(i+12,(j+12),dim)];
           dst[RIDX(i+13,dim-(j+12),dim)]=src[RIDX(i+13,(j+12),dim)];
           dst[RIDX(i+14,dim-(j+12),dim)]=src[RIDX(i+14,(j+12),dim)];
           dst[RIDX(i+15,dim-(j+12),dim)]=src[RIDX(i+15,(j+12),dim)];

           dst[RIDX(i,dim-(j+13),dim)]=src[RIDX(i,(j+13),dim)];
           dst[RIDX(i+1,dim-(j+13),dim)]=src[RIDX(i+1,(j+13),dim)];
           dst[RIDX(i+2,dim-(j+13),dim)]=src[RIDX(i+2,(j+13),dim)];
           dst[RIDX(i+3,dim-(j+13),dim)]=src[RIDX(i+3,(j+13),dim)];
           dst[RIDX(i+4,dim-(j+13),dim)]=src[RIDX(i+4,(j+13),dim)];
           dst[RIDX(i+5,dim-(j+13),dim)]=src[RIDX(i+5,(j+13),dim)];
           dst[RIDX(i+6,dim-(j+13),dim)]=src[RIDX(i+6,(j+13),dim)];
           dst[RIDX(i+7,dim-(j+13),dim)]=src[RIDX(i+7,(j+13),dim)];
           dst[RIDX(i+8,dim-(j+13),dim)]=src[RIDX(i+8,(j+13),dim)];
           dst[RIDX(i+9,dim-(j+13),dim)]=src[RIDX(i+9,(j+13),dim)];
           dst[RIDX(i+10,dim-(j+13),dim)]=src[RIDX(i+10,(j+13),dim)];
           dst[RIDX(i+11,dim-(j+13),dim)]=src[RIDX(i+11,(j+13),dim)];
           dst[RIDX(i+12,dim-(j+13),dim)]=src[RIDX(i+12,(j+13),dim)];
           dst[RIDX(i+13,dim-(j+13),dim)]=src[RIDX(i+13,(j+13),dim)];
           dst[RIDX(i+14,dim-(j+13),dim)]=src[RIDX(i+14,(j+13),dim)];
           dst[RIDX(i+15,dim-(j+13),dim)]=src[RIDX(i+15,(j+13),dim)];

           dst[RIDX(i,dim-(j+14),dim)]=src[RIDX(i,(j+14),dim)];
           dst[RIDX(i+1,dim-(j+14),dim)]=src[RIDX(i+1,(j+14),dim)];
           dst[RIDX(i+2,dim-(j+14),dim)]=src[RIDX(i+2,(j+14),dim)];
           dst[RIDX(i+3,dim-(j+14),dim)]=src[RIDX(i+3,(j+14),dim)];
           dst[RIDX(i+4,dim-(j+14),dim)]=src[RIDX(i+4,(j+14),dim)];
           dst[RIDX(i+5,dim-(j+14),dim)]=src[RIDX(i+5,(j+14),dim)];
           dst[RIDX(i+6,dim-(j+14),dim)]=src[RIDX(i+6,(j+14),dim)];
           dst[RIDX(i+7,dim-(j+14),dim)]=src[RIDX(i+7,(j+14),dim)];
           dst[RIDX(i+8,dim-(j+14),dim)]=src[RIDX(i+8,(j+14),dim)];
           dst[RIDX(i+9,dim-(j+14),dim)]=src[RIDX(i+9,(j+14),dim)];
           dst[RIDX(i+10,dim-(j+14),dim)]=src[RIDX(i+10,(j+14),dim)];
           dst[RIDX(i+11,dim-(j+14),dim)]=src[RIDX(i+11,(j+14),dim)];
           dst[RIDX(i+12,dim-(j+14),dim)]=src[RIDX(i+12,(j+14),dim)];
           dst[RIDX(i+13,dim-(j+14),dim)]=src[RIDX(i+13,(j+14),dim)];
           dst[RIDX(i+14,dim-(j+14),dim)]=src[RIDX(i+14,(j+14),dim)];
           dst[RIDX(i+15,dim-(j+14),dim)]=src[RIDX(i+15,(j+14),dim)];

           dst[RIDX(i,dim-(j+15),dim)]=src[RIDX(i,(j+15),dim)];
           dst[RIDX(i+1,dim-(j+15),dim)]=src[RIDX(i+1,(j+15),dim)];
           dst[RIDX(i+2,dim-(j+15),dim)]=src[RIDX(i+2,(j+15),dim)];
           dst[RIDX(i+3,dim-(j+15),dim)]=src[RIDX(i+3,(j+15),dim)];
           dst[RIDX(i+4,dim-(j+15),dim)]=src[RIDX(i+4,(j+15),dim)];
           dst[RIDX(i+5,dim-(j+15),dim)]=src[RIDX(i+5,(j+15),dim)];
           dst[RIDX(i+6,dim-(j+15),dim)]=src[RIDX(i+6,(j+15),dim)];
           dst[RIDX(i+7,dim-(j+15),dim)]=src[RIDX(i+7,(j+15),dim)];
           dst[RIDX(i+8,dim-(j+15),dim)]=src[RIDX(i+8,(j+15),dim)];
           dst[RIDX(i+9,dim-(j+15),dim)]=src[RIDX(i+9,(j+15),dim)];
           dst[RIDX(i+10,dim-(j+15),dim)]=src[RIDX(i+10,(j+15),dim)];
           dst[RIDX(i+11,dim-(j+15),dim)]=src[RIDX(i+11,(j+15),dim)];
           dst[RIDX(i+12,dim-(j+15),dim)]=src[RIDX(i+12,(j+15),dim)];
           dst[RIDX(i+13,dim-(j+15),dim)]=src[RIDX(i+13,(j+15),dim)];
           dst[RIDX(i+14,dim-(j+15),dim)]=src[RIDX(i+14,(j+15),dim)];
           dst[RIDX(i+15,dim-(j+15),dim)]=src[RIDX(i+15,(j+15),dim)];

       }
}

char mirror4_descr[]= "mirror4 with 16 blocking";
void mirror4(int dim,int *src,int *dst){
	int i, j, k, l;
	int div = 16;
    for (i = 0; i < dim; i += div) {
        for (j = 0; j < dim; j += div) {
			      for (k = i; k < i + div; k++) {
				       for (l = j; l < j + div; l++) {
                  //dst[RIDX(i,dim-j,dim)]=src[RIDX(i,j,dim)];
                  dst[RIDX(l,dim-k,dim)]=src[RIDX(l,k,dim)];

                  //dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
					        //dst[RIDX(k, l, dim)] = src[RIDX(l, dim - 1 - k, dim)];
				       }
			      }
        }
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
  mirror3(dim,src,dst);

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
}
