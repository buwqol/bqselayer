#ifndef BQSELAYER_MTRX_H
#define BQSELAYER_MTRX_H
#include "PrimTypes.h"
#include "Vect.h"
typedef union { struct { tFP32 m00, m01; tFP32 m10, m11; }; tFP32 m[2][2]; tFP32V2D row[2]; } tFP32M2x2;
LINK_C_Begin
tFP32M2x2 tFP32M2x2_Make(tFP32 m00, tFP32 m01, tFP32 m10, tFP32 m11);
tFP32M2x2 tFP32M2x2_Zero(tNone);
tFP32M2x2 tFP32M2x2_Id(tNone);
tFP32M2x2 tFP32M2x2_Add(tFP32M2x2 mtrx1, tFP32M2x2 mtrx2);
tFP32M2x2 tFP32M2x2_Sub(tFP32M2x2 mtrx1, tFP32M2x2 mtrx2);
tFP32M2x2 tFP32M2x2_Mul(tFP32M2x2 mtrx1, tFP32M2x2 mtrx2);
tFP32M2x2 tFP32M2x2_MulFlt(tFP32M2x2 mtrx, tFP32 mod);
/*Warn: Silently returns a matrix with all components either -Inf or +Inf when `mod` is 0.*/
tFP32M2x2 tFP32M2x2_DivFlt(tFP32M2x2 mtrx, tFP32 mod);
/*Note: Returns `False` on success.*/
tBln tFP32M2x2_DivFlt_safe(tFP32M2x2 *mtrx, tFP32 mod);
tBln tFP32M2x2_IsEq(tFP32M2x2 mtrx1, tFP32M2x2 mtrx2);
tBln tFP32M2x2_IsNearby(tFP32M2x2 mtrx1, tFP32M2x2 mtrx2, tFP32 eps);
tFP32V2D tFP32M2x2_MulVect(tFP32M2x2 mtrx, tFP32V2D vect);
tFP32M2x2 tFP32M2x2_Transp(tFP32M2x2 mtrx);
tFP32 tFP32M2x2_Det(tFP32M2x2 mtrx);
tFP32M2x2 tFP32M2x2_Cofact(tFP32M2x2 mtrx);
tFP32M2x2 tFP32M2x2_Adj(tFP32M2x2 mtrx);
/*Warn: Silently returns `tFP32M2x2_Zero` on failure.*/
tFP32M2x2 tFP32M2x2_Inv(tFP32M2x2 mtrx);
/*Note: Returns `False` on success.*/
tBln tFP32M2x2_Inv_safe(tFP32M2x2 *mtrx);
/*Note: Parameter `ang` is in radians.*/
tFP32M2x2 tFP32M2x2_Rot_fast(tFP32 ang);
tFP32M2x2 tFP32M2x2_Rot_iter(tFP32 ang, tIUSz itr);
tFP32M2x2 tFP32M2x2_Rot(tFP32 ang);
tFP32M2x2 tFP32M2x2_Scale(tFP32 x, tFP32 y);
tFP32 tFP32M2x2_Trace(tFP32M2x2 mtrx);
tNone tFP32M2x2_RowSwap(tFP32M2x2 *mtrx);
tNone tFP32M2x2_RowAdd(tFP32M2x2 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP32 mult);
tNone tFP32M2x2_RowMult(tFP32M2x2 *mtrx, tIU8 idx, tFP32 mult);
tNone tFP32M2x2_RowEch(tFP32M2x2 *mtrx);
tNone tFP32M2x2_RowRedEch(tFP32M2x2 *mtrx);
tFP32M2x2 tFP32M2x2_InvAff(tFP32M2x2 mtrx);
ForceInline tBln tFP32M2x2_IsAff(tFP32M2x2 mtrx);
LINK_C_End
#ifdef BQSELAYER_MTRX_IMPL
tFP32M2x2 tFP32M2x2_Make(tFP32 m00, tFP32 m01, tFP32 m10, tFP32 m11)
{
	tFP32M2x2 mtrx;
	mtrx.m00 = m00;
	mtrx.m01 = m01;
	mtrx.m10 = m10;
	mtrx.m11 = m11;
	return mtrx;
}
tFP32M2x2 tFP32M2x2_Zero(tNone)
{
	tFP32M2x2 mtrx;
	mtrx.m00 = 0.0F;
	mtrx.m01 = 0.0F;
	mtrx.m10 = 0.0F;
	mtrx.m11 = 0.0F;
	return mtrx;
}
tFP32M2x2 tFP32M2x2_Id(tNone)
{
	tFP32M2x2 mtrx;
	mtrx.m00 = 1.0F;
	mtrx.m01 = 0.0F;
	mtrx.m10 = 0.0F;
	mtrx.m11 = 1.0F;
	return mtrx;
}
tFP32M2x2 tFP32M2x2_Add(tFP32M2x2 mtrx1, tFP32M2x2 mtrx2)
{
	mtrx1.m00 += mtrx2.m00;
	mtrx1.m01 += mtrx2.m01;
	mtrx1.m10 += mtrx2.m10;
	mtrx1.m11 += mtrx2.m11;
	return mtrx1;
}
tFP32M2x2 tFP32M2x2_Sub(tFP32M2x2 mtrx1, tFP32M2x2 mtrx2)
{
	mtrx1.m00 -= mtrx2.m00;
	mtrx1.m01 -= mtrx2.m01;
	mtrx1.m10 -= mtrx2.m10;
	mtrx1.m11 -= mtrx2.m11;
	return mtrx1;
}
tFP32M2x2 tFP32M2x2_Mul(tFP32M2x2 mtrx1, tFP32M2x2 mtrx2)
{
	tFP32M2x2 mtrx;
	mtrx.m00 = mtrx1.m00 * mtrx2.m00 + mtrx1.m01 * mtrx2.m10;
	mtrx.m01 = mtrx1.m00 * mtrx2.m01 + mtrx1.m01 * mtrx2.m11;
	mtrx.m10 = mtrx1.m10 * mtrx2.m00 + mtrx1.m11 * mtrx2.m10;
	mtrx.m11 = mtrx1.m10 * mtrx2.m01 + mtrx1.m11 * mtrx2.m11;
	return mtrx;
}
tFP32M2x2 tFP32M2x2_MulFlt(tFP32M2x2 mtrx, tFP32 mod)
{
	mtrx.m00 *= mod;
	mtrx.m01 *= mod;
	mtrx.m10 *= mod;
	mtrx.m11 *= mod;
	return mtrx;
}
tFP32M2x2 tFP32M2x2_DivFlt(tFP32M2x2 mtrx, tFP32 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNearby(mod, 0.0F))
	{
		mtrx.m00 = tFP32_IsNeg(mtrx.m00) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m01 = tFP32_IsNeg(mtrx.m01) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m10 = tFP32_IsNeg(mtrx.m10) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m11 = tFP32_IsNeg(mtrx.m11) ? tFP32_NegInf() : tFP32_Inf();
		return mtrx;
	}
