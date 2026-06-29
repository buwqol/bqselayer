#ifndef BQSELAYER_QUAT_H
#define BQSELAYER_QUAT_H
#include "PrimTypes.h"
typedef union { struct { tFP32 real; tFP32 i, j, k; }; tFP32 comp[4U]; } tFP32Quat;
LINK_C_Begin
ForceInline tFP32Quat tFP32Quat_Make(tFP32 real, tFP32 i, tFP32 j, tFP32 k);
ForceInline tFP32 tFP32Quat_MagSq(tFP32Quat quat);
ForceInline tFP32 tFP32Quat_Mag_iter(tFP32Quat quat, tIUSz itr);
ForceInline tFP32 tFP32Quat_Mag(tFP32Quat quat);
LINK_C_End
#ifdef BQSELAYER_QUAT_IMPL
ForceInline tFP32Quat tFP32Quat_Make(tFP32 real, tFP32 i, tFP32 j, tFP32 k)
{
	tFP32Quat quat;
	quat.real = real;
	quat.i = i;
	quat.j = j;
	quat.k = k;
	return quat;
}
ForceInline tFP32 tFP32Quat_MagSq(tFP32Quat quat)
{
	return tFP32_Sq(quat.real) + tFP32_Sq(quat.i) + tFP32_Sq(quat.j) + tFP32_Sq(quat.k);
}
ForceInline tFP32 tFP32Quat_Mag_iter(tFP32Quat quat, tIUSz itr)
{
	return tFP32_Sqrt_iter(tFP32Quat_MagSq(quat), itr);
}
ForceInline tFP32 tFP32Quat_Mag(tFP32Quat quat)
{
	return tFP32_Sqrt(tFP32Quat_MagSq(quat));
}
#endif/*BQSELAYER_QUAT_IMPL*/
#endif/*BQSELAYER_QUAT_H*/