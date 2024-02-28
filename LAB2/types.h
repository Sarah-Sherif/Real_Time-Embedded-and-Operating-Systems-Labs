#ifndef _TYPES_H_
#define _TYPES_H_


//Types
typedef unsigned char			        boolean;
typedef signed char				int8;
typedef unsigned char			        uint8;
typedef signed short			        int16;
typedef unsigned short			        uint16;
typedef signed long				int32;
typedef unsigned long			        uint32;
typedef signed long long		        int64;
typedef unsigned long long		        uint64;
typedef float					float32;
typedef double 					float64;

//Volatiles
typedef volatile int8	    	                vint8;
typedef volatile uint8		                vuint8;
typedef volatile int16		                vint16;
typedef volatile uint16		                vuint16;
typedef volatile int32	                	vint32;
typedef volatile uint32		                vuint32;
typedef volatile int64		                vint64;
typedef volatile uint64		                vuint64;
typedef volatile float32		        vfloat32;
typedef volatile float64		        vfloat64;


//Pointers 
typedef  int8*  	    	                int8_ptr;
typedef  uint8* 		                uint8_ptr;
typedef  int16* 		                int16_ptr;
typedef  uint16*		                uint16_ptr;
typedef  int32* 		                int32_ptr;
typedef  uint32*		                uint32_ptr;
typedef  int64* 		                int64_ptr;
typedef  uint64*		                uint64_ptr;
typedef  float32*     		                float32_ptr;
typedef  float64*	    	                float64_ptr;

//Volatiles Pointers
typedef  vint8*  	    	                vint8_ptr;
typedef  vuint8* 		                vuint8_ptr;
typedef  vint16* 		                vint16_ptr;
typedef  vuint16*		                vuint16_ptr;
typedef  vint32* 		                vint32_ptr;
typedef  vuint32*		                vuint32_ptr;
typedef  vint64* 		                vint64_ptr;
typedef  vuint64*		                vuint64_ptr;
typedef  vfloat32*     		                vfloat32_ptr;
typedef  vfloat64*	    	                vfloat64_ptr;

#endif