#else
	Assertion(!tFP32_IsNearby(mod, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	mtrx.m00 /= mod;
	mtrx.m01 /= mod;
	mtrx.m10 /= mod;
	mtrx.m11 /= mod;
	return mtrx;
}
tBln tFP32M2x2_DivFlt_safe(tFP32M2x2 *mtrx, tFP32 mod)
{
	if (tFP32_IsNearby(mod, 0.0F)) return True;
	mtrx->m00 /= mod;
	mtrx->m01 /= mod;
	mtrx->m10 /= mod;
	mtrx->m11 /= mod;
	return False;
}
tBln tFP32M2x2_IsEq(tFP32M2x2 mtrx1, tFP32M2x2 mtrx2)
{
	return tFP32_IsNearby(mtrx1.m00, mtrx2.m00) && tFP32_IsNearby(mtrx1.m01, mtrx2.m01) && tFP32_IsNearby(mtrx1.m10, mtrx2.m10) && tFP32_IsNearby(mtrx1.m11, mtrx2.m11);
}
tBln tFP32M2x2_IsNearby(tFP32M2x2 mtrx1, tFP32M2x2 mtrx2, tFP32 eps)
{
	return (tFP32_Abs(mtrx1.m00 - mtrx2.m00) <= eps) && (tFP32_Abs(mtrx1.m01 - mtrx2.m01) <= eps) && (tFP32_Abs(mtrx1.m10 - mtrx2.m10) <= eps) && (tFP32_Abs(mtrx1.m11 - mtrx2.m11) <= eps);
}
tFP32V2D tFP32M2x2_MulVect(tFP32M2x2 mtrx, tFP32V2D vect)
{
	tFP32V2D res;
	res.x = mtrx.m00 * vect.x + mtrx.m01 * vect.y;
	res.y = mtrx.m10 * vect.x + mtrx.m11 * vect.y;
	return res;
}
tFP32M2x2 tFP32M2x2_Transp(tFP32M2x2 mtrx)
{
	tFP32 tmp = mtrx.m01;
	mtrx.m01 = mtrx.m10;
	mtrx.m10 = tmp;
	return mtrx;
}
tFP32 tFP32M2x2_Det(tFP32M2x2 mtrx)
{
	return (mtrx.m00 * mtrx.m11) - (mtrx.m01 * mtrx.m10);
}
tFP32M2x2 tFP32M2x2_Cofact(tFP32M2x2 mtrx)
{
	tFP32 tmp = mtrx.m00;
	mtrx.m00 = mtrx.m11;
	mtrx.m11 = tmp;
	mtrx.m01 = tFP32_Neg(mtrx.m10);
	mtrx.m10 = tFP32_Neg(mtrx.m01);
	return mtrx;
}
tFP32M2x2 tFP32M2x2_Adj(tFP32M2x2 mtrx)
{
	tFP32 tmp = mtrx.m00;
	mtrx.m00 = mtrx.m11;
	mtrx.m11 = tmp;
	mtrx.m01 = tFP32_Neg(mtrx.m01);
	mtrx.m10 = tFP32_Neg(mtrx.m10);
	return mtrx;
}
tFP32M2x2 tFP32M2x2_Inv(tFP32M2x2 mtrx)
{
	tFP32 det = tFP32M2x2_Det(mtrx);
#ifndef BQSELAYER_DEBUG
	if (tFP32_Abs(det) <= tFP32_Eps) return tFP32M2x2_Zero();
#else
	Assertion(tFP32_Abs(det) > tFP32_Eps);
#endif/*BQSELAYER_DEBUG*/
	return tFP32M2x2_DivFlt(tFP32M2x2_Adj(mtrx), det);
}
tBln tFP32M2x2_Inv_safe(tFP32M2x2 *mtrx)
{
	tFP32 det = tFP32M2x2_Det(*mtrx);
	if (tFP32_Abs(det) <= tFP32_Eps) return True;
	*mtrx = tFP32M2x2_DivFlt(tFP32M2x2_Adj(*mtrx), det);
	return False;
}
tFP32M2x2 tFP32M2x2_Rot_fast(tFP32 ang)
{
	tFP32M2x2 mtrx;
	mtrx.m00 = mtrx.m11 = tFP32_Cosine_fast(ang);
	mtrx.m10 = tFP32_Sine_fast(ang);
	mtrx.m01 = tFP32_Neg(mtrx.m10);
	return mtrx;
}
tFP32M2x2 tFP32M2x2_Rot_iter(tFP32 ang, tIUSz itr)
{
	tFP32M2x2 mtrx;
	mtrx.m00 = mtrx.m11 = tFP32_Cosine_iter(ang, itr);
	mtrx.m10 = tFP32_Sine_iter(ang, itr);
	mtrx.m01 = tFP32_Neg(mtrx.m10);
	return mtrx;
}
tFP32M2x2 tFP32M2x2_Rot(tFP32 ang)
{
	tFP32M2x2 mtrx;
	mtrx.m00 = mtrx.m11 = tFP32_Cosine(ang);
	mtrx.m10 = tFP32_Sine(ang);
	mtrx.m01 = tFP32_Neg(mtrx.m10);
	return mtrx;
}
tFP32M2x2 tFP32M2x2_Scale(tFP32 x, tFP32 y)
{
	tFP32M2x2 mtrx;
	mtrx.m00 = x;
	mtrx.m11 = y;
	mtrx.m01 = mtrx.m10 = 0.0F;
	return mtrx;
}
tFP32 tFP32M2x2_Trace(tFP32M2x2 mtrx)
{
	return mtrx.m00 + mtrx.m11;
}
tNone tFP32M2x2_RowSwap(tFP32M2x2 *mtrx)
{
	tFP32_Swap(&mtrx->m00, &mtrx->m10);
	tFP32_Swap(&mtrx->m01, &mtrx->m11);
}
tNone tFP32M2x2_RowAdd(tFP32M2x2 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP32 mult)
{
	mtrx->m[dstRow][0] += mtrx->m[srcRow][0] * mult;
	mtrx->m[dstRow][1] += mtrx->m[srcRow][1] * mult;
}
tNone tFP32M2x2_RowMult(tFP32M2x2 *mtrx, tIU8 idx, tFP32 mult)
{
	mtrx->m[idx][0] *= mult;
	mtrx->m[idx][1] *= mult;
}
tNone tFP32M2x2_RowEch(tFP32M2x2 *mtrx)
{
	tIU8 pivotRow = 0U;
	for (tIU8 col = 0U; col < 2U; ++col)
	{
		if (pivotRow >= 2U) break;
		tBln foundPivot = False;
		if (!tFP32_IsNearby(mtrx->m[pivotRow][col], 0.0F)) foundPivot = True;
		else
		{
			for (tIU8 idx = 1U; idx < 2U - pivotRow; ++idx)
			{
				if (!tFP32_IsNearby(mtrx->m[pivotRow + idx][col], 0.0F))
				{
					tFP32M2x2_RowSwap(mtrx);
					foundPivot = True;
					break;
				}
			}
			if (foundPivot == False) continue;
		}
		tFP32M2x2_RowMult(mtrx, pivotRow, tFP32_Recip(mtrx->m[pivotRow][col]));
		for (tIU8 idx = 1U; idx < 2U - pivotRow; ++idx) tFP32M2x2_RowAdd(mtrx, pivotRow + idx, pivotRow, tFP32_Neg(mtrx->m[pivotRow + idx][col]));
		++pivotRow;
	}
}
tNone tFP32M2x2_RowRedEch(tFP32M2x2 *mtrx)
{
	tFP32M2x2_RowEch(mtrx);
	tIU8 pivotRow = 1U;
	for (tIU8 col = pivotRow; col > 0U; --col)
	{
		if (pivotRow == 0U) break;
		for (tIU8 idx = 0U; idx < pivotRow; ++idx) tFP32M2x2_RowAdd(mtrx, idx, pivotRow, tFP32_Neg(mtrx->m[idx][col]));
		--pivotRow;
	}
}
tFP32M2x2 tFP32M2x2_InvAff(tFP32M2x2 mtrx)
{
	if (!tFP32M2x2_IsAff(mtrx)) return tFP32M2x2_Zero();
	tFP32 invA = tFP32_Recip(mtrx.m00);
	tFP32M2x2 out;
	out.m00 = invA;
	out.m01 = -mtrx.m01 * invA;
	out.m10 = 0.0F;
	out.m11 = 1.0F;
	return out;
}
ForceInline tBln tFP32M2x2_IsAff(tFP32M2x2 mtrx)
{
	return tFP32_IsNearby(mtrx.m10, 0.0F) && tFP32_IsNearby(mtrx.m11, 0.0F);
}
#endif/*BQSELAYER_MTRX_IMPL*/
typedef union { struct { tFP32 m00, m01, m02; tFP32 m10, m11, m12; tFP32 m20, m21, m22; }; tFP32 m[3][3]; tFP32V3D row[3]; } tFP32M3x3;
LINK_C_Begin
tFP32M3x3 tFP32M3x3_Make(tFP32 m00, tFP32 m01, tFP32 m02, tFP32 m10, tFP32 m11, tFP32 m12, tFP32 m20, tFP32 m21, tFP32 m22);
tFP32M3x3 tFP32M3x3_Zero(tNone);
tFP32M3x3 tFP32M3x3_Id(tNone);
tFP32M3x3 tFP32M3x3_Add(tFP32M3x3 mtrx1, tFP32M3x3 mtrx2);
tFP32M3x3 tFP32M3x3_Sub(tFP32M3x3 mtrx1, tFP32M3x3 mtrx2);
tFP32M3x3 tFP32M3x3_Mul(tFP32M3x3 mtrx1, tFP32M3x3 mtrx2);
tFP32M3x3 tFP32M3x3_MulFlt(tFP32M3x3 mtrx, tFP32 mod);
/*Warn: Silently returns a matrix with all components either -Inf or +Inf when `mod` is 0.*/
tFP32M3x3 tFP32M3x3_DivFlt(tFP32M3x3 mtrx, tFP32 mod);
/*Note: Returns `False` on success.*/
tBln tFP32M3x3_DivFlt_safe(tFP32M3x3 *mtrx, tFP32 mod);
tBln tFP32M3x3_IsEq(tFP32M3x3 mtrx1, tFP32M3x3 mtrx2);
tBln tFP32M3x3_IsNearby(tFP32M3x3 mtrx1, tFP32M3x3 mtrx2, tFP32 eps);
tFP32V3D tFP32M3x3_MulVect(tFP32M3x3 mtrx, tFP32V3D vect);
tFP32M3x3 tFP32M3x3_Transp(tFP32M3x3 mtrx);
tFP32 tFP32M3x3_Det(tFP32M3x3 mtrx);
tFP32M3x3 tFP32M3x3_Cofact(tFP32M3x3 mtrx);
tFP32M3x3 tFP32M3x3_Adj(tFP32M3x3 mtrx);
/*Warn: Silently returns `tFP32M3x3_Zero` on failure.*/
tFP32M3x3 tFP32M3x3_Inv(tFP32M3x3 mtrx);
/*Note: Returns `False` on success.*/
tBln tFP32M3x3_Inv_safe(tFP32M3x3 *mtrx);
tFP32M3x3 tFP32M3x3_Transl(tFP32 x, tFP32 y);
tFP32M3x3 tFP32M3x3_Scale(tFP32 x, tFP32 y);
/*Note: Parameter `ang` is in radians.*/
tFP32M3x3 tFP32M3x3_Rot_fast(tFP32 ang);
tFP32M3x3 tFP32M3x3_Rot_iter(tFP32 ang, tIUSz itr);
tFP32M3x3 tFP32M3x3_Rot(tFP32 ang);
tFP32 tFP32M3x3_Trace(tFP32M3x3 mtrx);
tFP32V2D tFP32M3x3_TransfPoint(tFP32M3x3 mtrx, tFP32V2D vect);
tFP32V2D tFP32M3x3_TransfDir(tFP32M3x3 mtrx, tFP32V2D vect);
tNone tFP32M3x3_RowSwap(tFP32M3x3 *mtrx, tIU8 idx1, tIU8 idx2);
tNone tFP32M3x3_RowAdd(tFP32M3x3 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP32 mult);
tNone tFP32M3x3_RowMult(tFP32M3x3 *mtrx, tIU8 idx, tFP32 mult);
tNone tFP32M3x3_RowEch(tFP32M3x3 *mtrx);
tNone tFP32M3x3_RowRedEch(tFP32M3x3 *mtrx);
tFP32M3x3 tFP32M3x3_InvAff(tFP32M3x3 mtrx);
ForceInline tBln tFP32M3x3_IsAff(tFP32M3x3 mtrx);
LINK_C_End
#ifdef BQSELAYER_MTRX_IMPL
tFP32M3x3 tFP32M3x3_Make(tFP32 m00, tFP32 m01, tFP32 m02, tFP32 m10, tFP32 m11, tFP32 m12, tFP32 m20, tFP32 m21, tFP32 m22)
{
	tFP32M3x3 mtrx;
	mtrx.m00 = m00;
	mtrx.m01 = m01;
	mtrx.m02 = m02;
	mtrx.m10 = m10;
	mtrx.m11 = m11;
	mtrx.m12 = m12;
	mtrx.m20 = m20;
	mtrx.m21 = m21;
	mtrx.m22 = m22;
	return mtrx;
}
tFP32M3x3 tFP32M3x3_Zero(tNone)
{
	tFP32M3x3 mtrx;
	mtrx.m00 = mtrx.m01 = mtrx.m02 = mtrx.m10 = mtrx.m11 = mtrx.m12 = mtrx.m20 = mtrx.m21 = mtrx.m22 = 0.0F;
	return mtrx;
}
tFP32M3x3 tFP32M3x3_Id(tNone)
{
	tFP32M3x3 mtrx;
	mtrx.m01 = mtrx.m02 = mtrx.m10 = mtrx.m12 = mtrx.m20 = mtrx.m21 = 0.0F;
	mtrx.m00 = mtrx.m11 = mtrx.m22 = 1.0F;
	return mtrx;
}
tFP32M3x3 tFP32M3x3_Add(tFP32M3x3 mtrx1, tFP32M3x3 mtrx2)
{
	mtrx1.m00 += mtrx2.m00;
	mtrx1.m01 += mtrx2.m01;
	mtrx1.m02 += mtrx2.m02;
	mtrx1.m10 += mtrx2.m10;
	mtrx1.m11 += mtrx2.m11;
	mtrx1.m12 += mtrx2.m12;
	mtrx1.m20 += mtrx2.m20;
	mtrx1.m21 += mtrx2.m21;
	mtrx1.m22 += mtrx2.m22;
	return mtrx1;
}
tFP32M3x3 tFP32M3x3_Sub(tFP32M3x3 mtrx1, tFP32M3x3 mtrx2)
{
	mtrx1.m00 -= mtrx2.m00;
	mtrx1.m01 -= mtrx2.m01;
	mtrx1.m02 -= mtrx2.m02;
	mtrx1.m10 -= mtrx2.m10;
	mtrx1.m11 -= mtrx2.m11;
	mtrx1.m12 -= mtrx2.m12;
	mtrx1.m20 -= mtrx2.m20;
	mtrx1.m21 -= mtrx2.m21;
	mtrx1.m22 -= mtrx2.m22;
	return mtrx1;
}
tFP32M3x3 tFP32M3x3_Mul(tFP32M3x3 mtrx1, tFP32M3x3 mtrx2)
{
	tFP32M3x3 res;
	res.m00 = (mtrx1.m00 * mtrx2.m00) + (mtrx1.m01 * mtrx2.m10) + (mtrx1.m02 * mtrx2.m20);
	res.m01 = (mtrx1.m00 * mtrx2.m01) + (mtrx1.m01 * mtrx2.m11) + (mtrx1.m02 * mtrx2.m21);
	res.m02 = (mtrx1.m00 * mtrx2.m02) + (mtrx1.m01 * mtrx2.m12) + (mtrx1.m02 * mtrx2.m22);
	res.m10 = (mtrx1.m10 * mtrx2.m00) + (mtrx1.m11 * mtrx2.m10) + (mtrx1.m12 * mtrx2.m20);
	res.m11 = (mtrx1.m10 * mtrx2.m01) + (mtrx1.m11 * mtrx2.m11) + (mtrx1.m12 * mtrx2.m21);
	res.m12 = (mtrx1.m10 * mtrx2.m02) + (mtrx1.m11 * mtrx2.m12) + (mtrx1.m12 * mtrx2.m22);
	res.m20 = (mtrx1.m20 * mtrx2.m00) + (mtrx1.m21 * mtrx2.m10) + (mtrx1.m22 * mtrx2.m20);
	res.m21 = (mtrx1.m20 * mtrx2.m01) + (mtrx1.m21 * mtrx2.m11) + (mtrx1.m22 * mtrx2.m21);
	res.m22 = (mtrx1.m20 * mtrx2.m02) + (mtrx1.m21 * mtrx2.m12) + (mtrx1.m22 * mtrx2.m22);
	return res;
}
tFP32M3x3 tFP32M3x3_MulFlt(tFP32M3x3 mtrx, tFP32 mod)
{
	mtrx.m00 *= mod;
	mtrx.m01 *= mod;
	mtrx.m02 *= mod;
	mtrx.m10 *= mod;
	mtrx.m11 *= mod;
	mtrx.m12 *= mod;
	mtrx.m20 *= mod;
	mtrx.m21 *= mod;
	mtrx.m22 *= mod;
	return mtrx;
}
tFP32M3x3 tFP32M3x3_DivFlt(tFP32M3x3 mtrx, tFP32 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNearby(mod, 0.0F))
	{
		mtrx.m00 = tFP32_IsNeg(mtrx.m00) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m01 = tFP32_IsNeg(mtrx.m01) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m02 = tFP32_IsNeg(mtrx.m02) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m10 = tFP32_IsNeg(mtrx.m10) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m11 = tFP32_IsNeg(mtrx.m11) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m12 = tFP32_IsNeg(mtrx.m12) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m20 = tFP32_IsNeg(mtrx.m20) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m21 = tFP32_IsNeg(mtrx.m21) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m22 = tFP32_IsNeg(mtrx.m22) ? tFP32_NegInf() : tFP32_Inf();
		return mtrx;
	}
#else
	Assertion(!tFP32_IsNearby(mod, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	mtrx.m00 /= mod;
	mtrx.m01 /= mod;
	mtrx.m02 /= mod;
	mtrx.m10 /= mod;
	mtrx.m11 /= mod;
	mtrx.m12 /= mod;
	mtrx.m20 /= mod;
	mtrx.m21 /= mod;
	mtrx.m22 /= mod;
	return mtrx;
}
tBln tFP32M3x3_DivFlt_safe(tFP32M3x3 *mtrx, tFP32 mod)
{
	if (tFP32_IsNearby(mod, 0.0F)) return True;
	mtrx->m00 /= mod;
	mtrx->m01 /= mod;
	mtrx->m02 /= mod;
	mtrx->m10 /= mod;
	mtrx->m11 /= mod;
	mtrx->m12 /= mod;
	mtrx->m20 /= mod;
	mtrx->m21 /= mod;
	mtrx->m22 /= mod;
	return False;
}
tBln tFP32M3x3_IsEq(tFP32M3x3 mtrx1, tFP32M3x3 mtrx2)
{
	return tFP32_IsNearby(mtrx1.m00, mtrx2.m00) && tFP32_IsNearby(mtrx1.m01, mtrx2.m01) && tFP32_IsNearby(mtrx1.m02, mtrx2.m02) && tFP32_IsNearby(mtrx1.m10, mtrx2.m10) && tFP32_IsNearby(mtrx1.m11, mtrx2.m11) && tFP32_IsNearby(mtrx1.m12, mtrx2.m12) && tFP32_IsNearby(mtrx1.m20, mtrx2.m20) && tFP32_IsNearby(mtrx1.m21, mtrx2.m21) && tFP32_IsNearby(mtrx1.m22, mtrx2.m22);
}
tBln tFP32M3x3_IsNearby(tFP32M3x3 mtrx1, tFP32M3x3 mtrx2, tFP32 eps)
{
	return (tFP32_Abs(mtrx1.m00 - mtrx2.m00) <= eps) && (tFP32_Abs(mtrx1.m01 - mtrx2.m01) <= eps) && (tFP32_Abs(mtrx1.m02 - mtrx2.m02) <= eps) && (tFP32_Abs(mtrx1.m10 - mtrx2.m10) <= eps) && (tFP32_Abs(mtrx1.m11 - mtrx2.m11) <= eps) && (tFP32_Abs(mtrx1.m12 - mtrx2.m12) <= eps) && (tFP32_Abs(mtrx1.m20 - mtrx2.m20) <= eps) && (tFP32_Abs(mtrx1.m21 - mtrx2.m21) <= eps) && (tFP32_Abs(mtrx1.m22 - mtrx2.m22) <= eps);
}
tFP32V3D tFP32M3x3_MulVect(tFP32M3x3 mtrx, tFP32V3D vect)
{
	tFP32V3D res;
	res.x = (mtrx.m00 * vect.x) + (mtrx.m01 * vect.y) + (mtrx.m02 * vect.z);
	res.y = (mtrx.m10 * vect.x) + (mtrx.m11 * vect.y) + (mtrx.m12 * vect.z);
	res.z = (mtrx.m20 * vect.x) + (mtrx.m21 * vect.y) + (mtrx.m22 * vect.z);
	return res;
}
tFP32M3x3 tFP32M3x3_Transp(tFP32M3x3 mtrx)
{
	tFP32 tmp = mtrx.m01;
	mtrx.m01 = mtrx.m10;
	mtrx.m10 = tmp;
	tmp = mtrx.m02;
	mtrx.m02 = mtrx.m20;
	mtrx.m20 = tmp;
	tmp = mtrx.m12;
	mtrx.m12 = mtrx.m21;
	mtrx.m21 = tmp;
	return mtrx;
}
tFP32 tFP32M3x3_Det(tFP32M3x3 mtrx)
{
	return (mtrx.m00 * ((mtrx.m11 * mtrx.m22) - (mtrx.m12 * mtrx.m21))) - (mtrx.m01 * ((mtrx.m10 * mtrx.m22) - (mtrx.m12 * mtrx.m20))) + (mtrx.m02 * ((mtrx.m10 * mtrx.m21) - (mtrx.m11 * mtrx.m20)));
}
tFP32M3x3 tFP32M3x3_Cofact(tFP32M3x3 mtrx)
{
	tFP32M3x3 cof;
	cof.m00 = mtrx.m11 * mtrx.m22 - mtrx.m12 * mtrx.m21;
	cof.m01 = tFP32_Neg(mtrx.m10 * mtrx.m22 - mtrx.m12 * mtrx.m20);
	cof.m02 = mtrx.m10 * mtrx.m21 - mtrx.m11 * mtrx.m20;
	cof.m10 = tFP32_Neg(mtrx.m01 * mtrx.m22 - mtrx.m02 * mtrx.m21);
	cof.m11 = mtrx.m00 * mtrx.m22 - mtrx.m02 * mtrx.m20;
	cof.m12 = tFP32_Neg(mtrx.m00 * mtrx.m21 - mtrx.m01 * mtrx.m20);
	cof.m20 = mtrx.m01 * mtrx.m12 - mtrx.m02 * mtrx.m11;
	cof.m21 = tFP32_Neg(mtrx.m00 * mtrx.m12 - mtrx.m02 * mtrx.m10);
	cof.m22 = mtrx.m00 * mtrx.m11 - mtrx.m01 * mtrx.m10;
	return cof;
}
tFP32M3x3 tFP32M3x3_Adj(tFP32M3x3 mtrx)
{
	return tFP32M3x3_Transp(tFP32M3x3_Cofact(mtrx));
}
tFP32M3x3 tFP32M3x3_Inv(tFP32M3x3 mtrx)
{
	tFP32 det = tFP32M3x3_Det(mtrx);
#ifndef BQSELAYER_DEBUG
	if (tFP32_Abs(det) <= tFP32_Eps) return tFP32M3x3_Zero();
#else
	Assertion(tFP32_Abs(det) > tFP32_Eps);
#endif/*BQSELAYER_DEBUG*/
	return tFP32M3x3_DivFlt(tFP32M3x3_Adj(mtrx), det);
}
tBln tFP32M3x3_Inv_safe(tFP32M3x3 *mtrx)
{
	tFP32 det = tFP32M3x3_Det(*mtrx);
	if (tFP32_Abs(det) <= tFP32_Eps) return True;
	*mtrx = tFP32M3x3_DivFlt(tFP32M3x3_Adj(*mtrx), det);
	return False;
}
tFP32M3x3 tFP32M3x3_Transl(tFP32 x, tFP32 y)
{
	tFP32M3x3 mtrx = tFP32M3x3_Id();
	mtrx.m02 = x;
	mtrx.m12 = y;
	return mtrx;
}
tFP32M3x3 tFP32M3x3_Scale(tFP32 x, tFP32 y)
{
	tFP32M3x3 mtrx = tFP32M3x3_Id();
	mtrx.m00 = x;
	mtrx.m11 = y;
	return mtrx;
}
tFP32M3x3 tFP32M3x3_Rot_fast(tFP32 ang)
{
	tFP32M3x3 mtrx = tFP32M3x3_Id();
	mtrx.m00 = mtrx.m11 = tFP32_Cosine_fast(ang);
	mtrx.m10 = tFP32_Sine_fast(ang);
	mtrx.m01 = tFP32_Neg(mtrx.m10);
	return mtrx;
}
tFP32M3x3 tFP32M3x3_Rot_iter(tFP32 ang, tIUSz itr)
{
	tFP32M3x3 mtrx = tFP32M3x3_Id();
	mtrx.m00 = mtrx.m11 = tFP32_Cosine_iter(ang, itr);
	mtrx.m10 = tFP32_Sine_iter(ang, itr);
	mtrx.m01 = tFP32_Neg(mtrx.m10);
	return mtrx;
}
tFP32M3x3 tFP32M3x3_Rot(tFP32 ang)
{
	tFP32M3x3 mtrx = tFP32M3x3_Id();
	mtrx.m00 = mtrx.m11 = tFP32_Cosine(ang);
	mtrx.m10 = tFP32_Sine(ang);
	mtrx.m01 = tFP32_Neg(mtrx.m10);
	return mtrx;
}
tFP32 tFP32M3x3_Trace(tFP32M3x3 mtrx)
{
	return mtrx.m00 + mtrx.m11 + mtrx.m22;
}
tFP32V2D tFP32M3x3_TransfPoint(tFP32M3x3 mtrx, tFP32V2D vect)
{
	tFP32V2D res;
	res.x = mtrx.m00 * vect.x + mtrx.m01 * vect.y + mtrx.m02;
	res.y = mtrx.m10 * vect.x + mtrx.m11 * vect.y + mtrx.m12;
	return res;
}
tFP32V2D tFP32M3x3_TransfDir(tFP32M3x3 mtrx, tFP32V2D vect)
{
	tFP32V2D res;
	res.x = mtrx.m00 * vect.x + mtrx.m01 * vect.y;
	res.y = mtrx.m10 * vect.x + mtrx.m11 * vect.y;
	return res;
}
tNone tFP32M3x3_RowSwap(tFP32M3x3 *mtrx, tIU8 idx1, tIU8 idx2)
{
	tFP32_Swap(&mtrx->m[idx1][0], &mtrx->m[idx2][0]);
	tFP32_Swap(&mtrx->m[idx1][1], &mtrx->m[idx2][1]);
	tFP32_Swap(&mtrx->m[idx1][2], &mtrx->m[idx2][2]);
}
tNone tFP32M3x3_RowAdd(tFP32M3x3 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP32 mult)
{
	mtrx->m[dstRow][0] += mtrx->m[srcRow][0] * mult;
	mtrx->m[dstRow][1] += mtrx->m[srcRow][1] * mult;
	mtrx->m[dstRow][2] += mtrx->m[srcRow][2] * mult;
}
tNone tFP32M3x3_RowMult(tFP32M3x3 *mtrx, tIU8 idx, tFP32 mult)
{
	mtrx->m[idx][0] *= mult;
	mtrx->m[idx][1] *= mult;
	mtrx->m[idx][2] *= mult;
}
tNone tFP32M3x3_RowEch(tFP32M3x3 *mtrx)
{
	tIU8 pivotRow = 0U;
	for (tIU8 col = 0U; col < 3U; ++col)
	{
		if (pivotRow >= 3U) break;
		tBln foundPivot = False;
		if (!tFP32_IsNearby(mtrx->m[pivotRow][col], 0.0F)) foundPivot = True;
		else
		{
			for (tIU8 idx = 1U; idx < 3U - pivotRow; ++idx)
			{
				if (!tFP32_IsNearby(mtrx->m[pivotRow + idx][col], 0.0F))
				{
					tFP32M3x3_RowSwap(mtrx, pivotRow, pivotRow + idx);
					foundPivot = True;
					break;
				}
			}
			if (foundPivot == False) continue;
		}
		tFP32M3x3_RowMult(mtrx, pivotRow, tFP32_Recip(mtrx->m[pivotRow][col]));
		for (tIU8 idx = 1U; idx < 3U - pivotRow; ++idx) tFP32M3x3_RowAdd(mtrx, pivotRow + idx, pivotRow, tFP32_Neg(mtrx->m[pivotRow + idx][col]));
		++pivotRow;
	}
}
tNone tFP32M3x3_RowRedEch(tFP32M3x3 *mtrx)
{
	tFP32M3x3_RowEch(mtrx);
	for (tIS8 row = 2; row >= 0; --row)
	{
		tBln foundPivot = False;
		tIU8 pivotCol = 0;
		for (tIU8 col = 0U; col < 3; ++col)
		{
			if (!tFP32_IsNearby(mtrx->m[row][col], 0.0F))
			{
				foundPivot = True;
				pivotCol = col;
				break;
			}
		}
		if (foundPivot == False) continue;
		for (tIU8 aboveRow = 0U; aboveRow < row; ++aboveRow) tFP32M3x3_RowAdd(mtrx, aboveRow, row, tFP32_Neg(mtrx->m[aboveRow][pivotCol]));
	}
}
tFP32M3x3 tFP32M3x3_InvAff(tFP32M3x3 mtrx)
{
	if (!tFP32M3x3_IsAff(mtrx)) return tFP32M3x3_Zero();
	tFP32 det = mtrx.m00 * mtrx.m11 - mtrx.m01 * mtrx.m10;
	tFP32 invDet = tFP32_Recip(det);
	tFP32M3x3 out;
	out.m00 = mtrx.m11 * invDet;
	out.m01 = tFP32_Neg(mtrx.m01 * invDet);
	out.m10 = tFP32_Neg(mtrx.m10 * invDet);
	out.m11 = mtrx.m00 * invDet;
	out.m02 = tFP32_Neg(out.m00 * mtrx.m02 + out.m01 * mtrx.m12);
	out.m12 = tFP32_Neg(out.m10 * mtrx.m02 + out.m11 * mtrx.m12);
	out.m20 = 0.0F;
	out.m21 = 0.0F;
	out.m22 = 1.0F;
	return out;
}
ForceInline tBln tFP32M3x3_IsAff(tFP32M3x3 mtrx)
{
	return tFP32_IsNearby(mtrx.m20, 0.0F) && tFP32_IsNearby(mtrx.m21, 0.0F) && tFP32_IsNearby(mtrx.m22, 0.0F);
}
#endif/*BQSELAYER_MTRX_IMPL*/
typedef union { struct { tFP32 m00, m01, m02, m03; tFP32 m10, m11, m12, m13; tFP32 m20, m21, m22, m23; tFP32 m30, m31, m32, m33; }; tFP32 m[4][4]; tFP32V4D row[4]; } tFP32M4x4;
LINK_C_Begin
tFP32M4x4 tFP32M4x4_Make(tFP32 m00, tFP32 m01, tFP32 m02, tFP32 m03, tFP32 m10, tFP32 m11, tFP32 m12, tFP32 m13, tFP32 m20, tFP32 m21, tFP32 m22, tFP32 m23, tFP32 m30, tFP32 m31, tFP32 m32, tFP32 m33);
tFP32M4x4 tFP32M4x4_Zero(tNone);
tFP32M4x4 tFP32M4x4_Id(tNone);
tFP32M4x4 tFP32M4x4_Add(tFP32M4x4 mtrx1, tFP32M4x4 mtrx2);
tFP32M4x4 tFP32M4x4_Sub(tFP32M4x4 mtrx1, tFP32M4x4 mtrx2);
tFP32M4x4 tFP32M4x4_Mul(tFP32M4x4 mtrx1, tFP32M4x4 mtrx2);
tFP32M4x4 tFP32M4x4_MulFlt(tFP32M4x4 mtrx, tFP32 mod);
/*Warn: Silently returns a matrix with all components either -Inf or +Inf when `mod` is 0.*/
tFP32M4x4 tFP32M4x4_DivFlt(tFP32M4x4 mtrx, tFP32 mod);
/*Note: Returns `False` on success.*/
tBln tFP32M4x4_DivFlt_safe(tFP32M4x4 *mtrx, tFP32 mod);
tBln tFP32M4x4_IsEq(tFP32M4x4 mtrx1, tFP32M4x4 mtrx2);
tBln tFP32M4x4_IsNearby(tFP32M4x4 mtrx1, tFP32M4x4 mtrx2, tFP32 eps);
tFP32V4D tFP32M4x4_MulVect(tFP32M4x4 mtrx, tFP32V4D vect);
tFP32M4x4 tFP32M4x4_Transp(tFP32M4x4 mtrx);
tFP32 tFP32M4x4_Det(tFP32M4x4 mtrx);
/*Warn: Silently returns `tFP32M3x3_Zero` on failure.*/
tFP32M3x3 tFP32M4x4_Minor(tFP32M4x4 mtrx, tIU8 row, tIU8 col);
/*Note: Returns `False` on success.*/
tBln tFP32M4x4_Minor_s(tFP32M3x3 *out, tFP32M4x4 mtrx, tIU8 row, tIU8 col);
tFP32M4x4 tFP32M4x4_Cofact(tFP32M4x4 mtrx);
tFP32M4x4 tFP32M4x4_Adj(tFP32M4x4 mtrx);
/*Warn: Silently returns `tFP32M4x4_Zero` on failure.*/
tFP32M4x4 tFP32M4x4_Inv(tFP32M4x4 mtrx);
/*Note: Returns `False` on success.*/
tBln tFP32M4x4_Inv_safe(tFP32M4x4 *mtrx);
tFP32M4x4 tFP32M4x4_Transl(tFP32 x, tFP32 y, tFP32 z);
tFP32M4x4 tFP32M4x4_Scale(tFP32 x, tFP32 y, tFP32 z);
/*Note: Parameter `ang` is in radians.*/
tFP32M4x4 tFP32M4x4_RotX_fast(tFP32 ang);
/*Note: Parameter `ang` is in radians.*/
tFP32M4x4 tFP32M4x4_RotX_iter(tFP32 ang, tIUSz itr);
/*Note: Parameter `ang` is in radians.*/
tFP32M4x4 tFP32M4x4_RotX(tFP32 ang);
/*Note: Parameter `ang` is in radians.*/
tFP32M4x4 tFP32M4x4_RotY_fast(tFP32 ang);
/*Note: Parameter `ang` is in radians.*/
tFP32M4x4 tFP32M4x4_RotY_iter(tFP32 ang, tIUSz itr);
/*Note: Parameter `ang` is in radians.*/
tFP32M4x4 tFP32M4x4_RotY(tFP32 ang);
/*Note: Parameter `ang` is in radians.*/
tFP32M4x4 tFP32M4x4_RotZ_fast(tFP32 ang);
/*Note: Parameter `ang` is in radians.*/
tFP32M4x4 tFP32M4x4_RotZ_iter(tFP32 ang, tIUSz itr);
/*Note: Parameter `ang` is in radians.*/
tFP32M4x4 tFP32M4x4_RotZ(tFP32 ang);
tFP32M4x4 tFP32M4x4_Ortho(tFP32 left, tFP32 right, tFP32 bot, tFP32 top, tFP32 near, tFP32 far);
tFP32 tFP32M4x4_Trace(tFP32M4x4 mtrx);
/*Note: Parameter `ang` is in radians.*/
tFP32M4x4 tFP32M4x4_RotAxis_fast(tFP32V3D axis, tFP32 ang);
tFP32M4x4 tFP32M4x4_RotAxis_iter(tFP32V3D axis, tFP32 ang, tIUSz itr);
tFP32M4x4 tFP32M4x4_RotAxis(tFP32V3D axis, tFP32 ang);
tFP32V3D tFP32M4x4_TransfPoint(tFP32M4x4 mtrx, tFP32V3D vect);
tFP32V3D tFP32M4x4_TransfDir(tFP32M4x4 mtrx, tFP32V3D vect);
tNone tFP32M4x4_RowSwap(tFP32M4x4 *mtrx, tIU8 idx1, tIU8 idx2);
tNone tFP32M4x4_RowAdd(tFP32M4x4 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP32 mult);
tNone tFP32M4x4_RowMult(tFP32M4x4 *mtrx, tIU8 idx, tFP32 mult);
tNone tFP32M4x4_RowEch(tFP32M4x4 *mtrx);
tNone tFP32M4x4_RowRedEch(tFP32M4x4 *mtrx);
/*Warn: Returns `tFP32M4x4_Zero` if parameter `mtrx` is not an affine matrix.*/
tFP32M4x4 tFP32M4x4_InvAff(tFP32M4x4 mtrx);
tFP32M4x4 tFP32M4x4_Persp_fast(tFP32 fov, tFP32 aspRatio, tFP32 near, tFP32 far, tIS8 minZ);
tFP32M4x4 tFP32M4x4_Persp_iter(tFP32 fov, tFP32 aspRatio, tFP32 near, tFP32 far, tIS8 minZ, tIUSz itr);
tFP32M4x4 tFP32M4x4_Persp(tFP32 fov, tFP32 aspRatio, tFP32 near, tFP32 far, tIS8 minZ);
tBln tFP32M4x4_IsAff(tFP32M4x4 mtrx);
tFP32M4x4 tFP32M4x4_LookAt(tFP32V3D eye, tFP32V3D target, tFP32V3D up);
tFP32M3x3 tFP32M4x4_NormalMtrx(tFP32M4x4 mtrx);
LINK_C_End
#ifdef BQSELAYER_MTRX_IMPL
tFP32M4x4 tFP32M4x4_Make(tFP32 m00, tFP32 m01, tFP32 m02, tFP32 m03, tFP32 m10, tFP32 m11, tFP32 m12, tFP32 m13, tFP32 m20, tFP32 m21, tFP32 m22, tFP32 m23, tFP32 m30, tFP32 m31, tFP32 m32, tFP32 m33)
{
	tFP32M4x4 mtrx;
	mtrx.m00 = m00;
	mtrx.m01 = m01;
	mtrx.m02 = m02;
	mtrx.m03 = m03;
	mtrx.m10 = m10;
	mtrx.m11 = m11;
	mtrx.m12 = m12;
	mtrx.m13 = m13;
	mtrx.m20 = m20;
	mtrx.m21 = m21;
	mtrx.m22 = m22;
	mtrx.m23 = m23;
	mtrx.m30 = m30;
	mtrx.m31 = m31;
	mtrx.m32 = m32;
	mtrx.m33 = m33;
	return mtrx;
}
tFP32M4x4 tFP32M4x4_Zero(tNone)
{
	tFP32M4x4 mtrx;
	mtrx.m00 = mtrx.m01 = mtrx.m02 = mtrx.m03 = mtrx.m10 = mtrx.m11 = mtrx.m12 = mtrx.m13 = mtrx.m20 = mtrx.m21 = mtrx.m22 = mtrx.m23 = mtrx.m30 = mtrx.m31 = mtrx.m32 = mtrx.m33 = 0.0F;
	return mtrx;
}
tFP32M4x4 tFP32M4x4_Id(tNone)
{
	tFP32M4x4 mtrx;
	mtrx.m01 = mtrx.m02 = mtrx.m03 = mtrx.m10 = mtrx.m12 = mtrx.m13 = mtrx.m20 = mtrx.m21 = mtrx.m23 = mtrx.m30 = mtrx.m31 = mtrx.m32 = 0.0F;
	mtrx.m00 = mtrx.m11 = mtrx.m22 = mtrx.m33 = 1.0F;
	return mtrx;
}
tFP32M4x4 tFP32M4x4_Add(tFP32M4x4 mtrx1, tFP32M4x4 mtrx2)
{
	mtrx1.m00 += mtrx2.m00;
	mtrx1.m01 += mtrx2.m01;
	mtrx1.m02 += mtrx2.m02;
	mtrx1.m03 += mtrx2.m03;
	mtrx1.m10 += mtrx2.m10;
	mtrx1.m11 += mtrx2.m11;
	mtrx1.m12 += mtrx2.m12;
	mtrx1.m13 += mtrx2.m13;
	mtrx1.m20 += mtrx2.m20;
	mtrx1.m21 += mtrx2.m21;
	mtrx1.m22 += mtrx2.m22;
	mtrx1.m23 += mtrx2.m23;
	mtrx1.m30 += mtrx2.m30;
	mtrx1.m31 += mtrx2.m31;
	mtrx1.m32 += mtrx2.m32;
	mtrx1.m33 += mtrx2.m33;
	return mtrx1;
}
tFP32M4x4 tFP32M4x4_Sub(tFP32M4x4 mtrx1, tFP32M4x4 mtrx2)
{
	mtrx1.m00 -= mtrx2.m00;
	mtrx1.m01 -= mtrx2.m01;
	mtrx1.m02 -= mtrx2.m02;
	mtrx1.m03 -= mtrx2.m03;
	mtrx1.m10 -= mtrx2.m10;
	mtrx1.m11 -= mtrx2.m11;
	mtrx1.m12 -= mtrx2.m12;
	mtrx1.m13 -= mtrx2.m13;
	mtrx1.m20 -= mtrx2.m20;
	mtrx1.m21 -= mtrx2.m21;
	mtrx1.m22 -= mtrx2.m22;
	mtrx1.m23 -= mtrx2.m23;
	mtrx1.m30 -= mtrx2.m30;
	mtrx1.m31 -= mtrx2.m31;
	mtrx1.m32 -= mtrx2.m32;
	mtrx1.m33 -= mtrx2.m33;
	return mtrx1;
}
tFP32M4x4 tFP32M4x4_Mul(tFP32M4x4 mtrx1, tFP32M4x4 mtrx2)
{
	tFP32M4x4 res;
	res.m00 = (mtrx1.m00 * mtrx2.m00) + (mtrx1.m01 * mtrx2.m10) + (mtrx1.m02 * mtrx2.m20) + (mtrx1.m03 * mtrx2.m30);
	res.m01 = (mtrx1.m00 * mtrx2.m01) + (mtrx1.m01 * mtrx2.m11) + (mtrx1.m02 * mtrx2.m21) + (mtrx1.m03 * mtrx2.m31);
	res.m02 = (mtrx1.m00 * mtrx2.m02) + (mtrx1.m01 * mtrx2.m12) + (mtrx1.m02 * mtrx2.m22) + (mtrx1.m03 * mtrx2.m32);
	res.m03 = (mtrx1.m00 * mtrx2.m03) + (mtrx1.m01 * mtrx2.m13) + (mtrx1.m02 * mtrx2.m23) + (mtrx1.m03 * mtrx2.m33);
	res.m10 = (mtrx1.m10 * mtrx2.m00) + (mtrx1.m11 * mtrx2.m10) + (mtrx1.m12 * mtrx2.m20) + (mtrx1.m13 * mtrx2.m30);
	res.m11 = (mtrx1.m10 * mtrx2.m01) + (mtrx1.m11 * mtrx2.m11) + (mtrx1.m12 * mtrx2.m21) + (mtrx1.m13 * mtrx2.m31);
	res.m12 = (mtrx1.m10 * mtrx2.m02) + (mtrx1.m11 * mtrx2.m12) + (mtrx1.m12 * mtrx2.m22) + (mtrx1.m13 * mtrx2.m32);
	res.m13 = (mtrx1.m10 * mtrx2.m03) + (mtrx1.m11 * mtrx2.m13) + (mtrx1.m12 * mtrx2.m23) + (mtrx1.m13 * mtrx2.m33);
	res.m20 = (mtrx1.m20 * mtrx2.m00) + (mtrx1.m21 * mtrx2.m10) + (mtrx1.m22 * mtrx2.m20) + (mtrx1.m23 * mtrx2.m30);
	res.m21 = (mtrx1.m20 * mtrx2.m01) + (mtrx1.m21 * mtrx2.m11) + (mtrx1.m22 * mtrx2.m21) + (mtrx1.m23 * mtrx2.m31);
	res.m22 = (mtrx1.m20 * mtrx2.m02) + (mtrx1.m21 * mtrx2.m12) + (mtrx1.m22 * mtrx2.m22) + (mtrx1.m23 * mtrx2.m32);
	res.m23 = (mtrx1.m20 * mtrx2.m03) + (mtrx1.m21 * mtrx2.m13) + (mtrx1.m22 * mtrx2.m23) + (mtrx1.m23 * mtrx2.m33);
	res.m30 = (mtrx1.m30 * mtrx2.m00) + (mtrx1.m31 * mtrx2.m10) + (mtrx1.m32 * mtrx2.m20) + (mtrx1.m33 * mtrx2.m30);
	res.m31 = (mtrx1.m30 * mtrx2.m01) + (mtrx1.m31 * mtrx2.m11) + (mtrx1.m32 * mtrx2.m21) + (mtrx1.m33 * mtrx2.m31);
	res.m32 = (mtrx1.m30 * mtrx2.m02) + (mtrx1.m31 * mtrx2.m12) + (mtrx1.m32 * mtrx2.m22) + (mtrx1.m33 * mtrx2.m32);
	res.m33 = (mtrx1.m30 * mtrx2.m03) + (mtrx1.m31 * mtrx2.m13) + (mtrx1.m32 * mtrx2.m23) + (mtrx1.m33 * mtrx2.m33);
	return res;
}
tFP32M4x4 tFP32M4x4_MulFlt(tFP32M4x4 mtrx, tFP32 mod)
{
	mtrx.m00 *= mod;
	mtrx.m01 *= mod;
	mtrx.m02 *= mod;
	mtrx.m03 *= mod;
	mtrx.m10 *= mod;
	mtrx.m11 *= mod;
	mtrx.m12 *= mod;
	mtrx.m13 *= mod;
	mtrx.m20 *= mod;
	mtrx.m21 *= mod;
	mtrx.m22 *= mod;
	mtrx.m23 *= mod;
	mtrx.m30 *= mod;
	mtrx.m31 *= mod;
	mtrx.m32 *= mod;
	mtrx.m33 *= mod;
	return mtrx;
}
tFP32M4x4 tFP32M4x4_DivFlt(tFP32M4x4 mtrx, tFP32 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP32_IsNearby(mod, 0.0F))
	{
		mtrx.m00 = tFP32_IsNeg(mtrx.m00) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m01 = tFP32_IsNeg(mtrx.m01) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m02 = tFP32_IsNeg(mtrx.m02) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m03 = tFP32_IsNeg(mtrx.m03) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m10 = tFP32_IsNeg(mtrx.m10) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m11 = tFP32_IsNeg(mtrx.m11) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m12 = tFP32_IsNeg(mtrx.m12) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m13 = tFP32_IsNeg(mtrx.m13) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m20 = tFP32_IsNeg(mtrx.m20) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m21 = tFP32_IsNeg(mtrx.m21) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m22 = tFP32_IsNeg(mtrx.m22) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m23 = tFP32_IsNeg(mtrx.m23) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m30 = tFP32_IsNeg(mtrx.m30) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m31 = tFP32_IsNeg(mtrx.m31) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m32 = tFP32_IsNeg(mtrx.m32) ? tFP32_NegInf() : tFP32_Inf();
		mtrx.m33 = tFP32_IsNeg(mtrx.m33) ? tFP32_NegInf() : tFP32_Inf();
		return mtrx;
	}
#else
	Assertion(!tFP32_IsNearby(mod, 0.0F));
#endif/*BQSELAYER_DEBUG*/
	mtrx.m00 /= mod;
	mtrx.m01 /= mod;
	mtrx.m02 /= mod;
	mtrx.m03 /= mod;
	mtrx.m10 /= mod;
	mtrx.m11 /= mod;
	mtrx.m12 /= mod;
	mtrx.m13 /= mod;
	mtrx.m20 /= mod;
	mtrx.m21 /= mod;
	mtrx.m22 /= mod;
	mtrx.m23 /= mod;
	mtrx.m30 /= mod;
	mtrx.m31 /= mod;
	mtrx.m32 /= mod;
	mtrx.m33 /= mod;
	return mtrx;
}
tBln tFP32M4x4_DivFlt_safe(tFP32M4x4 *mtrx, tFP32 mod)
{
	if (tFP32_IsNearby(mod, 0.0F)) return True;
	mtrx->m00 /= mod;
	mtrx->m01 /= mod;
	mtrx->m02 /= mod;
	mtrx->m03 /= mod;
	mtrx->m10 /= mod;
	mtrx->m11 /= mod;
	mtrx->m12 /= mod;
	mtrx->m13 /= mod;
	mtrx->m20 /= mod;
	mtrx->m21 /= mod;
	mtrx->m22 /= mod;
	mtrx->m23 /= mod;
	mtrx->m30 /= mod;
	mtrx->m31 /= mod;
	mtrx->m32 /= mod;
	mtrx->m33 /= mod;
	return False;
}
tBln tFP32M4x4_IsEq(tFP32M4x4 mtrx1, tFP32M4x4 mtrx2)
{
	return tFP32_IsNearby(mtrx1.m00, mtrx2.m00) && tFP32_IsNearby(mtrx1.m01, mtrx2.m01) && tFP32_IsNearby(mtrx1.m02, mtrx2.m02) && tFP32_IsNearby(mtrx1.m03, mtrx2.m03) && tFP32_IsNearby(mtrx1.m10, mtrx2.m10) && tFP32_IsNearby(mtrx1.m11, mtrx2.m11) && tFP32_IsNearby(mtrx1.m12, mtrx2.m12) && tFP32_IsNearby(mtrx1.m13, mtrx2.m13) && tFP32_IsNearby(mtrx1.m20, mtrx2.m20) && tFP32_IsNearby(mtrx1.m21, mtrx2.m21) && tFP32_IsNearby(mtrx1.m22, mtrx2.m22) && tFP32_IsNearby(mtrx1.m23, mtrx2.m23) && tFP32_IsNearby(mtrx1.m30, mtrx2.m30) && tFP32_IsNearby(mtrx1.m31, mtrx2.m31) && tFP32_IsNearby(mtrx1.m32, mtrx2.m32) && tFP32_IsNearby(mtrx1.m33, mtrx2.m33);
}
tBln tFP32M4x4_IsNearby(tFP32M4x4 mtrx1, tFP32M4x4 mtrx2, tFP32 eps)
{
	return (tFP32_Abs(mtrx1.m00 - mtrx2.m00) <= eps) && (tFP32_Abs(mtrx1.m01 - mtrx2.m01) <= eps) && (tFP32_Abs(mtrx1.m02 - mtrx2.m02) <= eps) && (tFP32_Abs(mtrx1.m03 - mtrx2.m03) <= eps) && (tFP32_Abs(mtrx1.m10 - mtrx2.m10) <= eps) && (tFP32_Abs(mtrx1.m11 - mtrx2.m11) <= eps) && (tFP32_Abs(mtrx1.m12 - mtrx2.m12) <= eps) && (tFP32_Abs(mtrx1.m13 - mtrx2.m13) <= eps) && (tFP32_Abs(mtrx1.m20 - mtrx2.m20) <= eps) && (tFP32_Abs(mtrx1.m21 - mtrx2.m21) <= eps) && (tFP32_Abs(mtrx1.m22 - mtrx2.m22) <= eps) && (tFP32_Abs(mtrx1.m23 - mtrx2.m23) <= eps) && (tFP32_Abs(mtrx1.m30 - mtrx2.m30) <= eps) && (tFP32_Abs(mtrx1.m31 - mtrx2.m31) <= eps) && (tFP32_Abs(mtrx1.m32 - mtrx2.m32) <= eps) && (tFP32_Abs(mtrx1.m33 - mtrx2.m33) <= eps);
}
tFP32V4D tFP32M4x4_MulVect(tFP32M4x4 mtrx, tFP32V4D vect)
{
	tFP32V4D res;
	res.x = (mtrx.m00 * vect.x) + (mtrx.m01 * vect.y) + (mtrx.m02 * vect.z) + (mtrx.m03 * vect.w);
	res.y = (mtrx.m10 * vect.x) + (mtrx.m11 * vect.y) + (mtrx.m12 * vect.z) + (mtrx.m13 * vect.w);
	res.z = (mtrx.m20 * vect.x) + (mtrx.m21 * vect.y) + (mtrx.m22 * vect.z) + (mtrx.m23 * vect.w);
	res.w = (mtrx.m30 * vect.x) + (mtrx.m31 * vect.y) + (mtrx.m32 * vect.z) + (mtrx.m33 * vect.w);
	return res;
}
tFP32M4x4 tFP32M4x4_Transp(tFP32M4x4 mtrx)
{
	return tFP32M4x4_Make(mtrx.m00, mtrx.m10, mtrx.m20, mtrx.m30, mtrx.m01, mtrx.m11, mtrx.m21, mtrx.m31, mtrx.m02, mtrx.m12, mtrx.m22, mtrx.m32, mtrx.m03, mtrx.m13, mtrx.m23, mtrx.m33);
}
tFP32 tFP32M4x4_Det(tFP32M4x4 mtrx)
{
	return (mtrx.m00 * (tFP32M3x3_Det(tFP32M3x3_Make(mtrx.m11, mtrx.m12, mtrx.m13, mtrx.m21, mtrx.m22, mtrx.m23, mtrx.m31, mtrx.m32, mtrx.m33)))) - (mtrx.m01 * (tFP32M3x3_Det(tFP32M3x3_Make(mtrx.m10, mtrx.m12, mtrx.m13, mtrx.m20, mtrx.m22, mtrx.m23, mtrx.m30, mtrx.m32, mtrx.m33)))) + (mtrx.m02 * (tFP32M3x3_Det(tFP32M3x3_Make(mtrx.m10, mtrx.m11, mtrx.m13, mtrx.m20, mtrx.m21, mtrx.m23, mtrx.m30, mtrx.m31, mtrx.m33)))) - (mtrx.m03 * (tFP32M3x3_Det(tFP32M3x3_Make(mtrx.m10, mtrx.m11, mtrx.m12, mtrx.m20, mtrx.m21, mtrx.m22, mtrx.m30, mtrx.m31, mtrx.m32))));
}
tFP32M3x3 tFP32M4x4_Minor(tFP32M4x4 mtrx, tIU8 row, tIU8 col)
{
#ifndef BQSELAYER_DEBUG
	if (row >= 4U) return tFP32M3x3_Zero();
	if (col >= 4U) return tFP32M3x3_Zero();
#else
	Assertion(row < 4U);
	Assertion(col < 4U);
#endif/*BQSELAYER_DEBUG*/
	tFP32M3x3 minor;
	tIU8 offsetI = 0U;
	for (tIU8 idx = 0U; idx < 3U; ++idx)
	{
		if (idx == row) offsetI = 1U;
		tIU8 offsetJ = 0U;
		for (tIU8 jdx = 0U; jdx < 3U; ++jdx)
		{
			if (jdx == col) offsetJ = 1U;
			minor.m[idx][jdx] = mtrx.m[idx + offsetI][jdx + offsetJ];
		}
	}
	return minor;
}
tBln tFP32M4x4_Minor_s(tFP32M3x3 *out, tFP32M4x4 mtrx, tIU8 row, tIU8 col)
{
	if (row >= 4U) return True;
	if (col >= 4U) return True;
	tIU8 offsetI = 0U;
	for (tIU8 idx = 0U; idx < 3U; ++idx)
	{
		if (idx == row) offsetI = 1U;
		tIU8 offsetJ = 0U;
		for (tIU8 jdx = 0U; jdx < 3U; ++jdx)
		{
			if (jdx == col) offsetJ = 1U;
			out->m[idx][jdx] = mtrx.m[idx + offsetI][jdx + offsetJ];
		}
	}
	return False;
}
tFP32M4x4 tFP32M4x4_Cofact(tFP32M4x4 mtrx)
{
	tFP32M4x4 cof;
	for (tIU8 idx = 0U; idx < 4U; ++idx)
	{
		for (tIU8 jdx = 0U; jdx < 4U; ++jdx)
		{
			cof.m[idx][jdx] = tFP32M3x3_Det(tFP32M4x4_Minor(mtrx, idx, jdx));
			if ((idx + jdx) & 1U) cof.m[idx][jdx] = tFP32_Neg(cof.m[idx][jdx]);
		}
	}
	return cof;
}
tFP32M4x4 tFP32M4x4_Adj(tFP32M4x4 mtrx)
{
	return tFP32M4x4_Transp(tFP32M4x4_Cofact(mtrx));
}
tFP32M4x4 tFP32M4x4_Inv(tFP32M4x4 mtrx)
{
	tFP32 det = tFP32M4x4_Det(mtrx);
#ifndef BQSELAYER_DEBUG
	if (tFP32_Abs(det) <= tFP32_Eps) return tFP32M4x4_Zero();
#else
	Assertion(tFP32_Abs(det) > tFP32_Eps);
#endif/*BQSELAYER_DEBUG*/
	return tFP32M4x4_DivFlt(tFP32M4x4_Adj(mtrx), det);
}
tBln tFP32M4x4_Inv_safe(tFP32M4x4 *mtrx)
{
	tFP32 det = tFP32M4x4_Det(*mtrx);
	if (tFP32_Abs(det) <= tFP32_Eps) return True;
	*mtrx = tFP32M4x4_DivFlt(tFP32M4x4_Adj(*mtrx), det);
	return False;
}
tFP32M4x4 tFP32M4x4_Transl(tFP32 x, tFP32 y, tFP32 z)
{
	return tFP32M4x4_Make(1.0F, 0.0F, 0.0F, x, 0.0F, 1.0F, 0.0F, y, 0.0F, 0.0F, 1.0F, z, 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32M4x4 tFP32M4x4_Scale(tFP32 x, tFP32 y, tFP32 z)
{
	return tFP32M4x4_Make(x, 0.0F, 0.0F, 0.0F, 0.0F, y, 0.0F, 0.0F, 0.0F, 0.0F, z, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32M4x4 tFP32M4x4_RotX_fast(tFP32 ang)
{
	const tFP32 tmpC = tFP32_Cosine_fast(ang);
	const tFP32 tmpS = tFP32_Sine_fast(ang);
	return tFP32M4x4_Make(1.0F, 0.0F, 0.0F, 0.0F, 0.0F, tmpC, -tmpS, 0.0F, 0.0F, tmpS, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32M4x4 tFP32M4x4_RotX_iter(tFP32 ang, tIUSz itr)
{
	const tFP32 tmpC = tFP32_Cosine_iter(ang, itr);
	const tFP32 tmpS = tFP32_Sine_iter(ang, itr);
	return tFP32M4x4_Make(1.0F, 0.0F, 0.0F, 0.0F, 0.0F, tmpC, -tmpS, 0.0F, 0.0F, tmpS, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32M4x4 tFP32M4x4_RotX(tFP32 ang)
{
	const tFP32 tmpC = tFP32_Cosine(ang);
	const tFP32 tmpS = tFP32_Sine(ang);
	return tFP32M4x4_Make(1.0F, 0.0F, 0.0F, 0.0F, 0.0F, tmpC, -tmpS, 0.0F, 0.0F, tmpS, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32M4x4 tFP32M4x4_RotY_fast(tFP32 ang)
{
	tFP32 tmpC = tFP32_Cosine_fast(ang);
	tFP32 tmpS = tFP32_Sine_fast(ang);
	return tFP32M4x4_Make(tmpC, 0.0F, tmpS, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -tmpS, 0.0F, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32M4x4 tFP32M4x4_RotY_iter(tFP32 ang, tIUSz itr)
{
	tFP32 tmpC = tFP32_Cosine_iter(ang, itr);
	tFP32 tmpS = tFP32_Sine_iter(ang, itr);
	return tFP32M4x4_Make(tmpC, 0.0F, tmpS, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -tmpS, 0.0F, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32M4x4 tFP32M4x4_RotY(tFP32 ang)
{
	tFP32 tmpC = tFP32_Cosine(ang);
	tFP32 tmpS = tFP32_Sine(ang);
	return tFP32M4x4_Make(tmpC, 0.0F, tmpS, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -tmpS, 0.0F, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32M4x4 tFP32M4x4_RotZ_fast(tFP32 ang)
{
	tFP32 tmpC = tFP32_Cosine_fast(ang);
	tFP32 tmpS = tFP32_Sine_fast(ang);
	return tFP32M4x4_Make(tmpC, -tmpS, 0.0F, 0.0F, tmpS, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32M4x4 tFP32M4x4_RotZ_iter(tFP32 ang, tIUSz itr)
{
	tFP32 tmpC = tFP32_Cosine_iter(ang, itr);
	tFP32 tmpS = tFP32_Sine_iter(ang, itr);
	return tFP32M4x4_Make(tmpC, -tmpS, 0.0F, 0.0F, tmpS, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32M4x4 tFP32M4x4_RotZ(tFP32 ang)
{
	tFP32 tmpC = tFP32_Cosine(ang);
	tFP32 tmpS = tFP32_Sine(ang);
	return tFP32M4x4_Make(tmpC, -tmpS, 0.0F, 0.0F, tmpS, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32M4x4 tFP32M4x4_Ortho(tFP32 left, tFP32 right, tFP32 bot, tFP32 top, tFP32 near, tFP32 far)
{
	tFP32 tmpX = tFP32_Recip(right - left);
	tFP32 tmpY = tFP32_Recip(top - bot);
	tFP32 tmpZ = tFP32_Recip(far - near);
	return tFP32M4x4_Make(2.0F * tmpX, 0.0F, 0.0F, tFP32_Neg(right + left) * tmpX, 0.0F, 2.0F * tmpY, 0.0F, tFP32_Neg(top + bot) * tmpY, 0.0F, 0.0F, tmpZ, tFP32_Neg(near * tmpZ), 0.0F, 0.0F, 0.0F, 1.0F);
}
tFP32 tFP32M4x4_Trace(tFP32M4x4 mtrx)
{
	return mtrx.m00 + mtrx.m11 + mtrx.m22 + mtrx.m33;
}
tNone tFP32M4x4_RowSwap(tFP32M4x4 *mtrx, tIU8 idx1, tIU8 idx2)
{
	tFP32_Swap(&mtrx->m[idx1][0], &mtrx->m[idx2][0]);
	tFP32_Swap(&mtrx->m[idx1][1], &mtrx->m[idx2][1]);
	tFP32_Swap(&mtrx->m[idx1][2], &mtrx->m[idx2][2]);
	tFP32_Swap(&mtrx->m[idx1][3], &mtrx->m[idx2][3]);
}
tNone tFP32M4x4_RowAdd(tFP32M4x4 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP32 mult)
{
	mtrx->m[dstRow][0] += mtrx->m[srcRow][0] * mult;
	mtrx->m[dstRow][1] += mtrx->m[srcRow][1] * mult;
	mtrx->m[dstRow][2] += mtrx->m[srcRow][2] * mult;
	mtrx->m[dstRow][3] += mtrx->m[srcRow][3] * mult;
}
tNone tFP32M4x4_RowMult(tFP32M4x4 *mtrx, tIU8 idx, tFP32 mult)
{
	mtrx->m[idx][0] *= mult;
	mtrx->m[idx][1] *= mult;
	mtrx->m[idx][2] *= mult;
	mtrx->m[idx][3] *= mult;
}
tNone tFP32M4x4_RowEch(tFP32M4x4 *mtrx)
{
	tIU8 pivotRow = 0U;
	for (tIU8 col = 0U; col < 4U; ++col)
	{
		if (pivotRow >= 4U) break;
		tBln foundPivot = False;
		if (!tFP32_IsNearby(mtrx->m[pivotRow][col], 0.0F)) foundPivot = True;
		else
		{
			for (tIU8 idx = 1U; idx < 4U - pivotRow; ++idx)
			{
				if (!tFP32_IsNearby(mtrx->m[pivotRow + idx][col], 0.0F))
				{
					tFP32M4x4_RowSwap(mtrx, pivotRow, pivotRow + idx);
					foundPivot = True;
					break;
				}
			}
			if (foundPivot == False) continue;
		}
		tFP32M4x4_RowMult(mtrx, pivotRow, tFP32_Recip(mtrx->m[pivotRow][col]));
		for (tIU8 idx = 1U; idx < 4U - pivotRow; ++idx) tFP32M4x4_RowAdd(mtrx, pivotRow + idx, pivotRow, tFP32_Neg(mtrx->m[pivotRow + idx][col]));
		++pivotRow;
	}
}
tNone tFP32M4x4_RowRedEch(tFP32M4x4 *mtrx)
{
	tFP32M4x4_RowEch(mtrx);
	for (tIS8 row = 3; row >= 0; --row)
	{
		tBln foundPivot = False;
		tIU8 pivotCol = 0;
		for (tIU8 col = 0U; col < 4; ++col)
		{
			if (!tFP32_IsNearby(mtrx->m[row][col], 0.0F))
			{
				foundPivot = True;
				pivotCol = col;
				break;
			}
		}
		if (foundPivot == False) continue;
		for (tIU8 aboveRow = 0U; aboveRow < row; ++aboveRow) tFP32M4x4_RowAdd(mtrx, aboveRow, row, tFP32_Neg(mtrx->m[aboveRow][pivotCol]));
	}
}
tFP32V3D tFP32M4x4_TransfPoint(tFP32M4x4 mtrx, tFP32V3D vect)
{
	tFP32V4D tmp;
	tmp.x = vect.x;
	tmp.y = vect.y;
	tmp.z = vect.z;
	tmp.w = 1.0F;
	tmp = tFP32M4x4_MulVect(mtrx, tmp);
	return tFP32V3D_Make(tmp.x, tmp.y, tmp.z);
}
tFP32V3D tFP32M4x4_TransfDir(tFP32M4x4 mtrx, tFP32V3D vect)
{
	tFP32V4D tmp;
	tmp.x = vect.x;
	tmp.y = vect.y;
	tmp.z = vect.z;
	tmp.w = 0.0F;
	tmp = tFP32M4x4_MulVect(mtrx, tmp);
	return tFP32V3D_Make(tmp.x, tmp.y, tmp.z);
}
tFP32M4x4 tFP32M4x4_RotAxis_fast(tFP32V3D axis, tFP32 ang)
{
	axis = tFP32V3D_Norm_fast(axis);
	tFP32 cosAng = tFP32_Cosine_fast(ang);
	tFP32 sinAng = tFP32_Sine_fast(ang);
	tFP32 transl = 1.0F - cosAng;
	tFP32 translX = transl * axis.x;
	tFP32 translY = transl * axis.y;
	tFP32 sinAngX = sinAng * axis.x;
	tFP32 sinAngY = sinAng * axis.y;
	tFP32 sinAngZ = sinAng * axis.z;
	tFP32 translXY = translX * axis.y;
	tFP32 translXZ = translX * axis.z;
	tFP32 translYZ = translY * axis.z;
	tFP32M4x4 mat;
	mat.m00 = translX * axis.x + cosAng;
	mat.m01 = translXY - sinAngZ;
	mat.m02 = translXZ + sinAngY;
	mat.m03 = 0.0F;
	mat.m10 = translXY + sinAngZ;
	mat.m11 = translY * axis.y + cosAng;
	mat.m12 = translYZ - sinAngX;
	mat.m13 = 0.0F;
	mat.m20 = translXZ - sinAngY;
	mat.m21 = translYZ + sinAngX;
	mat.m22 = transl * axis.z * axis.z + cosAng;
	mat.m23 = 0.0F;
	mat.m30 = 0.0F;
	mat.m31 = 0.0F;
	mat.m32 = 0.0F;
	mat.m33 = 1.0F;
	return mat;
}
tFP32M4x4 tFP32M4x4_RotAxis_iter(tFP32V3D axis, tFP32 ang, tIUSz itr)
{
	axis = tFP32V3D_Norm(axis);
	tFP32 cosAng = tFP32_Cosine_iter(ang, itr);
	tFP32 sinAng = tFP32_Sine_iter(ang, itr);
	tFP32 transl = 1.0F - cosAng;
	tFP32 translX = transl * axis.x;
	tFP32 translY = transl * axis.y;
	tFP32 sinAngX = sinAng * axis.x;
	tFP32 sinAngY = sinAng * axis.y;
	tFP32 sinAngZ = sinAng * axis.z;
	tFP32 translXY = translX * axis.y;
	tFP32 translXZ = translX * axis.z;
	tFP32 translYZ = translY * axis.z;
	tFP32M4x4 mat;
	mat.m00 = translX * axis.x + cosAng;
	mat.m01 = translXY - sinAngZ;
	mat.m02 = translXZ + sinAngY;
	mat.m03 = 0.0F;
	mat.m10 = translXY + sinAngZ;
	mat.m11 = translY * axis.y + cosAng;
	mat.m12 = translYZ - sinAngX;
	mat.m13 = 0.0F;
	mat.m20 = translXZ - sinAngY;
	mat.m21 = translYZ + sinAngX;
	mat.m22 = transl * axis.z * axis.z + cosAng;
	mat.m23 = 0.0F;
	mat.m30 = 0.0F;
	mat.m31 = 0.0F;
	mat.m32 = 0.0F;
	mat.m33 = 1.0F;
	return mat;
}
tFP32M4x4 tFP32M4x4_RotAxis(tFP32V3D axis, tFP32 ang)
{
	axis = tFP32V3D_Norm(axis);
	tFP32 cosAng = tFP32_Cosine(ang);
	tFP32 sinAng = tFP32_Sine(ang);
	tFP32 transl = 1.0F - cosAng;
	tFP32 translX = transl * axis.x;
	tFP32 translY = transl * axis.y;
	tFP32 sinAngX = sinAng * axis.x;
	tFP32 sinAngY = sinAng * axis.y;
	tFP32 sinAngZ = sinAng * axis.z;
	tFP32 translXY = translX * axis.y;
	tFP32 translXZ = translX * axis.z;
	tFP32 translYZ = translY * axis.z;
	tFP32M4x4 mat;
	mat.m00 = translX * axis.x + cosAng;
	mat.m01 = translXY - sinAngZ;
	mat.m02 = translXZ + sinAngY;
	mat.m03 = 0.0F;
	mat.m10 = translXY + sinAngZ;
	mat.m11 = translY * axis.y + cosAng;
	mat.m12 = translYZ - sinAngX;
	mat.m13 = 0.0F;
	mat.m20 = translXZ - sinAngY;
	mat.m21 = translYZ + sinAngX;
	mat.m22 = transl * axis.z * axis.z + cosAng;
	mat.m23 = 0.0F;
	mat.m30 = 0.0F;
	mat.m31 = 0.0F;
	mat.m32 = 0.0F;
	mat.m33 = 1.0F;
	return mat;
}
tFP32M4x4 tFP32M4x4_InvAff(tFP32M4x4 mtrx)
{
	if (!tFP32M4x4_IsAff(mtrx)) return tFP32M4x4_Zero();
	tFP32 det = mtrx.m00 * (mtrx.m11 * mtrx.m22 - mtrx.m12 * mtrx.m21) - mtrx.m01 * (mtrx.m10 * mtrx.m22 - mtrx.m12 * mtrx.m20) + mtrx.m02 * (mtrx.m10 * mtrx.m21 - mtrx.m11 * mtrx.m20);
	tFP32 invDet = tFP32_Recip(det);
	tFP32M4x4 out;
	out.m00 = (mtrx.m11 * mtrx.m22 - mtrx.m12 * mtrx.m21) * invDet;
	out.m01 = tFP32_Neg(mtrx.m01 * mtrx.m22 - mtrx.m02 * mtrx.m21) * invDet;
	out.m02 = (mtrx.m01 * mtrx.m12 - mtrx.m02 * mtrx.m11) * invDet;
	out.m10 = tFP32_Neg(mtrx.m10 * mtrx.m22 - mtrx.m12 * mtrx.m20) * invDet;
	out.m11 = (mtrx.m00 * mtrx.m22 - mtrx.m02 * mtrx.m20) * invDet;
	out.m12 = tFP32_Neg(mtrx.m00 * mtrx.m12 - mtrx.m02 * mtrx.m10) * invDet;
	out.m20 = (mtrx.m10 * mtrx.m21 - mtrx.m11 * mtrx.m20) * invDet;
	out.m21 = tFP32_Neg(mtrx.m00 * mtrx.m21 - mtrx.m01 * mtrx.m20) * invDet;
	out.m22 = (mtrx.m00 * mtrx.m11 - mtrx.m01 * mtrx.m10) * invDet;
	out.m03 = tFP32_Neg(out.m00 * mtrx.m03 + out.m01 * mtrx.m13 + out.m02 * mtrx.m23);
	out.m13 = tFP32_Neg(out.m10 * mtrx.m03 + out.m11 * mtrx.m13 + out.m12 * mtrx.m23);
	out.m23 = tFP32_Neg(out.m20 * mtrx.m03 + out.m21 * mtrx.m13 + out.m22 * mtrx.m23);
	out.m30 = 0.0F;
	out.m31 = 0.0F;
	out.m32 = 0.0F;
	out.m33 = 1.0F;
	return out;
}
tFP32M4x4 tFP32M4x4_Persp_fast(tFP32 fov, tFP32 aspRatio, tFP32 near, tFP32 far, tIS8 minZ)
{
	if (minZ != -1 && minZ != 0) return tFP32M4x4_Zero();
	tFP32 yScale = tFP32_Recip(tFP32_Tangent_fast(fov * 0.5F));
	tFP32 xScale = yScale / aspRatio;
	tFP32 dst = far - near;
	tFP32M4x4 out = tFP32M4x4_Zero();
	out.m00 = xScale;
	out.m11 = yScale;
	if (minZ == 0)
	{
		out.m22 = far / dst;
		out.m23 = (far * near) / dst;
	}
	else
	{
		out.m22 = tFP32_Neg(far + near) / dst;
		out.m23 = tFP32_Neg(2.0F * far * near) / dst;
	}
	out.m32 = -1.0F;
	return out;
}
tFP32M4x4 tFP32M4x4_Persp_iter(tFP32 fov, tFP32 aspRatio, tFP32 near, tFP32 far, tIS8 minZ, tIUSz itr)
{
	if (minZ != -1 && minZ != 0) return tFP32M4x4_Zero();
	tFP32 yScale = tFP32_Recip(tFP32_Tangent_iter(fov * 0.5F, itr));
	tFP32 xScale = yScale / aspRatio;
	tFP32 dst = far - near;
	tFP32M4x4 out = tFP32M4x4_Zero();
	out.m00 = xScale;
	out.m11 = yScale;
	if (minZ == 0)
	{
		out.m22 = far / dst;
		out.m23 = (far * near) / dst;
	}
	else
	{
		out.m22 = tFP32_Neg(far + near) / dst;
		out.m23 = tFP32_Neg(2.0F * far * near) / dst;
	}
	out.m32 = -1.0F;
	return out;
}
tFP32M4x4 tFP32M4x4_Persp(tFP32 fov, tFP32 aspRatio, tFP32 near, tFP32 far, tIS8 minZ)
{
	if (minZ != -1 && minZ != 0) return tFP32M4x4_Zero();
	tFP32 yScale = tFP32_Recip(tFP32_Tangent(fov * 0.5F));
	tFP32 xScale = yScale / aspRatio;
	tFP32 dst = far - near;
	tFP32M4x4 out = tFP32M4x4_Zero();
	out.m00 = xScale;
	out.m11 = yScale;
	if (minZ == 0)
	{
		out.m22 = far / dst;
		out.m23 = (far * near) / dst;
	}
	else
	{
		out.m22 = -(far + near) / dst;
		out.m23 = -(2.0F * far * near) / dst;
	}
	out.m32 = -1.0F;
	return out;
}
tBln tFP32M4x4_IsAff(tFP32M4x4 mtrx)
{
	return tFP32_IsNearby(mtrx.m30, 0.0F) && tFP32_IsNearby(mtrx.m31, 0.0F) && tFP32_IsNearby(mtrx.m32, 0.0F) && tFP32_IsNearby(mtrx.m33, 1.0F);
}
tFP32M4x4 tFP32M4x4_LookAt(tFP32V3D eye, tFP32V3D target, tFP32V3D up)
{
	tFP32V3D forward = tFP32V3D_Norm(tFP32V3D_Sub(target, eye));
	tFP32V3D right = tFP32V3D_Norm(tFP32V3D_Cross(forward, up));
	tFP32V3D newUp = tFP32V3D_Cross(right, forward);
	tFP32M4x4 mat;
	mat.m00 = right.x;
	mat.m01 = right.y;
	mat.m02 = right.z;
	mat.m03 = tFP32_Neg(tFP32V3D_Dot(right, eye));
	mat.m10 = newUp.x;
	mat.m11 = newUp.y;
	mat.m12 = newUp.z;
	mat.m13 = tFP32_Neg(tFP32V3D_Dot(newUp, eye));
	mat.m20 = tFP32_Neg(forward.x);
	mat.m21 = tFP32_Neg(forward.y);
	mat.m22 = tFP32_Neg(forward.z);
	mat.m23 = tFP32V3D_Dot(forward, eye);
	mat.m30 = 0.0F;
	mat.m31 = 0.0F;
	mat.m32 = 0.0F;
	mat.m33 = 1.0F;
	return mat;
}
tFP32M3x3 tFP32M4x4_NormalMtrx(tFP32M4x4 mtrx)
{
	tFP32M4x4 invTrans = tFP32M4x4_Transp(tFP32M4x4_Inv(mtrx));
	tFP32M3x3 res;
	res.m00 = invTrans.m00;
	res.m01 = invTrans.m01;
	res.m02 = invTrans.m02;
	res.m10 = invTrans.m10;
	res.m11 = invTrans.m11;
	res.m12 = invTrans.m12;
	res.m20 = invTrans.m20;
	res.m21 = invTrans.m21;
	res.m22 = invTrans.m22;
	return res;
}
#endif/*BQSELAYER_MTRX_IMPL*/
typedef union { struct { tFP64 m00, m01; tFP64 m10, m11; }; tFP64 m[2][2]; tFP64V2D row[2]; } tFP64M2x2;
LINK_C_Begin
tFP64M2x2 tFP64M2x2_Make(tFP64 m00, tFP64 m01, tFP64 m10, tFP64 m11);
tFP64M2x2 tFP64M2x2_Zero(tNone);
tFP64M2x2 tFP64M2x2_Id(tNone);
tFP64M2x2 tFP64M2x2_Add(tFP64M2x2 mtrx1, tFP64M2x2 mtrx2);
tFP64M2x2 tFP64M2x2_Sub(tFP64M2x2 mtrx1, tFP64M2x2 mtrx2);
tFP64M2x2 tFP64M2x2_Mul(tFP64M2x2 mtrx1, tFP64M2x2 mtrx2);
tFP64M2x2 tFP64M2x2_MulDbl(tFP64M2x2 mtrx, tFP64 mod);
/*Warn: Silently returns a matrix with all components either -Inf or +Inf when `mod` is 0.*/
tFP64M2x2 tFP64M2x2_DivDbl(tFP64M2x2 mtrx, tFP64 mod);
/*Note: Returns `False` on success.*/
tBln tFP64M2x2_DivDbl_safe(tFP64M2x2 *mtrx, tFP64 mod);
tBln tFP64M2x2_IsEq(tFP64M2x2 mtrx1, tFP64M2x2 mtrx2);
tBln tFP64M2x2_IsNearby(tFP64M2x2 mtrx1, tFP64M2x2 mtrx2, tFP64 eps);
tFP64V2D tFP64M2x2_MulVect(tFP64M2x2 mtrx, tFP64V2D vect);
tFP64M2x2 tFP64M2x2_Transp(tFP64M2x2 mtrx);
tFP64 tFP64M2x2_Det(tFP64M2x2 mtrx);
tFP64M2x2 tFP64M2x2_Cofact(tFP64M2x2 mtrx);
tFP64M2x2 tFP64M2x2_Adj(tFP64M2x2 mtrx);
/*Warn: Silently returns `tFP64M2x2_Zero` on failure.*/
tFP64M2x2 tFP64M2x2_Inv(tFP64M2x2 mtrx);
/*Note: Returns `False` on success.*/
tBln tFP64M2x2_Inv_safe(tFP64M2x2 *mtrx);
/*Note: Parameter `ang` is in radians.*/
tFP64M2x2 tFP64M2x2_Rot_fast(tFP64 ang);
tFP64M2x2 tFP64M2x2_Rot_iter(tFP64 ang, tIUSz itr);
tFP64M2x2 tFP64M2x2_Rot(tFP64 ang);
tFP64M2x2 tFP64M2x2_Scale(tFP64 x, tFP64 y);
tFP64 tFP64M2x2_Trace(tFP64M2x2 mtrx);
tNone tFP64M2x2_RowSwap(tFP64M2x2 *mtrx);
tNone tFP64M2x2_RowAdd(tFP64M2x2 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP64 mult);
tNone tFP64M2x2_RowMult(tFP64M2x2 *mtrx, tIU8 idx, tFP64 mult);
tNone tFP64M2x2_RowEch(tFP64M2x2 *mtrx);
tNone tFP64M2x2_RowRedEch(tFP64M2x2 *mtrx);
tFP64M2x2 tFP64M2x2_InvAff(tFP64M2x2 mtrx);
ForceInline tBln tFP64M2x2_IsAff(tFP64M2x2 mtrx);
LINK_C_End
#ifdef BQSELAYER_MTRX_IMPL
tFP64M2x2 tFP64M2x2_Make(tFP64 m00, tFP64 m01, tFP64 m10, tFP64 m11)
{
	tFP64M2x2 mtrx;
	mtrx.m00 = m00;
	mtrx.m01 = m01;
	mtrx.m10 = m10;
	mtrx.m11 = m11;
	return mtrx;
}
tFP64M2x2 tFP64M2x2_Zero(tNone)
{
	tFP64M2x2 mtrx;
	mtrx.m00 = 0.0;
	mtrx.m01 = 0.0;
	mtrx.m10 = 0.0;
	mtrx.m11 = 0.0;
	return mtrx;
}
tFP64M2x2 tFP64M2x2_Id(tNone)
{
	tFP64M2x2 mtrx;
	mtrx.m00 = 1.0;
	mtrx.m01 = 0.0;
	mtrx.m10 = 0.0;
	mtrx.m11 = 1.0;
	return mtrx;
}
tFP64M2x2 tFP64M2x2_Add(tFP64M2x2 mtrx1, tFP64M2x2 mtrx2)
{
	mtrx1.m00 += mtrx2.m00;
	mtrx1.m01 += mtrx2.m01;
	mtrx1.m10 += mtrx2.m10;
	mtrx1.m11 += mtrx2.m11;
	return mtrx1;
}
tFP64M2x2 tFP64M2x2_Sub(tFP64M2x2 mtrx1, tFP64M2x2 mtrx2)
{
	mtrx1.m00 -= mtrx2.m00;
	mtrx1.m01 -= mtrx2.m01;
	mtrx1.m10 -= mtrx2.m10;
	mtrx1.m11 -= mtrx2.m11;
	return mtrx1;
}
tFP64M2x2 tFP64M2x2_Mul(tFP64M2x2 mtrx1, tFP64M2x2 mtrx2)
{
	tFP64M2x2 mtrx;
	mtrx.m00 = mtrx1.m00 * mtrx2.m00 + mtrx1.m01 * mtrx2.m10;
	mtrx.m01 = mtrx1.m00 * mtrx2.m01 + mtrx1.m01 * mtrx2.m11;
	mtrx.m10 = mtrx1.m10 * mtrx2.m00 + mtrx1.m11 * mtrx2.m10;
	mtrx.m11 = mtrx1.m10 * mtrx2.m01 + mtrx1.m11 * mtrx2.m11;
	return mtrx;
}
tFP64M2x2 tFP64M2x2_MulDbl(tFP64M2x2 mtrx, tFP64 mod)
{
	mtrx.m00 *= mod;
	mtrx.m01 *= mod;
	mtrx.m10 *= mod;
	mtrx.m11 *= mod;
	return mtrx;
}
tFP64M2x2 tFP64M2x2_DivDbl(tFP64M2x2 mtrx, tFP64 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNearby(mod, 0.0))
	{
		mtrx.m00 = tFP64_IsNeg(mtrx.m00) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m01 = tFP64_IsNeg(mtrx.m01) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m10 = tFP64_IsNeg(mtrx.m10) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m11 = tFP64_IsNeg(mtrx.m11) ? tFP64_NegInf() : tFP64_Inf();
		return mtrx;
	}
#else
	Assertion(!tFP64_IsNearby(mod, 0.0));
#endif/*BQSELAYER_DEBUG*/
	mtrx.m00 /= mod;
	mtrx.m01 /= mod;
	mtrx.m10 /= mod;
	mtrx.m11 /= mod;
	return mtrx;
}
tBln tFP64M2x2_DivDbl_safe(tFP64M2x2 *mtrx, tFP64 mod)
{
	if (tFP64_IsNearby(mod, 0.0)) return True;
	mtrx->m00 /= mod;
	mtrx->m01 /= mod;
	mtrx->m10 /= mod;
	mtrx->m11 /= mod;
	return False;
}
tBln tFP64M2x2_IsEq(tFP64M2x2 mtrx1, tFP64M2x2 mtrx2)
{
	return tFP64_IsNearby(mtrx1.m00, mtrx2.m00) && tFP64_IsNearby(mtrx1.m01, mtrx2.m01) && tFP64_IsNearby(mtrx1.m10, mtrx2.m10) && tFP64_IsNearby(mtrx1.m11, mtrx2.m11);
}
tBln tFP64M2x2_IsNearby(tFP64M2x2 mtrx1, tFP64M2x2 mtrx2, tFP64 eps)
{
	return (tFP64_Abs(mtrx1.m00 - mtrx2.m00) <= eps) && (tFP64_Abs(mtrx1.m01 - mtrx2.m01) <= eps) && (tFP64_Abs(mtrx1.m10 - mtrx2.m10) <= eps) && (tFP64_Abs(mtrx1.m11 - mtrx2.m11) <= eps);
}
tFP64V2D tFP64M2x2_MulVect(tFP64M2x2 mtrx, tFP64V2D vect)
{
	tFP64V2D res;
	res.x = mtrx.m00 * vect.x + mtrx.m01 * vect.y;
	res.y = mtrx.m10 * vect.x + mtrx.m11 * vect.y;
	return res;
}
tFP64M2x2 tFP64M2x2_Transp(tFP64M2x2 mtrx)
{
	tFP64 tmp = mtrx.m01;
	mtrx.m01 = mtrx.m10;
	mtrx.m10 = tmp;
	return mtrx;
}
tFP64 tFP64M2x2_Det(tFP64M2x2 mtrx)
{
	return (mtrx.m00 * mtrx.m11) - (mtrx.m01 * mtrx.m10);
}
tFP64M2x2 tFP64M2x2_Cofact(tFP64M2x2 mtrx)
{
	tFP64 tmp = mtrx.m00;
	mtrx.m00 = mtrx.m11;
	mtrx.m11 = tmp;
	mtrx.m01 = tFP64_Neg(mtrx.m10);
	mtrx.m10 = tFP64_Neg(mtrx.m01);
	return mtrx;
}
tFP64M2x2 tFP64M2x2_Adj(tFP64M2x2 mtrx)
{
	tFP64 tmp = mtrx.m00;
	mtrx.m00 = mtrx.m11;
	mtrx.m11 = tmp;
	mtrx.m01 = tFP64_Neg(mtrx.m01);
	mtrx.m10 = tFP64_Neg(mtrx.m10);
	return mtrx;
}
tFP64M2x2 tFP64M2x2_Inv(tFP64M2x2 mtrx)
{
	tFP64 det = tFP64M2x2_Det(mtrx);
#ifndef BQSELAYER_DEBUG
	if (tFP64_Abs(det) <= tFP64_Eps) return tFP64M2x2_Zero();
#else
	Assertion(tFP64_Abs(det) > tFP64_Eps);
#endif/*BQSELAYER_DEBUG*/
	return tFP64M2x2_DivDbl(tFP64M2x2_Adj(mtrx), det);
}
tBln tFP64M2x2_Inv_safe(tFP64M2x2 *mtrx)
{
	tFP64 det = tFP64M2x2_Det(*mtrx);
	if (tFP64_Abs(det) <= tFP64_Eps) return True;
	*mtrx = tFP64M2x2_DivDbl(tFP64M2x2_Adj(*mtrx), det);
	return False;
}
tFP64M2x2 tFP64M2x2_Rot_fast(tFP64 ang)
{
	tFP64M2x2 mtrx;
	mtrx.m00 = mtrx.m11 = tFP64_Cosine_fast(ang);
	mtrx.m10 = tFP64_Sine_fast(ang);
	mtrx.m01 = tFP64_Neg(mtrx.m10);
	return mtrx;
}
tFP64M2x2 tFP64M2x2_Rot_iter(tFP64 ang, tIUSz itr)
{
	tFP64M2x2 mtrx;
	mtrx.m00 = mtrx.m11 = tFP64_Cosine_iter(ang, itr);
	mtrx.m10 = tFP64_Sine_iter(ang, itr);
	mtrx.m01 = tFP64_Neg(mtrx.m10);
	return mtrx;
}
tFP64M2x2 tFP64M2x2_Rot(tFP64 ang)
{
	tFP64M2x2 mtrx;
	mtrx.m00 = mtrx.m11 = tFP64_Cosine(ang);
	mtrx.m10 = tFP64_Sine(ang);
	mtrx.m01 = tFP64_Neg(mtrx.m10);
	return mtrx;
}
tFP64M2x2 tFP64M2x2_Scale(tFP64 x, tFP64 y)
{
	tFP64M2x2 mtrx;
	mtrx.m00 = x;
	mtrx.m11 = y;
	mtrx.m01 = mtrx.m10 = 0.0;
	return mtrx;
}
tFP64 tFP64M2x2_Trace(tFP64M2x2 mtrx)
{
	return mtrx.m00 + mtrx.m11;
}
tNone tFP64M2x2_RowSwap(tFP64M2x2 *mtrx)
{
	tFP64_Swap(&mtrx->m00, &mtrx->m10);
	tFP64_Swap(&mtrx->m01, &mtrx->m11);
}
tNone tFP64M2x2_RowAdd(tFP64M2x2 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP64 mult)
{
	mtrx->m[dstRow][0] += mtrx->m[srcRow][0] * mult;
	mtrx->m[dstRow][1] += mtrx->m[srcRow][1] * mult;
}
tNone tFP64M2x2_RowMult(tFP64M2x2 *mtrx, tIU8 idx, tFP64 mult)
{
	mtrx->m[idx][0] *= mult;
	mtrx->m[idx][1] *= mult;
}
tNone tFP64M2x2_RowEch(tFP64M2x2 *mtrx)
{
	tIU8 pivotRow = 0U;
	for (tIU8 col = 0U; col < 2U; ++col)
	{
		if (pivotRow >= 2U) break;
		tBln foundPivot = False;
		if (!tFP64_IsNearby(mtrx->m[pivotRow][col], 0.0)) foundPivot = True;
		else
		{
			for (tIU8 idx = 1U; idx < 2U - pivotRow; ++idx)
			{
				if (!tFP64_IsNearby(mtrx->m[pivotRow + idx][col], 0.0))
				{
					tFP64M2x2_RowSwap(mtrx);
					foundPivot = True;
					break;
				}
			}
			if (foundPivot == False) continue;
		}
		tFP64M2x2_RowMult(mtrx, pivotRow, tFP64_Recip(mtrx->m[pivotRow][col]));
		for (tIU8 idx = 1U; idx < 2U - pivotRow; ++idx) tFP64M2x2_RowAdd(mtrx, pivotRow + idx, pivotRow, tFP64_Neg(mtrx->m[pivotRow + idx][col]));
		++pivotRow;
	}
}
tNone tFP64M2x2_RowRedEch(tFP64M2x2 *mtrx)
{
	tFP64M2x2_RowEch(mtrx);
	tIU8 pivotRow = 1U;
	for (tIU8 col = pivotRow; col > 0U; --col)
	{
		if (pivotRow == 0U) break;
		for (tIU8 idx = 0U; idx < pivotRow; ++idx) tFP64M2x2_RowAdd(mtrx, idx, pivotRow, tFP64_Neg(mtrx->m[idx][col]));
		--pivotRow;
	}
}
tFP64M2x2 tFP64M2x2_InvAff(tFP64M2x2 mtrx)
{
	if (!tFP64M2x2_IsAff(mtrx)) return tFP64M2x2_Zero();
	tFP64 invA = tFP64_Recip(mtrx.m00);
	tFP64M2x2 out;
	out.m00 = invA;
	out.m01 = -mtrx.m01 * invA;
	out.m10 = 0.0;
	out.m11 = 1.0;
	return out;
}
ForceInline tBln tFP64M2x2_IsAff(tFP64M2x2 mtrx)
{
	return tFP64_IsNearby(mtrx.m10, 0.0) && tFP64_IsNearby(mtrx.m11, 0.0);
}
#endif/*BQSELAYER_MTRX_IMPL*/
typedef union { struct { tFP64 m00, m01, m02; tFP64 m10, m11, m12; tFP64 m20, m21, m22; }; tFP64 m[3][3]; tFP64V3D row[3]; } tFP64M3x3;
LINK_C_Begin
tFP64M3x3 tFP64M3x3_Make(tFP64 m00, tFP64 m01, tFP64 m02, tFP64 m10, tFP64 m11, tFP64 m12, tFP64 m20, tFP64 m21, tFP64 m22);
tFP64M3x3 tFP64M3x3_Zero(tNone);
tFP64M3x3 tFP64M3x3_Id(tNone);
tFP64M3x3 tFP64M3x3_Add(tFP64M3x3 mtrx1, tFP64M3x3 mtrx2);
tFP64M3x3 tFP64M3x3_Sub(tFP64M3x3 mtrx1, tFP64M3x3 mtrx2);
tFP64M3x3 tFP64M3x3_Mul(tFP64M3x3 mtrx1, tFP64M3x3 mtrx2);
tFP64M3x3 tFP64M3x3_MulDbl(tFP64M3x3 mtrx, tFP64 mod);
/*Warn: Silently returns a matrix with all components either -Inf or +Inf when `mod` is 0.*/
tFP64M3x3 tFP64M3x3_DivDbl(tFP64M3x3 mtrx, tFP64 mod);
/*Note: Returns `False` on success.*/
tBln tFP64M3x3_DivDbl_safe(tFP64M3x3 *mtrx, tFP64 mod);
tBln tFP64M3x3_IsEq(tFP64M3x3 mtrx1, tFP64M3x3 mtrx2);
tBln tFP64M3x3_IsNearby(tFP64M3x3 mtrx1, tFP64M3x3 mtrx2, tFP64 eps);
tFP64V3D tFP64M3x3_MulVect(tFP64M3x3 mtrx, tFP64V3D vect);
tFP64M3x3 tFP64M3x3_Transp(tFP64M3x3 mtrx);
tFP64 tFP64M3x3_Det(tFP64M3x3 mtrx);
tFP64M3x3 tFP64M3x3_Cofact(tFP64M3x3 mtrx);
tFP64M3x3 tFP64M3x3_Adj(tFP64M3x3 mtrx);
/*Warn: Silently returns `tFP64M3x3_Zero` on failure.*/
tFP64M3x3 tFP64M3x3_Inv(tFP64M3x3 mtrx);
/*Note: Returns `False` on success.*/
tBln tFP64M3x3_Inv_safe(tFP64M3x3 *mtrx);
tFP64M3x3 tFP64M3x3_Transl(tFP64 x, tFP64 y);
tFP64M3x3 tFP64M3x3_Scale(tFP64 x, tFP64 y);
/*Note: Parameter `ang` is in radians.*/
tFP64M3x3 tFP64M3x3_Rot_fast(tFP64 ang);
tFP64M3x3 tFP64M3x3_Rot_iter(tFP64 ang, tIUSz itr);
tFP64M3x3 tFP64M3x3_Rot(tFP64 ang);
tFP64 tFP64M3x3_Trace(tFP64M3x3 mtrx);
tFP64V2D tFP64M3x3_TransfPoint(tFP64M3x3 mtrx, tFP64V2D vect);
tFP64V2D tFP64M3x3_TransfDir(tFP64M3x3 mtrx, tFP64V2D vect);
tNone tFP64M3x3_RowSwap(tFP64M3x3 *mtrx, tIU8 idx1, tIU8 idx2);
tNone tFP64M3x3_RowAdd(tFP64M3x3 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP64 mult);
tNone tFP64M3x3_RowMult(tFP64M3x3 *mtrx, tIU8 idx, tFP64 mult);
tNone tFP64M3x3_RowEch(tFP64M3x3 *mtrx);
tNone tFP64M3x3_RowRedEch(tFP64M3x3 *mtrx);
tFP64M3x3 tFP64M3x3_InvAff(tFP64M3x3 mtrx);
ForceInline tBln tFP64M3x3_IsAff(tFP64M3x3 mtrx);
LINK_C_End
#ifdef BQSELAYER_MTRX_IMPL
tFP64M3x3 tFP64M3x3_Make(tFP64 m00, tFP64 m01, tFP64 m02, tFP64 m10, tFP64 m11, tFP64 m12, tFP64 m20, tFP64 m21, tFP64 m22)
{
	tFP64M3x3 mtrx;
	mtrx.m00 = m00;
	mtrx.m01 = m01;
	mtrx.m02 = m02;
	mtrx.m10 = m10;
	mtrx.m11 = m11;
	mtrx.m12 = m12;
	mtrx.m20 = m20;
	mtrx.m21 = m21;
	mtrx.m22 = m22;
	return mtrx;
}
tFP64M3x3 tFP64M3x3_Zero(tNone)
{
	tFP64M3x3 mtrx;
	mtrx.m00 = mtrx.m01 = mtrx.m02 = mtrx.m10 = mtrx.m11 = mtrx.m12 = mtrx.m20 = mtrx.m21 = mtrx.m22 = 0.0;
	return mtrx;
}
tFP64M3x3 tFP64M3x3_Id(tNone)
{
	tFP64M3x3 mtrx;
	mtrx.m01 = mtrx.m02 = mtrx.m10 = mtrx.m12 = mtrx.m20 = mtrx.m21 = 0.0;
	mtrx.m00 = mtrx.m11 = mtrx.m22 = 1.0;
	return mtrx;
}
tFP64M3x3 tFP64M3x3_Add(tFP64M3x3 mtrx1, tFP64M3x3 mtrx2)
{
	mtrx1.m00 += mtrx2.m00;
	mtrx1.m01 += mtrx2.m01;
	mtrx1.m02 += mtrx2.m02;
	mtrx1.m10 += mtrx2.m10;
	mtrx1.m11 += mtrx2.m11;
	mtrx1.m12 += mtrx2.m12;
	mtrx1.m20 += mtrx2.m20;
	mtrx1.m21 += mtrx2.m21;
	mtrx1.m22 += mtrx2.m22;
	return mtrx1;
}
tFP64M3x3 tFP64M3x3_Sub(tFP64M3x3 mtrx1, tFP64M3x3 mtrx2)
{
	mtrx1.m00 -= mtrx2.m00;
	mtrx1.m01 -= mtrx2.m01;
	mtrx1.m02 -= mtrx2.m02;
	mtrx1.m10 -= mtrx2.m10;
	mtrx1.m11 -= mtrx2.m11;
	mtrx1.m12 -= mtrx2.m12;
	mtrx1.m20 -= mtrx2.m20;
	mtrx1.m21 -= mtrx2.m21;
	mtrx1.m22 -= mtrx2.m22;
	return mtrx1;
}
tFP64M3x3 tFP64M3x3_Mul(tFP64M3x3 mtrx1, tFP64M3x3 mtrx2)
{
	tFP64M3x3 res;
	res.m00 = (mtrx1.m00 * mtrx2.m00) + (mtrx1.m01 * mtrx2.m10) + (mtrx1.m02 * mtrx2.m20);
	res.m01 = (mtrx1.m00 * mtrx2.m01) + (mtrx1.m01 * mtrx2.m11) + (mtrx1.m02 * mtrx2.m21);
	res.m02 = (mtrx1.m00 * mtrx2.m02) + (mtrx1.m01 * mtrx2.m12) + (mtrx1.m02 * mtrx2.m22);
	res.m10 = (mtrx1.m10 * mtrx2.m00) + (mtrx1.m11 * mtrx2.m10) + (mtrx1.m12 * mtrx2.m20);
	res.m11 = (mtrx1.m10 * mtrx2.m01) + (mtrx1.m11 * mtrx2.m11) + (mtrx1.m12 * mtrx2.m21);
	res.m12 = (mtrx1.m10 * mtrx2.m02) + (mtrx1.m11 * mtrx2.m12) + (mtrx1.m12 * mtrx2.m22);
	res.m20 = (mtrx1.m20 * mtrx2.m00) + (mtrx1.m21 * mtrx2.m10) + (mtrx1.m22 * mtrx2.m20);
	res.m21 = (mtrx1.m20 * mtrx2.m01) + (mtrx1.m21 * mtrx2.m11) + (mtrx1.m22 * mtrx2.m21);
	res.m22 = (mtrx1.m20 * mtrx2.m02) + (mtrx1.m21 * mtrx2.m12) + (mtrx1.m22 * mtrx2.m22);
	return res;
}
tFP64M3x3 tFP64M3x3_MulDbl(tFP64M3x3 mtrx, tFP64 mod)
{
	mtrx.m00 *= mod;
	mtrx.m01 *= mod;
	mtrx.m02 *= mod;
	mtrx.m10 *= mod;
	mtrx.m11 *= mod;
	mtrx.m12 *= mod;
	mtrx.m20 *= mod;
	mtrx.m21 *= mod;
	mtrx.m22 *= mod;
	return mtrx;
}
tFP64M3x3 tFP64M3x3_DivDbl(tFP64M3x3 mtrx, tFP64 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNearby(mod, 0.0))
	{
		mtrx.m00 = tFP64_IsNeg(mtrx.m00) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m01 = tFP64_IsNeg(mtrx.m01) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m02 = tFP64_IsNeg(mtrx.m02) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m10 = tFP64_IsNeg(mtrx.m10) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m11 = tFP64_IsNeg(mtrx.m11) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m12 = tFP64_IsNeg(mtrx.m12) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m20 = tFP64_IsNeg(mtrx.m20) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m21 = tFP64_IsNeg(mtrx.m21) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m22 = tFP64_IsNeg(mtrx.m22) ? tFP64_NegInf() : tFP64_Inf();
		return mtrx;
	}
#else
	Assertion(!tFP64_IsNearby(mod, 0.0));
#endif/*BQSELAYER_DEBUG*/
	mtrx.m00 /= mod;
	mtrx.m01 /= mod;
	mtrx.m02 /= mod;
	mtrx.m10 /= mod;
	mtrx.m11 /= mod;
	mtrx.m12 /= mod;
	mtrx.m20 /= mod;
	mtrx.m21 /= mod;
	mtrx.m22 /= mod;
	return mtrx;
}
tBln tFP64M3x3_DivDbl_safe(tFP64M3x3 *mtrx, tFP64 mod)
{
	if (tFP64_IsNearby(mod, 0.0)) return True;
	mtrx->m00 /= mod;
	mtrx->m01 /= mod;
	mtrx->m02 /= mod;
	mtrx->m10 /= mod;
	mtrx->m11 /= mod;
	mtrx->m12 /= mod;
	mtrx->m20 /= mod;
	mtrx->m21 /= mod;
	mtrx->m22 /= mod;
	return False;
}
tBln tFP64M3x3_IsEq(tFP64M3x3 mtrx1, tFP64M3x3 mtrx2)
{
	return tFP64_IsNearby(mtrx1.m00, mtrx2.m00) && tFP64_IsNearby(mtrx1.m01, mtrx2.m01) && tFP64_IsNearby(mtrx1.m02, mtrx2.m02) && tFP64_IsNearby(mtrx1.m10, mtrx2.m10) && tFP64_IsNearby(mtrx1.m11, mtrx2.m11) && tFP64_IsNearby(mtrx1.m12, mtrx2.m12) && tFP64_IsNearby(mtrx1.m20, mtrx2.m20) && tFP64_IsNearby(mtrx1.m21, mtrx2.m21) && tFP64_IsNearby(mtrx1.m22, mtrx2.m22);
}
tBln tFP64M3x3_IsNearby(tFP64M3x3 mtrx1, tFP64M3x3 mtrx2, tFP64 eps)
{
	return (tFP64_Abs(mtrx1.m00 - mtrx2.m00) <= eps) && (tFP64_Abs(mtrx1.m01 - mtrx2.m01) <= eps) && (tFP64_Abs(mtrx1.m02 - mtrx2.m02) <= eps) && (tFP64_Abs(mtrx1.m10 - mtrx2.m10) <= eps) && (tFP64_Abs(mtrx1.m11 - mtrx2.m11) <= eps) && (tFP64_Abs(mtrx1.m12 - mtrx2.m12) <= eps) && (tFP64_Abs(mtrx1.m20 - mtrx2.m20) <= eps) && (tFP64_Abs(mtrx1.m21 - mtrx2.m21) <= eps) && (tFP64_Abs(mtrx1.m22 - mtrx2.m22) <= eps);
}
tFP64V3D tFP64M3x3_MulVect(tFP64M3x3 mtrx, tFP64V3D vect)
{
	tFP64V3D res;
	res.x = (mtrx.m00 * vect.x) + (mtrx.m01 * vect.y) + (mtrx.m02 * vect.z);
	res.y = (mtrx.m10 * vect.x) + (mtrx.m11 * vect.y) + (mtrx.m12 * vect.z);
	res.z = (mtrx.m20 * vect.x) + (mtrx.m21 * vect.y) + (mtrx.m22 * vect.z);
	return res;
}
tFP64M3x3 tFP64M3x3_Transp(tFP64M3x3 mtrx)
{
	tFP64 tmp = mtrx.m01;
	mtrx.m01 = mtrx.m10;
	mtrx.m10 = tmp;
	tmp = mtrx.m02;
	mtrx.m02 = mtrx.m20;
	mtrx.m20 = tmp;
	tmp = mtrx.m12;
	mtrx.m12 = mtrx.m21;
	mtrx.m21 = tmp;
	return mtrx;
}
tFP64 tFP64M3x3_Det(tFP64M3x3 mtrx)
{
	return (mtrx.m00 * ((mtrx.m11 * mtrx.m22) - (mtrx.m12 * mtrx.m21))) - (mtrx.m01 * ((mtrx.m10 * mtrx.m22) - (mtrx.m12 * mtrx.m20))) + (mtrx.m02 * ((mtrx.m10 * mtrx.m21) - (mtrx.m11 * mtrx.m20)));
}
tFP64M3x3 tFP64M3x3_Cofact(tFP64M3x3 mtrx)
{
	tFP64M3x3 cof;
	cof.m00 = mtrx.m11 * mtrx.m22 - mtrx.m12 * mtrx.m21;
	cof.m01 = tFP64_Neg(mtrx.m10 * mtrx.m22 - mtrx.m12 * mtrx.m20);
	cof.m02 = mtrx.m10 * mtrx.m21 - mtrx.m11 * mtrx.m20;
	cof.m10 = tFP64_Neg(mtrx.m01 * mtrx.m22 - mtrx.m02 * mtrx.m21);
	cof.m11 = mtrx.m00 * mtrx.m22 - mtrx.m02 * mtrx.m20;
	cof.m12 = tFP64_Neg(mtrx.m00 * mtrx.m21 - mtrx.m01 * mtrx.m20);
	cof.m20 = mtrx.m01 * mtrx.m12 - mtrx.m02 * mtrx.m11;
	cof.m21 = tFP64_Neg(mtrx.m00 * mtrx.m12 - mtrx.m02 * mtrx.m10);
	cof.m22 = mtrx.m00 * mtrx.m11 - mtrx.m01 * mtrx.m10;
	return cof;
}
tFP64M3x3 tFP64M3x3_Adj(tFP64M3x3 mtrx)
{
	return tFP64M3x3_Transp(tFP64M3x3_Cofact(mtrx));
}
tFP64M3x3 tFP64M3x3_Inv(tFP64M3x3 mtrx)
{
	tFP64 det = tFP64M3x3_Det(mtrx);
#ifndef BQSELAYER_DEBUG
	if (tFP64_Abs(det) <= tFP64_Eps) return tFP64M3x3_Zero();
#else
	Assertion(tFP64_Abs(det) > tFP64_Eps);
#endif/*BQSELAYER_DEBUG*/
	return tFP64M3x3_DivDbl(tFP64M3x3_Adj(mtrx), det);
}
tBln tFP64M3x3_Inv_safe(tFP64M3x3 *mtrx)
{
	tFP64 det = tFP64M3x3_Det(*mtrx);
	if (tFP64_Abs(det) <= tFP64_Eps) return True;
	*mtrx = tFP64M3x3_DivDbl(tFP64M3x3_Adj(*mtrx), det);
	return False;
}
tFP64M3x3 tFP64M3x3_Transl(tFP64 x, tFP64 y)
{
	tFP64M3x3 mtrx = tFP64M3x3_Id();
	mtrx.m02 = x;
	mtrx.m12 = y;
	return mtrx;
}
tFP64M3x3 tFP64M3x3_Scale(tFP64 x, tFP64 y)
{
	tFP64M3x3 mtrx = tFP64M3x3_Id();
	mtrx.m00 = x;
	mtrx.m11 = y;
	return mtrx;
}
tFP64M3x3 tFP64M3x3_Rot_fast(tFP64 ang)
{
	tFP64M3x3 mtrx = tFP64M3x3_Id();
	mtrx.m00 = mtrx.m11 = tFP64_Cosine_fast(ang);
	mtrx.m10 = tFP64_Sine_fast(ang);
	mtrx.m01 = tFP64_Neg(mtrx.m10);
	return mtrx;
}
tFP64M3x3 tFP64M3x3_Rot_iter(tFP64 ang, tIUSz itr)
{
	tFP64M3x3 mtrx = tFP64M3x3_Id();
	mtrx.m00 = mtrx.m11 = tFP64_Cosine_iter(ang, itr);
	mtrx.m10 = tFP64_Sine_iter(ang, itr);
	mtrx.m01 = tFP64_Neg(mtrx.m10);
	return mtrx;
}
tFP64M3x3 tFP64M3x3_Rot(tFP64 ang)
{
	tFP64M3x3 mtrx = tFP64M3x3_Id();
	mtrx.m00 = mtrx.m11 = tFP64_Cosine(ang);
	mtrx.m10 = tFP64_Sine(ang);
	mtrx.m01 = tFP64_Neg(mtrx.m10);
	return mtrx;
}
tFP64 tFP64M3x3_Trace(tFP64M3x3 mtrx)
{
	return mtrx.m00 + mtrx.m11 + mtrx.m22;
}
tFP64V2D tFP64M3x3_TransfPoint(tFP64M3x3 mtrx, tFP64V2D vect)
{
	tFP64V2D res;
	res.x = mtrx.m00 * vect.x + mtrx.m01 * vect.y + mtrx.m02;
	res.y = mtrx.m10 * vect.x + mtrx.m11 * vect.y + mtrx.m12;
	return res;
}
tFP64V2D tFP64M3x3_TransfDir(tFP64M3x3 mtrx, tFP64V2D vect)
{
	tFP64V2D res;
	res.x = mtrx.m00 * vect.x + mtrx.m01 * vect.y;
	res.y = mtrx.m10 * vect.x + mtrx.m11 * vect.y;
	return res;
}
tNone tFP64M3x3_RowSwap(tFP64M3x3 *mtrx, tIU8 idx1, tIU8 idx2)
{
	tFP64_Swap(&mtrx->m[idx1][0], &mtrx->m[idx2][0]);
	tFP64_Swap(&mtrx->m[idx1][1], &mtrx->m[idx2][1]);
	tFP64_Swap(&mtrx->m[idx1][2], &mtrx->m[idx2][2]);
}
tNone tFP64M3x3_RowAdd(tFP64M3x3 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP64 mult)
{
	mtrx->m[dstRow][0] += mtrx->m[srcRow][0] * mult;
	mtrx->m[dstRow][1] += mtrx->m[srcRow][1] * mult;
	mtrx->m[dstRow][2] += mtrx->m[srcRow][2] * mult;
}
tNone tFP64M3x3_RowMult(tFP64M3x3 *mtrx, tIU8 idx, tFP64 mult)
{
	mtrx->m[idx][0] *= mult;
	mtrx->m[idx][1] *= mult;
	mtrx->m[idx][2] *= mult;
}
tNone tFP64M3x3_RowEch(tFP64M3x3 *mtrx)
{
	tIU8 pivotRow = 0U;
	for (tIU8 col = 0U; col < 3U; ++col)
	{
		if (pivotRow >= 3U) break;
		tBln foundPivot = False;
		if (!tFP64_IsNearby(mtrx->m[pivotRow][col], 0.0)) foundPivot = True;
		else
		{
			for (tIU8 idx = 1U; idx < 3U - pivotRow; ++idx)
			{
				if (!tFP64_IsNearby(mtrx->m[pivotRow + idx][col], 0.0))
				{
					tFP64M3x3_RowSwap(mtrx, pivotRow, pivotRow + idx);
					foundPivot = True;
					break;
				}
			}
			if (foundPivot == False) continue;
		}
		tFP64M3x3_RowMult(mtrx, pivotRow, tFP64_Recip(mtrx->m[pivotRow][col]));
		for (tIU8 idx = 1U; idx < 3U - pivotRow; ++idx) tFP64M3x3_RowAdd(mtrx, pivotRow + idx, pivotRow, tFP64_Neg(mtrx->m[pivotRow + idx][col]));
		++pivotRow;
	}
}
tNone tFP64M3x3_RowRedEch(tFP64M3x3 *mtrx)
{
	tFP64M3x3_RowEch(mtrx);
	for (tIS8 row = 2; row >= 0; --row)
	{
		tBln foundPivot = False;
		tIU8 pivotCol = 0;
		for (tIU8 col = 0U; col < 3; ++col)
		{
			if (!tFP64_IsNearby(mtrx->m[row][col], 0.0))
			{
				foundPivot = True;
				pivotCol = col;
				break;
			}
		}
		if (foundPivot == False) continue;
		for (tIU8 aboveRow = 0U; aboveRow < row; ++aboveRow) tFP64M3x3_RowAdd(mtrx, aboveRow, row, tFP64_Neg(mtrx->m[aboveRow][pivotCol]));
	}
}
tFP64M3x3 tFP64M3x3_InvAff(tFP64M3x3 mtrx)
{
	if (!tFP64M3x3_IsAff(mtrx)) return tFP64M3x3_Zero();
	tFP64 det = mtrx.m00 * mtrx.m11 - mtrx.m01 * mtrx.m10;
	tFP64 invDet = tFP64_Recip(det);
	tFP64M3x3 out;
	out.m00 = mtrx.m11 * invDet;
	out.m01 = tFP64_Neg(mtrx.m01 * invDet);
	out.m10 = tFP64_Neg(mtrx.m10 * invDet);
	out.m11 = mtrx.m00 * invDet;
	out.m02 = tFP64_Neg(out.m00 * mtrx.m02 + out.m01 * mtrx.m12);
	out.m12 = tFP64_Neg(out.m10 * mtrx.m02 + out.m11 * mtrx.m12);
	out.m20 = 0.0;
	out.m21 = 0.0;
	out.m22 = 1.0;
	return out;
}
ForceInline tBln tFP64M3x3_IsAff(tFP64M3x3 mtrx)
{
	return tFP64_IsNearby(mtrx.m20, 0.0F) && tFP64_IsNearby(mtrx.m21, 0.0F) && tFP64_IsNearby(mtrx.m22, 0.0F);
}
#endif/*BQSELAYER_MTRX_IMPL*/
typedef union { struct { tFP64 m00, m01, m02, m03; tFP64 m10, m11, m12, m13; tFP64 m20, m21, m22, m23; tFP64 m30, m31, m64, m33; }; tFP64 m[4][4]; tFP64V4D row[4]; } tFP64M4x4;
LINK_C_Begin
tFP64M4x4 tFP64M4x4_Make(tFP64 m00, tFP64 m01, tFP64 m02, tFP64 m03, tFP64 m10, tFP64 m11, tFP64 m12, tFP64 m13, tFP64 m20, tFP64 m21, tFP64 m22, tFP64 m23, tFP64 m30, tFP64 m31, tFP64 m64, tFP64 m33);
tFP64M4x4 tFP64M4x4_Zero(tNone);
tFP64M4x4 tFP64M4x4_Id(tNone);
tFP64M4x4 tFP64M4x4_Add(tFP64M4x4 mtrx1, tFP64M4x4 mtrx2);
tFP64M4x4 tFP64M4x4_Sub(tFP64M4x4 mtrx1, tFP64M4x4 mtrx2);
tFP64M4x4 tFP64M4x4_Mul(tFP64M4x4 mtrx1, tFP64M4x4 mtrx2);
tFP64M4x4 tFP64M4x4_MulDbl(tFP64M4x4 mtrx, tFP64 mod);
/*Warn: Silently returns a matrix with all components either -Inf or +Inf when `mod` is 0.*/
tFP64M4x4 tFP64M4x4_DivDbl(tFP64M4x4 mtrx, tFP64 mod);
/*Note: Returns `False` on success.*/
tBln tFP64M4x4_DivDbl_safe(tFP64M4x4 *mtrx, tFP64 mod);
tBln tFP64M4x4_IsEq(tFP64M4x4 mtrx1, tFP64M4x4 mtrx2);
tBln tFP64M4x4_IsNearby(tFP64M4x4 mtrx1, tFP64M4x4 mtrx2, tFP64 eps);
tFP64V4D tFP64M4x4_MulVect(tFP64M4x4 mtrx, tFP64V4D vect);
tFP64M4x4 tFP64M4x4_Transp(tFP64M4x4 mtrx);
tFP64 tFP64M4x4_Det(tFP64M4x4 mtrx);
/*Warn: Silently returns `tFP64M3x3_Zero` on failure.*/
tFP64M3x3 tFP64M4x4_Minor(tFP64M4x4 mtrx, tIU8 row, tIU8 col);
/*Note: Returns `False` on success.*/
tBln tFP64M4x4_Minor_s(tFP64M3x3 *out, tFP64M4x4 mtrx, tIU8 row, tIU8 col);
tFP64M4x4 tFP64M4x4_Cofact(tFP64M4x4 mtrx);
tFP64M4x4 tFP64M4x4_Adj(tFP64M4x4 mtrx);
/*Warn: Silently returns `tFP64M4x4_Zero` on failure.*/
tFP64M4x4 tFP64M4x4_Inv(tFP64M4x4 mtrx);
/*Note: Returns `False` on success.*/
tBln tFP64M4x4_Inv_safe(tFP64M4x4 *mtrx);
tFP64M4x4 tFP64M4x4_Transl(tFP64 x, tFP64 y, tFP64 z);
tFP64M4x4 tFP64M4x4_Scale(tFP64 x, tFP64 y, tFP64 z);
/*Note: Parameter `ang` is in radians.*/
tFP64M4x4 tFP64M4x4_RotX_fast(tFP64 ang);
/*Note: Parameter `ang` is in radians.*/
tFP64M4x4 tFP64M4x4_RotX_iter(tFP64 ang, tIUSz itr);
/*Note: Parameter `ang` is in radians.*/
tFP64M4x4 tFP64M4x4_RotX(tFP64 ang);
/*Note: Parameter `ang` is in radians.*/
tFP64M4x4 tFP64M4x4_RotY_fast(tFP64 ang);
/*Note: Parameter `ang` is in radians.*/
tFP64M4x4 tFP64M4x4_RotY_iter(tFP64 ang, tIUSz itr);
/*Note: Parameter `ang` is in radians.*/
tFP64M4x4 tFP64M4x4_RotY(tFP64 ang);
/*Note: Parameter `ang` is in radians.*/
tFP64M4x4 tFP64M4x4_RotZ_fast(tFP64 ang);
/*Note: Parameter `ang` is in radians.*/
tFP64M4x4 tFP64M4x4_RotZ_iter(tFP64 ang, tIUSz itr);
/*Note: Parameter `ang` is in radians.*/
tFP64M4x4 tFP64M4x4_RotZ(tFP64 ang);
tFP64M4x4 tFP64M4x4_Ortho(tFP64 left, tFP64 right, tFP64 bot, tFP64 top, tFP64 near, tFP64 far);
tFP64 tFP64M4x4_Trace(tFP64M4x4 mtrx);
/*Note: Parameter `ang` is in radians.*/
tFP64M4x4 tFP64M4x4_RotAxis_fast(tFP64V3D axis, tFP64 ang);
tFP64M4x4 tFP64M4x4_RotAxis_iter(tFP64V3D axis, tFP64 ang, tIUSz itr);
tFP64M4x4 tFP64M4x4_RotAxis(tFP64V3D axis, tFP64 ang);
tFP64V3D tFP64M4x4_TransfPoint(tFP64M4x4 mtrx, tFP64V3D vect);
tFP64V3D tFP64M4x4_TransfDir(tFP64M4x4 mtrx, tFP64V3D vect);
tNone tFP64M4x4_RowSwap(tFP64M4x4 *mtrx, tIU8 idx1, tIU8 idx2);
tNone tFP64M4x4_RowAdd(tFP64M4x4 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP64 mult);
tNone tFP64M4x4_RowMult(tFP64M4x4 *mtrx, tIU8 idx, tFP64 mult);
tNone tFP64M4x4_RowEch(tFP64M4x4 *mtrx);
tNone tFP64M4x4_RowRedEch(tFP64M4x4 *mtrx);
/*Warn: Returns `tFP64M4x4_Zero` if parameter `mtrx` is not an affine matrix.*/
tFP64M4x4 tFP64M4x4_InvAff(tFP64M4x4 mtrx);
tFP64M4x4 tFP64M4x4_Persp_fast(tFP64 fov, tFP64 aspRatio, tFP64 near, tFP64 far, tIS8 minZ);
tFP64M4x4 tFP64M4x4_Persp_iter(tFP64 fov, tFP64 aspRatio, tFP64 near, tFP64 far, tIS8 minZ, tIUSz itr);
tFP64M4x4 tFP64M4x4_Persp(tFP64 fov, tFP64 aspRatio, tFP64 near, tFP64 far, tIS8 minZ);
tBln tFP64M4x4_IsAff(tFP64M4x4 mtrx);
tFP64M4x4 tFP64M4x4_LookAt(tFP64V3D eye, tFP64V3D target, tFP64V3D up);
tFP64M3x3 tFP64M4x4_NormalMtrx(tFP64M4x4 mtrx);
LINK_C_End
#ifdef BQSELAYER_MTRX_IMPL
tFP64M4x4 tFP64M4x4_Make(tFP64 m00, tFP64 m01, tFP64 m02, tFP64 m03, tFP64 m10, tFP64 m11, tFP64 m12, tFP64 m13, tFP64 m20, tFP64 m21, tFP64 m22, tFP64 m23, tFP64 m30, tFP64 m31, tFP64 m64, tFP64 m33)
{
	tFP64M4x4 mtrx;
	mtrx.m00 = m00;
	mtrx.m01 = m01;
	mtrx.m02 = m02;
	mtrx.m03 = m03;
	mtrx.m10 = m10;
	mtrx.m11 = m11;
	mtrx.m12 = m12;
	mtrx.m13 = m13;
	mtrx.m20 = m20;
	mtrx.m21 = m21;
	mtrx.m22 = m22;
	mtrx.m23 = m23;
	mtrx.m30 = m30;
	mtrx.m31 = m31;
	mtrx.m64 = m64;
	mtrx.m33 = m33;
	return mtrx;
}
tFP64M4x4 tFP64M4x4_Zero(tNone)
{
	tFP64M4x4 mtrx;
	mtrx.m00 = mtrx.m01 = mtrx.m02 = mtrx.m03 = mtrx.m10 = mtrx.m11 = mtrx.m12 = mtrx.m13 = mtrx.m20 = mtrx.m21 = mtrx.m22 = mtrx.m23 = mtrx.m30 = mtrx.m31 = mtrx.m64 = mtrx.m33 = 0.0;
	return mtrx;
}
tFP64M4x4 tFP64M4x4_Id(tNone)
{
	tFP64M4x4 mtrx;
	mtrx.m01 = mtrx.m02 = mtrx.m03 = mtrx.m10 = mtrx.m12 = mtrx.m13 = mtrx.m20 = mtrx.m21 = mtrx.m23 = mtrx.m30 = mtrx.m31 = mtrx.m64 = 0.0;
	mtrx.m00 = mtrx.m11 = mtrx.m22 = mtrx.m33 = 1.0;
	return mtrx;
}
tFP64M4x4 tFP64M4x4_Add(tFP64M4x4 mtrx1, tFP64M4x4 mtrx2)
{
	mtrx1.m00 += mtrx2.m00;
	mtrx1.m01 += mtrx2.m01;
	mtrx1.m02 += mtrx2.m02;
	mtrx1.m03 += mtrx2.m03;
	mtrx1.m10 += mtrx2.m10;
	mtrx1.m11 += mtrx2.m11;
	mtrx1.m12 += mtrx2.m12;
	mtrx1.m13 += mtrx2.m13;
	mtrx1.m20 += mtrx2.m20;
	mtrx1.m21 += mtrx2.m21;
	mtrx1.m22 += mtrx2.m22;
	mtrx1.m23 += mtrx2.m23;
	mtrx1.m30 += mtrx2.m30;
	mtrx1.m31 += mtrx2.m31;
	mtrx1.m64 += mtrx2.m64;
	mtrx1.m33 += mtrx2.m33;
	return mtrx1;
}
tFP64M4x4 tFP64M4x4_Sub(tFP64M4x4 mtrx1, tFP64M4x4 mtrx2)
{
	mtrx1.m00 -= mtrx2.m00;
	mtrx1.m01 -= mtrx2.m01;
	mtrx1.m02 -= mtrx2.m02;
	mtrx1.m03 -= mtrx2.m03;
	mtrx1.m10 -= mtrx2.m10;
	mtrx1.m11 -= mtrx2.m11;
	mtrx1.m12 -= mtrx2.m12;
	mtrx1.m13 -= mtrx2.m13;
	mtrx1.m20 -= mtrx2.m20;
	mtrx1.m21 -= mtrx2.m21;
	mtrx1.m22 -= mtrx2.m22;
	mtrx1.m23 -= mtrx2.m23;
	mtrx1.m30 -= mtrx2.m30;
	mtrx1.m31 -= mtrx2.m31;
	mtrx1.m64 -= mtrx2.m64;
	mtrx1.m33 -= mtrx2.m33;
	return mtrx1;
}
tFP64M4x4 tFP64M4x4_Mul(tFP64M4x4 mtrx1, tFP64M4x4 mtrx2)
{
	tFP64M4x4 res;
	res.m00 = (mtrx1.m00 * mtrx2.m00) + (mtrx1.m01 * mtrx2.m10) + (mtrx1.m02 * mtrx2.m20) + (mtrx1.m03 * mtrx2.m30);
	res.m01 = (mtrx1.m00 * mtrx2.m01) + (mtrx1.m01 * mtrx2.m11) + (mtrx1.m02 * mtrx2.m21) + (mtrx1.m03 * mtrx2.m31);
	res.m02 = (mtrx1.m00 * mtrx2.m02) + (mtrx1.m01 * mtrx2.m12) + (mtrx1.m02 * mtrx2.m22) + (mtrx1.m03 * mtrx2.m64);
	res.m03 = (mtrx1.m00 * mtrx2.m03) + (mtrx1.m01 * mtrx2.m13) + (mtrx1.m02 * mtrx2.m23) + (mtrx1.m03 * mtrx2.m33);
	res.m10 = (mtrx1.m10 * mtrx2.m00) + (mtrx1.m11 * mtrx2.m10) + (mtrx1.m12 * mtrx2.m20) + (mtrx1.m13 * mtrx2.m30);
	res.m11 = (mtrx1.m10 * mtrx2.m01) + (mtrx1.m11 * mtrx2.m11) + (mtrx1.m12 * mtrx2.m21) + (mtrx1.m13 * mtrx2.m31);
	res.m12 = (mtrx1.m10 * mtrx2.m02) + (mtrx1.m11 * mtrx2.m12) + (mtrx1.m12 * mtrx2.m22) + (mtrx1.m13 * mtrx2.m64);
	res.m13 = (mtrx1.m10 * mtrx2.m03) + (mtrx1.m11 * mtrx2.m13) + (mtrx1.m12 * mtrx2.m23) + (mtrx1.m13 * mtrx2.m33);
	res.m20 = (mtrx1.m20 * mtrx2.m00) + (mtrx1.m21 * mtrx2.m10) + (mtrx1.m22 * mtrx2.m20) + (mtrx1.m23 * mtrx2.m30);
	res.m21 = (mtrx1.m20 * mtrx2.m01) + (mtrx1.m21 * mtrx2.m11) + (mtrx1.m22 * mtrx2.m21) + (mtrx1.m23 * mtrx2.m31);
	res.m22 = (mtrx1.m20 * mtrx2.m02) + (mtrx1.m21 * mtrx2.m12) + (mtrx1.m22 * mtrx2.m22) + (mtrx1.m23 * mtrx2.m64);
	res.m23 = (mtrx1.m20 * mtrx2.m03) + (mtrx1.m21 * mtrx2.m13) + (mtrx1.m22 * mtrx2.m23) + (mtrx1.m23 * mtrx2.m33);
	res.m30 = (mtrx1.m30 * mtrx2.m00) + (mtrx1.m31 * mtrx2.m10) + (mtrx1.m64 * mtrx2.m20) + (mtrx1.m33 * mtrx2.m30);
	res.m31 = (mtrx1.m30 * mtrx2.m01) + (mtrx1.m31 * mtrx2.m11) + (mtrx1.m64 * mtrx2.m21) + (mtrx1.m33 * mtrx2.m31);
	res.m64 = (mtrx1.m30 * mtrx2.m02) + (mtrx1.m31 * mtrx2.m12) + (mtrx1.m64 * mtrx2.m22) + (mtrx1.m33 * mtrx2.m64);
	res.m33 = (mtrx1.m30 * mtrx2.m03) + (mtrx1.m31 * mtrx2.m13) + (mtrx1.m64 * mtrx2.m23) + (mtrx1.m33 * mtrx2.m33);
	return res;
}
tFP64M4x4 tFP64M4x4_MulDbl(tFP64M4x4 mtrx, tFP64 mod)
{
	mtrx.m00 *= mod;
	mtrx.m01 *= mod;
	mtrx.m02 *= mod;
	mtrx.m03 *= mod;
	mtrx.m10 *= mod;
	mtrx.m11 *= mod;
	mtrx.m12 *= mod;
	mtrx.m13 *= mod;
	mtrx.m20 *= mod;
	mtrx.m21 *= mod;
	mtrx.m22 *= mod;
	mtrx.m23 *= mod;
	mtrx.m30 *= mod;
	mtrx.m31 *= mod;
	mtrx.m64 *= mod;
	mtrx.m33 *= mod;
	return mtrx;
}
tFP64M4x4 tFP64M4x4_DivDbl(tFP64M4x4 mtrx, tFP64 mod)
{
#ifndef BQSELAYER_DEBUG
	if (tFP64_IsNearby(mod, 0.0))
	{
		mtrx.m00 = tFP64_IsNeg(mtrx.m00) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m01 = tFP64_IsNeg(mtrx.m01) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m02 = tFP64_IsNeg(mtrx.m02) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m03 = tFP64_IsNeg(mtrx.m03) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m10 = tFP64_IsNeg(mtrx.m10) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m11 = tFP64_IsNeg(mtrx.m11) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m12 = tFP64_IsNeg(mtrx.m12) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m13 = tFP64_IsNeg(mtrx.m13) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m20 = tFP64_IsNeg(mtrx.m20) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m21 = tFP64_IsNeg(mtrx.m21) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m22 = tFP64_IsNeg(mtrx.m22) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m23 = tFP64_IsNeg(mtrx.m23) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m30 = tFP64_IsNeg(mtrx.m30) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m31 = tFP64_IsNeg(mtrx.m31) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m64 = tFP64_IsNeg(mtrx.m64) ? tFP64_NegInf() : tFP64_Inf();
		mtrx.m33 = tFP64_IsNeg(mtrx.m33) ? tFP64_NegInf() : tFP64_Inf();
		return mtrx;
	}
#else
	Assertion(!tFP64_IsNearby(mod, 0.0));
#endif/*BQSELAYER_DEBUG*/
	mtrx.m00 /= mod;
	mtrx.m01 /= mod;
	mtrx.m02 /= mod;
	mtrx.m03 /= mod;
	mtrx.m10 /= mod;
	mtrx.m11 /= mod;
	mtrx.m12 /= mod;
	mtrx.m13 /= mod;
	mtrx.m20 /= mod;
	mtrx.m21 /= mod;
	mtrx.m22 /= mod;
	mtrx.m23 /= mod;
	mtrx.m30 /= mod;
	mtrx.m31 /= mod;
	mtrx.m64 /= mod;
	mtrx.m33 /= mod;
	return mtrx;
}
tBln tFP64M4x4_DivDbl_safe(tFP64M4x4 *mtrx, tFP64 mod)
{
	if (tFP64_IsNearby(mod, 0.0)) return True;
	mtrx->m00 /= mod;
	mtrx->m01 /= mod;
	mtrx->m02 /= mod;
	mtrx->m03 /= mod;
	mtrx->m10 /= mod;
	mtrx->m11 /= mod;
	mtrx->m12 /= mod;
	mtrx->m13 /= mod;
	mtrx->m20 /= mod;
	mtrx->m21 /= mod;
	mtrx->m22 /= mod;
	mtrx->m23 /= mod;
	mtrx->m30 /= mod;
	mtrx->m31 /= mod;
	mtrx->m64 /= mod;
	mtrx->m33 /= mod;
	return False;
}
tBln tFP64M4x4_IsEq(tFP64M4x4 mtrx1, tFP64M4x4 mtrx2)
{
	return tFP64_IsNearby(mtrx1.m00, mtrx2.m00) && tFP64_IsNearby(mtrx1.m01, mtrx2.m01) && tFP64_IsNearby(mtrx1.m02, mtrx2.m02) && tFP64_IsNearby(mtrx1.m03, mtrx2.m03) && tFP64_IsNearby(mtrx1.m10, mtrx2.m10) && tFP64_IsNearby(mtrx1.m11, mtrx2.m11) && tFP64_IsNearby(mtrx1.m12, mtrx2.m12) && tFP64_IsNearby(mtrx1.m13, mtrx2.m13) && tFP64_IsNearby(mtrx1.m20, mtrx2.m20) && tFP64_IsNearby(mtrx1.m21, mtrx2.m21) && tFP64_IsNearby(mtrx1.m22, mtrx2.m22) && tFP64_IsNearby(mtrx1.m23, mtrx2.m23) && tFP64_IsNearby(mtrx1.m30, mtrx2.m30) && tFP64_IsNearby(mtrx1.m31, mtrx2.m31) && tFP64_IsNearby(mtrx1.m64, mtrx2.m64) && tFP64_IsNearby(mtrx1.m33, mtrx2.m33);
}
tBln tFP64M4x4_IsNearby(tFP64M4x4 mtrx1, tFP64M4x4 mtrx2, tFP64 eps)
{
	return (tFP64_Abs(mtrx1.m00 - mtrx2.m00) <= eps) && (tFP64_Abs(mtrx1.m01 - mtrx2.m01) <= eps) && (tFP64_Abs(mtrx1.m02 - mtrx2.m02) <= eps) && (tFP64_Abs(mtrx1.m03 - mtrx2.m03) <= eps) && (tFP64_Abs(mtrx1.m10 - mtrx2.m10) <= eps) && (tFP64_Abs(mtrx1.m11 - mtrx2.m11) <= eps) && (tFP64_Abs(mtrx1.m12 - mtrx2.m12) <= eps) && (tFP64_Abs(mtrx1.m13 - mtrx2.m13) <= eps) && (tFP64_Abs(mtrx1.m20 - mtrx2.m20) <= eps) && (tFP64_Abs(mtrx1.m21 - mtrx2.m21) <= eps) && (tFP64_Abs(mtrx1.m22 - mtrx2.m22) <= eps) && (tFP64_Abs(mtrx1.m23 - mtrx2.m23) <= eps) && (tFP64_Abs(mtrx1.m30 - mtrx2.m30) <= eps) && (tFP64_Abs(mtrx1.m31 - mtrx2.m31) <= eps) && (tFP64_Abs(mtrx1.m64 - mtrx2.m64) <= eps) && (tFP64_Abs(mtrx1.m33 - mtrx2.m33) <= eps);
}
tFP64V4D tFP64M4x4_MulVect(tFP64M4x4 mtrx, tFP64V4D vect)
{
	tFP64V4D res;
	res.x = (mtrx.m00 * vect.x) + (mtrx.m01 * vect.y) + (mtrx.m02 * vect.z) + (mtrx.m03 * vect.w);
	res.y = (mtrx.m10 * vect.x) + (mtrx.m11 * vect.y) + (mtrx.m12 * vect.z) + (mtrx.m13 * vect.w);
	res.z = (mtrx.m20 * vect.x) + (mtrx.m21 * vect.y) + (mtrx.m22 * vect.z) + (mtrx.m23 * vect.w);
	res.w = (mtrx.m30 * vect.x) + (mtrx.m31 * vect.y) + (mtrx.m64 * vect.z) + (mtrx.m33 * vect.w);
	return res;
}
tFP64M4x4 tFP64M4x4_Transp(tFP64M4x4 mtrx)
{
	return tFP64M4x4_Make(mtrx.m00, mtrx.m10, mtrx.m20, mtrx.m30, mtrx.m01, mtrx.m11, mtrx.m21, mtrx.m31, mtrx.m02, mtrx.m12, mtrx.m22, mtrx.m64, mtrx.m03, mtrx.m13, mtrx.m23, mtrx.m33);
}
tFP64 tFP64M4x4_Det(tFP64M4x4 mtrx)
{
	return (mtrx.m00 * (tFP64M3x3_Det(tFP64M3x3_Make(mtrx.m11, mtrx.m12, mtrx.m13, mtrx.m21, mtrx.m22, mtrx.m23, mtrx.m31, mtrx.m64, mtrx.m33)))) - (mtrx.m01 * (tFP64M3x3_Det(tFP64M3x3_Make(mtrx.m10, mtrx.m12, mtrx.m13, mtrx.m20, mtrx.m22, mtrx.m23, mtrx.m30, mtrx.m64, mtrx.m33)))) + (mtrx.m02 * (tFP64M3x3_Det(tFP64M3x3_Make(mtrx.m10, mtrx.m11, mtrx.m13, mtrx.m20, mtrx.m21, mtrx.m23, mtrx.m30, mtrx.m31, mtrx.m33)))) - (mtrx.m03 * (tFP64M3x3_Det(tFP64M3x3_Make(mtrx.m10, mtrx.m11, mtrx.m12, mtrx.m20, mtrx.m21, mtrx.m22, mtrx.m30, mtrx.m31, mtrx.m64))));
}
tFP64M3x3 tFP64M4x4_Minor(tFP64M4x4 mtrx, tIU8 row, tIU8 col)
{
#ifndef BQSELAYER_DEBUG
	if (row >= 4U) return tFP64M3x3_Zero();
	if (col >= 4U) return tFP64M3x3_Zero();
#else
	Assertion(row < 4U);
	Assertion(col < 4U);
#endif/*BQSELAYER_DEBUG*/
	tFP64M3x3 minor;
	tIU8 offsetI = 0U;
	for (tIU8 idx = 0U; idx < 3U; ++idx)
	{
		if (idx == row) offsetI = 1U;
		tIU8 offsetJ = 0U;
		for (tIU8 jdx = 0U; jdx < 3U; ++jdx)
		{
			if (jdx == col) offsetJ = 1U;
			minor.m[idx][jdx] = mtrx.m[idx + offsetI][jdx + offsetJ];
		}
	}
	return minor;
}
tBln tFP64M4x4_Minor_s(tFP64M3x3 *out, tFP64M4x4 mtrx, tIU8 row, tIU8 col)
{
	if (row >= 4U) return True;
	if (col >= 4U) return True;
	tIU8 offsetI = 0U;
	for (tIU8 idx = 0U; idx < 3U; ++idx)
	{
		if (idx == row) offsetI = 1U;
		tIU8 offsetJ = 0U;
		for (tIU8 jdx = 0U; jdx < 3U; ++jdx)
		{
			if (jdx == col) offsetJ = 1U;
			out->m[idx][jdx] = mtrx.m[idx + offsetI][jdx + offsetJ];
		}
	}
	return False;
}
tFP64M4x4 tFP64M4x4_Cofact(tFP64M4x4 mtrx)
{
	tFP64M4x4 cof;
	for (tIU8 idx = 0U; idx < 4U; ++idx)
	{
		for (tIU8 jdx = 0U; jdx < 4U; ++jdx)
		{
			cof.m[idx][jdx] = tFP64M3x3_Det(tFP64M4x4_Minor(mtrx, idx, jdx));
			if ((idx + jdx) & 1U) cof.m[idx][jdx] = tFP64_Neg(cof.m[idx][jdx]);
		}
	}
	return cof;
}
tFP64M4x4 tFP64M4x4_Adj(tFP64M4x4 mtrx)
{
	return tFP64M4x4_Transp(tFP64M4x4_Cofact(mtrx));
}
tFP64M4x4 tFP64M4x4_Inv(tFP64M4x4 mtrx)
{
	tFP64 det = tFP64M4x4_Det(mtrx);
#ifndef BQSELAYER_DEBUG
	if (tFP64_Abs(det) <= tFP64_Eps) return tFP64M4x4_Zero();
#else
	Assertion(tFP64_Abs(det) > tFP64_Eps);
#endif/*BQSELAYER_DEBUG*/
	return tFP64M4x4_DivDbl(tFP64M4x4_Adj(mtrx), det);
}
tBln tFP64M4x4_Inv_safe(tFP64M4x4 *mtrx)
{
	tFP64 det = tFP64M4x4_Det(*mtrx);
	if (tFP64_Abs(det) <= tFP64_Eps) return True;
	*mtrx = tFP64M4x4_DivDbl(tFP64M4x4_Adj(*mtrx), det);
	return False;
}
tFP64M4x4 tFP64M4x4_Transl(tFP64 x, tFP64 y, tFP64 z)
{
	return tFP64M4x4_Make(1.0, 0.0, 0.0, x, 0.0, 1.0, 0.0, y, 0.0, 0.0, 1.0, z, 0.0, 0.0, 0.0, 1.0);
}
tFP64M4x4 tFP64M4x4_Scale(tFP64 x, tFP64 y, tFP64 z)
{
	return tFP64M4x4_Make(x, 0.0, 0.0, 0.0, 0.0, y, 0.0, 0.0, 0.0, 0.0, z, 0.0, 0.0, 0.0, 0.0, 1.0);
}
tFP64M4x4 tFP64M4x4_RotX_fast(tFP64 ang)
{
	const tFP64 tmpC = tFP64_Cosine_fast(ang);
	const tFP64 tmpS = tFP64_Sine_fast(ang);
	return tFP64M4x4_Make(1.0, 0.0, 0.0, 0.0, 0.0, tmpC, -tmpS, 0.0, 0.0, tmpS, tmpC, 0.0, 0.0, 0.0, 0.0, 1.0);
}
tFP64M4x4 tFP64M4x4_RotX_iter(tFP64 ang, tIUSz itr)
{
	const tFP64 tmpC = tFP64_Cosine_iter(ang, itr);
	const tFP64 tmpS = tFP64_Sine_iter(ang, itr);
	return tFP64M4x4_Make(1.0, 0.0, 0.0, 0.0, 0.0, tmpC, -tmpS, 0.0, 0.0, tmpS, tmpC, 0.0, 0.0, 0.0, 0.0, 1.0);
}
tFP64M4x4 tFP64M4x4_RotX(tFP64 ang)
{
	const tFP64 tmpC = tFP64_Cosine(ang);
	const tFP64 tmpS = tFP64_Sine(ang);
	return tFP64M4x4_Make(1.0, 0.0, 0.0, 0.0, 0.0, tmpC, -tmpS, 0.0, 0.0, tmpS, tmpC, 0.0, 0.0, 0.0, 0.0, 1.0);
}
tFP64M4x4 tFP64M4x4_RotY_fast(tFP64 ang)
{
	tFP64 tmpC = tFP64_Cosine_fast(ang);
	tFP64 tmpS = tFP64_Sine_fast(ang);
	return tFP64M4x4_Make(tmpC, 0.0, tmpS, 0.0, 0.0, 1.0, 0.0, 0.0, -tmpS, 0.0, tmpC, 0.0, 0.0, 0.0, 0.0, 1.0);
}
tFP64M4x4 tFP64M4x4_RotY_iter(tFP64 ang, tIUSz itr)
{
	tFP64 tmpC = tFP64_Cosine_iter(ang, itr);
	tFP64 tmpS = tFP64_Sine_iter(ang, itr);
	return tFP64M4x4_Make(tmpC, 0.0, tmpS, 0.0, 0.0, 1.0, 0.0, 0.0, -tmpS, 0.0, tmpC, 0.0, 0.0, 0.0, 0.0, 1.0);
}
tFP64M4x4 tFP64M4x4_RotY(tFP64 ang)
{
	tFP64 tmpC = tFP64_Cosine(ang);
	tFP64 tmpS = tFP64_Sine(ang);
	return tFP64M4x4_Make(tmpC, 0.0, tmpS, 0.0, 0.0, 1.0, 0.0, 0.0, -tmpS, 0.0, tmpC, 0.0, 0.0, 0.0, 0.0, 1.0);
}
tFP64M4x4 tFP64M4x4_RotZ_fast(tFP64 ang)
{
	tFP64 tmpC = tFP64_Cosine_fast(ang);
	tFP64 tmpS = tFP64_Sine_fast(ang);
	return tFP64M4x4_Make(tmpC, -tmpS, 0.0, 0.0, tmpS, tmpC, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}
tFP64M4x4 tFP64M4x4_RotZ_iter(tFP64 ang, tIUSz itr)
{
	tFP64 tmpC = tFP64_Cosine_iter(ang, itr);
	tFP64 tmpS = tFP64_Sine_iter(ang, itr);
	return tFP64M4x4_Make(tmpC, -tmpS, 0.0, 0.0, tmpS, tmpC, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}
tFP64M4x4 tFP64M4x4_RotZ(tFP64 ang)
{
	tFP64 tmpC = tFP64_Cosine(ang);
	tFP64 tmpS = tFP64_Sine(ang);
	return tFP64M4x4_Make(tmpC, -tmpS, 0.0, 0.0, tmpS, tmpC, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}
tFP64M4x4 tFP64M4x4_Ortho(tFP64 left, tFP64 right, tFP64 bot, tFP64 top, tFP64 near, tFP64 far)
{
	tFP64 tmpX = tFP64_Recip(right - left);
	tFP64 tmpY = tFP64_Recip(top - bot);
	tFP64 tmpZ = tFP64_Recip(far - near);
	return tFP64M4x4_Make(2.0 * tmpX, 0.0, 0.0, tFP64_Neg(right + left) * tmpX, 0.0, 2.0 * tmpY, 0.0, tFP64_Neg(top + bot) * tmpY, 0.0, 0.0, tmpZ, tFP64_Neg(near * tmpZ), 0.0, 0.0, 0.0, 1.0);
}
tFP64 tFP64M4x4_Trace(tFP64M4x4 mtrx)
{
	return mtrx.m00 + mtrx.m11 + mtrx.m22 + mtrx.m33;
}
tNone tFP64M4x4_RowSwap(tFP64M4x4 *mtrx, tIU8 idx1, tIU8 idx2)
{
	tFP64_Swap(&mtrx->m[idx1][0], &mtrx->m[idx2][0]);
	tFP64_Swap(&mtrx->m[idx1][1], &mtrx->m[idx2][1]);
	tFP64_Swap(&mtrx->m[idx1][2], &mtrx->m[idx2][2]);
	tFP64_Swap(&mtrx->m[idx1][3], &mtrx->m[idx2][3]);
}
tNone tFP64M4x4_RowAdd(tFP64M4x4 *mtrx, tIU8 dstRow, tIU8 srcRow, tFP64 mult)
{
	mtrx->m[dstRow][0] += mtrx->m[srcRow][0] * mult;
	mtrx->m[dstRow][1] += mtrx->m[srcRow][1] * mult;
	mtrx->m[dstRow][2] += mtrx->m[srcRow][2] * mult;
	mtrx->m[dstRow][3] += mtrx->m[srcRow][3] * mult;
}
tNone tFP64M4x4_RowMult(tFP64M4x4 *mtrx, tIU8 idx, tFP64 mult)
{
	mtrx->m[idx][0] *= mult;
	mtrx->m[idx][1] *= mult;
	mtrx->m[idx][2] *= mult;
	mtrx->m[idx][3] *= mult;
}
tNone tFP64M4x4_RowEch(tFP64M4x4 *mtrx)
{
	tIU8 pivotRow = 0U;
	for (tIU8 col = 0U; col < 4U; ++col)
	{
		if (pivotRow >= 4U) break;
		tBln foundPivot = False;
		if (!tFP64_IsNearby(mtrx->m[pivotRow][col], 0.0)) foundPivot = True;
		else
		{
			for (tIU8 idx = 1U; idx < 4U - pivotRow; ++idx)
			{
				if (!tFP64_IsNearby(mtrx->m[pivotRow + idx][col], 0.0))
				{
					tFP64M4x4_RowSwap(mtrx, pivotRow, pivotRow + idx);
					foundPivot = True;
					break;
				}
			}
			if (foundPivot == False) continue;
		}
		tFP64M4x4_RowMult(mtrx, pivotRow, tFP64_Recip(mtrx->m[pivotRow][col]));
		for (tIU8 idx = 1U; idx < 4U - pivotRow; ++idx) tFP64M4x4_RowAdd(mtrx, pivotRow + idx, pivotRow, tFP64_Neg(mtrx->m[pivotRow + idx][col]));
		++pivotRow;
	}
}
tNone tFP64M4x4_RowRedEch(tFP64M4x4 *mtrx)
{
	tFP64M4x4_RowEch(mtrx);
	for (tIS8 row = 3; row >= 0; --row)
	{
		tBln foundPivot = False;
		tIU8 pivotCol = 0;
		for (tIU8 col = 0U; col < 4; ++col)
		{
			if (!tFP64_IsNearby(mtrx->m[row][col], 0.0))
			{
				foundPivot = True;
				pivotCol = col;
				break;
			}
		}
		if (foundPivot == False) continue;
		for (tIU8 aboveRow = 0U; aboveRow < row; ++aboveRow) tFP64M4x4_RowAdd(mtrx, aboveRow, row, tFP64_Neg(mtrx->m[aboveRow][pivotCol]));
	}
}
tFP64V3D tFP64M4x4_TransfPoint(tFP64M4x4 mtrx, tFP64V3D vect)
{
	tFP64V4D tmp;
	tmp.x = vect.x;
	tmp.y = vect.y;
	tmp.z = vect.z;
	tmp.w = 1.0;
	tmp = tFP64M4x4_MulVect(mtrx, tmp);
	return tFP64V3D_Make(tmp.x, tmp.y, tmp.z);
}
tFP64V3D tFP64M4x4_TransfDir(tFP64M4x4 mtrx, tFP64V3D vect)
{
	tFP64V4D tmp;
	tmp.x = vect.x;
	tmp.y = vect.y;
	tmp.z = vect.z;
	tmp.w = 0.0;
	tmp = tFP64M4x4_MulVect(mtrx, tmp);
	return tFP64V3D_Make(tmp.x, tmp.y, tmp.z);
}
tFP64M4x4 tFP64M4x4_RotAxis_fast(tFP64V3D axis, tFP64 ang)
{
	axis = tFP64V3D_Norm_fast(axis);
	tFP64 cosAng = tFP64_Cosine_fast(ang);
	tFP64 sinAng = tFP64_Sine_fast(ang);
	tFP64 transl = 1.0 - cosAng;
	tFP64 translX = transl * axis.x;
	tFP64 translY = transl * axis.y;
	tFP64 sinAngX = sinAng * axis.x;
	tFP64 sinAngY = sinAng * axis.y;
	tFP64 sinAngZ = sinAng * axis.z;
	tFP64 translXY = translX * axis.y;
	tFP64 translXZ = translX * axis.z;
	tFP64 translYZ = translY * axis.z;
	tFP64M4x4 mat;
	mat.m00 = translX * axis.x + cosAng;
	mat.m01 = translXY - sinAngZ;
	mat.m02 = translXZ + sinAngY;
	mat.m03 = 0.0;
	mat.m10 = translXY + sinAngZ;
	mat.m11 = translY * axis.y + cosAng;
	mat.m12 = translYZ - sinAngX;
	mat.m13 = 0.0;
	mat.m20 = translXZ - sinAngY;
	mat.m21 = translYZ + sinAngX;
	mat.m22 = transl * axis.z * axis.z + cosAng;
	mat.m23 = 0.0;
	mat.m30 = 0.0;
	mat.m31 = 0.0;
	mat.m64 = 0.0;
	mat.m33 = 1.0;
	return mat;
}
tFP64M4x4 tFP64M4x4_RotAxis_iter(tFP64V3D axis, tFP64 ang, tIUSz itr)
{
	axis = tFP64V3D_Norm(axis);
	tFP64 cosAng = tFP64_Cosine_iter(ang, itr);
	tFP64 sinAng = tFP64_Sine_iter(ang, itr);
	tFP64 transl = 1.0 - cosAng;
	tFP64 translX = transl * axis.x;
	tFP64 translY = transl * axis.y;
	tFP64 sinAngX = sinAng * axis.x;
	tFP64 sinAngY = sinAng * axis.y;
	tFP64 sinAngZ = sinAng * axis.z;
	tFP64 translXY = translX * axis.y;
	tFP64 translXZ = translX * axis.z;
	tFP64 translYZ = translY * axis.z;
	tFP64M4x4 mat;
	mat.m00 = translX * axis.x + cosAng;
	mat.m01 = translXY - sinAngZ;
	mat.m02 = translXZ + sinAngY;
	mat.m03 = 0.0;
	mat.m10 = translXY + sinAngZ;
	mat.m11 = translY * axis.y + cosAng;
	mat.m12 = translYZ - sinAngX;
	mat.m13 = 0.0;
	mat.m20 = translXZ - sinAngY;
	mat.m21 = translYZ + sinAngX;
	mat.m22 = transl * axis.z * axis.z + cosAng;
	mat.m23 = 0.0;
	mat.m30 = 0.0;
	mat.m31 = 0.0;
	mat.m64 = 0.0;
	mat.m33 = 1.0;
	return mat;
}
tFP64M4x4 tFP64M4x4_RotAxis(tFP64V3D axis, tFP64 ang)
{
	axis = tFP64V3D_Norm(axis);
	tFP64 cosAng = tFP64_Cosine(ang);
	tFP64 sinAng = tFP64_Sine(ang);
	tFP64 transl = 1.0 - cosAng;
	tFP64 translX = transl * axis.x;
	tFP64 translY = transl * axis.y;
	tFP64 sinAngX = sinAng * axis.x;
	tFP64 sinAngY = sinAng * axis.y;
	tFP64 sinAngZ = sinAng * axis.z;
	tFP64 translXY = translX * axis.y;
	tFP64 translXZ = translX * axis.z;
	tFP64 translYZ = translY * axis.z;
	tFP64M4x4 mat;
	mat.m00 = translX * axis.x + cosAng;
	mat.m01 = translXY - sinAngZ;
	mat.m02 = translXZ + sinAngY;
	mat.m03 = 0.0;
	mat.m10 = translXY + sinAngZ;
	mat.m11 = translY * axis.y + cosAng;
	mat.m12 = translYZ - sinAngX;
	mat.m13 = 0.0;
	mat.m20 = translXZ - sinAngY;
	mat.m21 = translYZ + sinAngX;
	mat.m22 = transl * axis.z * axis.z + cosAng;
	mat.m23 = 0.0;
	mat.m30 = 0.0;
	mat.m31 = 0.0;
	mat.m64 = 0.0;
	mat.m33 = 1.0;
	return mat;
}
tFP64M4x4 tFP64M4x4_InvAff(tFP64M4x4 mtrx)
{
	if (!tFP64M4x4_IsAff(mtrx)) return tFP64M4x4_Zero();
	tFP64 det = mtrx.m00 * (mtrx.m11 * mtrx.m22 - mtrx.m12 * mtrx.m21) - mtrx.m01 * (mtrx.m10 * mtrx.m22 - mtrx.m12 * mtrx.m20) + mtrx.m02 * (mtrx.m10 * mtrx.m21 - mtrx.m11 * mtrx.m20);
	tFP64 invDet = tFP64_Recip(det);
	tFP64M4x4 out;
	out.m00 = (mtrx.m11 * mtrx.m22 - mtrx.m12 * mtrx.m21) * invDet;
	out.m01 = tFP64_Neg(mtrx.m01 * mtrx.m22 - mtrx.m02 * mtrx.m21) * invDet;
	out.m02 = (mtrx.m01 * mtrx.m12 - mtrx.m02 * mtrx.m11) * invDet;
	out.m10 = tFP64_Neg(mtrx.m10 * mtrx.m22 - mtrx.m12 * mtrx.m20) * invDet;
	out.m11 = (mtrx.m00 * mtrx.m22 - mtrx.m02 * mtrx.m20) * invDet;
	out.m12 = tFP64_Neg(mtrx.m00 * mtrx.m12 - mtrx.m02 * mtrx.m10) * invDet;
	out.m20 = (mtrx.m10 * mtrx.m21 - mtrx.m11 * mtrx.m20) * invDet;
	out.m21 = tFP64_Neg(mtrx.m00 * mtrx.m21 - mtrx.m01 * mtrx.m20) * invDet;
	out.m22 = (mtrx.m00 * mtrx.m11 - mtrx.m01 * mtrx.m10) * invDet;
	out.m03 = tFP64_Neg(out.m00 * mtrx.m03 + out.m01 * mtrx.m13 + out.m02 * mtrx.m23);
	out.m13 = tFP64_Neg(out.m10 * mtrx.m03 + out.m11 * mtrx.m13 + out.m12 * mtrx.m23);
	out.m23 = tFP64_Neg(out.m20 * mtrx.m03 + out.m21 * mtrx.m13 + out.m22 * mtrx.m23);
	out.m30 = 0.0;
	out.m31 = 0.0;
	out.m64 = 0.0;
	out.m33 = 1.0;
	return out;
}
tFP64M4x4 tFP64M4x4_Persp_fast(tFP64 fov, tFP64 aspRatio, tFP64 near, tFP64 far, tIS8 minZ)
{
	if (minZ != -1 && minZ != 0) return tFP64M4x4_Zero();
	tFP64 yScale = tFP64_Recip(tFP64_Tangent_fast(fov * 0.5));
	tFP64 xScale = yScale / aspRatio;
	tFP64 dst = far - near;
	tFP64M4x4 out = tFP64M4x4_Zero();
	out.m00 = xScale;
	out.m11 = yScale;
	if (minZ == 0)
	{
		out.m22 = far / dst;
		out.m23 = (far * near) / dst;
	}
	else
	{
		out.m22 = tFP64_Neg(far + near) / dst;
		out.m23 = tFP64_Neg(2.0 * far * near) / dst;
	}
	out.m64 = -1.0;
	return out;
}
tFP64M4x4 tFP64M4x4_Persp_iter(tFP64 fov, tFP64 aspRatio, tFP64 near, tFP64 far, tIS8 minZ, tIUSz itr)
{
	if (minZ != -1 && minZ != 0) return tFP64M4x4_Zero();
	tFP64 yScale = tFP64_Recip(tFP64_Tangent_iter(fov * 0.5, itr));
	tFP64 xScale = yScale / aspRatio;
	tFP64 dst = far - near;
	tFP64M4x4 out = tFP64M4x4_Zero();
	out.m00 = xScale;
	out.m11 = yScale;
	if (minZ == 0)
	{
		out.m22 = far / dst;
		out.m23 = (far * near) / dst;
	}
	else
	{
		out.m22 = tFP64_Neg(far + near) / dst;
		out.m23 = tFP64_Neg(2.0 * far * near) / dst;
	}
	out.m64 = -1.0;
	return out;
}
tFP64M4x4 tFP64M4x4_Persp(tFP64 fov, tFP64 aspRatio, tFP64 near, tFP64 far, tIS8 minZ)
{
	if (minZ != -1 && minZ != 0) return tFP64M4x4_Zero();
	tFP64 yScale = tFP64_Recip(tFP64_Tangent(fov * 0.5));
	tFP64 xScale = yScale / aspRatio;
	tFP64 dst = far - near;
	tFP64M4x4 out = tFP64M4x4_Zero();
	out.m00 = xScale;
	out.m11 = yScale;
	if (minZ == 0)
	{
		out.m22 = far / dst;
		out.m23 = (far * near) / dst;
	}
	else
	{
		out.m22 = -(far + near) / dst;
		out.m23 = -(2.0 * far * near) / dst;
	}
	out.m64 = -1.0;
	return out;
}
tBln tFP64M4x4_IsAff(tFP64M4x4 mtrx)
{
	return tFP64_IsNearby(mtrx.m30, 0.0) && tFP64_IsNearby(mtrx.m31, 0.0) && tFP64_IsNearby(mtrx.m64, 0.0) && tFP64_IsNearby(mtrx.m33, 1.0);
}
tFP64M4x4 tFP64M4x4_LookAt(tFP64V3D eye, tFP64V3D target, tFP64V3D up)
{
	tFP64V3D forward = tFP64V3D_Norm(tFP64V3D_Sub(target, eye));
	tFP64V3D right = tFP64V3D_Norm(tFP64V3D_Cross(forward, up));
	tFP64V3D newUp = tFP64V3D_Cross(right, forward);
	tFP64M4x4 mat;
	mat.m00 = right.x;
	mat.m01 = right.y;
	mat.m02 = right.z;
	mat.m03 = tFP64_Neg(tFP64V3D_Dot(right, eye));
	mat.m10 = newUp.x;
	mat.m11 = newUp.y;
	mat.m12 = newUp.z;
	mat.m13 = tFP64_Neg(tFP64V3D_Dot(newUp, eye));
	mat.m20 = tFP64_Neg(forward.x);
	mat.m21 = tFP64_Neg(forward.y);
	mat.m22 = tFP64_Neg(forward.z);
	mat.m23 = tFP64V3D_Dot(forward, eye);
	mat.m30 = 0.0;
	mat.m31 = 0.0;
	mat.m64 = 0.0;
	mat.m33 = 1.0;
	return mat;
}
tFP64M3x3 tFP64M4x4_NormalMtrx(tFP64M4x4 mtrx)
{
	tFP64M4x4 invTrans = tFP64M4x4_Transp(tFP64M4x4_Inv(mtrx));
	tFP64M3x3 res;
	res.m00 = invTrans.m00;
	res.m01 = invTrans.m01;
	res.m02 = invTrans.m02;
	res.m10 = invTrans.m10;
	res.m11 = invTrans.m11;
	res.m12 = invTrans.m12;
	res.m20 = invTrans.m20;
	res.m21 = invTrans.m21;
	res.m22 = invTrans.m22;
	return res;
}
#endif/*BQSELAYER_MTRX_IMPL*/
#endif/*BQSELAYER_MTRX_H*/