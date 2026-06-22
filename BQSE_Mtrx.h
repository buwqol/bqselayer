#ifndef BQSELAYER_MTRX_H
#define BQSELAYER_MTRX_H
#include "BQSE_PrimTypes.h"
#include "BQSE_Vect.h"
typedef union { struct { tF32 m00, m01; tF32 m10, m11; }; tF32 m[2][2]; tF32V2D row[2]; } tF32M2x2;
tF32M2x2 tF32M2x2_Make(tF32 m00, tF32 m01, tF32 m10, tF32 m11);
tF32M2x2 tF32M2x2_Zero(tNone);
tF32M2x2 tF32M2x2_Id(tNone);
tF32M2x2 tF32M2x2_Add(tF32M2x2 mtrx1, tF32M2x2 mtrx2);
tF32M2x2 tF32M2x2_Sub(tF32M2x2 mtrx1, tF32M2x2 mtrx2);
tF32M2x2 tF32M2x2_Mul(tF32M2x2 mtrx1, tF32M2x2 mtrx2);
tF32M2x2 tF32M2x2_MulFlt(tF32M2x2 mtrx, tF32 mod);
/*Warn: Silently returns `tF32M2x2_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M2x2 tF32M2x2_DivFlt(tF32M2x2 mtrx, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32M2x2_DivFlt_safe(tF32M2x2 *mtrx, tF32 mod);
tBln tF32M2x2_Eq(tF32M2x2 mtrx1, tF32M2x2 mtrx2);
tBln tF32M2x2_Nearby(tF32M2x2 mtrx1, tF32M2x2 mtrx2, tF32 eps);
tF32V2D tF32M2x2_MulVec(tF32M2x2 mtrx, tF32V2D vec);
tF32M2x2 tF32M2x2_Transp(tF32M2x2 mtrx);
tF32 tF32M2x2_Det(tF32M2x2 mtrx);
tF32M2x2 tF32M2x2_Cofact(tF32M2x2 mtrx);
tF32M2x2 tF32M2x2_Adj(tF32M2x2 mtrx);
/*Warn: Silently returns `tF32M2x2_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M2x2 tF32M2x2_Inv(tF32M2x2 mtrx);
/*Note: Returns `False` on success.*/
tBln tF32M2x2_Inv_safe(tF32M2x2 *mtrx);
/*Note: `ang` is in radians.*/
tF32M2x2 tF32M2x2_Rot(tF32 ang);
tF32M2x2 tF32M2x2_Scale(tF32 x, tF32 y);
tF32 tF32M2x2_Trace(tF32M2x2 mtrx);
tNone tF32M2x2_RowSwap(tF32M2x2 *mtrx);
tNone tF32M2x2_RowAdd(tF32M2x2 *mtrx, tU8 dstRow, tU8 srcRow, tF32 mult);
tNone tF32M2x2_RowMult(tF32M2x2 *mtrx, tU8 idx, tF32 mult);
tNone tF32M2x2_RowEch(tF32M2x2 *mtrx);
tNone tF32M2x2_RowRedEch(tF32M2x2 *mtrx);
#ifdef BQSE_IMPL
tF32M2x2 tF32M2x2_Make(tF32 m00, tF32 m01, tF32 m10, tF32 m11)
{
	tF32M2x2 mtrx;
	mtrx.m00 = m00;
	mtrx.m01 = m01;
	mtrx.m10 = m10;
	mtrx.m11 = m11;
	return mtrx;
}
tF32M2x2 tF32M2x2_Zero(tNone)
{
	tF32M2x2 mtrx;
	mtrx.m00 = 0.0F;
	mtrx.m01 = 0.0F;
	mtrx.m10 = 0.0F;
	mtrx.m11 = 0.0F;
	return mtrx;
}
tF32M2x2 tF32M2x2_Id(tNone)
{
	tF32M2x2 mtrx;
	mtrx.m00 = 1.0F;
	mtrx.m01 = 0.0F;
	mtrx.m10 = 0.0F;
	mtrx.m11 = 1.0F;
	return mtrx;
}
tF32M2x2 tF32M2x2_Add(tF32M2x2 mtrx1, tF32M2x2 mtrx2)
{
	mtrx1.m00 += mtrx2.m00;
	mtrx1.m01 += mtrx2.m01;
	mtrx1.m10 += mtrx2.m10;
	mtrx1.m11 += mtrx2.m11;
	return mtrx1;
}
tF32M2x2 tF32M2x2_Sub(tF32M2x2 mtrx1, tF32M2x2 mtrx2)
{
	mtrx1.m00 -= mtrx2.m00;
	mtrx1.m01 -= mtrx2.m01;
	mtrx1.m10 -= mtrx2.m10;
	mtrx1.m11 -= mtrx2.m11;
	return mtrx1;
}
tF32M2x2 tF32M2x2_Mul(tF32M2x2 mtrx1, tF32M2x2 mtrx2)
{
	tF32M2x2 mtrx;
	mtrx.m00 = mtrx1.m00 * mtrx2.m00 + mtrx1.m01 * mtrx2.m10;
	mtrx.m01 = mtrx1.m00 * mtrx2.m01 + mtrx1.m01 * mtrx2.m11;
	mtrx.m10 = mtrx1.m10 * mtrx2.m00 + mtrx1.m11 * mtrx2.m10;
	mtrx.m11 = mtrx1.m10 * mtrx2.m01 + mtrx1.m11 * mtrx2.m11;
	return mtrx;
}
tF32M2x2 tF32M2x2_MulFlt(tF32M2x2 mtrx, tF32 mod)
{
	mtrx.m00 *= mod;
	mtrx.m01 *= mod;
	mtrx.m10 *= mod;
	mtrx.m11 *= mod;
	return mtrx;
}
tF32M2x2 tF32M2x2_DivFlt(tF32M2x2 mtrx, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return tF32M2x2_Zero();
#else
	Assertion(mod != 0.0F);
#endif
	mtrx.m00 /= mod;
	mtrx.m01 /= mod;
	mtrx.m10 /= mod;
	mtrx.m11 /= mod;
	return mtrx;
}
tBln tF32M2x2_DivFlt_safe(tF32M2x2 *mtrx, tF32 mod)
{
	if (mod == 0.0F) return True;
	mtrx->m00 /= mod;
	mtrx->m01 /= mod;
	mtrx->m10 /= mod;
	mtrx->m11 /= mod;
	return False;
}
tBln tF32M2x2_Eq(tF32M2x2 mtrx1, tF32M2x2 mtrx2)
{
	return (mtrx1.m00 == mtrx2.m00) && (mtrx1.m01 == mtrx2.m01) && (mtrx1.m10 == mtrx2.m10) && (mtrx1.m11 == mtrx2.m11);
}
tBln tF32M2x2_Nearby(tF32M2x2 mtrx1, tF32M2x2 mtrx2, tF32 eps)
{
	return (tF32_Abs(mtrx1.m00 - mtrx2.m00) <= eps) && (tF32_Abs(mtrx1.m01 - mtrx2.m01) <= eps) && (tF32_Abs(mtrx1.m10 - mtrx2.m10) <= eps) && (tF32_Abs(mtrx1.m11 - mtrx2.m11) <= eps);
}
tF32V2D tF32M2x2_MulVec(tF32M2x2 mtrx, tF32V2D vec)
{
	tF32V2D res;
	res.x = mtrx.m00 * vec.x + mtrx.m01 * vec.y;
	res.y = mtrx.m10 * vec.x + mtrx.m11 * vec.y;
	return res;
}
tF32M2x2 tF32M2x2_Transp(tF32M2x2 mtrx)
{
	tF32 tmp = mtrx.m01;
	mtrx.m01 = mtrx.m10;
	mtrx.m10 = tmp;
	return mtrx;
}
tF32 tF32M2x2_Det(tF32M2x2 mtrx)
{
	return (mtrx.m00 * mtrx.m11) - (mtrx.m01 * mtrx.m10);
}
tF32M2x2 tF32M2x2_Cofact(tF32M2x2 mtrx)
{
	tF32 tmp = mtrx.m00;
	mtrx.m00 = mtrx.m11;
	mtrx.m11 = tmp;
	mtrx.m01 = tF32_Neg(mtrx.m10);
	mtrx.m10 = tF32_Neg(mtrx.m01);
	return mtrx;
}
tF32M2x2 tF32M2x2_Adj(tF32M2x2 mtrx)
{
	tF32 tmp = mtrx.m00;
	mtrx.m00 = mtrx.m11;
	mtrx.m11 = tmp;
	mtrx.m01 = tF32_Neg(mtrx.m01);
	mtrx.m10 = tF32_Neg(mtrx.m10);
	return mtrx;
}
tF32M2x2 tF32M2x2_Inv(tF32M2x2 mtrx)
{
	tF32 det = tF32M2x2_Det(mtrx);
#ifndef BQSE_DEBUG
	if (tF32_Abs(det) <= tF32_Eps) return tF32M2x2_Zero();
#else
	Assertion(tF32_Abs(det) > tF32_Eps);
#endif
	return tF32M2x2_DivFlt(tF32M2x2_Adj(mtrx), det);
}
tBln tF32M2x2_Inv_safe(tF32M2x2 *mtrx)
{
	tF32 det = tF32M2x2_Det(*mtrx);
	if (tF32_Abs(det) <= tF32_Eps) return True;
	*mtrx = tF32M2x2_DivFlt(tF32M2x2_Adj(*mtrx), det);
	return False;
}
tF32M2x2 tF32M2x2_Rot(tF32 ang)
{
	tF32M2x2 mtrx;
	mtrx.m00 = mtrx.m11 = tF32_Cosine(ang);
	mtrx.m10 = tF32_Sine(ang);
	mtrx.m01 = tF32_Neg(mtrx.m10);
	return mtrx;
}
tF32M2x2 tF32M2x2_Scale(tF32 x, tF32 y)
{
	tF32M2x2 mtrx;
	mtrx.m00 = x;
	mtrx.m11 = y;
	mtrx.m01 = mtrx.m10 = 0.0F;
	return mtrx;
}
tF32 tF32M2x2_Trace(tF32M2x2 mtrx)
{
	return mtrx.m00 + mtrx.m11;
}
tNone tF32M2x2_RowSwap(tF32M2x2 *mtrx)
{
	tF32_Swap(&mtrx->m[0][0], &mtrx->m[1][0]);
	tF32_Swap(&mtrx->m[0][1], &mtrx->m[1][1]);
}
tNone tF32M2x2_RowAdd(tF32M2x2 *mtrx, tU8 dstRow, tU8 srcRow, tF32 mult)
{
	mtrx->m[dstRow][0] += mtrx->m[srcRow][0] * mult;
	mtrx->m[dstRow][1] += mtrx->m[srcRow][1] * mult;
}
tNone tF32M2x2_RowMult(tF32M2x2 *mtrx, tU8 idx, tF32 mult)
{
	mtrx->m[idx][0] *= mult;
	mtrx->m[idx][1] *= mult;
}
// TODO: Optimize these two functions eventually, but for now they're fine - more so for my own understanding.
tNone tF32M2x2_RowEch(tF32M2x2 *mtrx)
{
	tU8 pivotRow = 0U;
	for (tU8 col = 0U; col < 2U; ++col)
	{
		if (pivotRow >= 2U) break;
		tBln foundPivot = False;
		if (mtrx->m[pivotRow][col] != 0.0F) foundPivot = True;
		else
		{
			for (tU8 idx = 1U; idx < 2U - pivotRow; ++idx)
			{
				if (mtrx->m[pivotRow + idx][col] != 0.0F)
				{
					tF32M2x2_RowSwap(mtrx);
					foundPivot = True;
					break;
				}
			}
			if (foundPivot == False) continue;
		}
		tF32M2x2_RowMult(mtrx, pivotRow, 1.0F / mtrx->m[pivotRow][col]);
		for (tU8 idx = 1U; idx < 2U - pivotRow; ++idx) tF32M2x2_RowAdd(mtrx, pivotRow + idx, pivotRow, tF32_Neg(mtrx->m[pivotRow + idx][col]));
		++pivotRow;
	}
}
tNone tF32M2x2_RowRedEch(tF32M2x2 *mtrx)
{
	tF32M2x2_RowEch(mtrx);
	tU8 pivotRow = 1U;
	for (tU8 col = pivotRow; col > 0U; --col)
	{
		if (pivotRow == 0U) break;
		for (tU8 idx = 0U; idx < pivotRow; ++idx) tF32M2x2_RowAdd(mtrx, idx, pivotRow, tF32_Neg(mtrx->m[idx][col]));
		--pivotRow;
	}
}
#endif
typedef union { struct { tF32 m00, m01, m02; tF32 m10, m11, m12; tF32 m20, m21, m22; }; tF32 m[3][3]; tF32V3D row[3]; } tF32M3x3;
tF32M3x3 tF32M3x3_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m10, tF32 m11, tF32 m12, tF32 m20, tF32 m21, tF32 m22);
tF32M3x3 tF32M3x3_Zero(tNone);
tF32M3x3 tF32M3x3_Id(tNone);
tF32M3x3 tF32M3x3_Add(tF32M3x3 mtrx1, tF32M3x3 mtrx2);
tF32M3x3 tF32M3x3_Sub(tF32M3x3 mtrx1, tF32M3x3 mtrx2);
tF32M3x3 tF32M3x3_Mul(tF32M3x3 mtrx1, tF32M3x3 mtrx2);
tF32M3x3 tF32M3x3_MulFlt(tF32M3x3 mtrx, tF32 mod);
/*Warn: Silently returns `tF32M3x3_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M3x3 tF32M3x3_DivFlt(tF32M3x3 mtrx, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32M3x3_DivFlt_safe(tF32M3x3 *mtrx, tF32 mod);
tBln tF32M3x3_Eq(tF32M3x3 mtrx1, tF32M3x3 mtrx2);
tBln tF32M3x3_Nearby(tF32M3x3 mtrx1, tF32M3x3 mtrx2, tF32 eps);
tF32V3D tF32M3x3_MulVec(tF32M3x3 mtrx, tF32V3D vec);
tF32M3x3 tF32M3x3_Transp(tF32M3x3 mtrx);
tF32 tF32M3x3_Det(tF32M3x3 mtrx);
tF32M3x3 tF32M3x3_Cofact(tF32M3x3 mtrx);
tF32M3x3 tF32M3x3_Adj(tF32M3x3 mtrx);
/*Warn: Silently returns `tF32M3x3_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M3x3 tF32M3x3_Inv(tF32M3x3 mtrx);
/*Note: Returns `False` on success.*/
tBln tF32M3x3_Inv_safe(tF32M3x3 *mtrx);
tF32M3x3 tF32M3x3_Transl(tF32 x, tF32 y);
tF32M3x3 tF32M3x3_Scale(tF32 x, tF32 y);
/*Note: `ang` is in radians.*/
tF32M3x3 tF32M3x3_Rot(tF32 ang);
tF32 tF32M3x3_Trace(tF32M3x3 mtrx);
tF32V2D tF32M3x3_TransfPoint(tF32M3x3 mtrx, tF32V2D vec);
tF32V2D tF32M3x3_TransfDir(tF32M3x3 mtrx, tF32V2D vec);
tNone tF32M3x3_RowSwap(tF32M3x3 *mtrx, tU8 idx1, tU8 idx2);
tNone tF32M3x3_RowAdd(tF32M3x3 *mtrx, tU8 dstRow, tU8 srcRow, tF32 mult);
tNone tF32M3x3_RowMult(tF32M3x3 *mtrx, tU8 idx, tF32 mult);
tNone tF32M3x3_RowEch(tF32M3x3 *mtrx);
tNone tF32M3x3_RowRedEch(tF32M3x3 *mtrx);
#ifdef BQSE_IMPL
tF32M3x3 tF32M3x3_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m10, tF32 m11, tF32 m12, tF32 m20, tF32 m21, tF32 m22)
{
	tF32M3x3 mtrx;
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
tF32M3x3 tF32M3x3_Zero(tNone)
{
	tF32M3x3 mtrx;
	mtrx.m00 = mtrx.m01 = mtrx.m02 = mtrx.m10 = mtrx.m11 = mtrx.m12 = mtrx.m20 = mtrx.m21 = mtrx.m22 = 0.0F;
	return mtrx;
}
tF32M3x3 tF32M3x3_Id(tNone)
{
	tF32M3x3 mtrx;
	mtrx.m01 = mtrx.m02 = mtrx.m10 = mtrx.m12 = mtrx.m20 = mtrx.m21 = 0.0F;
	mtrx.m00 = mtrx.m11 = mtrx.m22 = 1.0F;
	return mtrx;
}
tF32M3x3 tF32M3x3_Add(tF32M3x3 mtrx1, tF32M3x3 mtrx2)
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
tF32M3x3 tF32M3x3_Sub(tF32M3x3 mtrx1, tF32M3x3 mtrx2)
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
tF32M3x3 tF32M3x3_Mul(tF32M3x3 mtrx1, tF32M3x3 mtrx2)
{
	tF32M3x3 res;
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
tF32M3x3 tF32M3x3_MulFlt(tF32M3x3 mtrx, tF32 mod)
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
tF32M3x3 tF32M3x3_DivFlt(tF32M3x3 mtrx, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return tF32M3x3_Zero();
#else
	Assertion(mod != 0.0F);
#endif
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
tBln tF32M3x3_DivFlt_safe(tF32M3x3 *mtrx, tF32 mod)
{
	if (mod == 0.0F) return True;
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
tBln tF32M3x3_Eq(tF32M3x3 mtrx1, tF32M3x3 mtrx2)
{
	return (mtrx1.m00 == mtrx2.m00) && (mtrx1.m01 == mtrx2.m01) && (mtrx1.m02 == mtrx2.m02) && (mtrx1.m10 == mtrx2.m10) && (mtrx1.m11 == mtrx2.m11) && (mtrx1.m12 == mtrx2.m12) && (mtrx1.m20 == mtrx2.m20) && (mtrx1.m21 == mtrx2.m21) && (mtrx1.m22 == mtrx2.m22);
}
tBln tF32M3x3_Nearby(tF32M3x3 mtrx1, tF32M3x3 mtrx2, tF32 eps)
{
	return (tF32_Abs(mtrx1.m00 - mtrx2.m00) <= eps) && (tF32_Abs(mtrx1.m01 - mtrx2.m01) <= eps) && (tF32_Abs(mtrx1.m02 - mtrx2.m02) <= eps) && (tF32_Abs(mtrx1.m10 - mtrx2.m10) <= eps) && (tF32_Abs(mtrx1.m11 - mtrx2.m11) <= eps) && (tF32_Abs(mtrx1.m12 - mtrx2.m12) <= eps) && (tF32_Abs(mtrx1.m20 - mtrx2.m20) <= eps) && (tF32_Abs(mtrx1.m21 - mtrx2.m21) <= eps) && (tF32_Abs(mtrx1.m22 - mtrx2.m22) <= eps);
}
tF32V3D tF32M3x3_MulVec(tF32M3x3 mtrx, tF32V3D vec)
{
	tF32V3D res;
	res.x = (mtrx.m00 * vec.x) + (mtrx.m01 * vec.y) + (mtrx.m02 * vec.z);
	res.y = (mtrx.m10 * vec.x) + (mtrx.m11 * vec.y) + (mtrx.m12 * vec.z);
	res.z = (mtrx.m20 * vec.x) + (mtrx.m21 * vec.y) + (mtrx.m22 * vec.z);
	return res;
}
tF32M3x3 tF32M3x3_Transp(tF32M3x3 mtrx)
{
	tF32 tmp = mtrx.m01;
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
tF32 tF32M3x3_Det(tF32M3x3 mtrx)
{
	return (mtrx.m00 * ((mtrx.m11 * mtrx.m22) - (mtrx.m12 * mtrx.m21))) - (mtrx.m01 * ((mtrx.m10 * mtrx.m22) - (mtrx.m12 * mtrx.m20))) + (mtrx.m02 * ((mtrx.m10 * mtrx.m21) - (mtrx.m11 * mtrx.m20)));
}
tF32M3x3 tF32M3x3_Cofact(tF32M3x3 mtrx)
{
	tF32M3x3 cof;
	cof.m00 = mtrx.m11 * mtrx.m22 - mtrx.m12 * mtrx.m21;
	cof.m01 = tF32_Neg(mtrx.m10 * mtrx.m22 - mtrx.m12 * mtrx.m20);
	cof.m02 = mtrx.m10 * mtrx.m21 - mtrx.m11 * mtrx.m20;
	cof.m10 = tF32_Neg(mtrx.m01 * mtrx.m22 - mtrx.m02 * mtrx.m21);
	cof.m11 = mtrx.m00 * mtrx.m22 - mtrx.m02 * mtrx.m20;
	cof.m12 = tF32_Neg(mtrx.m00 * mtrx.m21 - mtrx.m01 * mtrx.m20);
	cof.m20 = mtrx.m01 * mtrx.m12 - mtrx.m02 * mtrx.m11;
	cof.m21 = tF32_Neg(mtrx.m00 * mtrx.m12 - mtrx.m02 * mtrx.m10);
	cof.m22 = mtrx.m00 * mtrx.m11 - mtrx.m01 * mtrx.m10;
	return cof;
}
tF32M3x3 tF32M3x3_Adj(tF32M3x3 mtrx)
{
	return tF32M3x3_Transp(tF32M3x3_Cofact(mtrx));
}
tF32M3x3 tF32M3x3_Inv(tF32M3x3 mtrx)
{
	tF32 det = tF32M3x3_Det(mtrx);
#ifndef BQSE_DEBUG
	if (tF32_Abs(det) <= tF32_Eps) return tF32M3x3_Zero();
#else
	Assertion(tF32_Abs(det) > tF32_Eps);
#endif
	return tF32M3x3_DivFlt(tF32M3x3_Adj(mtrx), det);
}
tBln tF32M3x3_Inv_safe(tF32M3x3 *mtrx)
{
	tF32 det = tF32M3x3_Det(*mtrx);
	if (tF32_Abs(det) <= tF32_Eps) return True;
	*mtrx = tF32M3x3_DivFlt(tF32M3x3_Adj(*mtrx), det);
	return False;
}
tF32M3x3 tF32M3x3_Transl(tF32 x, tF32 y)
{
	tF32M3x3 mtrx = tF32M3x3_Id();
	mtrx.m02 = x;
	mtrx.m12 = y;
	return mtrx;
}
tF32M3x3 tF32M3x3_Scale(tF32 x, tF32 y)
{
	tF32M3x3 mtrx = tF32M3x3_Id();
	mtrx.m00 = x;
	mtrx.m11 = y;
	return mtrx;
}
tF32M3x3 tF32M3x3_Rot(tF32 ang)
{
	tF32M3x3 mtrx = tF32M3x3_Id();
	mtrx.m00 = mtrx.m11 = tF32_Cosine(ang);
	mtrx.m10 = tF32_Sine(ang);
	mtrx.m01 = tF32_Neg(mtrx.m10);
	return mtrx;
}
tF32 tF32M3x3_Trace(tF32M3x3 mtrx)
{
	return mtrx.m00 + mtrx.m11 + mtrx.m22;
}
tF32V2D tF32M3x3_TransfPoint(tF32M3x3 mtrx, tF32V2D vec)
{
	tF32V2D res;
	res.x = mtrx.m00 * vec.x + mtrx.m01 * vec.y + mtrx.m02;
	res.y = mtrx.m10 * vec.x + mtrx.m11 * vec.y + mtrx.m12;
	return res;
}
tF32V2D tF32M3x3_TransfDir(tF32M3x3 mtrx, tF32V2D vec)
{
	tF32V2D res;
	res.x = mtrx.m00 * vec.x + mtrx.m01 * vec.y;
	res.y = mtrx.m10 * vec.x + mtrx.m11 * vec.y;
	return res;
}
tNone tF32M3x3_RowSwap(tF32M3x3 *mtrx, tU8 idx1, tU8 idx2)
{
	tF32_Swap(&mtrx->m[idx1][0], &mtrx->m[idx2][0]);
	tF32_Swap(&mtrx->m[idx1][1], &mtrx->m[idx2][1]);
	tF32_Swap(&mtrx->m[idx1][2], &mtrx->m[idx2][2]);
}
tNone tF32M3x3_RowAdd(tF32M3x3 *mtrx, tU8 dstRow, tU8 srcRow, tF32 mult)
{
	mtrx->m[dstRow][0] += mtrx->m[srcRow][0] * mult;
	mtrx->m[dstRow][1] += mtrx->m[srcRow][1] * mult;
	mtrx->m[dstRow][2] += mtrx->m[srcRow][2] * mult;
}
tNone tF32M3x3_RowMult(tF32M3x3 *mtrx, tU8 idx, tF32 mult)
{
	mtrx->m[idx][0] *= mult;
	mtrx->m[idx][1] *= mult;
	mtrx->m[idx][2] *= mult;
}
tNone tF32M3x3_RowEch(tF32M3x3 *mtrx)
{
	tU8 pivotRow = 0U;
	for (tU8 col = 0U; col < 3U; ++col)
	{
		if (pivotRow >= 3U) break;
		tBln foundPivot = False;
		if (mtrx->m[pivotRow][col] != 0.0F) foundPivot = True;
		else
		{
			for (tU8 idx = 1U; idx < 3U - pivotRow; ++idx)
			{
				if (mtrx->m[pivotRow + idx][col] != 0.0F)
				{
					tF32M3x3_RowSwap(mtrx, pivotRow, pivotRow + idx);
					foundPivot = True;
					break;
				}
			}
			if (foundPivot == False) continue;
		}
		tF32M3x3_RowMult(mtrx, pivotRow, 1.0F / mtrx->m[pivotRow][col]);
		for (tU8 idx = 1U; idx < 3U - pivotRow; ++idx) tF32M3x3_RowAdd(mtrx, pivotRow + idx, pivotRow, tF32_Neg(mtrx->m[pivotRow + idx][col]));
		++pivotRow;
	}
}
tNone tF32M3x3_RowRedEch(tF32M3x3 *mtrx)
{
	tF32M3x3_RowEch(mtrx);
	for (tS8 row = 2; row >= 0; --row)
	{
		tBln foundPivot = False;
		tU8 pivotCol = 0;
		for (tU8 col = 0U; col < 3; ++col)
		{
			if (mtrx->m[row][col] != 0.0F)
			{
				foundPivot = True;
				pivotCol = col;
				break;
			}
		}
		if (foundPivot == False) continue;
		for (tU8 aboveRow = 0U; aboveRow < row; ++aboveRow) tF32M3x3_RowAdd(mtrx, aboveRow, row, tF32_Neg(mtrx->m[aboveRow][pivotCol]));
	}
}
#endif
typedef union { struct { tF32 m00, m01, m02, m03; tF32 m10, m11, m12, m13; tF32 m20, m21, m22, m23; tF32 m30, m31, m32, m33; }; tF32 m[4][4]; tF32V4D row[4]; } tF32M4x4;
tF32M4x4 tF32M4x4_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m03, tF32 m10, tF32 m11, tF32 m12, tF32 m13, tF32 m20, tF32 m21, tF32 m22, tF32 m23, tF32 m30, tF32 m31, tF32 m32, tF32 m33);
tF32M4x4 tF32M4x4_Zero(tNone);
tF32M4x4 tF32M4x4_Id(tNone);
tF32M4x4 tF32M4x4_Add(tF32M4x4 mtrx1, tF32M4x4 mtrx2);
tF32M4x4 tF32M4x4_Sub(tF32M4x4 mtrx1, tF32M4x4 mtrx2);
tF32M4x4 tF32M4x4_Mul(tF32M4x4 mtrx1, tF32M4x4 mtrx2);
tF32M4x4 tF32M4x4_MulFlt(tF32M4x4 mtrx, tF32 mod);
/*Warn: Silently returns `tF32M4x4_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M4x4 tF32M4x4_DivFlt(tF32M4x4 mtrx, tF32 mod);
/*Note: Returns `False` on success.*/
tBln tF32M4x4_DivFlt_safe(tF32M4x4 *mtrx, tF32 mod);
tBln tF32M4x4_Eq(tF32M4x4 mtrx1, tF32M4x4 mtrx2);
tBln tF32M4x4_Nearby(tF32M4x4 mtrx1, tF32M4x4 mtrx2, tF32 eps);
tF32V4D tF32M4x4_MulVec(tF32M4x4 mtrx, tF32V4D vec);
tF32M4x4 tF32M4x4_Transp(tF32M4x4 mtrx);
tF32 tF32M4x4_Det(tF32M4x4 mtrx);
/*Warn: Silently returns `tF32M3x3_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M3x3 tF32M4x4_Minor(tF32M4x4 mtrx, tU8 row, tU8 col);
/*Note: Returns `False` on success.*/
tBln tF32M4x4_Minor_s(tF32M3x3 *out, tF32M4x4 mtrx, tU8 row, tU8 col);
tF32M4x4 tF32M4x4_Cofact(tF32M4x4 mtrx);
tF32M4x4 tF32M4x4_Adj(tF32M4x4 mtrx);
/*Warn: Silently returns `tF32M4x4_Zero` on failure when BQSE_DEBUG is not defined.*/
tF32M4x4 tF32M4x4_Inv(tF32M4x4 mtrx);
/*Note: Returns `False` on success.*/
tBln tF32M4x4_Inv_safe(tF32M4x4 *mtrx);
tF32M4x4 tF32M4x4_Transl(tF32 x, tF32 y, tF32 z);
tF32M4x4 tF32M4x4_Scale(tF32 x, tF32 y, tF32 z);
/*Note: `ang` is in radians.*/
tF32M4x4 tF32M4x4_RotX(tF32 ang);
/*Note: `ang` is in radians.*/
tF32M4x4 tF32M4x4_RotY(tF32 ang);
/*Note: `ang` is in radians.*/
tF32M4x4 tF32M4x4_RotZ(tF32 ang);
// TODO: Do the rest of these
tF32M4x4 tF32M4x4_Persp(tF32 fov, tF32 aspect, tF32 near, tF32 far);
tF32M4x4 tF32M4x4_Ortho(tF32 left, tF32 right, tF32 bot, tF32 top, tF32 near, tF32 far);
tF32 tF32M4x4_Trace(tF32M4x4 mtrx);
tF32M4x4 tF32M4x4_InvAff(tF32M4x4 mtrx);
/*Note: `ang` is in radians.*/
tF32M4x4 tF32M4x4_RotAxis(tF32V3D axis, tF32 ang);
tF32V3D tF32M4x4_TransfPoint(tF32M4x4 mtrx, tF32V3D vec);
tF32V3D tF32M4x4_TransfDir(tF32M4x4 mtrx, tF32V3D vec);
tNone tF32M4x4_RowSwap(tF32M4x4 *mtrx, tU8 idx1, tU8 idx2);
tNone tF32M4x4_RowAdd(tF32M4x4 *mtrx, tU8 dstRow, tU8 srcRow, tF32 mult);
tNone tF32M4x4_RowMult(tF32M4x4 *mtrx, tU8 idx, tF32 mult);
tNone tF32M4x4_RowEch(tF32M4x4 *mtrx);
#ifdef BQSE_IMPL
tF32M4x4 tF32M4x4_Make(tF32 m00, tF32 m01, tF32 m02, tF32 m03, tF32 m10, tF32 m11, tF32 m12, tF32 m13, tF32 m20, tF32 m21, tF32 m22, tF32 m23, tF32 m30, tF32 m31, tF32 m32, tF32 m33)
{
	tF32M4x4 mtrx;
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
tF32M4x4 tF32M4x4_Zero(tNone)
{
	tF32M4x4 mtrx;
	mtrx.m00 = mtrx.m01 = mtrx.m02 = mtrx.m03 = mtrx.m10 = mtrx.m11 = mtrx.m12 = mtrx.m13 = mtrx.m20 = mtrx.m21 = mtrx.m22 = mtrx.m23 = mtrx.m30 = mtrx.m31 = mtrx.m32 = mtrx.m33 = 0.0F;
	return mtrx;
}
tF32M4x4 tF32M4x4_Id(tNone)
{
	tF32M4x4 mtrx;
	mtrx.m01 = mtrx.m02 = mtrx.m03 = mtrx.m10 = mtrx.m12 = mtrx.m13 = mtrx.m20 = mtrx.m21 = mtrx.m23 = mtrx.m30 = mtrx.m31 = mtrx.m32 = 0.0F;
	mtrx.m00 = mtrx.m11 = mtrx.m22 = mtrx.m33 = 1.0F;
	return mtrx;
}
tF32M4x4 tF32M4x4_Add(tF32M4x4 mtrx1, tF32M4x4 mtrx2)
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
tF32M4x4 tF32M4x4_Sub(tF32M4x4 mtrx1, tF32M4x4 mtrx2)
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
tF32M4x4 tF32M4x4_Mul(tF32M4x4 mtrx1, tF32M4x4 mtrx2)
{
	tF32M4x4 res;
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
tF32M4x4 tF32M4x4_MulFlt(tF32M4x4 mtrx, tF32 mod)
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
tF32M4x4 tF32M4x4_DivFlt(tF32M4x4 mtrx, tF32 mod)
{
#ifndef BQSE_DEBUG
	if (mod == 0.0F) return tF32M4x4_Zero();
#else
	Assertion(mod != 0.0F);
#endif
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
tBln tF32M4x4_DivFlt_safe(tF32M4x4 *mtrx, tF32 mod)
{
	if (mod == 0.0F) return True;
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
tBln tF32M4x4_Eq(tF32M4x4 mtrx1, tF32M4x4 mtrx2)
{
	return mtrx1.m00 == mtrx2.m00 && mtrx1.m01 == mtrx2.m01 && mtrx1.m02 == mtrx2.m02 && mtrx1.m03 == mtrx2.m03 && mtrx1.m10 == mtrx2.m10 && mtrx1.m11 == mtrx2.m11 && mtrx1.m12 == mtrx2.m12 && mtrx1.m13 == mtrx2.m13 && mtrx1.m20 == mtrx2.m20 && mtrx1.m21 == mtrx2.m21 && mtrx1.m22 == mtrx2.m22 && mtrx1.m23 == mtrx2.m23 && mtrx1.m30 == mtrx2.m30 && mtrx1.m31 == mtrx2.m31 && mtrx1.m32 == mtrx2.m32 && mtrx1.m33 == mtrx2.m33;
}
tBln tF32M4x4_Nearby(tF32M4x4 mtrx1, tF32M4x4 mtrx2, tF32 eps)
{
	return (tF32_Abs(mtrx1.m00 - mtrx2.m00) <= eps) && (tF32_Abs(mtrx1.m01 - mtrx2.m01) <= eps) && (tF32_Abs(mtrx1.m02 - mtrx2.m02) <= eps) && (tF32_Abs(mtrx1.m03 - mtrx2.m03) <= eps) && (tF32_Abs(mtrx1.m10 - mtrx2.m10) <= eps) && (tF32_Abs(mtrx1.m11 - mtrx2.m11) <= eps) && (tF32_Abs(mtrx1.m12 - mtrx2.m12) <= eps) && (tF32_Abs(mtrx1.m13 - mtrx2.m13) <= eps) && (tF32_Abs(mtrx1.m20 - mtrx2.m20) <= eps) && (tF32_Abs(mtrx1.m21 - mtrx2.m21) <= eps) && (tF32_Abs(mtrx1.m22 - mtrx2.m22) <= eps) && (tF32_Abs(mtrx1.m23 - mtrx2.m23) <= eps) && (tF32_Abs(mtrx1.m30 - mtrx2.m30) <= eps) && (tF32_Abs(mtrx1.m31 - mtrx2.m31) <= eps) && (tF32_Abs(mtrx1.m32 - mtrx2.m32) <= eps) && (tF32_Abs(mtrx1.m33 - mtrx2.m33) <= eps);
}
tF32V4D tF32M4x4_MulVec(tF32M4x4 mtrx, tF32V4D vec)
{
	tF32V4D res;
	res.x = (mtrx.m00 * vec.x) + (mtrx.m01 * vec.y) + (mtrx.m02 * vec.z) + (mtrx.m03 * vec.w);
	res.y = (mtrx.m10 * vec.x) + (mtrx.m11 * vec.y) + (mtrx.m12 * vec.z) + (mtrx.m13 * vec.w);
	res.z = (mtrx.m20 * vec.x) + (mtrx.m21 * vec.y) + (mtrx.m22 * vec.z) + (mtrx.m23 * vec.w);
	res.w = (mtrx.m30 * vec.x) + (mtrx.m31 * vec.y) + (mtrx.m32 * vec.z) + (mtrx.m33 * vec.w);
	return res;
}
tF32M4x4 tF32M4x4_Transp(tF32M4x4 mtrx)
{
	return tF32M4x4_Make(mtrx.m00, mtrx.m10, mtrx.m20, mtrx.m30, mtrx.m01, mtrx.m11, mtrx.m21, mtrx.m31, mtrx.m02, mtrx.m12, mtrx.m22, mtrx.m32, mtrx.m03, mtrx.m13, mtrx.m23, mtrx.m33);
}
tF32 tF32M4x4_Det(tF32M4x4 mtrx)
{
	return (mtrx.m00 * (tF32M3x3_Det(tF32M3x3_Make(mtrx.m11, mtrx.m12, mtrx.m13, mtrx.m21, mtrx.m22, mtrx.m23, mtrx.m31, mtrx.m32, mtrx.m33)))) - (mtrx.m01 * (tF32M3x3_Det(tF32M3x3_Make(mtrx.m10, mtrx.m12, mtrx.m13, mtrx.m20, mtrx.m22, mtrx.m23, mtrx.m30, mtrx.m32, mtrx.m33)))) + (mtrx.m02 * (tF32M3x3_Det(tF32M3x3_Make(mtrx.m10, mtrx.m11, mtrx.m13, mtrx.m20, mtrx.m21, mtrx.m23, mtrx.m30, mtrx.m31, mtrx.m33)))) - (mtrx.m03 * (tF32M3x3_Det(tF32M3x3_Make(mtrx.m10, mtrx.m11, mtrx.m12, mtrx.m20, mtrx.m21, mtrx.m22, mtrx.m30, mtrx.m31, mtrx.m32))));
}
tF32M3x3 tF32M4x4_Minor(tF32M4x4 mtrx, tU8 row, tU8 col)
{
#ifndef BQSE_DEBUG
	if (row >= 4U) return tF32M3x3_Zero();
	if (col >= 4U) return tF32M3x3_Zero();
#else
	Assertion(row < 4U);
	Assertion(col < 4U);
#endif
	tF32M3x3 minor;
	tU8 offsetI = 0U;
	for (tU8 idx = 0U; idx < 3U; ++idx)
	{
		if (idx == row) offsetI = 1U;
		tU8 offsetJ = 0U;
		for (tU8 jdx = 0U; jdx < 3U; ++jdx)
		{
			if (jdx == col) offsetJ = 1U;
			minor.m[idx][jdx] = mtrx.m[idx + offsetI][jdx + offsetJ];
		}
	}
	return minor;
}
tBln tF32M4x4_Minor_s(tF32M3x3 *out, tF32M4x4 mtrx, tU8 row, tU8 col)
{
	if (row >= 4U) return True;
	if (col >= 4U) return True;
	tU8 offsetI = 0U;
	for (tU8 idx = 0U; idx < 3U; ++idx)
	{
		if (idx == row) offsetI = 1U;
		tU8 offsetJ = 0U;
		for (tU8 jdx = 0U; jdx < 3U; ++jdx)
		{
			if (jdx == col) offsetJ = 1U;
			out->m[idx][jdx] = mtrx.m[idx + offsetI][jdx + offsetJ];
		}
	}
	return False;
}
tF32M4x4 tF32M4x4_Cofact(tF32M4x4 mtrx)
{
	tF32M4x4 cof;
	for (tU8 idx = 0U; idx < 4U; ++idx)
	{
		for (tU8 jdx = 0U; jdx < 4U; ++jdx)
		{
			cof.m[idx][jdx] = tF32M3x3_Det(tF32M4x4_Minor(mtrx, idx, jdx));
			if ((idx + jdx) & 1U) cof.m[idx][jdx] = tF32_Neg(cof.m[idx][jdx]);
		}
	}
	return cof;
}
tF32M4x4 tF32M4x4_Adj(tF32M4x4 mtrx)
{
	return tF32M4x4_Transp(tF32M4x4_Cofact(mtrx));
}
tF32M4x4 tF32M4x4_Inv(tF32M4x4 mtrx)
{
	tF32 det = tF32M4x4_Det(mtrx);
#ifndef BQSE_DEBUG
	if (tF32_Abs(det) <= tF32_Eps) return tF32M4x4_Zero();
#else
	Assertion(tF32_Abs(det) > tF32_Eps);
#endif
	return tF32M4x4_DivFlt(tF32M4x4_Adj(mtrx), det);
}
tBln tF32M4x4_Inv_safe(tF32M4x4 *mtrx)
{
	tF32 det = tF32M4x4_Det(*mtrx);
	if (tF32_Abs(det) <= tF32_Eps) return True;
	*mtrx = tF32M4x4_DivFlt(tF32M4x4_Adj(*mtrx), det);
	return False;
}
tF32M4x4 tF32M4x4_Transl(tF32 x, tF32 y, tF32 z)
{
	return tF32M4x4_Make(1.0F, 0.0F, 0.0F, x, 0.0F, 1.0F, 0.0F, y, 0.0F, 0.0F, 1.0F, z, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_Scale(tF32 x, tF32 y, tF32 z)
{
	return tF32M4x4_Make(x, 0.0F, 0.0F, 0.0F, 0.0F, y, 0.0F, 0.0F, 0.0F, 0.0F, z, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_RotX(tF32 ang)
{
	const tF32 tmpC = tF32_Cosine(ang);
	const tF32 tmpS = tF32_Sine(ang);
	return tF32M4x4_Make(1.0F, 0.0F, 0.0F, 0.0F, 0.0F, tmpC, -tmpS, 0.0F, 0.0F, tmpS, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_RotY(tF32 ang)
{
	tF32 tmpC = tF32_Cosine(ang);
	tF32 tmpS = tF32_Sine(ang);
	return tF32M4x4_Make(tmpC, 0.0F, tmpS, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, -tmpS, 0.0F, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_RotZ(tF32 ang)
{
	tF32 tmpC = tF32_Cosine(ang);
	tF32 tmpS = tF32_Sine(ang);
	return tF32M4x4_Make(tmpC, -tmpS, 0.0F, 0.0F, tmpS, tmpC, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32M4x4 tF32M4x4_Persp(tF32 fov, tF32 aspect, tF32 near, tF32 far);
tF32M4x4 tF32M4x4_Ortho(tF32 left, tF32 right, tF32 bot, tF32 top, tF32 near, tF32 far)
{
	tF32 tmpX = 1.0F / (right - left);
	tF32 tmpY = 1.0F / (top - bot);
	tF32 tmpZ = 1.0F / (far - near);
	return tF32M4x4_Make(2.0F * tmpX, 0.0F, 0.0F, tF32_Neg(right + left) * tmpX, 0.0F, 2.0F * tmpY, 0.0F, tF32_Neg(top + bot) * tmpY, 0.0F, 0.0F, tmpZ, tF32_Neg(near * tmpZ), 0.0F, 0.0F, 0.0F, 1.0F);
}
tF32 tF32M4x4_Trace(tF32M4x4 mtrx)
{
	return mtrx.m00 + mtrx.m11 + mtrx.m22 + mtrx.m33;
}
tF32M4x4 tF32M4x4_InvAff(tF32M4x4 mtrx);
tF32M4x4 tF32M4x4_RotAxis(tF32V3D axis, tF32 ang);
tF32V3D tF32M4x4_TransfPoint(tF32M4x4 mtrx, tF32V3D vec);
tF32V3D tF32M4x4_TransfDir(tF32M4x4 mtrx, tF32V3D vec);
tNone tF32M4x4_RowSwap(tF32M4x4 *mtrx, tU8 idx1, tU8 idx2)
{
	tF32_Swap(&mtrx->m[idx1][0], &mtrx->m[idx2][0]);
	tF32_Swap(&mtrx->m[idx1][1], &mtrx->m[idx2][1]);
	tF32_Swap(&mtrx->m[idx1][2], &mtrx->m[idx2][2]);
	tF32_Swap(&mtrx->m[idx1][3], &mtrx->m[idx2][3]);
}
tNone tF32M4x4_RowAdd(tF32M4x4 *mtrx, tU8 dstRow, tU8 srcRow, tF32 mult)
{
	mtrx->m[dstRow][0] += mtrx->m[srcRow][0] * mult;
	mtrx->m[dstRow][1] += mtrx->m[srcRow][1] * mult;
	mtrx->m[dstRow][2] += mtrx->m[srcRow][2] * mult;
	mtrx->m[dstRow][3] += mtrx->m[srcRow][3] * mult;
}
tNone tF32M4x4_RowMult(tF32M4x4 *mtrx, tU8 idx, tF32 mult)
{
	mtrx->m[idx][0] *= mult;
	mtrx->m[idx][1] *= mult;
	mtrx->m[idx][2] *= mult;
	mtrx->m[idx][3] *= mult;
}
tNone tF32M4x4_RowEch(tF32M4x4 *mtrx)
{
	tU8 pivotRow = 0U;
	for (tU8 col = 0U; col < 4U; ++col)
	{
		if (pivotRow >= 4U) break;
		tBln foundPivot = False;
		if (mtrx->m[pivotRow][col] != 0.0F) foundPivot = True;
		else
		{
			for (tU8 idx = 1U; idx < 4U - pivotRow; ++idx)
			{
				if (mtrx->m[pivotRow + idx][col] != 0.0F)
				{
					tF32M4x4_RowSwap(mtrx, pivotRow, pivotRow + idx);
					foundPivot = True;
					break;
				}
			}
			if (foundPivot == False) continue;
		}
		tF32M4x4_RowMult(mtrx, pivotRow, 1.0F / mtrx->m[pivotRow][col]);
		for (tU8 idx = 1U; idx < 4U - pivotRow; ++idx) tF32M4x4_RowAdd(mtrx, pivotRow + idx, pivotRow, tF32_Neg(mtrx->m[pivotRow + idx][col]));
		++pivotRow;
	}
}
tNone tF32M4x4_RowEch(tF32M4x4 *mtrx)
{
	tU8 pivotRow = 0U;
	for (tU8 col = 0U; col < 4U; ++col)
	{
		if (pivotRow >= 4U) break;
		tBln foundPivot = False;
		if (mtrx->m[pivotRow][col] != 0.0F) foundPivot = True;
		else
		{
			for (tU8 idx = 1U; idx < 4U - pivotRow; ++idx)
			{
				if (mtrx->m[pivotRow + idx][col] != 0.0F)
				{
					tF32M4x4_RowSwap(mtrx, pivotRow, pivotRow + idx);
					foundPivot = True;
					break;
				}
			}
			if (foundPivot == False) continue;
		}
		tF32M4x4_RowMult(mtrx, pivotRow, 1.0F / mtrx->m[pivotRow][col]);
		for (tU8 idx = 1U; idx < 4U - pivotRow; ++idx) tF32M4x4_RowAdd(mtrx, pivotRow + idx, pivotRow, tF32_Neg(mtrx->m[pivotRow + idx][col]));
		++pivotRow;
	}
}
tNone tF32M4x4_RowRedEch(tF32M4x4 *mtrx)
{
	tF32M4x4_RowEch(mtrx);
	for (tS8 row = 3; row >= 0; --row)
	{
		tBln foundPivot = False;
		tU8 pivotCol = 0;
		for (tU8 col = 0U; col < 4; ++col)
		{
			if (mtrx->m[row][col] != 0.0F)
			{
				foundPivot = True;
				pivotCol = col;
				break;
			}
		}
		if (foundPivot == False) continue;
		for (tU8 aboveRow = 0U; aboveRow < row; ++aboveRow) tF32M4x4_RowAdd(mtrx, aboveRow, row, tF32_Neg(mtrx->m[aboveRow][pivotCol]));
	}
}
// TODO: tF32M4x4 function implementations.
#endif
typedef union { struct { tF64 m00, m01; tF64 m10, m11; }; tF64 m[2][2]; tF64V2D row[2]; } tF64M2x2;
// TODO: tF64M2x2 function declarations.
#ifdef BQSE_IMPL
// TODO: tF64M2x2 function implementations.
#endif
typedef union { struct { tF64 m00, m01, m02; tF64 m10, m11, m12; tF64 m20, m21, m22; }; tF64 m[3][3]; tF64V3D row[3]; } tF64M3x3;
// TODO: tF64M3x3 function declarations.
#ifdef BQSE_IMPL
// TODO: tF64M3x3 function implementations.
#endif
typedef union { struct { tF64 m00, m01, m02, m03; tF64 m10, m11, m12, m13; tF64 m20, m21, m22, m23; tF64 m30, m31, m32, m33; }; tF64 m[4][4]; tF64V4D row[4]; } tF64M4x4;
// TODO: tF64M4x4 function declarations.
#ifdef BQSE_IMPL
// TODO: tF64M4x4 function implementations.
#endif
#endif/*BQSELAYER_MTRX_H*/