#ifndef __optpfd__zxczxcr__
#define __optpfd__zxczxcr__

#include "stdio.h"
#include  <iostream>
#include "pfor.h"
#include "S16.h"

#define BS 64
#define FRAC 0.10
#define S 16
#define PCHUNK 64
#define EXTRAGAP 1
#define pfdBlock = 64

// S16 header
void s16_encode(unsigned int **_w, unsigned int **_p, unsigned int m)
{
    int cnum[16] = {28, 21, 21, 21, 14, 9, 8, 7, 6, 6, 5, 5, 4, 3, 2, 1};
    int cbits[16][28] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,0,0,0,0,0,0,0},
        {2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {4,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {3,4,4,4,4,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {5,5,5,5,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {4,4,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {6,6,6,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {5,5,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {10,9,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {14,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {28,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
    
    unsigned int _k, _j, _m, _o;
    
    for (_k = 0; _k < 16; _k++)
    {
        (**_w) = _k<<28;
        _m = (cnum[_k] < m)? cnum[_k]:m;
        for (_j = 0, _o = 0; (_j < _m) && (*((*_p)+_j) < (1<<cbits[_k][_j])); )
        {
            (**_w) += ((*((*_p)+_j))<<_o);
            _o += cbits[_k][_j];
            _j++;
        }
        if (_j == _m)
        {
            (*_p) += _m;
            (*_w)++;
            break;
        }
    }
}


/* more optimized handcoded edition */

#define S16_DECODE(_w, _p)	\
{ \
_k = (*_w)>>28; \
switch(_k) \
{ \
case 0: \
*_p = (*_w) & 1;     _p++; \
*_p = (*_w>>1) & 1;  _p++; \
*_p = (*_w>>2) & 1;  _p++; \
*_p = (*_w>>3) & 1;  _p++; \
*_p = (*_w>>4) & 1;  _p++; \
*_p = (*_w>>5) & 1;  _p++; \
*_p = (*_w>>6) & 1;  _p++; \
*_p = (*_w>>7) & 1;  _p++; \
*_p = (*_w>>8) & 1;  _p++; \
*_p = (*_w>>9) & 1;  _p++; \
*_p = (*_w>>10) & 1;  _p++; \
*_p = (*_w>>11) & 1;  _p++; \
*_p = (*_w>>12) & 1;  _p++; \
*_p = (*_w>>13) & 1;  _p++; \
*_p = (*_w>>14) & 1;  _p++; \
*_p = (*_w>>15) & 1;  _p++; \
*_p = (*_w>>16) & 1;  _p++; \
*_p = (*_w>>17) & 1;  _p++; \
*_p = (*_w>>18) & 1;  _p++; \
*_p = (*_w>>19) & 1;  _p++; \
*_p = (*_w>>20) & 1;  _p++; \
*_p = (*_w>>21) & 1;  _p++; \
*_p = (*_w>>22) & 1;  _p++; \
*_p = (*_w>>23) & 1;  _p++; \
*_p = (*_w>>24) & 1;  _p++; \
*_p = (*_w>>25) & 1;  _p++; \
*_p = (*_w>>26) & 1;  _p++; \
*_p = (*_w>>27) & 1;  _p++; \
break; \
case 1: \
*_p = (*_w) & 3;     _p++; \
*_p = (*_w>>2) & 3;  _p++; \
*_p = (*_w>>4) & 3;  _p++; \
*_p = (*_w>>6) & 3;  _p++; \
*_p = (*_w>>8) & 3;  _p++; \
*_p = (*_w>>10) & 3;  _p++; \
*_p = (*_w>>12) & 3;  _p++; \
*_p = (*_w>>14) & 1;  _p++; \
*_p = (*_w>>15) & 1;  _p++; \
*_p = (*_w>>16) & 1;  _p++; \
*_p = (*_w>>17) & 1;  _p++; \
*_p = (*_w>>18) & 1;  _p++; \
*_p = (*_w>>19) & 1;  _p++; \
*_p = (*_w>>20) & 1;  _p++; \
*_p = (*_w>>21) & 1;  _p++; \
*_p = (*_w>>22) & 1;  _p++; \
*_p = (*_w>>23) & 1;  _p++; \
*_p = (*_w>>24) & 1;  _p++; \
*_p = (*_w>>25) & 1;  _p++; \
*_p = (*_w>>26) & 1;  _p++; \
*_p = (*_w>>27) & 1;  _p++; \
break; \
case 2: \
*_p = (*_w) & 1;     _p++; \
*_p = (*_w>>1) & 1;  _p++; \
*_p = (*_w>>2) & 1;  _p++; \
*_p = (*_w>>3) & 1;  _p++; \
*_p = (*_w>>4) & 1;  _p++; \
*_p = (*_w>>5) & 1;  _p++; \
*_p = (*_w>>6) & 1;  _p++; \
*_p = (*_w>>7) & 3;  _p++; \
*_p = (*_w>>9) & 3;  _p++; \
*_p = (*_w>>11) & 3;  _p++; \
*_p = (*_w>>13) & 3;  _p++; \
*_p = (*_w>>15) & 3;  _p++; \
*_p = (*_w>>17) & 3;  _p++; \
*_p = (*_w>>19) & 3;  _p++; \
*_p = (*_w>>21) & 1;  _p++; \
*_p = (*_w>>22) & 1;  _p++; \
*_p = (*_w>>23) & 1;  _p++; \
*_p = (*_w>>24) & 1;  _p++; \
*_p = (*_w>>25) & 1;  _p++; \
*_p = (*_w>>26) & 1;  _p++; \
*_p = (*_w>>27) & 1;  _p++; \
break; \
case 3: \
*_p = (*_w) & 1;     _p++; \
*_p = (*_w>>1) & 1;  _p++; \
*_p = (*_w>>2) & 1;  _p++; \
*_p = (*_w>>3) & 1;  _p++; \
*_p = (*_w>>4) & 1;  _p++; \
*_p = (*_w>>5) & 1;  _p++; \
*_p = (*_w>>6) & 1;  _p++; \
*_p = (*_w>>7) & 1;  _p++; \
*_p = (*_w>>8) & 1;  _p++; \
*_p = (*_w>>9) & 1;  _p++; \
*_p = (*_w>>10) & 1;  _p++; \
*_p = (*_w>>11) & 1;  _p++; \
*_p = (*_w>>12) & 1;  _p++; \
*_p = (*_w>>13) & 1;  _p++; \
*_p = (*_w>>14) & 3;  _p++; \
*_p = (*_w>>16) & 3;  _p++; \
*_p = (*_w>>18) & 3;  _p++; \
*_p = (*_w>>20) & 3;  _p++; \
*_p = (*_w>>22) & 3;  _p++; \
*_p = (*_w>>24) & 3;  _p++; \
*_p = (*_w>>26) & 3;  _p++; \
break; \
case 4: \
*_p = (*_w) & 3;     _p++; \
*_p = (*_w>>2) & 3;  _p++; \
*_p = (*_w>>4) & 3;  _p++; \
*_p = (*_w>>6) & 3;  _p++; \
*_p = (*_w>>8) & 3;  _p++; \
*_p = (*_w>>10) & 3;  _p++; \
*_p = (*_w>>12) & 3;  _p++; \
*_p = (*_w>>14) & 3;  _p++; \
*_p = (*_w>>16) & 3;  _p++; \
*_p = (*_w>>18) & 3;  _p++; \
*_p = (*_w>>20) & 3;  _p++; \
*_p = (*_w>>22) & 3;  _p++; \
*_p = (*_w>>24) & 3;  _p++; \
*_p = (*_w>>26) & 3;  _p++; \
break; \
case 5: \
*_p = (*_w) & 15;     _p++; \
*_p = (*_w>>4) & 7;  _p++; \
*_p = (*_w>>7) & 7;  _p++; \
*_p = (*_w>>10) & 7;  _p++; \
*_p = (*_w>>13) & 7;  _p++; \
*_p = (*_w>>16) & 7;  _p++; \
*_p = (*_w>>19) & 7;  _p++; \
*_p = (*_w>>22) & 7;  _p++; \
*_p = (*_w>>25) & 7;  _p++; \
break; \
case 6: \
*_p = (*_w) & 7;     _p++; \
*_p = (*_w>>3) & 15;  _p++; \
*_p = (*_w>>7) & 15;  _p++; \
*_p = (*_w>>11) & 15;  _p++; \
*_p = (*_w>>15) & 15;  _p++; \
*_p = (*_w>>19) & 7;  _p++; \
*_p = (*_w>>22) & 7;  _p++; \
*_p = (*_w>>25) & 7;  _p++; \
break; \
case 7: \
*_p = (*_w) & 15;     _p++; \
*_p = (*_w>>4) & 15;  _p++; \
*_p = (*_w>>8) & 15;  _p++; \
*_p = (*_w>>12) & 15;  _p++; \
*_p = (*_w>>16) & 15;  _p++; \
*_p = (*_w>>20) & 15;  _p++; \
*_p = (*_w>>24) & 15;  _p++; \
break; \
case 8: \
*_p = (*_w) & 31;     _p++; \
*_p = (*_w>>5) & 31;  _p++; \
*_p = (*_w>>10) & 31;  _p++; \
*_p = (*_w>>15) & 31;  _p++; \
*_p = (*_w>>20) & 15;  _p++; \
*_p = (*_w>>24) & 15;  _p++; \
break; \
case 9: \
*_p = (*_w) & 15;     _p++; \
*_p = (*_w>>4) & 15;  _p++; \
*_p = (*_w>>8) & 31;  _p++; \
*_p = (*_w>>13) & 31;  _p++; \
*_p = (*_w>>18) & 31;  _p++; \
*_p = (*_w>>23) & 31;  _p++; \
break; \
case 10: \
*_p = (*_w) & 63;     _p++; \
*_p = (*_w>>6) & 63;  _p++; \
*_p = (*_w>>12) & 63;  _p++; \
*_p = (*_w>>18) & 31;  _p++; \
*_p = (*_w>>23) & 31;  _p++; \
break; \
case 11: \
*_p = (*_w) & 31;     _p++; \
*_p = (*_w>>5) & 31;  _p++; \
*_p = (*_w>>10) & 63;  _p++; \
*_p = (*_w>>16) & 63;  _p++; \
*_p = (*_w>>22) & 63;  _p++; \
break; \
case 12: \
*_p = (*_w) & 127;     _p++; \
*_p = (*_w>>7) & 127;  _p++; \
*_p = (*_w>>14) & 127;  _p++; \
*_p = (*_w>>21) & 127;  _p++; \
break; \
case 13: \
*_p = (*_w) & 1023;     _p++; \
*_p = (*_w>>10) & 511;  _p++; \
*_p = (*_w>>19) & 511;  _p++; \
break; \
case 14: \
*_p = (*_w) & 16383;     _p++; \
*_p = (*_w>>14) & 16383;  _p++; \
break; \
case 15: \
*_p = (*_w) & ((1<<28)-1);     _p++; \
break; \
}\
_w++; \
}

// END OF S16

// START OF UNPACK


/*************************************************************/
/* macros for fast unpacking of integers of fixed bit length */
/*************************************************************/
/*
 void unpack0(unsigned int *p, unsigned int *w)
 {
 int i;
 for (i = 0; i < BS; i += 32, p += 32) {
 p[0] = 0;
 p[1] = 0;
 p[2] = 0;
 p[3] = 0;
 p[4] = 0;
 p[5] = 0;
 p[6] = 0;
 p[7] = 0;
 p[8] = 0;
 p[9] = 0;
 p[10] = 0;
 
 p[11] = 0;
 p[12] = 0;
 p[13] = 0;
 p[14] = 0;
 p[15] = 0;
 p[16] = 0;
 p[17] = 0;
 p[18] = 0;
 p[19] = 0;
 p[20] = 0;
 
 p[21] = 0;
 p[22] = 0;
 p[23] = 0;
 p[24] = 0;
 p[25] = 0;
 p[26] = 0;
 p[27] = 0;
 p[28] = 0;
 p[29] = 0;
 p[30] = 0;
 p[31] = 0;
 }
 }
 */

/*** old unpack0
 void unpack0(unsigned int *p, unsigned int *w)
 {
 int i;
 
 for (i = 0; i < BS; i++)  p[i] = 0;
 }
 ***/

// END OF UNPACK

void pack(unsigned int *v, unsigned int b, unsigned int n, unsigned int *w);

int detailed_p4_encode(unsigned int **w, unsigned int* p, int num, int &flag)
{
    std::cout << num << " ";
    int i, j, s;
    flag = 0;
    unsigned int b = cnum[num];
    //	int bb_e;
    //	int bb_p;
    int p_low;
    unsigned int e_n = 0;
    //	int max_p = 0;
    //	int max_e = 0;
    
    
    unsigned int* out = (unsigned*)malloc(sizeof(unsigned)*PCHUNK*2);
    unsigned int* ex = (unsigned*)malloc(sizeof(unsigned)*PCHUNK*2);
    unsigned int* po = (unsigned*)malloc(sizeof(unsigned)*PCHUNK*2);
    unsigned int *_pp, *_ww;
    
    if (b == 32)
    {
        flag = (num << 10) + 0;
        for (i = 0; i < PCHUNK ; i++)  (*w)[i] = p[i];
        *w += (PCHUNK);
        
        free(out);
        free(ex);
        free(po);
        return 0;
    }
    if(num == 0)
    std::cout << num << "1 ";
    for (i = 0; i < PCHUNK ; i++)
    {
        if ( p[i] >= (1<<b) )		//exception
        {
            p_low = p[i] & ((1<<b)-1);
            out[i] = p_low;
            ex[e_n] = (p[i] >> b);
            po[(e_n++)] = i;               //
        }
        else
            out[i] = p[i];
    }
    if(num == 0)
        std::cout << num << "2 ";
    
    //std::cout << "in4" << std::endl;
#if (EXTRAGAP==1)
    /*get the gap of position*/
    for(j = e_n - 1;j > 0;j--)
    {
        po[j] = po[j] - po[j-1] ;
        po[j] --;
    }
#endif
    if(num == 0)
        std::cout << num << "3 ";

    if (true) {
        
        s = ((b * PCHUNK)>>5);
        flag = ((num<<10)) + e_n;
        
        for (i = 0; i < s; i++)  (*w)[i] = 0;
        pack(out, b, PCHUNK , *w);
        *w += s;
        
        unsigned int *all_array = (unsigned*)malloc(sizeof(unsigned) * PCHUNK * 4) ;
        for(j=0; j < e_n; j++) {
            all_array[2*j] = po[j];
            all_array[2*j + 1] =ex[j];
        }
        for (_pp = all_array, _ww = (*w); _pp < &(all_array[2*e_n]); ) {
            int tmp = S16::compress(_pp,  &(all_array[2*e_n]) - _pp, _ww);
            _pp += tmp;
        }

        (*w) += (_ww - (*w));
        free(ex);
        
        free(po);
        
        free(all_array);
        
        return (e_n);
    }
    
}


void p4_encode_wrap(unsigned int **desbuf, unsigned int* docid, int &flag) {
    int f = 0;
    unsigned int *_w = (*desbuf);
    int minsize = BS * 8;
    int bestb = 0;
    int excn = 0;
    int bestexcn;
    for (int i = 0; i < 17; i++) {
        unsigned int *tempbuf = _w;
        excn = detailed_p4_encode(&tempbuf, docid, i, f);
        int size = (unsigned char *)tempbuf - (unsigned char *)_w;
        if (size < minsize) {
            minsize = size;
            bestb = i;
            bestexcn = excn;
        }
    }

    detailed_p4_encode(desbuf, docid, bestb, f);
    flag = f;
}

unsigned int OPTPFDCompressDocids(unsigned int * docids, unsigned int* comp,  int length) {
    int tmplen = (length / 64) * 64;
    std::cout << tmplen << "\n";
    // pointer to buffer, dids vector
    unsigned int* tmp = comp;
    int didsFlag = 0;
    
    // for each block in padded list length compress block of dids
    for (size_t i = 0; i < tmplen; i += 64) { // pfdblock must equal BS
        p4_encode_wrap( &comp, docids + i, didsFlag );
        //
        std::cout << *(docids + i) << " ";
    }
    
    //  cout << " after !@#!" << endl;
    // compute the total compressed size in bytes
    int size = ((unsigned int *)(comp)) - ((unsigned int *)(tmp));
    
    
    //  cout << " after !@#123!: sz" << size << endl;
    return (unsigned int) size;
}



/*modified p4decode */
unsigned int* detailed_p4_decode(unsigned int *_p, unsigned int *_w,  unsigned int *all_array, int flag)
{
    int i;//, s;
    //  unsigned int x;
    
    unsigned int *_ww,*_pp;
    
    // get b and e_n
    unsigned int b = cnum[((flag >> 10) & 31)];
    unsigned int e_n = (flag & 1023);
    
    (unpack[((flag >> 10) & 31)])(_p, _w);
    _w += ((b * BS)>>5);
    unsigned int _k = 0;
    unsigned int psum = 0;
    if(e_n != 0)
    {
        for (_pp = all_array, _ww = (unsigned int *)(_w); _pp < &(all_array[e_n*2]);)
        {
            S16_DECODE(_ww, _pp);
        }
        _w += (_ww - _w);
#if (EXTRAGAP==1)
        psum = all_array[0];
        for(i = 0; i < e_n; i++)
        {
            _p[psum] += (all_array[(i<<1) + 1]<<b);
            psum += all_array[(i + 1)<<1] + 1;
        }
#else
        for(i = 0; i < e_n; i++)
        {
            psum = all_array[(i<<1)];
            _p[psum] += (all_array[(i<<1)+1]<<b);
        }
#endif
    }
    return(_w);
}



#endif 